// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:srv/EvaluateDriver.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__BUILDER_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/srv/detail/evaluate_driver__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arlo_interfaces
{

namespace srv
{

namespace builder
{

class Init_EvaluateDriver_Request_maxtime
{
public:
  explicit Init_EvaluateDriver_Request_maxtime(::arlo_interfaces::srv::EvaluateDriver_Request & msg)
  : msg_(msg)
  {}
  ::arlo_interfaces::srv::EvaluateDriver_Request maxtime(::arlo_interfaces::srv::EvaluateDriver_Request::_maxtime_type arg)
  {
    msg_.maxtime = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Request msg_;
};

class Init_EvaluateDriver_Request_weightsfile
{
public:
  Init_EvaluateDriver_Request_weightsfile()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EvaluateDriver_Request_maxtime weightsfile(::arlo_interfaces::srv::EvaluateDriver_Request::_weightsfile_type arg)
  {
    msg_.weightsfile = std::move(arg);
    return Init_EvaluateDriver_Request_maxtime(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::srv::EvaluateDriver_Request>()
{
  return arlo_interfaces::srv::builder::Init_EvaluateDriver_Request_weightsfile();
}

}  // namespace arlo_interfaces


namespace arlo_interfaces
{

namespace srv
{

namespace builder
{

class Init_EvaluateDriver_Response_dist2mates
{
public:
  explicit Init_EvaluateDriver_Response_dist2mates(::arlo_interfaces::srv::EvaluateDriver_Response & msg)
  : msg_(msg)
  {}
  ::arlo_interfaces::srv::EvaluateDriver_Response dist2mates(::arlo_interfaces::srv::EvaluateDriver_Response::_dist2mates_type arg)
  {
    msg_.dist2mates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Response msg_;
};

class Init_EvaluateDriver_Response_energy
{
public:
  explicit Init_EvaluateDriver_Response_energy(::arlo_interfaces::srv::EvaluateDriver_Response & msg)
  : msg_(msg)
  {}
  Init_EvaluateDriver_Response_dist2mates energy(::arlo_interfaces::srv::EvaluateDriver_Response::_energy_type arg)
  {
    msg_.energy = std::move(arg);
    return Init_EvaluateDriver_Response_dist2mates(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Response msg_;
};

class Init_EvaluateDriver_Response_damage
{
public:
  explicit Init_EvaluateDriver_Response_damage(::arlo_interfaces::srv::EvaluateDriver_Response & msg)
  : msg_(msg)
  {}
  Init_EvaluateDriver_Response_energy damage(::arlo_interfaces::srv::EvaluateDriver_Response::_damage_type arg)
  {
    msg_.damage = std::move(arg);
    return Init_EvaluateDriver_Response_energy(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Response msg_;
};

class Init_EvaluateDriver_Response_dist2go
{
public:
  explicit Init_EvaluateDriver_Response_dist2go(::arlo_interfaces::srv::EvaluateDriver_Response & msg)
  : msg_(msg)
  {}
  Init_EvaluateDriver_Response_damage dist2go(::arlo_interfaces::srv::EvaluateDriver_Response::_dist2go_type arg)
  {
    msg_.dist2go = std::move(arg);
    return Init_EvaluateDriver_Response_damage(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Response msg_;
};

class Init_EvaluateDriver_Response_time
{
public:
  Init_EvaluateDriver_Response_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EvaluateDriver_Response_dist2go time(::arlo_interfaces::srv::EvaluateDriver_Response::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_EvaluateDriver_Response_dist2go(msg_);
  }

private:
  ::arlo_interfaces::srv::EvaluateDriver_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::srv::EvaluateDriver_Response>()
{
  return arlo_interfaces::srv::builder::Init_EvaluateDriver_Response_time();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__BUILDER_HPP_
