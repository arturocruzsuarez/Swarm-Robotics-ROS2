// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__BUILDER_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/msg/detail/estado_arlo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arlo_interfaces
{

namespace msg
{

namespace builder
{

class Init_EstadoArlo_dist_to_mates
{
public:
  explicit Init_EstadoArlo_dist_to_mates(::arlo_interfaces::msg::EstadoArlo & msg)
  : msg_(msg)
  {}
  ::arlo_interfaces::msg::EstadoArlo dist_to_mates(::arlo_interfaces::msg::EstadoArlo::_dist_to_mates_type arg)
  {
    msg_.dist_to_mates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::msg::EstadoArlo msg_;
};

class Init_EstadoArlo_odom
{
public:
  explicit Init_EstadoArlo_odom(::arlo_interfaces::msg::EstadoArlo & msg)
  : msg_(msg)
  {}
  Init_EstadoArlo_dist_to_mates odom(::arlo_interfaces::msg::EstadoArlo::_odom_type arg)
  {
    msg_.odom = std::move(arg);
    return Init_EstadoArlo_dist_to_mates(msg_);
  }

private:
  ::arlo_interfaces::msg::EstadoArlo msg_;
};

class Init_EstadoArlo_sensor4
{
public:
  explicit Init_EstadoArlo_sensor4(::arlo_interfaces::msg::EstadoArlo & msg)
  : msg_(msg)
  {}
  Init_EstadoArlo_odom sensor4(::arlo_interfaces::msg::EstadoArlo::_sensor4_type arg)
  {
    msg_.sensor4 = std::move(arg);
    return Init_EstadoArlo_odom(msg_);
  }

private:
  ::arlo_interfaces::msg::EstadoArlo msg_;
};

class Init_EstadoArlo_sensor3
{
public:
  explicit Init_EstadoArlo_sensor3(::arlo_interfaces::msg::EstadoArlo & msg)
  : msg_(msg)
  {}
  Init_EstadoArlo_sensor4 sensor3(::arlo_interfaces::msg::EstadoArlo::_sensor3_type arg)
  {
    msg_.sensor3 = std::move(arg);
    return Init_EstadoArlo_sensor4(msg_);
  }

private:
  ::arlo_interfaces::msg::EstadoArlo msg_;
};

class Init_EstadoArlo_sensor2
{
public:
  explicit Init_EstadoArlo_sensor2(::arlo_interfaces::msg::EstadoArlo & msg)
  : msg_(msg)
  {}
  Init_EstadoArlo_sensor3 sensor2(::arlo_interfaces::msg::EstadoArlo::_sensor2_type arg)
  {
    msg_.sensor2 = std::move(arg);
    return Init_EstadoArlo_sensor3(msg_);
  }

private:
  ::arlo_interfaces::msg::EstadoArlo msg_;
};

class Init_EstadoArlo_sensor1
{
public:
  Init_EstadoArlo_sensor1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EstadoArlo_sensor2 sensor1(::arlo_interfaces::msg::EstadoArlo::_sensor1_type arg)
  {
    msg_.sensor1 = std::move(arg);
    return Init_EstadoArlo_sensor2(msg_);
  }

private:
  ::arlo_interfaces::msg::EstadoArlo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::msg::EstadoArlo>()
{
  return arlo_interfaces::msg::builder::Init_EstadoArlo_sensor1();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__BUILDER_HPP_
