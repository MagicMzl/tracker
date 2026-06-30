// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_camera_perception:msg/TrackedObjectArray.idl
// generated code does not contain a copyright notice
#include "lidar_camera_perception/msg/detail/tracked_object_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `objects`
#include "lidar_camera_perception/msg/detail/tracked_object__functions.h"

bool
lidar_camera_perception__msg__TrackedObjectArray__init(lidar_camera_perception__msg__TrackedObjectArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lidar_camera_perception__msg__TrackedObjectArray__fini(msg);
    return false;
  }
  // objects
  if (!lidar_camera_perception__msg__TrackedObject__Sequence__init(&msg->objects, 0)) {
    lidar_camera_perception__msg__TrackedObjectArray__fini(msg);
    return false;
  }
  return true;
}

void
lidar_camera_perception__msg__TrackedObjectArray__fini(lidar_camera_perception__msg__TrackedObjectArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // objects
  lidar_camera_perception__msg__TrackedObject__Sequence__fini(&msg->objects);
}

bool
lidar_camera_perception__msg__TrackedObjectArray__are_equal(const lidar_camera_perception__msg__TrackedObjectArray * lhs, const lidar_camera_perception__msg__TrackedObjectArray * rhs)
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
  // objects
  if (!lidar_camera_perception__msg__TrackedObject__Sequence__are_equal(
      &(lhs->objects), &(rhs->objects)))
  {
    return false;
  }
  return true;
}

bool
lidar_camera_perception__msg__TrackedObjectArray__copy(
  const lidar_camera_perception__msg__TrackedObjectArray * input,
  lidar_camera_perception__msg__TrackedObjectArray * output)
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
  // objects
  if (!lidar_camera_perception__msg__TrackedObject__Sequence__copy(
      &(input->objects), &(output->objects)))
  {
    return false;
  }
  return true;
}

lidar_camera_perception__msg__TrackedObjectArray *
lidar_camera_perception__msg__TrackedObjectArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_camera_perception__msg__TrackedObjectArray * msg = (lidar_camera_perception__msg__TrackedObjectArray *)allocator.allocate(sizeof(lidar_camera_perception__msg__TrackedObjectArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_camera_perception__msg__TrackedObjectArray));
  bool success = lidar_camera_perception__msg__TrackedObjectArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_camera_perception__msg__TrackedObjectArray__destroy(lidar_camera_perception__msg__TrackedObjectArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_camera_perception__msg__TrackedObjectArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_camera_perception__msg__TrackedObjectArray__Sequence__init(lidar_camera_perception__msg__TrackedObjectArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_camera_perception__msg__TrackedObjectArray * data = NULL;

  if (size) {
    data = (lidar_camera_perception__msg__TrackedObjectArray *)allocator.zero_allocate(size, sizeof(lidar_camera_perception__msg__TrackedObjectArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_camera_perception__msg__TrackedObjectArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_camera_perception__msg__TrackedObjectArray__fini(&data[i - 1]);
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
lidar_camera_perception__msg__TrackedObjectArray__Sequence__fini(lidar_camera_perception__msg__TrackedObjectArray__Sequence * array)
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
      lidar_camera_perception__msg__TrackedObjectArray__fini(&array->data[i]);
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

lidar_camera_perception__msg__TrackedObjectArray__Sequence *
lidar_camera_perception__msg__TrackedObjectArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_camera_perception__msg__TrackedObjectArray__Sequence * array = (lidar_camera_perception__msg__TrackedObjectArray__Sequence *)allocator.allocate(sizeof(lidar_camera_perception__msg__TrackedObjectArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_camera_perception__msg__TrackedObjectArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_camera_perception__msg__TrackedObjectArray__Sequence__destroy(lidar_camera_perception__msg__TrackedObjectArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_camera_perception__msg__TrackedObjectArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_camera_perception__msg__TrackedObjectArray__Sequence__are_equal(const lidar_camera_perception__msg__TrackedObjectArray__Sequence * lhs, const lidar_camera_perception__msg__TrackedObjectArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_camera_perception__msg__TrackedObjectArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_camera_perception__msg__TrackedObjectArray__Sequence__copy(
  const lidar_camera_perception__msg__TrackedObjectArray__Sequence * input,
  lidar_camera_perception__msg__TrackedObjectArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_camera_perception__msg__TrackedObjectArray);
    lidar_camera_perception__msg__TrackedObjectArray * data =
      (lidar_camera_perception__msg__TrackedObjectArray *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_camera_perception__msg__TrackedObjectArray__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          lidar_camera_perception__msg__TrackedObjectArray__fini(&data[i]);
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
    if (!lidar_camera_perception__msg__TrackedObjectArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
