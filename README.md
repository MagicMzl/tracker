# Tracking Pipeline Running Guide

## 0. Quick Commands

### Step 0. Check existing OpenCOOD npy files

```bash
MODEL_DIR=/home/zonglin/projects/V2X-Real/opencood/logs/point_pillar_v2xvit_2025_07_10_17_45_40

find $MODEL_DIR/npy -name "*_pred.npy" | wc -l
find $MODEL_DIR/npy -name "*_pcd.npy" | wc -l
ls $MODEL_DIR/npy | head
ls $MODEL_DIR/npy | tail
```

If the required npy files already exist, skip Step 1 and directly start from Step 2.

---

### Step 1. Generate OpenCOOD npy files if needed

```bash
conda activate opencood

cd /home/zonglin/projects/V2X-Real

export MODEL_DIR=/home/zonglin/projects/V2X-Real/opencood/logs/point_pillar_v2xvit_2025_07_10_17_45_40
export PYTHONPATH=$PWD:$PYTHONPATH

CUDA_VISIBLE_DEVICES=1 python opencood/tools/inference.py \
  --model_dir $MODEL_DIR \
  --fusion_method intermediate \
  --save_npy
```

Output folder:

```bash
/home/zonglin/projects/V2X-Real/opencood/logs/point_pillar_v2xvit_2025_07_10_17_45_40/npy
```

---

### Step 2. Choose frame range

Open the synchronized publisher:

```bash
gedit /home/zonglin/v2x_ws/sync_opencood_demo.py
```

Modify:

```python
START_IDX = 0
END_IDX = 118
```

Example ranges:

```text
scene1: START_IDX = 0,   END_IDX = 118
scene2: START_IDX = 119, END_IDX = 358
scene3: START_IDX = 359, END_IDX = 508
```

Save the file.

---

### Step 3. Terminal 1: Run synchronized point cloud and bbox publisher

```bash
cd /home/zonglin/v2x_ws

source /opt/ros/foxy/setup.bash

/usr/bin/python3 sync_opencood_demo.py
```

This publishes:

```text
/kitti/point_cloud
/lidar/bounding_boxes
```

Keep this terminal running.

---

### Step 4. Terminal 2: Run latest tracker

```bash
cd /home/zonglin/moon_project/ros2_ws

source /opt/ros/foxy/setup.bash
source install/setup.bash

/home/zonglin/moon_project/ros2_ws/install/lidar_camera_perception/lib/lidar_camera_perception/lidar_tracker_node
```

This publishes:

```text
/lidar/tracked_objects
/lidar/tracking_output
```

Keep this terminal running.

---

### Step 5. Terminal 3: Open RViz

```bash
source /opt/ros/foxy/setup.bash
source /home/zonglin/moon_project/ros2_ws/install/setup.bash

rviz2
```

In RViz:

```text
Fixed Frame: base_link
```

Add:

```text
PointCloud2  → /kitti/point_cloud
MarkerArray  → /lidar/bounding_boxes
MarkerArray  → /lidar/tracked_objects
```

Do not add `/lidar/tracking_output` in RViz. It is a structured message, not a MarkerArray.

---

### Step 6. Terminal 4: Check structured tracking output

```bash
source /opt/ros/foxy/setup.bash
source /home/zonglin/moon_project/ros2_ws/install/setup.bash

ros2 topic list | grep -E "bounding|tracked|tracking|kitti"
```

Expected:

```text
/kitti/point_cloud
/lidar/bounding_boxes
/lidar/tracked_objects
/lidar/tracking_output
```

Check type:

```bash
ros2 topic type /lidar/tracking_output
```

Expected:

```text
lidar_camera_perception/msg/TrackedObjectArray
```

Check message definition:

```bash
ros2 interface show lidar_camera_perception/msg/TrackedObject
```

Expected:

```text
std_msgs/Header header

int32 track_id
int32 age
float64 timestamp

geometry_msgs/Pose pose
geometry_msgs/Vector3 size
geometry_msgs/Twist velocity
```

Echo output:

```bash
timeout 5 ros2 topic echo /lidar/tracking_output | grep -E "track_id:|age:|timestamp:|position:|size:|velocity:"
```

Expected fields:

```text
track_id
age
timestamp
pose / position
size
velocity
```

---

### Step 7. Test that another agent/node can receive the message

```bash
cd /home/zonglin/v2x_ws

source /opt/ros/foxy/setup.bash
source /home/zonglin/moon_project/ros2_ws/install/setup.bash

/usr/bin/python3 listen_tracking_output.py
```

Expected output:

```text
frame_id: base_link
num objects: ...
id=..., age(frame)=..., pos=(...), size=(...), vel=(...)
```

This confirms that another ROS2 node / agent can subscribe to `/lidar/tracking_output`.

---

# 1. What each step does

## Step 1: OpenCOOD inference

OpenCOOD generates:

```text
*_pcd.npy
*_pred.npy
```

The output folder is:

```bash
/home/zonglin/projects/V2X-Real/opencood/logs/point_pillar_v2xvit_2025_07_10_17_45_40/npy
```

`*_pcd.npy` is the point cloud.

`*_pred.npy` is the OpenCOOD 3D detection output. In this setup, each `pred.npy` file stores boxes as:

```text
(N, 8, 3)
```

meaning each 3D box has 8 corners, and each corner has xyz coordinates.

---

## Step 2–3: synchronized publisher

The publisher script is:

```bash
/home/zonglin/v2x_ws/sync_opencood_demo.py
```

It reads the same frame index from:

```text
i_pcd.npy
i_pred.npy
```

Then publishes:

```text
/kitti/point_cloud      sensor_msgs/msg/PointCloud2
/lidar/bounding_boxes   visualization_msgs/msg/MarkerArray
```

`/lidar/bounding_boxes` is the tracker input.

---

## Step 4: latest tracker

Latest tracker source code:

```bash
/home/zonglin/moon_project/ros2_ws/src/ros2_lidar_camera_perception/src/lidar_tracker_node.cpp
```

Build output executable:

```bash
/home/zonglin/moon_project/ros2_ws/install/lidar_camera_perception/lib/lidar_camera_perception/lidar_tracker_node
```

The tracker subscribes to:

```text
/lidar/bounding_boxes
```

The tracker publishes:

```text
/lidar/tracked_objects
/lidar/tracking_output
```

`/lidar/tracked_objects` is for RViz visualization.

`/lidar/tracking_output` is for other agents / other ROS2 nodes.

---

## Step 6: structured tracking message

The new structured output is:

```text
Topic:
/lidar/tracking_output

Type:
lidar_camera_perception/msg/TrackedObjectArray
```

Each tracked object contains:

```text
track_id
age
timestamp
pose
size
velocity
```

Field meaning:

```text
track_id      tracking ID
age           ID age in number of frames
timestamp     merged timestamp = sec + nanosec / 1e9
pose + size   bounding box
velocity      vx, vy, vz from tracker Kalman state
```

---

# 2. Important paths

OpenCOOD repo:

```bash
/home/zonglin/projects/V2X-Real
```

Dataset:

```bash
/media/Disk2/data/v2xreal/test_tracking
```

OpenCOOD model directory:

```bash
/home/zonglin/projects/V2X-Real/opencood/logs/point_pillar_v2xvit_2025_07_10_17_45_40
```

OpenCOOD npy output:

```bash
/home/zonglin/projects/V2X-Real/opencood/logs/point_pillar_v2xvit_2025_07_10_17_45_40/npy
```

Synchronized publisher:

```bash
/home/zonglin/v2x_ws/sync_opencood_demo.py
```

Tracking output listener:

```bash
/home/zonglin/v2x_ws/listen_tracking_output.py
```

Tracker workspace:

```bash
/home/zonglin/moon_project/ros2_ws
```

Latest tracker source:

```bash
/home/zonglin/moon_project/ros2_ws/src/ros2_lidar_camera_perception/src/lidar_tracker_node.cpp
```

Custom message files:

```bash
/home/zonglin/moon_project/ros2_ws/src/ros2_lidar_camera_perception/msg/TrackedObject.msg
/home/zonglin/moon_project/ros2_ws/src/ros2_lidar_camera_perception/msg/TrackedObjectArray.msg
```

Tracker executable:

```bash
/home/zonglin/moon_project/ros2_ws/install/lidar_camera_perception/lib/lidar_camera_perception/lidar_tracker_node
```

---

# 3. Special cases and debugging

## Case 1. If `/lidar/bounding_boxes` does not exist

Check:

```bash
ros2 topic info /lidar/bounding_boxes
```

If it says:

```text
Unknown topic '/lidar/bounding_boxes'
```

then the publisher is not running.

Run Terminal 1 again:

```bash
cd /home/zonglin/v2x_ws
source /opt/ros/foxy/setup.bash
/usr/bin/python3 sync_opencood_demo.py
```

---

## Case 2. If tracker has no output

Check whether bbox input exists:

```bash
ros2 topic info /lidar/bounding_boxes
```

Check whether tracker is running:

```bash
ros2 node list | grep tracker
```

Expected:

```text
/lidar_tracker_node
```

Then check output:

```bash
ros2 topic list | grep tracking
```

Expected:

```text
/lidar/tracking_output
```

---

## Case 3. If message type looks outdated

If `.msg` files were modified, rebuild:

```bash
cd /home/zonglin/moon_project/ros2_ws

source /opt/ros/foxy/setup.bash

colcon build --packages-select lidar_camera_perception --symlink-install
source install/setup.bash
```

Then refresh ROS2 daemon if needed:

```bash
ros2 daemon stop
sleep 2
ros2 daemon start
```

Check again:

```bash
ros2 interface show lidar_camera_perception/msg/TrackedObject
```

Expected latest fields:

```text
int32 track_id
int32 age
float64 timestamp
```

---

## Case 4. If the wrong bbox publisher is running

Check current publisher process:

```bash
ps -ef | grep -E "sync_opencood|bbox_pub|publisher" | grep -v grep
```

Correct OpenCOOD publisher should be:

```text
/usr/bin/python3 sync_opencood_demo.py
```

If this is running instead:

```text
ros2 run v2x_bbox_publisher bbox_pub
```

then `/lidar/bounding_boxes` may be coming from `v2x_gt_boxes`, not OpenCOOD prediction.

Kill wrong publisher:

```bash
pkill -9 -f bbox_pub
```

Then run the correct publisher:

```bash
cd /home/zonglin/v2x_ws
source /opt/ros/foxy/setup.bash
/usr/bin/python3 sync_opencood_demo.py
```

Check bbox namespace:

```bash
timeout 3 ros2 topic echo /lidar/bounding_boxes | grep "ns:" | head
```

Expected for OpenCOOD publisher:

```text
ns: opencood_pred_sync
```

If it shows:

```text
ns: v2x_gt_boxes
```

then the old bbox publisher is still being used.

---

## Case 5. If RViz shows the world rotating around the center vehicle

This usually means the data is visualized in:

```text
base_link
```

In `base_link`, the ego vehicle stays fixed, and other objects move relative to it.

This is not a tracker output bug. It is a coordinate-frame / ego-frame visualization behavior.

Current RViz setting:

```text
Fixed Frame: base_link
```

To make the world stable, the data would need to be transformed to a global frame such as:

```text
map
```

using ego pose / transformation matrix.

---

## Case 6. If `BrokenPipeError` appears when using `head`

Example command:

```bash
timeout 3 ros2 topic echo /lidar/bounding_boxes | head -n 100
```

Sometimes it prints:

```text
BrokenPipeError
```

This is not a ROS topic error. It happens because `head` exits after reading enough lines while `ros2 topic echo` is still trying to print.

It can be ignored.

---

# 4. Final expected result

After the full pipeline is running:

Input topic:

```text
/lidar/bounding_boxes
```

RViz visualization topic:

```text
/lidar/tracked_objects
```

Structured output topic for other agents:

```text
/lidar/tracking_output
```

`/lidar/tracking_output` includes:

```text
track_id
age, frame count
timestamp, sec + nanosec / 1e9
bounding box pose
bounding box size
velocity vx/vy/vz
```
