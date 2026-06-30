#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <array>
#include <unordered_map>
#include "lidar_camera_perception/msg/tracked_object_array.hpp"

class Track {
public:
    int track_id;
    int age;
    int hits;
    int time_since_update;
    std::vector<double> size;
    std::array<double, 4> orientation; // x, y, z, w

    // Kalman Filter matrices
    Eigen::VectorXd x; // State: [x, y, z, vx, vy, vz]
    Eigen::MatrixXd P; // State covariance
    Eigen::MatrixXd F; // State transition matrix
    Eigen::MatrixXd H; // Measurement matrix
    Eigen::MatrixXd R; // Measurement noise covariance
    Eigen::MatrixXd Q; // Process noise covariance
    Eigen::MatrixXd I; // Identity matrix

    Track(const Eigen::Vector3d& detection, const std::vector<double>& dimensions, const std::array<double, 4>& quat, int id) 
        : track_id(id), age(1), hits(1), time_since_update(0), size(dimensions), orientation(quat) 
    {
        x = Eigen::VectorXd::Zero(6);
        x.head(3) = detection;

        P = Eigen::MatrixXd::Identity(6, 6) * 10.0;
        
        F = Eigen::MatrixXd::Identity(6, 6); // dt added during predict()
        
        H = Eigen::MatrixXd::Zero(3, 6);
        H(0, 0) = 1.0; H(1, 1) = 1.0; H(2, 2) = 1.0;

        R = Eigen::MatrixXd::Identity(3, 3) * 0.5;
        Q = Eigen::MatrixXd::Identity(6, 6) * 0.1;
        I = Eigen::MatrixXd::Identity(6, 6);
    }

    Eigen::Vector3d predict(double dt) {
        // Update physics model with actual dt
        F(0, 3) = dt;
        F(1, 4) = dt;
        F(2, 5) = dt;

        x = F * x;
        P = F * P * F.transpose() + Q;

        age += 1;
        time_since_update += 1;
        return x.head(3);
    }

    void update(const Eigen::Vector3d& detection, const std::vector<double>& dimensions, const std::array<double, 4>& quat) {
        Eigen::Vector3d y = detection - (H * x); 
        Eigen::MatrixXd S = H * P * H.transpose() + R; 
        Eigen::MatrixXd K = P * H.transpose() * S.inverse();

        x = x + (K * y);
        P = (I - K * H) * P;

        size = dimensions;
        orientation = quat;
        time_since_update = 0;
        hits += 1;
    }
};

class ObjectTrackingNode : public rclcpp::Node {
public:
    ObjectTrackingNode() : Node("lidar_tracker_node"), next_track_id_(0), last_timestamp_(-1.0) {

        this->declare_parameter<int>("max_age", 3);
        this->get_parameter("max_age", max_age_);

        this->declare_parameter<double>("distance_threshold", 4.0);
        this->get_parameter("distance_threshold", distance_threshold_);

        subscription_ = this->create_subscription<visualization_msgs::msg::MarkerArray>(
            "/lidar/bounding_boxes", 10,
            std::bind(&ObjectTrackingNode::detection_callback, this, std::placeholders::_1));

        tracked_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("/lidar/tracked_objects", 10);
        tracking_output_pub_ = this->create_publisher<lidar_camera_perception::msg::TrackedObjectArray>("/lidar/tracking_output", 10);

        RCLCPP_INFO(this->get_logger(), "Lidar Tracker Node Started...");
    }

private:
    std::vector<Track> tracks_;
    int next_track_id_;
    double last_timestamp_;
    std::unordered_map<int, double> id_start_time_;

    // Tuned Parameters
    int max_age_;
    double distance_threshold_;

    void detection_callback(const visualization_msgs::msg::MarkerArray::SharedPtr msg) {
        if (msg->markers.empty()) return;

        double current_time_float = 0.0;
        std::string current_frame = "map";
        builtin_interfaces::msg::Time stamp;
        bool stamp_found = false;

        // Extract raw detections & timestamp
        std::vector<Eigen::Vector3d> detections;
        std::vector<std::vector<double>> dimensions;
        std::vector<std::array<double, 4>> orientations;

        for (const auto& marker : msg->markers) {
            if (marker.action == visualization_msgs::msg::Marker::ADD) {
                if (!stamp_found) {
                    stamp = marker.header.stamp;
                    current_frame = marker.header.frame_id;
                    current_time_float = stamp.sec + (stamp.nanosec * 1e-9);
                    stamp_found = true;
                }
                detections.push_back(Eigen::Vector3d(marker.pose.position.x, marker.pose.position.y, marker.pose.position.z));
                dimensions.push_back({marker.scale.x, marker.scale.y, marker.scale.z});
                orientations.push_back({marker.pose.orientation.x, marker.pose.orientation.y, marker.pose.orientation.z, marker.pose.orientation.w});
            }
        }

        if (!stamp_found) return;

        // Calculate dynamic dt
        double dt = 0.1;
        if (last_timestamp_ > 0.0) {
            dt = current_time_float - last_timestamp_;
            if (dt <= 0.0 || dt > 2.0) dt = 0.1; // Fallback for loops/pauses
        }
        last_timestamp_ = current_time_float;

        // Predict
        std::vector<Eigen::Vector3d> predictions;
        for (auto& track : tracks_) {
            predictions.push_back(track.predict(dt));
        }

        // Data Association (Greedy Nearest-Neighbor)
        std::vector<std::pair<int, int>> matched_indices;
        std::vector<int> unmatched_detections;
        std::vector<int> unmatched_tracks;

        if (!tracks_.empty() && !detections.empty()) {
            struct MatchCost { int trk_idx; int det_idx; double cost; };
            std::vector<MatchCost> costs;

            for (size_t t = 0; t < predictions.size(); ++t) {
                for (size_t d = 0; d < detections.size(); ++d) {
                    double dist = (predictions[t] - detections[d]).norm();
                    if (dist < distance_threshold_) {
                        costs.push_back({(int)t, (int)d, dist});
                    }
                }
            }

            // Sort by lowest cost (closest pairs first)
            std::sort(costs.begin(), costs.end(), [](const MatchCost& a, const MatchCost& b) {
                return a.cost < b.cost;
            });

            std::vector<bool> trk_assigned(tracks_.size(), false);
            std::vector<bool> det_assigned(detections.size(), false);

            for (const auto& c : costs) {
                if (!trk_assigned[c.trk_idx] && !det_assigned[c.det_idx]) {
                    matched_indices.push_back({c.trk_idx, c.det_idx});
                    trk_assigned[c.trk_idx] = true;
                    det_assigned[c.det_idx] = true;
                }
            }

            for (size_t t = 0; t < tracks_.size(); ++t) {
                if (!trk_assigned[t]) unmatched_tracks.push_back(t);
            }
            for (size_t d = 0; d < detections.size(); ++d) {
                if (!det_assigned[d]) unmatched_detections.push_back(d);
            }
        } else {
            for (size_t d = 0; d < detections.size(); ++d) unmatched_detections.push_back(d);
            for (size_t t = 0; t < tracks_.size(); ++t) unmatched_tracks.push_back(t);
        }

        // Update matched tracks
        for (const auto& match : matched_indices) {
            tracks_[match.first].update(detections[match.second], dimensions[match.second], orientations[match.second]);
        }

        // Create new tracks
        for (int det_idx : unmatched_detections) {
            int new_track_id = next_track_id_++;
            tracks_.push_back(Track(detections[det_idx], dimensions[det_idx], orientations[det_idx], new_track_id));

            // Store first-seen timestamp for this ID.
            // Do not delete this entry when the track disappears briefly.
            if (id_start_time_.find(new_track_id) == id_start_time_.end()) {
                id_start_time_[new_track_id] = current_time_float;
            }
        }

        // Delete dead tracks
        tracks_.erase(std::remove_if(tracks_.begin(), tracks_.end(),
            [this](const Track& t) { return t.time_since_update > max_age_; }), tracks_.end());

        publish_markers(current_frame, stamp);
    }

    void publish_markers(const std::string& frame_id, const builtin_interfaces::msg::Time& stamp) {
        visualization_msgs::msg::MarkerArray marker_array;

        lidar_camera_perception::msg::TrackedObjectArray tracking_array;
        tracking_array.header.frame_id = frame_id;
        tracking_array.header.stamp = stamp;

        double stamp_time = stamp.sec + (stamp.nanosec * 1e-9);

        visualization_msgs::msg::Marker delete_all;
        delete_all.action = visualization_msgs::msg::Marker::DELETEALL;
        marker_array.markers.push_back(delete_all);

        for (const auto& track : tracks_) {
            if (track.hits < 3) continue;

            double x = track.x(0), y = track.x(1), z = track.x(2);
            double vx = track.x(3), vy = track.x(4), vz = track.x(5);

            if (id_start_time_.find(track.track_id) == id_start_time_.end()) {
                id_start_time_[track.track_id] = stamp_time;
            }
            // Bounding Box
            visualization_msgs::msg::Marker box_marker;
            box_marker.header.frame_id = frame_id;
            box_marker.header.stamp = stamp;
            box_marker.ns = "tracked_boxes";
            box_marker.id = track.track_id * 2;
            box_marker.type = visualization_msgs::msg::Marker::CUBE;
            box_marker.action = visualization_msgs::msg::Marker::ADD;
            box_marker.pose.position.x = x; box_marker.pose.position.y = y; box_marker.pose.position.z = z;
            box_marker.pose.orientation.x = track.orientation[0];
            box_marker.pose.orientation.y = track.orientation[1];
            box_marker.pose.orientation.z = track.orientation[2];
            box_marker.pose.orientation.w = track.orientation[3];
            box_marker.scale.x = track.size[0]; box_marker.scale.y = track.size[1]; box_marker.scale.z = track.size[2];
            box_marker.color.r = 0.0; box_marker.color.g = 1.0; box_marker.color.b = 0.0; box_marker.color.a = 0.5;
            marker_array.markers.push_back(box_marker);

            // Machine-readable tracking output
            lidar_camera_perception::msg::TrackedObject tracked_object;
            tracked_object.header = box_marker.header;
            tracked_object.track_id = track.track_id;
            tracked_object.age = track.age;
            tracked_object.timestamp = stamp_time;
            tracked_object.pose = box_marker.pose;
            tracked_object.size.x = track.size[0];
            tracked_object.size.y = track.size[1];
            tracked_object.size.z = track.size[2];
            tracked_object.velocity.linear.x = vx;
            tracked_object.velocity.linear.y = vy;
            tracked_object.velocity.linear.z = vz;
            tracked_object.velocity.angular.x = 0.0;
            tracked_object.velocity.angular.y = 0.0;
            tracked_object.velocity.angular.z = 0.0;
            tracking_array.objects.push_back(tracked_object);

            // Text
            visualization_msgs::msg::Marker text_marker;
            text_marker.header = box_marker.header;
            text_marker.ns = "tracked_text";
            text_marker.id = (track.track_id * 2) + 1;
            text_marker.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
            text_marker.pose.position.x = x; text_marker.pose.position.y = y; 
            text_marker.pose.position.z = z + (track.size[2] / 2.0) + 0.5;
            text_marker.scale.z = 0.6;
            text_marker.color.r = 1.0; text_marker.color.g = 1.0; text_marker.color.b = 1.0; text_marker.color.a = 1.0;
            
            char text_buffer[128];
            snprintf(text_buffer, sizeof(text_buffer), "ID: %d\nAge(frame): %d", track.track_id, track.age);
            text_marker.text = text_buffer;
            
            marker_array.markers.push_back(text_marker);
        }

        tracked_pub_->publish(marker_array);
        tracking_output_pub_->publish(tracking_array);
    }

    rclcpp::Subscription<visualization_msgs::msg::MarkerArray>::SharedPtr subscription_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr tracked_pub_;
    rclcpp::Publisher<lidar_camera_perception::msg::TrackedObjectArray>::SharedPtr tracking_output_pub_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ObjectTrackingNode>());
    rclcpp::shutdown();
    return 0;
}