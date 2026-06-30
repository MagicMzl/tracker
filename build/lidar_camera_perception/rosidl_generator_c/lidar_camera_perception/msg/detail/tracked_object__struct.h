// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_camera_perception:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__STRUCT_H_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'size'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

// Struct defined in msg/TrackedObject in the package lidar_camera_perception.
typedef struct lidar_camera_perception__msg__TrackedObject
{
  std_msgs__msg__Header header;
  int32_t track_id;
  int32_t age;
  double timestamp;
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Vector3 size;
  geometry_msgs__msg__Twist velocity;
} lidar_camera_perception__msg__TrackedObject;

// Struct for a sequence of lidar_camera_perception__msg__TrackedObject.
typedef struct lidar_camera_perception__msg__TrackedObject__Sequence
{
  lidar_camera_perception__msg__TrackedObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_camera_perception__msg__TrackedObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__STRUCT_H_
