// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice
#include "arlo_interfaces/msg/detail/estado_arlo__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sensor1`
// Member `sensor2`
// Member `sensor3`
// Member `sensor4`
#include "sensor_msgs/msg/detail/laser_scan__functions.h"
// Member `odom`
#include "nav_msgs/msg/detail/odometry__functions.h"

bool
arlo_interfaces__msg__EstadoArlo__init(arlo_interfaces__msg__EstadoArlo * msg)
{
  if (!msg) {
    return false;
  }
  // sensor1
  if (!sensor_msgs__msg__LaserScan__init(&msg->sensor1)) {
    arlo_interfaces__msg__EstadoArlo__fini(msg);
    return false;
  }
  // sensor2
  if (!sensor_msgs__msg__LaserScan__init(&msg->sensor2)) {
    arlo_interfaces__msg__EstadoArlo__fini(msg);
    return false;
  }
  // sensor3
  if (!sensor_msgs__msg__LaserScan__init(&msg->sensor3)) {
    arlo_interfaces__msg__EstadoArlo__fini(msg);
    return false;
  }
  // sensor4
  if (!sensor_msgs__msg__LaserScan__init(&msg->sensor4)) {
    arlo_interfaces__msg__EstadoArlo__fini(msg);
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__init(&msg->odom)) {
    arlo_interfaces__msg__EstadoArlo__fini(msg);
    return false;
  }
  // dist_to_mates
  return true;
}

void
arlo_interfaces__msg__EstadoArlo__fini(arlo_interfaces__msg__EstadoArlo * msg)
{
  if (!msg) {
    return;
  }
  // sensor1
  sensor_msgs__msg__LaserScan__fini(&msg->sensor1);
  // sensor2
  sensor_msgs__msg__LaserScan__fini(&msg->sensor2);
  // sensor3
  sensor_msgs__msg__LaserScan__fini(&msg->sensor3);
  // sensor4
  sensor_msgs__msg__LaserScan__fini(&msg->sensor4);
  // odom
  nav_msgs__msg__Odometry__fini(&msg->odom);
  // dist_to_mates
}

bool
arlo_interfaces__msg__EstadoArlo__are_equal(const arlo_interfaces__msg__EstadoArlo * lhs, const arlo_interfaces__msg__EstadoArlo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sensor1
  if (!sensor_msgs__msg__LaserScan__are_equal(
      &(lhs->sensor1), &(rhs->sensor1)))
  {
    return false;
  }
  // sensor2
  if (!sensor_msgs__msg__LaserScan__are_equal(
      &(lhs->sensor2), &(rhs->sensor2)))
  {
    return false;
  }
  // sensor3
  if (!sensor_msgs__msg__LaserScan__are_equal(
      &(lhs->sensor3), &(rhs->sensor3)))
  {
    return false;
  }
  // sensor4
  if (!sensor_msgs__msg__LaserScan__are_equal(
      &(lhs->sensor4), &(rhs->sensor4)))
  {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__are_equal(
      &(lhs->odom), &(rhs->odom)))
  {
    return false;
  }
  // dist_to_mates
  if (lhs->dist_to_mates != rhs->dist_to_mates) {
    return false;
  }
  return true;
}

bool
arlo_interfaces__msg__EstadoArlo__copy(
  const arlo_interfaces__msg__EstadoArlo * input,
  arlo_interfaces__msg__EstadoArlo * output)
{
  if (!input || !output) {
    return false;
  }
  // sensor1
  if (!sensor_msgs__msg__LaserScan__copy(
      &(input->sensor1), &(output->sensor1)))
  {
    return false;
  }
  // sensor2
  if (!sensor_msgs__msg__LaserScan__copy(
      &(input->sensor2), &(output->sensor2)))
  {
    return false;
  }
  // sensor3
  if (!sensor_msgs__msg__LaserScan__copy(
      &(input->sensor3), &(output->sensor3)))
  {
    return false;
  }
  // sensor4
  if (!sensor_msgs__msg__LaserScan__copy(
      &(input->sensor4), &(output->sensor4)))
  {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__copy(
      &(input->odom), &(output->odom)))
  {
    return false;
  }
  // dist_to_mates
  output->dist_to_mates = input->dist_to_mates;
  return true;
}

arlo_interfaces__msg__EstadoArlo *
arlo_interfaces__msg__EstadoArlo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__msg__EstadoArlo * msg = (arlo_interfaces__msg__EstadoArlo *)allocator.allocate(sizeof(arlo_interfaces__msg__EstadoArlo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arlo_interfaces__msg__EstadoArlo));
  bool success = arlo_interfaces__msg__EstadoArlo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arlo_interfaces__msg__EstadoArlo__destroy(arlo_interfaces__msg__EstadoArlo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arlo_interfaces__msg__EstadoArlo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arlo_interfaces__msg__EstadoArlo__Sequence__init(arlo_interfaces__msg__EstadoArlo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__msg__EstadoArlo * data = NULL;

  if (size) {
    data = (arlo_interfaces__msg__EstadoArlo *)allocator.zero_allocate(size, sizeof(arlo_interfaces__msg__EstadoArlo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arlo_interfaces__msg__EstadoArlo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arlo_interfaces__msg__EstadoArlo__fini(&data[i - 1]);
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
arlo_interfaces__msg__EstadoArlo__Sequence__fini(arlo_interfaces__msg__EstadoArlo__Sequence * array)
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
      arlo_interfaces__msg__EstadoArlo__fini(&array->data[i]);
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

arlo_interfaces__msg__EstadoArlo__Sequence *
arlo_interfaces__msg__EstadoArlo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__msg__EstadoArlo__Sequence * array = (arlo_interfaces__msg__EstadoArlo__Sequence *)allocator.allocate(sizeof(arlo_interfaces__msg__EstadoArlo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arlo_interfaces__msg__EstadoArlo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arlo_interfaces__msg__EstadoArlo__Sequence__destroy(arlo_interfaces__msg__EstadoArlo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arlo_interfaces__msg__EstadoArlo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arlo_interfaces__msg__EstadoArlo__Sequence__are_equal(const arlo_interfaces__msg__EstadoArlo__Sequence * lhs, const arlo_interfaces__msg__EstadoArlo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arlo_interfaces__msg__EstadoArlo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arlo_interfaces__msg__EstadoArlo__Sequence__copy(
  const arlo_interfaces__msg__EstadoArlo__Sequence * input,
  arlo_interfaces__msg__EstadoArlo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arlo_interfaces__msg__EstadoArlo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arlo_interfaces__msg__EstadoArlo * data =
      (arlo_interfaces__msg__EstadoArlo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arlo_interfaces__msg__EstadoArlo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arlo_interfaces__msg__EstadoArlo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arlo_interfaces__msg__EstadoArlo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
