// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "arlo_interfaces/msg/detail/mates_odom__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace arlo_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MatesOdom_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) arlo_interfaces::msg::MatesOdom(_init);
}

void MatesOdom_fini_function(void * message_memory)
{
  auto typed_message = static_cast<arlo_interfaces::msg::MatesOdom *>(message_memory);
  typed_message->~MatesOdom();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MatesOdom_message_member_array[2] = {
  {
    "odom",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_msgs::msg::Odometry>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces::msg::MatesOdom, odom),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arlo_interfaces::msg::MatesOdom, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MatesOdom_message_members = {
  "arlo_interfaces::msg",  // message namespace
  "MatesOdom",  // message name
  2,  // number of fields
  sizeof(arlo_interfaces::msg::MatesOdom),
  MatesOdom_message_member_array,  // message members
  MatesOdom_init_function,  // function to initialize message memory (memory has to be allocated)
  MatesOdom_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MatesOdom_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MatesOdom_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace arlo_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<arlo_interfaces::msg::MatesOdom>()
{
  return &::arlo_interfaces::msg::rosidl_typesupport_introspection_cpp::MatesOdom_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, arlo_interfaces, msg, MatesOdom)() {
  return &::arlo_interfaces::msg::rosidl_typesupport_introspection_cpp::MatesOdom_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
