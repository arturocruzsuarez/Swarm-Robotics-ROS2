// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arlo_interfaces:srv/GetMatesFitness.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__STRUCT_H_
#define ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetMatesFitness in the package arlo_interfaces.
typedef struct arlo_interfaces__srv__GetMatesFitness_Request
{
  uint8_t structure_needs_at_least_one_member;
} arlo_interfaces__srv__GetMatesFitness_Request;

// Struct for a sequence of arlo_interfaces__srv__GetMatesFitness_Request.
typedef struct arlo_interfaces__srv__GetMatesFitness_Request__Sequence
{
  arlo_interfaces__srv__GetMatesFitness_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__srv__GetMatesFitness_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GetMatesFitness in the package arlo_interfaces.
typedef struct arlo_interfaces__srv__GetMatesFitness_Response
{
  double fitness;
  int64_t id;
} arlo_interfaces__srv__GetMatesFitness_Response;

// Struct for a sequence of arlo_interfaces__srv__GetMatesFitness_Response.
typedef struct arlo_interfaces__srv__GetMatesFitness_Response__Sequence
{
  arlo_interfaces__srv__GetMatesFitness_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__srv__GetMatesFitness_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__STRUCT_H_
