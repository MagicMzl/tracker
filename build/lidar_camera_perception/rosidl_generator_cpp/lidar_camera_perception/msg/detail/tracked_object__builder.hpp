// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_camera_perception:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_

#include "lidar_camera_perception/msg/detail/tracked_object__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lidar_camera_perception
{

namespace msg
{

namespace builder
{

class Init_TrackedObject_velocity
{
public:
  explicit Init_TrackedObject_velocity(::lidar_camera_perception::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  ::lidar_camera_perception::msg::TrackedObject velocity(::lidar_camera_perception::msg::TrackedObject::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

class Init_TrackedObject_size
{
public:
  explicit Init_TrackedObject_size(::lidar_camera_perception::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_velocity size(::lidar_camera_perception::msg::TrackedObject::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_TrackedObject_velocity(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

class Init_TrackedObject_pose
{
public:
  explicit Init_TrackedObject_pose(::lidar_camera_perception::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_size pose(::lidar_camera_perception::msg::TrackedObject::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_TrackedObject_size(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

class Init_TrackedObject_timestamp
{
public:
  explicit Init_TrackedObject_timestamp(::lidar_camera_perception::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_pose timestamp(::lidar_camera_perception::msg::TrackedObject::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_TrackedObject_pose(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

class Init_TrackedObject_age
{
public:
  explicit Init_TrackedObject_age(::lidar_camera_perception::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_timestamp age(::lidar_camera_perception::msg::TrackedObject::_age_type arg)
  {
    msg_.age = std::move(arg);
    return Init_TrackedObject_timestamp(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

class Init_TrackedObject_track_id
{
public:
  explicit Init_TrackedObject_track_id(::lidar_camera_perception::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_age track_id(::lidar_camera_perception::msg::TrackedObject::_track_id_type arg)
  {
    msg_.track_id = std::move(arg);
    return Init_TrackedObject_age(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

class Init_TrackedObject_header
{
public:
  Init_TrackedObject_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedObject_track_id header(::lidar_camera_perception::msg::TrackedObject::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrackedObject_track_id(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_camera_perception::msg::TrackedObject>()
{
  return lidar_camera_perception::msg::builder::Init_TrackedObject_header();
}

}  // namespace lidar_camera_perception

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_
