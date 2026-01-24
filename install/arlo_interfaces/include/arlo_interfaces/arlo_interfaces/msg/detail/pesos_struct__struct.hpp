// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arlo_interfaces:msg/PesosStruct.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__STRUCT_HPP_
#define ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__msg__PesosStruct __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__msg__PesosStruct __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PesosStruct_
{
  using Type = PesosStruct_<ContainerAllocator>;

  explicit PesosStruct_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PesosStruct_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _pesos_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _pesos_type pesos;

  // setters for named parameter idiom
  Type & set__pesos(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->pesos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::msg::PesosStruct_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::msg::PesosStruct_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::msg::PesosStruct_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::msg::PesosStruct_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__msg__PesosStruct
    std::shared_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__msg__PesosStruct
    std::shared_ptr<arlo_interfaces::msg::PesosStruct_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PesosStruct_ & other) const
  {
    if (this->pesos != other.pesos) {
      return false;
    }
    return true;
  }
  bool operator!=(const PesosStruct_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PesosStruct_

// alias to use template instance with default allocator
using PesosStruct =
  arlo_interfaces::msg::PesosStruct_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__MSG__DETAIL__PESOS_STRUCT__STRUCT_HPP_
