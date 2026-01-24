// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arlo_interfaces:srv/EvaluateDriver.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__STRUCT_H_
#define ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'weightsfile'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/EvaluateDriver in the package arlo_interfaces.
typedef struct arlo_interfaces__srv__EvaluateDriver_Request
{
  rosidl_runtime_c__String weightsfile;
  int64_t maxtime;
} arlo_interfaces__srv__EvaluateDriver_Request;

// Struct for a sequence of arlo_interfaces__srv__EvaluateDriver_Request.
typedef struct arlo_interfaces__srv__EvaluateDriver_Request__Sequence
{
  arlo_interfaces__srv__EvaluateDriver_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__srv__EvaluateDriver_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/EvaluateDriver in the package arlo_interfaces.
typedef struct arlo_interfaces__srv__EvaluateDriver_Response
{
  double time;
  double dist2go;
  double damage;
  double energy;
  double dist2mates;
} arlo_interfaces__srv__EvaluateDriver_Response;

// Struct for a sequence of arlo_interfaces__srv__EvaluateDriver_Response.
typedef struct arlo_interfaces__srv__EvaluateDriver_Response__Sequence
{
  arlo_interfaces__srv__EvaluateDriver_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__srv__EvaluateDriver_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__STRUCT_H_
