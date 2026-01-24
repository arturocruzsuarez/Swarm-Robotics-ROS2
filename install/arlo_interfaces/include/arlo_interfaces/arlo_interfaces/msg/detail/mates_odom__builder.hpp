// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:msg/MatesOdom.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__BUILDER_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/msg/detail/mates_odom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arlo_interfaces
{

namespace msg
{

namespace builder
{

class Init_MatesOdom_name
{
public:
  explicit Init_MatesOdom_name(::arlo_interfaces::msg::MatesOdom & msg)
  : msg_(msg)
  {}
  ::arlo_interfaces::msg::MatesOdom name(::arlo_interfaces::msg::MatesOdom::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::msg::MatesOdom msg_;
};

class Init_MatesOdom_odom
{
public:
  Init_MatesOdom_odom()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MatesOdom_name odom(::arlo_interfaces::msg::MatesOdom::_odom_type arg)
  {
    msg_.odom = std::move(arg);
    return Init_MatesOdom_name(msg_);
  }

private:
  ::arlo_interfaces::msg::MatesOdom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::msg::MatesOdom>()
{
  return arlo_interfaces::msg::builder::Init_MatesOdom_odom();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__MSG__DETAIL__MATES_ODOM__BUILDER_HPP_
