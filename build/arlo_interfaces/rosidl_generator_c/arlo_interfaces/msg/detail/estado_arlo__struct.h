// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__STRUCT_H_
#define ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sensor1'
// Member 'sensor2'
// Member 'sensor3'
// Member 'sensor4'
#include "sensor_msgs/msg/detail/laser_scan__struct.h"
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__struct.h"

/// Struct defined in msg/EstadoArlo in the package arlo_interfaces.
typedef struct arlo_interfaces__msg__EstadoArlo
{
  sensor_msgs__msg__LaserScan sensor1;
  sensor_msgs__msg__LaserScan sensor2;
  sensor_msgs__msg__LaserScan sensor3;
  sensor_msgs__msg__LaserScan sensor4;
  nav_msgs__msg__Odometry odom;
  double dist_to_mates;
} arlo_interfaces__msg__EstadoArlo;

// Struct for a sequence of arlo_interfaces__msg__EstadoArlo.
typedef struct arlo_interfaces__msg__EstadoArlo__Sequence
{
  arlo_interfaces__msg__EstadoArlo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__msg__EstadoArlo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__STRUCT_H_
