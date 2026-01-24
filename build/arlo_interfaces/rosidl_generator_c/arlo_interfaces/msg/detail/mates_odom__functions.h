// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__FUNCTIONS_H_
#define ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "arlo_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "arlo_interfaces/msg/detail/mates_odom__struct.h"

/// Initialize msg/MatesOdom message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * arlo_interfaces__msg__MatesOdom
 * )) before or use
 * arlo_interfaces__msg__MatesOdom__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__MatesOdom__init(arlo_interfaces__msg__MatesOdom * msg);

/// Finalize msg/MatesOdom message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__MatesOdom__fini(arlo_interfaces__msg__MatesOdom * msg);

/// Create msg/MatesOdom message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * arlo_interfaces__msg__MatesOdom__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
arlo_interfaces__msg__MatesOdom *
arlo_interfaces__msg__MatesOdom__create();

/// Destroy msg/MatesOdom message.
/**
 * It calls
 * arlo_interfaces__msg__MatesOdom__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__MatesOdom__destroy(arlo_interfaces__msg__MatesOdom * msg);

/// Check for msg/MatesOdom message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__MatesOdom__are_equal(const arlo_interfaces__msg__MatesOdom * lhs, const arlo_interfaces__msg__MatesOdom * rhs);

/// Copy a msg/MatesOdom message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__MatesOdom__copy(
  const arlo_interfaces__msg__MatesOdom * input,
  arlo_interfaces__msg__MatesOdom * output);

/// Initialize array of msg/MatesOdom messages.
/**
 * It allocates the memory for the number of elements and calls
 * arlo_interfaces__msg__MatesOdom__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__MatesOdom__Sequence__init(arlo_interfaces__msg__MatesOdom__Sequence * array, size_t size);

/// Finalize array of msg/MatesOdom messages.
/**
 * It calls
 * arlo_interfaces__msg__MatesOdom__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__MatesOdom__Sequence__fini(arlo_interfaces__msg__MatesOdom__Sequence * array);

/// Create array of msg/MatesOdom messages.
/**
 * It allocates the memory for the array and calls
 * arlo_interfaces__msg__MatesOdom__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
arlo_interfaces__msg__MatesOdom__Sequence *
arlo_interfaces__msg__MatesOdom__Sequence__create(size_t size);

/// Destroy array of msg/MatesOdom messages.
/**
 * It calls
 * arlo_interfaces__msg__MatesOdom__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__MatesOdom__Sequence__destroy(arlo_interfaces__msg__MatesOdom__Sequence * array);

/// Check for msg/MatesOdom message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__MatesOdom__Sequence__are_equal(const arlo_interfaces__msg__MatesOdom__Sequence * lhs, const arlo_interfaces__msg__MatesOdom__Sequence * rhs);

/// Copy an array of msg/MatesOdom messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__MatesOdom__Sequence__copy(
  const arlo_interfaces__msg__MatesOdom__Sequence * input,
  arlo_interfaces__msg__MatesOdom__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__FUNCTIONS_H_
