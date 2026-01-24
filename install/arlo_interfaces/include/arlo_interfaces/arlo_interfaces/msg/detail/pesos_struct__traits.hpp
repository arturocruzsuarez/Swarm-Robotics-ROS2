// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arlo_interfaces:msg/PesosStruct.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__TRAITS_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arlo_interfaces/msg/detail/pesos_struct__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace arlo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PesosStruct & msg,
  std::ostream & out)
{
  out << "{";
  // member: pesos
  {
    if (msg.pesos.size() == 0) {
      out << "pesos: []";
    } else {
      out << "pesos: [";
      size_t pending_items = msg.pesos.size();
      for (auto item : msg.pesos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PesosStruct & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pesos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pesos.size() == 0) {
      out << "pesos: []\n";
    } else {
      out << "pesos:\n";
      for (auto item : msg.pesos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PesosStruct & msg, bool use_flow_style = false)
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
  const arlo_interfaces::msg::PesosStruct & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::msg::PesosStruct & msg)
{
  return arlo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::msg::PesosStruct>()
{
  return "arlo_interfaces::msg::PesosStruct";
}

template<>
inline const char * name<arlo_interfaces::msg::PesosStruct>()
{
  return "arlo_interfaces/msg/PesosStruct";
}

template<>
struct has_fixed_size<arlo_interfaces::msg::PesosStruct>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<arlo_interfaces::msg::PesosStruct>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<arlo_interfaces::msg::PesosStruct>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__TRAITS_HPP_
