// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lidar_camera_perception:msg/TrackedObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__STRUCT_H_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__STRUCT_H_

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
// Member 'objects'
#include "lidar_camera_perception/msg/detail/tracked_object__struct.h"

// Struct defined in msg/TrackedObjectArray in the package lidar_camera_perception.
typedef struct lidar_camera_perception__msg__TrackedObjectArray
{
  std_msgs__msg__Header header;
  lidar_camera_perception__msg__TrackedObject__Sequence objects;
} lidar_camera_perception__msg__TrackedObjectArray;

// Struct for a sequence of lidar_camera_perception__msg__TrackedObjectArray.
typedef struct lidar_camera_perception__msg__TrackedObjectArray__Sequence
{
  lidar_camera_perception__msg__TrackedObjectArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lidar_camera_perception__msg__TrackedObjectArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__STRUCT_H_
