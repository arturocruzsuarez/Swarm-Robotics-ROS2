// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arlo_interfaces:srv/GetImportantWeights.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__TRAITS_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arlo_interfaces/srv/detail/get_important_weights__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace arlo_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetImportantWeights_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetImportantWeights_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetImportantWeights_Request & msg, bool use_flow_style = false)
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
  const arlo_interfaces::srv::GetImportantWeights_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::srv::GetImportantWeights_Request & msg)
{
  return arlo_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::srv::GetImportantWeights_Request>()
{
  return "arlo_interfaces::srv::GetImportantWeights_Request";
}

template<>
inline const char * name<arlo_interfaces::srv::GetImportantWeights_Request>()
{
  return "arlo_interfaces/srv/GetImportantWeights_Request";
}

template<>
struct has_fixed_size<arlo_interfaces::srv::GetImportantWeights_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<arlo_interfaces::srv::GetImportantWeights_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<arlo_interfaces::srv::GetImportantWeights_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace arlo_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetImportantWeights_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: weightsfile
  {
    out << "weightsfile: ";
    rosidl_generator_traits::value_to_yaml(msg.weightsfile, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetImportantWeights_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetImportantWeights_Response & msg, bool use_flow_style = false)
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
  const arlo_interfaces::srv::GetImportantWeights_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  arlo_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arlo_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const arlo_interfaces::srv::GetImportantWeights_Response & msg)
{
  return arlo_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<arlo_interfaces::srv::GetImportantWeights_Response>()
{
  return "arlo_interfaces::srv::GetImportantWeights_Response";
}

template<>
inline const char * name<arlo_interfaces::srv::GetImportantWeights_Response>()
{
  return "arlo_interfaces/srv/GetImportantWeights_Response";
}

template<>
struct has_fixed_size<arlo_interfaces::srv::GetImportantWeights_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<arlo_interfaces::srv::GetImportantWeights_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<arlo_interfaces::srv::GetImportantWeights_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<arlo_interfaces::srv::GetImportantWeights>()
{
  return "arlo_interfaces::srv::GetImportantWeights";
}

template<>
inline const char * name<arlo_interfaces::srv::GetImportantWeights>()
{
  return "arlo_interfaces/srv/GetImportantWeights";
}

template<>
struct has_fixed_size<arlo_interfaces::srv::GetImportantWeights>
  : std::integral_constant<
    bool,
    has_fixed_size<arlo_interfaces::srv::GetImportantWeights_Request>::value &&
    has_fixed_size<arlo_interfaces::srv::GetImportantWeights_Response>::value
  >
{
};

template<>
struct has_bounded_size<arlo_interfaces::srv::GetImportantWeights>
  : std::integral_constant<
    bool,
    has_bounded_size<arlo_interfaces::srv::GetImportantWeights_Request>::value &&
    has_bounded_size<arlo_interfaces::srv::GetImportantWeights_Response>::value
  >
{
};

template<>
struct is_service<arlo_interfaces::srv::GetImportantWeights>
  : std::true_type
{
};

template<>
struct is_service_request<arlo_interfaces::srv::GetImportantWeights_Request>
  : std::true_type
{
};

template<>
struct is_service_response<arlo_interfaces::srv::GetImportantWeights_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__TRAITS_HPP_
