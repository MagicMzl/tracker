// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lidar_camera_perception:msg/TrackedObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__TRAITS_HPP_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__TRAITS_HPP_

#include "lidar_camera_perception/msg/detail/tracked_object_array__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lidar_camera_perception::msg::TrackedObjectArray>()
{
  return "lidar_camera_perception::msg::TrackedObjectArray";
}

template<>
inline const char * name<lidar_camera_perception::msg::TrackedObjectArray>()
{
  return "lidar_camera_perception/msg/TrackedObjectArray";
}

template<>
struct has_fixed_size<lidar_camera_perception::msg::TrackedObjectArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lidar_camera_perception::msg::TrackedObjectArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lidar_camera_perception::msg::TrackedObjectArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__TRAITS_HPP_
