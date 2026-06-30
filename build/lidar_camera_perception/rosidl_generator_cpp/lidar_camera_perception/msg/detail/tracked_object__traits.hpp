// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lidar_camera_perception:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__TRAITS_HPP_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__TRAITS_HPP_

#include "lidar_camera_perception/msg/detail/tracked_object__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'size'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lidar_camera_perception::msg::TrackedObject>()
{
  return "lidar_camera_perception::msg::TrackedObject";
}

template<>
inline const char * name<lidar_camera_perception::msg::TrackedObject>()
{
  return "lidar_camera_perception/msg/TrackedObject";
}

template<>
struct has_fixed_size<lidar_camera_perception::msg::TrackedObject>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<geometry_msgs::msg::Twist>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<lidar_camera_perception::msg::TrackedObject>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<geometry_msgs::msg::Twist>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<lidar_camera_perception::msg::TrackedObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT__TRAITS_HPP_
