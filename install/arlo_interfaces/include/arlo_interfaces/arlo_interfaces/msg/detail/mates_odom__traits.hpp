// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__TRAITS_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arlo_interfaces/msg/detail/mates_odom__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__traits.hpp"

namespace arlo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MatesOdom & msg,
  std::ostream & out)
{
  out << "{";
  // member: odom
  {
    out << "odom: ";
    to_flow_style_yaml(msg.odom, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MatesOdom & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: odom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "odom:\n";
    to_block_style_yaml(msg.odom, out, indentation + 2);
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MatesOdom & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace arlo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arlo_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arlo_interfaces::msg::MatesOdom & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::msg::MatesOdom & msg)
{
  return arlo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::msg::MatesOdom>()
{
  return "arlo_interfaces::msg::MatesOdom";
}

template<>
inline const char * name<arlo_interfaces::msg::MatesOdom>()
{
  return "arlo_interfaces/msg/MatesOdom";
}

template<>
struct has_fixed_size<arlo_interfaces::msg::MatesOdom>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<arlo_interfaces::msg::MatesOdom>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<arlo_interfaces::msg::MatesOdom>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__TRAITS_HPP_
