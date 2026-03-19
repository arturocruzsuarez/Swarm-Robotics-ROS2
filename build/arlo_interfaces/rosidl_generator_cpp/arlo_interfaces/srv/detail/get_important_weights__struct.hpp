// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arlo_interfaces:srv/GetImportantWeights.idl
// generated code does not contain a copyright notice

#ifndef ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__STRUCT_HPP_
#define ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Request __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Request __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetImportantWeights_Request_
{
  using Type = GetImportantWeights_Request_<ContainerAllocator>;

  explicit GetImportantWeights_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetImportantWeights_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Request
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Request
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetImportantWeights_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetImportantWeights_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetImportantWeights_Request_

// alias to use template instance with default allocator
using GetImportantWeights_Request =
  arlo_interfaces::srv::GetImportantWeights_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arlo_interfaces


#ifndef _WIN32
# define DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Response __attribute__((deprecated))
#else
# define DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Response __declspec(deprecated)
#endif

namespace arlo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetImportantWeights_Response_
{
  using Type = GetImportantWeights_Response_<ContainerAllocator>;

  explicit GetImportantWeights_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->weightsfile = "";
    }
  }

  explicit GetImportantWeights_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : weightsfile(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->weightsfile = "";
    }
  }

  // field types and members
  using _weightsfile_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _weightsfile_type weightsfile;

  // setters for named parameter idiom
  Type & set__weightsfile(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->weightsfile = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Response
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arlo_interfaces__srv__GetImportantWeights_Response
    std::shared_ptr<arlo_interfaces::srv::GetImportantWeights_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetImportantWeights_Response_ & other) const
  {
    if (this->weightsfile != other.weightsfile) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetImportantWeights_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetImportantWeights_Response_

// alias to use template instance with default allocator
using GetImportantWeights_Response =
  arlo_interfaces::srv::GetImportantWeights_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace arlo_interfaces

namespace arlo_interfaces
{

namespace srv
{

struct GetImportantWeights
{
  using Request = arlo_interfaces::srv::GetImportantWeights_Request;
  using Response = arlo_interfaces::srv::GetImportantWeights_Response;
};

}  // namespace srv

}  // namespace arlo_interfaces

#endif  // ARLO_INTERFACES__SRV__DETAIL__GET_IMPORTANT_WEIGHTS__STRUCT_HPP_
