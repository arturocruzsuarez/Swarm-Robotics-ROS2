// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:srv/GetImportantWeights.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__BUILDER_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/srv/detail/get_important_weights__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arlo_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::srv::GetImportantWeights_Request>()
{
  return ::arlo_interfaces::srv::GetImportantWeights_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace arlo_interfaces


namespace arlo_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetImportantWeights_Response_weightsfile
{
public:
  Init_GetImportantWeights_Response_weightsfile()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::arlo_interfaces::srv::GetImportantWeights_Response weightsfile(::arlo_interfaces::srv::GetImportantWeights_Response::_weightsfile_type arg)
  {
    msg_.weightsfile = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::srv::GetImportantWeights_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::srv::GetImportantWeights_Response>()
{
  return arlo_interfaces::srv::builder::Init_GetImportantWeights_Response_weightsfile();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__BUILDER_HPP_
