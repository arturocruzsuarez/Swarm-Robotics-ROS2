// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from arlo_interfaces:msg/PesosStruct.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__FUNCTIONS_H_
#define ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "arlo_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "arlo_interfaces/msg/detail/pesos_struct__struct.h"

/// Initialize msg/PesosStruct message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * arlo_interfaces__msg__PesosStruct
 * )) before or use
 * arlo_interfaces__msg__PesosStruct__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__PesosStruct__init(arlo_interfaces__msg__PesosStruct * msg);

/// Finalize msg/PesosStruct message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__PesosStruct__fini(arlo_interfaces__msg__PesosStruct * msg);

/// Create msg/PesosStruct message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * arlo_interfaces__msg__PesosStruct__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
arlo_interfaces__msg__PesosStruct *
arlo_interfaces__msg__PesosStruct__create();

/// Destroy msg/PesosStruct message.
/**
 * It calls
 * arlo_interfaces__msg__PesosStruct__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__PesosStruct__destroy(arlo_interfaces__msg__PesosStruct * msg);

/// Check for msg/PesosStruct message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__PesosStruct__are_equal(const arlo_interfaces__msg__PesosStruct * lhs, const arlo_interfaces__msg__PesosStruct * rhs);

/// Copy a msg/PesosStruct message.
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
arlo_interfaces__msg__PesosStruct__copy(
  const arlo_interfaces__msg__PesosStruct * input,
  arlo_interfaces__msg__PesosStruct * output);

/// Initialize array of msg/PesosStruct messages.
/**
 * It allocates the memory for the number of elements and calls
 * arlo_interfaces__msg__PesosStruct__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__PesosStruct__Sequence__init(arlo_interfaces__msg__PesosStruct__Sequence * array, size_t size);

/// Finalize array of msg/PesosStruct messages.
/**
 * It calls
 * arlo_interfaces__msg__PesosStruct__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__PesosStruct__Sequence__fini(arlo_interfaces__msg__PesosStruct__Sequence * array);

/// Create array of msg/PesosStruct messages.
/**
 * It allocates the memory for the array and calls
 * arlo_interfaces__msg__PesosStruct__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
arlo_interfaces__msg__PesosStruct__Sequence *
arlo_interfaces__msg__PesosStruct__Sequence__create(size_t size);

/// Destroy array of msg/PesosStruct messages.
/**
 * It calls
 * arlo_interfaces__msg__PesosStruct__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
void
arlo_interfaces__msg__PesosStruct__Sequence__destroy(arlo_interfaces__msg__PesosStruct__Sequence * array);

/// Check for msg/PesosStruct message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_arlo_interfaces
bool
arlo_interfaces__msg__PesosStruct__Sequence__are_equal(const arlo_interfaces__msg__PesosStruct__Sequence * lhs, const arlo_interfaces__msg__PesosStruct__Sequence * rhs);

/// Copy an array of msg/PesosStruct messages.
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
arlo_interfaces__msg__PesosStruct__Sequence__copy(
  const arlo_interfaces__msg__PesosStruct__Sequence * input,
  arlo_interfaces__msg__PesosStruct__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__FUNCTIONS_H_
