// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arlo_interfaces/msg/detail/estado_arlo__rosidl_typesupport_introspection_c.h"
#include "arlo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arlo_interfaces/msg/detail/estado_arlo__functions.h"
#include "arlo_interfaces/msg/detail/estado_arlo__struct.h"


// Include directives for member types
// Member `sensor1`
// Member `sensor2`
// Member `sensor3`
// Member `sensor4`
#include "sensor_msgs/msg/laser_scan.h"
// Member `sensor1`
// Member `sensor2`
// Member `sensor3`
// Member `sensor4`
#include "sensor_msgs/msg/detail/laser_scan__rosidl_typesupport_introspection_c.h"
// Member `odom`
#include "nav_msgs/msg/odometry.h"
// Member `odom`
#include "nav_msgs/msg/detail/odometry__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arlo_interfaces__msg__EstadoArlo__init(message_memory);
}

void arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_fini_function(void * message_memory)
{
  arlo_interfaces__msg__EstadoArlo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array[6] = {
  {
    "sensor1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__EstadoArlo, sensor1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sensor2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__EstadoArlo, sensor2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sensor3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__EstadoArlo, sensor3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sensor4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__EstadoArlo, sensor4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "odom",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__EstadoArlo, odom),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dist_to_mates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces__msg__EstadoArlo, dist_to_mates),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_members = {
  "arlo_interfaces__msg",  // message namespace
  "EstadoArlo",  // message name
  6,  // number of fields
  sizeof(arlo_interfaces__msg__EstadoArlo),
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array,  // message members
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_init_function,  // function to initialize message memory (memory has to be allocated)
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_type_support_handle = {
  0,
  &arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arlo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arlo_interfaces, msg, EstadoArlo)() {
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, LaserScan)();
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, LaserScan)();
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, LaserScan)();
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, LaserScan)();
  arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Odometry)();
  if (!arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_type_support_handle.typesupport_identifier) {
    arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &arlo_interfaces__msg__EstadoArlo__rosidl_typesupport_introspection_c__EstadoArlo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
