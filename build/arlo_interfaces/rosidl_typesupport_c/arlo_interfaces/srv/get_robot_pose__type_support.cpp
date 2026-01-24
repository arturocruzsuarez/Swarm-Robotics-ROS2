// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from arlo_interfaces:srv/GetRobotPose.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "arlo_interfaces/srv/detail/get_robot_pose__struct.h"
#include "arlo_interfaces/srv/detail/get_robot_pose__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace arlo_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetRobotPose_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetRobotPose_Request_type_support_ids_t;

static const _GetRobotPose_Request_type_support_ids_t _GetRobotPose_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetRobotPose_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetRobotPose_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetRobotPose_Request_type_support_symbol_names_t _GetRobotPose_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, arlo_interfaces, srv, GetRobotPose_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arlo_interfaces, srv, GetRobotPose_Request)),
  }
};

typedef struct _GetRobotPose_Request_type_support_data_t
{
  void * data[2];
} _GetRobotPose_Request_type_support_data_t;

static _GetRobotPose_Request_type_support_data_t _GetRobotPose_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetRobotPose_Request_message_typesupport_map = {
  2,
  "arlo_interfaces",
  &_GetRobotPose_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetRobotPose_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetRobotPose_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetRobotPose_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetRobotPose_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace arlo_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, arlo_interfaces, srv, GetRobotPose_Request)() {
  return &::arlo_interfaces::srv::rosidl_typesupport_c::GetRobotPose_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "arlo_interfaces/srv/detail/get_robot_pose__struct.h"
// already included above
// #include "arlo_interfaces/srv/detail/get_robot_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace arlo_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetRobotPose_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetRobotPose_Response_type_support_ids_t;

static const _GetRobotPose_Response_type_support_ids_t _GetRobotPose_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetRobotPose_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetRobotPose_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetRobotPose_Response_type_support_symbol_names_t _GetRobotPose_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, arlo_interfaces, srv, GetRobotPose_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arlo_interfaces, srv, GetRobotPose_Response)),
  }
};

typedef struct _GetRobotPose_Response_type_support_data_t
{
  void * data[2];
} _GetRobotPose_Response_type_support_data_t;

static _GetRobotPose_Response_type_support_data_t _GetRobotPose_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetRobotPose_Response_message_typesupport_map = {
  2,
  "arlo_interfaces",
  &_GetRobotPose_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetRobotPose_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetRobotPose_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetRobotPose_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetRobotPose_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace arlo_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, arlo_interfaces, srv, GetRobotPose_Response)() {
  return &::arlo_interfaces::srv::rosidl_typesupport_c::GetRobotPose_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "arlo_interfaces/srv/detail/get_robot_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace arlo_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetRobotPose_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetRobotPose_type_support_ids_t;

static const _GetRobotPose_type_support_ids_t _GetRobotPose_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetRobotPose_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetRobotPose_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetRobotPose_type_support_symbol_names_t _GetRobotPose_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, arlo_interfaces, srv, GetRobotPose)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arlo_interfaces, srv, GetRobotPose)),
  }
};

typedef struct _GetRobotPose_type_support_data_t
{
  void * data[2];
} _GetRobotPose_type_support_data_t;

static _GetRobotPose_type_support_data_t _GetRobotPose_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetRobotPose_service_typesupport_map = {
  2,
  "arlo_interfaces",
  &_GetRobotPose_service_typesupport_ids.typesupport_identifier[0],
  &_GetRobotPose_service_typesupport_symbol_names.symbol_name[0],
  &_GetRobotPose_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetRobotPose_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetRobotPose_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace arlo_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, arlo_interfaces, srv, GetRobotPose)() {
  return &::arlo_interfaces::srv::rosidl_typesupport_c::GetRobotPose_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
