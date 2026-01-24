// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arlo_interfaces:srv/EvaluateDriver.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__TRAITS_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arlo_interfaces/srv/detail/evaluate_driver__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace arlo_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const EvaluateDriver_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: weightsfile
  {
    out << "weightsfile: ";
    rosidl_generator_traits::value_to_yaml(msg.weightsfile, out);
    out << ", ";
  }

  // member: maxtime
  {
    out << "maxtime: ";
    rosidl_generator_traits::value_to_yaml(msg.maxtime, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EvaluateDriver_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: weightsfile
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "weightsfile: ";
    rosidl_generator_traits::value_to_yaml(msg.weightsfile, out);
    out << "\n";
  }

  // member: maxtime
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "maxtime: ";
    rosidl_generator_traits::value_to_yaml(msg.maxtime, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EvaluateDriver_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace arlo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arlo_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arlo_interfaces::srv::EvaluateDriver_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::srv::EvaluateDriver_Request & msg)
{
  return arlo_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::srv::EvaluateDriver_Request>()
{
  return "arlo_interfaces::srv::EvaluateDriver_Request";
}

template<>
inline const char * name<arlo_interfaces::srv::EvaluateDriver_Request>()
{
  return "arlo_interfaces/srv/EvaluateDriver_Request";
}

template<>
struct has_fixed_size<arlo_interfaces::srv::EvaluateDriver_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<arlo_interfaces::srv::EvaluateDriver_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<arlo_interfaces::srv::EvaluateDriver_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace arlo_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const EvaluateDriver_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: dist2go
  {
    out << "dist2go: ";
    rosidl_generator_traits::value_to_yaml(msg.dist2go, out);
    out << ", ";
  }

  // member: damage
  {
    out << "damage: ";
    rosidl_generator_traits::value_to_yaml(msg.damage, out);
    out << ", ";
  }

  // member: energy
  {
    out << "energy: ";
    rosidl_generator_traits::value_to_yaml(msg.energy, out);
    out << ", ";
  }

  // member: dist2mates
  {
    out << "dist2mates: ";
    rosidl_generator_traits::value_to_yaml(msg.dist2mates, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EvaluateDriver_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: dist2go
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist2go: ";
    rosidl_generator_traits::value_to_yaml(msg.dist2go, out);
    out << "\n";
  }

  // member: damage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "damage: ";
    rosidl_generator_traits::value_to_yaml(msg.damage, out);
    out << "\n";
  }

  // member: energy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "energy: ";
    rosidl_generator_traits::value_to_yaml(msg.energy, out);
    out << "\n";
  }

  // member: dist2mates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist2mates: ";
    rosidl_generator_traits::value_to_yaml(msg.dist2mates, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EvaluateDriver_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace arlo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arlo_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arlo_interfaces::srv::EvaluateDriver_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::srv::EvaluateDriver_Response & msg)
{
  return arlo_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::srv::EvaluateDriver_Response>()
{
  return "arlo_interfaces::srv::EvaluateDriver_Response";
}

template<>
inline const char * name<arlo_interfaces::srv::EvaluateDriver_Response>()
{
  return "arlo_interfaces/srv/EvaluateDriver_Response";
}

template<>
struct has_fixed_size<arlo_interfaces::srv::EvaluateDriver_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<arlo_interfaces::srv::EvaluateDriver_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<arlo_interfaces::srv::EvaluateDriver_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<arlo_interfaces::srv::EvaluateDriver>()
{
  return "arlo_interfaces::srv::EvaluateDriver";
}

template<>
inline const char * name<arlo_interfaces::srv::EvaluateDriver>()
{
  return "arlo_interfaces/srv/EvaluateDriver";
}

template<>
struct has_fixed_size<arlo_interfaces::srv::EvaluateDriver>
  : std::integral_constant<
    bool,
    has_fixed_size<arlo_interfaces::srv::EvaluateDriver_Request>::value &&
    has_fixed_size<arlo_interfaces::srv::EvaluateDriver_Response>::value
  >
{
};

template<>
struct has_bounded_size<arlo_interfaces::srv::EvaluateDriver>
  : std::integral_constant<
    bool,
    has_bounded_size<arlo_interfaces::srv::EvaluateDriver_Request>::value &&
    has_bounded_size<arlo_interfaces::srv::EvaluateDriver_Response>::value
  >
{
};

template<>
struct is_service<arlo_interfaces::srv::EvaluateDriver>
  : std::true_type
{
};

template<>
struct is_service_request<arlo_interfaces::srv::EvaluateDriver_Request>
  : std::true_type
{
};

template<>
struct is_service_response<arlo_interfaces::srv::EvaluateDriver_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__TRAITS_HPP_
