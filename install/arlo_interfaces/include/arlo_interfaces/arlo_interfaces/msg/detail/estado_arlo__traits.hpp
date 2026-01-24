// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__TRAITS_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arlo_interfaces/msg/detail/estado_arlo__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'sensor1'
// Member 'sensor2'
// Member 'sensor3'
// Member 'sensor4'
#include "sensor_msgs/msg/detail/laser_scan__traits.hpp"
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__traits.hpp"

namespace arlo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EstadoArlo & msg,
  std::ostream & out)
{
  out << "{";
  // member: sensor1
  {
    out << "sensor1: ";
    to_flow_style_yaml(msg.sensor1, out);
    out << ", ";
  }

  // member: sensor2
  {
    out << "sensor2: ";
    to_flow_style_yaml(msg.sensor2, out);
    out << ", ";
  }

  // member: sensor3
  {
    out << "sensor3: ";
    to_flow_style_yaml(msg.sensor3, out);
    out << ", ";
  }

  // member: sensor4
  {
    out << "sensor4: ";
    to_flow_style_yaml(msg.sensor4, out);
    out << ", ";
  }

  // member: odom
  {
    out << "odom: ";
    to_flow_style_yaml(msg.odom, out);
    out << ", ";
  }

  // member: dist_to_mates
  {
    out << "dist_to_mates: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_to_mates, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EstadoArlo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sensor1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor1:\n";
    to_block_style_yaml(msg.sensor1, out, indentation + 2);
  }

  // member: sensor2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor2:\n";
    to_block_style_yaml(msg.sensor2, out, indentation + 2);
  }

  // member: sensor3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor3:\n";
    to_block_style_yaml(msg.sensor3, out, indentation + 2);
  }

  // member: sensor4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor4:\n";
    to_block_style_yaml(msg.sensor4, out, indentation + 2);
  }

  // member: odom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "odom:\n";
    to_block_style_yaml(msg.odom, out, indentation + 2);
  }

  // member: dist_to_mates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_to_mates: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_to_mates, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EstadoArlo & msg, bool use_flow_style = false)
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
  const arlo_interfaces::msg::EstadoArlo & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::msg::EstadoArlo & msg)
{
  return arlo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::msg::EstadoArlo>()
{
  return "arlo_interfaces::msg::EstadoArlo";
}

template<>
inline const char * name<arlo_interfaces::msg::EstadoArlo>()
{
  return "arlo_interfaces/msg/EstadoArlo";
}

template<>
struct has_fixed_size<arlo_interfaces::msg::EstadoArlo>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::Odometry>::value && has_fixed_size<sensor_msgs::msg::LaserScan>::value> {};

template<>
struct has_bounded_size<arlo_interfaces::msg::EstadoArlo>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::Odometry>::value && has_bounded_size<sensor_msgs::msg::LaserScan>::value> {};

template<>
struct is_message<arlo_interfaces::msg::EstadoArlo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__TRAITS_HPP_
