// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_camera_perception:msg/TrackedObject.idl
// generated code does not contain a copyright notice
#include "lidar_camera_perception/msg/detail/tracked_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `size`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
lidar_camera_perception__msg__TrackedObject__init(lidar_camera_perception__msg__TrackedObject * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lidar_camera_perception__msg__TrackedObject__fini(msg);
    return false;
  }
  // track_id
  // age
  // timestamp
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    lidar_camera_perception__msg__TrackedObject__fini(msg);
    return false;
  }
  // size
  if (!geometry_msgs__msg__Vector3__init(&msg->size)) {
    lidar_camera_perception__msg__TrackedObject__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__init(&msg->velocity)) {
    lidar_camera_perception__msg__TrackedObject__fini(msg);
    return false;
  }
  return true;
}

void
lidar_camera_perception__msg__TrackedObject__fini(lidar_camera_perception__msg__TrackedObject * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // track_id
  // age
  // timestamp
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // size
  geometry_msgs__msg__Vector3__fini(&msg->size);
  // velocity
  geometry_msgs__msg__Twist__fini(&msg->velocity);
}

bool
lidar_camera_perception__msg__TrackedObject__are_equal(const lidar_camera_perception__msg__TrackedObject * lhs, const lidar_camera_perception__msg__TrackedObject * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // track_id
  if (lhs->track_id != rhs->track_id) {
    return false;
  }
  // age
  if (lhs->age != rhs->age) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // size
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->size), &(rhs->size)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  return true;
}

bool
lidar_camera_perception__msg__TrackedObject__copy(
  const lidar_camera_perception__msg__TrackedObject * input,
  lidar_camera_perception__msg__TrackedObject * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // track_id
  output->track_id = input->track_id;
  // age
  output->age = input->age;
  // timestamp
  output->timestamp = input->timestamp;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // size
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->size), &(output->size)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  return true;
}

lidar_camera_perception__msg__TrackedObject *
lidar_camera_perception__msg__TrackedObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_camera_perception__msg__TrackedObject * msg = (lidar_camera_perception__msg__TrackedObject *)allocator.allocate(sizeof(lidar_camera_perception__msg__TrackedObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_camera_perception__msg__TrackedObject));
  bool success = lidar_camera_perception__msg__TrackedObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_camera_perception__msg__TrackedObject__destroy(lidar_camera_perception__msg__TrackedObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_camera_perception__msg__TrackedObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_camera_perception__msg__TrackedObject__Sequence__init(lidar_camera_perception__msg__TrackedObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_camera_perception__msg__TrackedObject * data = NULL;

  if (size) {
    data = (lidar_camera_perception__msg__TrackedObject *)allocator.zero_allocate(size, sizeof(lidar_camera_perception__msg__TrackedObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_camera_perception__msg__TrackedObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_camera_perception__msg__TrackedObject__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
lidar_camera_perception__msg__TrackedObject__Sequence__fini(lidar_camera_perception__msg__TrackedObject__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lidar_camera_perception__msg__TrackedObject__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

lidar_camera_perception__msg__TrackedObject__Sequence *
lidar_camera_perception__msg__TrackedObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_camera_perception__msg__TrackedObject__Sequence * array = (lidar_camera_perception__msg__TrackedObject__Sequence *)allocator.allocate(sizeof(lidar_camera_perception__msg__TrackedObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_camera_perception__msg__TrackedObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_camera_perception__msg__TrackedObject__Sequence__destroy(lidar_camera_perception__msg__TrackedObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_camera_perception__msg__TrackedObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_camera_perception__msg__TrackedObject__Sequence__are_equal(const lidar_camera_perception__msg__TrackedObject__Sequence * lhs, const lidar_camera_perception__msg__TrackedObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_camera_perception__msg__TrackedObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_camera_perception__msg__TrackedObject__Sequence__copy(
  const lidar_camera_perception__msg__TrackedObject__Sequence * input,
  lidar_camera_perception__msg__TrackedObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_camera_perception__msg__TrackedObject);
    lidar_camera_perception__msg__TrackedObject * data =
      (lidar_camera_perception__msg__TrackedObject *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_camera_perception__msg__TrackedObject__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          lidar_camera_perception__msg__TrackedObject__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_camera_perception__msg__TrackedObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
