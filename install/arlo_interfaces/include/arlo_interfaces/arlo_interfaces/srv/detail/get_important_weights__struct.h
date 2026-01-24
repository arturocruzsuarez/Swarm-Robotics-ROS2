// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arlo_interfaces:srv/GetImportantWeights.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__STRUCT_H_
#define ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetImportantWeights in the package arlo_interfaces.
typedef struct arlo_interfaces__srv__GetImportantWeights_Request
{
  uint8_t structure_needs_at_least_one_member;
} arlo_interfaces__srv__GetImportantWeights_Request;

// Struct for a sequence of arlo_interfaces__srv__GetImportantWeights_Request.
typedef struct arlo_interfaces__srv__GetImportantWeights_Request__Sequence
{
  arlo_interfaces__srv__GetImportantWeights_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__srv__GetImportantWeights_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'weightsfile'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetImportantWeights in the package arlo_interfaces.
typedef struct arlo_interfaces__srv__GetImportantWeights_Response
{
  rosidl_runtime_c__String weightsfile;
} arlo_interfaces__srv__GetImportantWeights_Response;

// Struct for a sequence of arlo_interfaces__srv__GetImportantWeights_Response.
typedef struct arlo_interfaces__srv__GetImportantWeights_Response__Sequence
{
  arlo_interfaces__srv__GetImportantWeights_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arlo_interfaces__srv__GetImportantWeights_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__STRUCT_H_
