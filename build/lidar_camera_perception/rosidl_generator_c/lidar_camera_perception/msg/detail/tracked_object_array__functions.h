// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lidar_camera_perception:msg/TrackedObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__FUNCTIONS_H_
#define LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lidar_camera_perception/msg/rosidl_generator_c__visibility_control.h"

#include "lidar_camera_perception/msg/detail/tracked_object_array__struct.h"

/// Initialize msg/TrackedObjectArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lidar_camera_perception__msg__TrackedObjectArray
 * )) before or use
 * lidar_camera_perception__msg__TrackedObjectArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
bool
lidar_camera_perception__msg__TrackedObjectArray__init(lidar_camera_perception__msg__TrackedObjectArray * msg);

/// Finalize msg/TrackedObjectArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
void
lidar_camera_perception__msg__TrackedObjectArray__fini(lidar_camera_perception__msg__TrackedObjectArray * msg);

/// Create msg/TrackedObjectArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lidar_camera_perception__msg__TrackedObjectArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
lidar_camera_perception__msg__TrackedObjectArray *
lidar_camera_perception__msg__TrackedObjectArray__create();

/// Destroy msg/TrackedObjectArray message.
/**
 * It calls
 * lidar_camera_perception__msg__TrackedObjectArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
void
lidar_camera_perception__msg__TrackedObjectArray__destroy(lidar_camera_perception__msg__TrackedObjectArray * msg);

/// Check for msg/TrackedObjectArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
bool
lidar_camera_perception__msg__TrackedObjectArray__are_equal(const lidar_camera_perception__msg__TrackedObjectArray * lhs, const lidar_camera_perception__msg__TrackedObjectArray * rhs);

/// Copy a msg/TrackedObjectArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
bool
lidar_camera_perception__msg__TrackedObjectArray__copy(
  const lidar_camera_perception__msg__TrackedObjectArray * input,
  lidar_camera_perception__msg__TrackedObjectArray * output);

/// Initialize array of msg/TrackedObjectArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * lidar_camera_perception__msg__TrackedObjectArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
bool
lidar_camera_perception__msg__TrackedObjectArray__Sequence__init(lidar_camera_perception__msg__TrackedObjectArray__Sequence * array, size_t size);

/// Finalize array of msg/TrackedObjectArray messages.
/**
 * It calls
 * lidar_camera_perception__msg__TrackedObjectArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
void
lidar_camera_perception__msg__TrackedObjectArray__Sequence__fini(lidar_camera_perception__msg__TrackedObjectArray__Sequence * array);

/// Create array of msg/TrackedObjectArray messages.
/**
 * It allocates the memory for the array and calls
 * lidar_camera_perception__msg__TrackedObjectArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
lidar_camera_perception__msg__TrackedObjectArray__Sequence *
lidar_camera_perception__msg__TrackedObjectArray__Sequence__create(size_t size);

/// Destroy array of msg/TrackedObjectArray messages.
/**
 * It calls
 * lidar_camera_perception__msg__TrackedObjectArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
void
lidar_camera_perception__msg__TrackedObjectArray__Sequence__destroy(lidar_camera_perception__msg__TrackedObjectArray__Sequence * array);

/// Check for msg/TrackedObjectArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
bool
lidar_camera_perception__msg__TrackedObjectArray__Sequence__are_equal(const lidar_camera_perception__msg__TrackedObjectArray__Sequence * lhs, const lidar_camera_perception__msg__TrackedObjectArray__Sequence * rhs);

/// Copy an array of msg/TrackedObjectArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lidar_camera_perception
bool
lidar_camera_perception__msg__TrackedObjectArray__Sequence__copy(
  const lidar_camera_perception__msg__TrackedObjectArray__Sequence * input,
  lidar_camera_perception__msg__TrackedObjectArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LIDAR_CAMERA_PERCEPTION__MSG__DETAIL__TRACKED_OBJECT_ARRAY__FUNCTIONS_H_
