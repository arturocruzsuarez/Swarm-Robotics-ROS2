// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arlo_interfaces:msg/PesosStruct.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arlo_interfaces/msg/detail/pesos_struct__rosidl_typesupport_introspection_c.h"
#include "arlo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arlo_interfaces/msg/detail/pesos_struct__functions.h"
#include "arlo_interfaces/msg/detail/pesos_struct__struct.h"


// Include directives for member types
// Member `pesos`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arlo_interfaces__msg__PesosStruct__init(message_memory);
}

void arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_fini_function(void * message_memory)
{
  arlo_interfaces__msg__PesosStruct__fini(message_memory);
}

size_t arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__size_function__PesosStruct__pesos(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__get_const_function__PesosStruct__pesos(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__get_function__PesosStruct__pesos(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__fetch_function__PesosStruct__pesos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__get_const_function__PesosStruct__pesos(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__assign_function__PesosStruct__pesos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__get_function__PesosStruct__pesos(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__resize_function__PesosStruct__pesos(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_member_array[1] = {
  {
    "pesos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__PesosStruct, pesos),  // bytes offset in struct
    NULL,  // default value
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__size_function__PesosStruct__pesos,  // size() function pointer
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__get_const_function__PesosStruct__pesos,  // get_const(index) function pointer
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__get_function__PesosStruct__pesos,  // get(index) function pointer
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__fetch_function__PesosStruct__pesos,  // fetch(index, &value) function pointer
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__assign_function__PesosStruct__pesos,  // assign(index, value) function pointer
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__resize_function__PesosStruct__pesos  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_members = {
  "arlo_interfaces__msg",  // message namespace
  "PesosStruct",  // message name
  1,  // number of fields
  sizeof(arlo_interfaces__msg__PesosStruct),
  arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_member_array,  // message members
  arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_init_function,  // function to initialize message memory (memory has to be allocated)
  arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_type_support_handle = {
  0,
  &arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arlo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arlo_interfaces, msg, PesosStruct)() {
  if (!arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_type_support_handle.typesupport_identifier) {
    arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arlo_interfaces__msg__PesosStruct__rosidl_typesupport_introspection_c__PesosStruct_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
