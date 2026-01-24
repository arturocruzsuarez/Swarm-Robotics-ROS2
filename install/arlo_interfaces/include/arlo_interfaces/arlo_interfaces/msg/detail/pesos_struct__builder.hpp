// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:msg/PesosStruct.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__BUILDER_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/msg/detail/pesos_struct__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arlo_interfaces
{

namespace msg
{

namespace builder
{

class Init_PesosStruct_pesos
{
public:
  Init_PesosStruct_pesos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::arlo_interfaces::msg::PesosStruct pesos(::arlo_interfaces::msg::PesosStruct::_pesos_type arg)
  {
    msg_.pesos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::msg::PesosStruct msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::msg::PesosStruct>()
{
  return arlo_interfaces::msg::builder::Init_PesosStruct_pesos();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__BUILDER_HPP_
