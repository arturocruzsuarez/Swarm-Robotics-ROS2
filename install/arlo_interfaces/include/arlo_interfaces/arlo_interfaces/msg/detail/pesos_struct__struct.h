// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arlo_interfaces:msg/PesosStruct.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__STRUCT_H_
#define ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pesos'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PesosStruct in the package arlo_interfaces.
typedef struct arlo_interfaces__msg__PesosStruct
{
  rosidl_runtime_c__double__Sequence pesos;
} arlo_interfaces__msg__PesosStruct;

// Struct for a sequence of arlo_interfaces__msg__PesosStruct.
typedef struct arlo_interfaces__msg__PesosStruct__Sequence
{
  arlo_interfaces__msg__PesosStruct * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__msg__PesosStruct__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__STRUCT_H_
