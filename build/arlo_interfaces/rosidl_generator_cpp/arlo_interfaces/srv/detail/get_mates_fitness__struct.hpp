// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arlo_interfaces:srv/GetMatesFitness.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__STRUCT_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Request __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Request __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMatesFitness_Request_
{
  using Type = GetMatesFitness_Request_<ContainerAllocator>;

  explicit GetMatesFitness_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetMatesFitness_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Request
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Request
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMatesFitness_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMatesFitness_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMatesFitness_Request_

// alias to use template instance with default allocator
using GetMatesFitness_Request =
  arlo_interfaces::srv::GetMatesFitness_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arlo_interfaces


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Response __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Response __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMatesFitness_Response_
{
  using Type = GetMatesFitness_Response_<ContainerAllocator>;

  explicit GetMatesFitness_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fitness = 0.0;
      this->id = 0ll;
    }
  }

  explicit GetMatesFitness_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fitness = 0.0;
      this->id = 0ll;
    }
  }

  // field types and members
  using _fitness_type =
    double;
  _fitness_type fitness;
  using _id_type =
    int64_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__fitness(
    const double & _arg)
  {
    this->fitness = _arg;
    return *this;
  }
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Response
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__srv__GetMatesFitness_Response
    std::shared_ptr<arlo_interfaces::srv::GetMatesFitness_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMatesFitness_Response_ & other) const
  {
    if (this->fitness != other.fitness) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMatesFitness_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMatesFitness_Response_

// alias to use template instance with default allocator
using GetMatesFitness_Response =
  arlo_interfaces::srv::GetMatesFitness_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arlo_interfaces

namespace arlo_interfaces
{

namespace srv
{

struct GetMatesFitness
{
  using Request = arlo_interfaces::srv::GetMatesFitness_Request;
  using Response = arlo_interfaces::srv::GetMatesFitness_Response;
};

}  // namespace srv

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_MATES_FITNESS__STRUCT_HPP_
