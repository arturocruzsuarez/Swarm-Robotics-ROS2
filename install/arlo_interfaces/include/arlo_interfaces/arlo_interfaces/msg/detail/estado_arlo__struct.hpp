// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__STRUCT_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'sensor1'
// Member 'sensor2'
// Member 'sensor3'
// Member 'sensor4'
#include "sensor_msgs/msg/detail/laser_scan__struct.hpp"
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__msg__EstadoArlo __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__msg__EstadoArlo __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EstadoArlo_
{
  using Type = EstadoArlo_<ContainerAllocator>;

  explicit EstadoArlo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor1(_init),
    sensor2(_init),
    sensor3(_init),
    sensor4(_init),
    odom(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dist_to_mates = 0.0;
    }
  }

  explicit EstadoArlo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor1(_alloc, _init),
    sensor2(_alloc, _init),
    sensor3(_alloc, _init),
    sensor4(_alloc, _init),
    odom(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dist_to_mates = 0.0;
    }
  }

  // field types and members
  using _sensor1_type =
    sensor_msgs::msg::LaserScan_<ContainerAllocator>;
  _sensor1_type sensor1;
  using _sensor2_type =
    sensor_msgs::msg::LaserScan_<ContainerAllocator>;
  _sensor2_type sensor2;
  using _sensor3_type =
    sensor_msgs::msg::LaserScan_<ContainerAllocator>;
  _sensor3_type sensor3;
  using _sensor4_type =
    sensor_msgs::msg::LaserScan_<ContainerAllocator>;
  _sensor4_type sensor4;
  using _odom_type =
    nav_msgs::msg::Odometry_<ContainerAllocator>;
  _odom_type odom;
  using _dist_to_mates_type =
    double;
  _dist_to_mates_type dist_to_mates;

  // setters for named parameter idiom
  Type & set__sensor1(
    const sensor_msgs::msg::LaserScan_<ContainerAllocator> & _arg)
  {
    this->sensor1 = _arg;
    return *this;
  }
  Type & set__sensor2(
    const sensor_msgs::msg::LaserScan_<ContainerAllocator> & _arg)
  {
    this->sensor2 = _arg;
    return *this;
  }
  Type & set__sensor3(
    const sensor_msgs::msg::LaserScan_<ContainerAllocator> & _arg)
  {
    this->sensor3 = _arg;
    return *this;
  }
  Type & set__sensor4(
    const sensor_msgs::msg::LaserScan_<ContainerAllocator> & _arg)
  {
    this->sensor4 = _arg;
    return *this;
  }
  Type & set__odom(
    const nav_msgs::msg::Odometry_<ContainerAllocator> & _arg)
  {
    this->odom = _arg;
    return *this;
  }
  Type & set__dist_to_mates(
    const double & _arg)
  {
    this->dist_to_mates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::msg::EstadoArlo_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::msg::EstadoArlo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::msg::EstadoArlo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::msg::EstadoArlo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__msg__EstadoArlo
    std::shared_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__msg__EstadoArlo
    std::shared_ptr<arlo_interfaces::msg::EstadoArlo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EstadoArlo_ & other) const
  {
    if (this->sensor1 != other.sensor1) {
      return false;
    }
    if (this->sensor2 != other.sensor2) {
      return false;
    }
    if (this->sensor3 != other.sensor3) {
      return false;
    }
    if (this->sensor4 != other.sensor4) {
      return false;
    }
    if (this->odom != other.odom) {
      return false;
    }
    if (this->dist_to_mates != other.dist_to_mates) {
      return false;
    }
    return true;
  }
  bool operator!=(const EstadoArlo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EstadoArlo_

// alias to use template instance with default allocator
using EstadoArlo =
  arlo_interfaces::msg::EstadoArlo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__MSG__DETAIL__ESTADO_ARLO__STRUCT_HPP_
