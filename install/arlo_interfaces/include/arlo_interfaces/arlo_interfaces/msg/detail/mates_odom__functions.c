// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice
#include "arlo_interfaces/msg/detail/mates_odom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `odom`
#include "nav_msgs/msg/detail/odometry__functions.h"
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
arlo_interfaces__msg__MatesOdom__init(arlo_interfaces__msg__MatesOdom * msg)
{
  if (!msg) {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__init(&msg->odom)) {
    arlo_interfaces__msg__MatesOdom__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    arlo_interfaces__msg__MatesOdom__fini(msg);
    return false;
  }
  return true;
}

void
arlo_interfaces__msg__MatesOdom__fini(arlo_interfaces__msg__MatesOdom * msg)
{
  if (!msg) {
    return;
  }
  // odom
  nav_msgs__msg__Odometry__fini(&msg->odom);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
arlo_interfaces__msg__MatesOdom__are_equal(const arlo_interfaces__msg__MatesOdom * lhs, const arlo_interfaces__msg__MatesOdom * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__are_equal(
      &(lhs->odom), &(rhs->odom)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
arlo_interfaces__msg__MatesOdom__copy(
  const arlo_interfaces__msg__MatesOdom * input,
  arlo_interfaces__msg__MatesOdom * output)
{
  if (!input || !output) {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__copy(
      &(input->odom), &(output->odom)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

arlo_interfaces__msg__MatesOdom *
arlo_interfaces__msg__MatesOdom__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__msg__MatesOdom * msg = (arlo_interfaces__msg__MatesOdom *)allocator.allocate(sizeof(arlo_interfaces__msg__MatesOdom), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arlo_interfaces__msg__MatesOdom));
  bool success = arlo_interfaces__msg__MatesOdom__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arlo_interfaces__msg__MatesOdom__destroy(arlo_interfaces__msg__MatesOdom * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arlo_interfaces__msg__MatesOdom__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arlo_interfaces__msg__MatesOdom__Sequence__init(arlo_interfaces__msg__MatesOdom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__msg__MatesOdom * data = NULL;

  if (size) {
    data = (arlo_interfaces__msg__MatesOdom *)allocator.zero_allocate(size, sizeof(arlo_interfaces__msg__MatesOdom), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arlo_interfaces__msg__MatesOdom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arlo_interfaces__msg__MatesOdom__fini(&data[i - 1]);
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
arlo_interfaces__msg__MatesOdom__Sequence__fini(arlo_interfaces__msg__MatesOdom__Sequence * array)
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
      arlo_interfaces__msg__MatesOdom__fini(&array->data[i]);
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

arlo_interfaces__msg__MatesOdom__Sequence *
arlo_interfaces__msg__MatesOdom__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__msg__MatesOdom__Sequence * array = (arlo_interfaces__msg__MatesOdom__Sequence *)allocator.allocate(sizeof(arlo_interfaces__msg__MatesOdom__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arlo_interfaces__msg__MatesOdom__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arlo_interfaces__msg__MatesOdom__Sequence__destroy(arlo_interfaces__msg__MatesOdom__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arlo_interfaces__msg__MatesOdom__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arlo_interfaces__msg__MatesOdom__Sequence__are_equal(const arlo_interfaces__msg__MatesOdom__Sequence * lhs, const arlo_interfaces__msg__MatesOdom__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arlo_interfaces__msg__MatesOdom__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arlo_interfaces__msg__MatesOdom__Sequence__copy(
  const arlo_interfaces__msg__MatesOdom__Sequence * input,
  arlo_interfaces__msg__MatesOdom__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arlo_interfaces__msg__MatesOdom);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arlo_interfaces__msg__MatesOdom * data =
      (arlo_interfaces__msg__MatesOdom *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arlo_interfaces__msg__MatesOdom__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arlo_interfaces__msg__MatesOdom__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arlo_interfaces__msg__MatesOdom__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
