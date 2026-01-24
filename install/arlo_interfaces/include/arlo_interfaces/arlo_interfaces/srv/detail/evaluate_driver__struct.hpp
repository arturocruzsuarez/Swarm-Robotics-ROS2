// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arlo_interfaces:srv/EvaluateDriver.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__STRUCT_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Request __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Request __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EvaluateDriver_Request_
{
  using Type = EvaluateDriver_Request_<ContainerAllocator>;

  explicit EvaluateDriver_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->weightsfile = "";
      this->maxtime = 0ll;
    }
  }

  explicit EvaluateDriver_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : weightsfile(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->weightsfile = "";
      this->maxtime = 0ll;
    }
  }

  // field types and members
  using _weightsfile_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _weightsfile_type weightsfile;
  using _maxtime_type =
    int64_t;
  _maxtime_type maxtime;

  // setters for named parameter idiom
  Type & set__weightsfile(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->weightsfile = _arg;
    return *this;
  }
  Type & set__maxtime(
    const int64_t & _arg)
  {
    this->maxtime = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Request
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Request
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EvaluateDriver_Request_ & other) const
  {
    if (this->weightsfile != other.weightsfile) {
      return false;
    }
    if (this->maxtime != other.maxtime) {
      return false;
    }
    return true;
  }
  bool operator!=(const EvaluateDriver_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EvaluateDriver_Request_

// alias to use template instance with default allocator
using EvaluateDriver_Request =
  arlo_interfaces::srv::EvaluateDriver_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arlo_interfaces


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Response __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Response __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EvaluateDriver_Response_
{
  using Type = EvaluateDriver_Response_<ContainerAllocator>;

  explicit EvaluateDriver_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0;
      this->dist2go = 0.0;
      this->damage = 0.0;
      this->energy = 0.0;
      this->dist2mates = 0.0;
    }
  }

  explicit EvaluateDriver_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0;
      this->dist2go = 0.0;
      this->damage = 0.0;
      this->energy = 0.0;
      this->dist2mates = 0.0;
    }
  }

  // field types and members
  using _time_type =
    double;
  _time_type time;
  using _dist2go_type =
    double;
  _dist2go_type dist2go;
  using _damage_type =
    double;
  _damage_type damage;
  using _energy_type =
    double;
  _energy_type energy;
  using _dist2mates_type =
    double;
  _dist2mates_type dist2mates;

  // setters for named parameter idiom
  Type & set__time(
    const double & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__dist2go(
    const double & _arg)
  {
    this->dist2go = _arg;
    return *this;
  }
  Type & set__damage(
    const double & _arg)
  {
    this->damage = _arg;
    return *this;
  }
  Type & set__energy(
    const double & _arg)
  {
    this->energy = _arg;
    return *this;
  }
  Type & set__dist2mates(
    const double & _arg)
  {
    this->dist2mates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Response
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__srv__EvaluateDriver_Response
    std::shared_ptr<arlo_interfaces::srv::EvaluateDriver_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EvaluateDriver_Response_ & other) const
  {
    if (this->time != other.time) {
      return false;
    }
    if (this->dist2go != other.dist2go) {
      return false;
    }
    if (this->damage != other.damage) {
      return false;
    }
    if (this->energy != other.energy) {
      return false;
    }
    if (this->dist2mates != other.dist2mates) {
      return false;
    }
    return true;
  }
  bool operator!=(const EvaluateDriver_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EvaluateDriver_Response_

// alias to use template instance with default allocator
using EvaluateDriver_Response =
  arlo_interfaces::srv::EvaluateDriver_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arlo_interfaces

namespace arlo_interfaces
{

namespace srv
{

struct EvaluateDriver
{
  using Request = arlo_interfaces::srv::EvaluateDriver_Request;
  using Response = arlo_interfaces::srv::EvaluateDriver_Response;
};

}  // namespace srv

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__EVALUATE_DRIVER__STRUCT_HPP_
