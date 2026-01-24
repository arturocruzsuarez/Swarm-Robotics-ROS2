// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "arlo_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "arlo_interfaces/msg/detail/mates_odom__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace arlo_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arlo_interfaces
cdr_serialize(
  const arlo_interfaces::msg::MatesOdom & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arlo_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  arlo_interfaces::msg::MatesOdom & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arlo_interfaces
get_serialized_size(
  const arlo_interfaces::msg::MatesOdom & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arlo_interfaces
max_serialized_size_MatesOdom(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace arlo_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arlo_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, arlo_interfaces, msg, MatesOdom)();

#ifdef __cplusplus
}
#endif

#endif  // ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
