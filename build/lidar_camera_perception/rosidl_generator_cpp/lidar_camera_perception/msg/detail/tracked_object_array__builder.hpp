// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lidar_camera_perception:msg/TrackedObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__BUILDER_HPP_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__BUILDER_HPP_

#include "lidar_camera_perception/msg/detail/tracked_object_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lidar_camera_perception
{

namespace msg
{

namespace builder
{

class Init_TrackedObjectArray_objects
{
public:
  explicit Init_TrackedObjectArray_objects(::lidar_camera_perception::msg::TrackedObjectArray & msg)
  : msg_(msg)
  {}
  ::lidar_camera_perception::msg::TrackedObjectArray objects(::lidar_camera_perception::msg::TrackedObjectArray::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObjectArray msg_;
};

class Init_TrackedObjectArray_header
{
public:
  Init_TrackedObjectArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedObjectArray_objects header(::lidar_camera_perception::msg::TrackedObjectArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrackedObjectArray_objects(msg_);
  }

private:
  ::lidar_camera_perception::msg::TrackedObjectArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lidar_camera_perception::msg::TrackedObjectArray>()
{
  return lidar_camera_perception::msg::builder::Init_TrackedObjectArray_header();
}

}  // namespace lidar_camera_perception

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__BUILDER_HPP_
