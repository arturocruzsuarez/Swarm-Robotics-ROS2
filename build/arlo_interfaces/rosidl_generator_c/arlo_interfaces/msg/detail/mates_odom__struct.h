// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__STRUCT_H_
#define ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__struct.h"
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MatesOdom in the package arlo_interfaces.
typedef struct arlo_interfaces__msg__MatesOdom
{
  nav_msgs__msg__Odometry odom;
  rosidl_runtime_c__String name;
} arlo_interfaces__msg__MatesOdom;

// Struct for a sequence of arlo_interfaces__msg__MatesOdom.
typedef struct arlo_interfaces__msg__MatesOdom__Sequence
{
  arlo_interfaces__msg__MatesOdom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__msg__MatesOdom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__STRUCT_H_
