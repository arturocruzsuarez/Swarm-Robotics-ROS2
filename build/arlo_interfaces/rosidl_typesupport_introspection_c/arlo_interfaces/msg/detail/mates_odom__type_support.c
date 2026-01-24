// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arlo_interfaces/msg/detail/mates_odom__rosidl_typesupport_introspection_c.h"
#include "arlo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arlo_interfaces/msg/detail/mates_odom__functions.h"
#include "arlo_interfaces/msg/detail/mates_odom__struct.h"


// Include directives for member types
// Member `odom`
#include "nav_msgs/msg/odometry.h"
// Member `odom`
#include "nav_msgs/msg/detail/odometry__rosidl_typesupport_introspection_c.h"
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arlo_interfaces__msg__MatesOdom__init(message_memory);
}

void arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_fini_function(void * message_memory)
{
  arlo_interfaces__msg__MatesOdom__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_member_array[2] = {
  {
    "odom",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__MatesOdom, odom),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__MatesOdom, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_members = {
  "arlo_interfaces__msg",  // message namespace
  "MatesOdom",  // message name
  2,  // number of fields
  sizeof(arlo_interfaces__msg__MatesOdom),
  arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_member_array,  // message members
  arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_init_function,  // function to initialize message memory (memory has to be allocated)
  arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_type_support_handle = {
  0,
  &arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arlo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arlo_interfaces, msg, MatesOdom)() {
  arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Odometry)();
  if (!arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_type_support_handle.typesupport_identifier) {
    arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arlo_interfaces__msg__MatesOdom__rosidl_typesupport_introspection_c__MatesOdom_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
