// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arlo_interfaces:srv/GetRobotPose.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_ROBOT_POSE__BUILDER_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__GET_ROBOT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arlo_interfaces/srv/detail/get_robot_pose__struct.hpp"
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
auto build<::arlo_interfaces::srv::GetRobotPose_Request>()
{
  return ::arlo_interfaces::srv::GetRobotPose_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace arlo_interfaces


namespace arlo_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRobotPose_Response_y
{
public:
  explicit Init_GetRobotPose_Response_y(::arlo_interfaces::srv::GetRobotPose_Response & msg)
  : msg_(msg)
  {}
  ::arlo_interfaces::srv::GetRobotPose_Response y(::arlo_interfaces::srv::GetRobotPose_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arlo_interfaces::srv::GetRobotPose_Response msg_;
};

class Init_GetRobotPose_Response_x
{
public:
  Init_GetRobotPose_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotPose_Response_y x(::arlo_interfaces::srv::GetRobotPose_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetRobotPose_Response_y(msg_);
  }

private:
  ::arlo_interfaces::srv::GetRobotPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::arlo_interfaces::srv::GetRobotPose_Response>()
{
  return arlo_interfaces::srv::builder::Init_GetRobotPose_Response_x();
}

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_ROBOT_POSE__BUILDER_HPP_
