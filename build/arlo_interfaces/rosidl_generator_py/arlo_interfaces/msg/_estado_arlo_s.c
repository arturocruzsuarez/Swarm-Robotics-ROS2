// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from arlo_interfaces:msg/EstadoArlo.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "arlo_interfaces/msg/detail/estado_arlo__struct.h"
#include "arlo_interfaces/msg/detail/estado_arlo__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__laser_scan__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__laser_scan__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__laser_scan__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__laser_scan__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__laser_scan__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__laser_scan__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__laser_scan__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__laser_scan__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool nav_msgs__msg__odometry__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * nav_msgs__msg__odometry__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool arlo_interfaces__msg__estado_arlo__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("arlo_interfaces.msg._estado_arlo.EstadoArlo", full_classname_dest, 43) == 0);
  }
  arlo_interfaces__msg__EstadoArlo * ros_message = _ros_message;
  {  // sensor1
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor1");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__laser_scan__convert_from_py(field, &ros_message->sensor1)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // sensor2
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor2");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__laser_scan__convert_from_py(field, &ros_message->sensor2)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // sensor3
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor3");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__laser_scan__convert_from_py(field, &ros_message->sensor3)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // sensor4
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor4");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__laser_scan__convert_from_py(field, &ros_message->sensor4)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // odom
    PyObject * field = PyObject_GetAttrString(_pymsg, "odom");
    if (!field) {
      return false;
    }
    if (!nav_msgs__msg__odometry__convert_from_py(field, &ros_message->odom)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // dist_to_mates
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist_to_mates");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist_to_mates = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * arlo_interfaces__msg__estado_arlo__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EstadoArlo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("arlo_interfaces.msg._estado_arlo");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EstadoArlo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  arlo_interfaces__msg__EstadoArlo * ros_message = (arlo_interfaces__msg__EstadoArlo *)raw_ros_message;
  {  // sensor1
    PyObject * field = NULL;
    field = sensor_msgs__msg__laser_scan__convert_to_py(&ros_message->sensor1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor2
    PyObject * field = NULL;
    field = sensor_msgs__msg__laser_scan__convert_to_py(&ros_message->sensor2);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor3
    PyObject * field = NULL;
    field = sensor_msgs__msg__laser_scan__convert_to_py(&ros_message->sensor3);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor4
    PyObject * field = NULL;
    field = sensor_msgs__msg__laser_scan__convert_to_py(&ros_message->sensor4);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // odom
    PyObject * field = NULL;
    field = nav_msgs__msg__odometry__convert_to_py(&ros_message->odom);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "odom", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist_to_mates
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist_to_mates);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist_to_mates", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
