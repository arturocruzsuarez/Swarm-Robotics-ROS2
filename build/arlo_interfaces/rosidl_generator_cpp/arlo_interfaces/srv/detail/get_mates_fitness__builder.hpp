// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:srv/GetMatesFitness.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__BUILDER_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/srv/detail/get_mates_fitness__struct.hpp"
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
auto build<::arlo_interfaces::srv::GetMatesFitness_Request>()
{
  return ::arlo_interfaces::srv::GetMatesFitness_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace arlo_interfaces


namespace arlo_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetMatesFitness_Response_id
{
public:
  explicit Init_GetMatesFitness_Response_id(::arlo_interfaces::srv::GetMatesFitness_Response & msg)
  : msg_(msg)
  {}
  ::arlo_interfaces::srv::GetMatesFitness_Response id(::arlo_interfaces::srv::GetMatesFitness_Response::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::srv::GetMatesFitness_Response msg_;
};

class Init_GetMatesFitness_Response_fitness
{
public:
  Init_GetMatesFitness_Response_fitness()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMatesFitness_Response_id fitness(::arlo_interfaces::srv::GetMatesFitness_Response::_fitness_type arg)
  {
    msg_.fitness = std::move(arg);
    return Init_GetMatesFitness_Response_id(msg_);
  }

private:
  ::arlo_interfaces::srv::GetMatesFitness_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::srv::GetMatesFitness_Response>()
{
  return arlo_interfaces::srv::builder::Init_GetMatesFitness_Response_fitness();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__BUILDER_HPP_
