// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from arlo_interfaces:srv/EvaluateDriver.idl
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
#include "arlo_interfaces/srv/detail/evaluate_driver__struct.h"
#include "arlo_interfaces/srv/detail/evaluate_driver__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool arlo_interfaces__srv__evaluate_driver__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
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
    assert(strncmp("arlo_interfaces.srv._evaluate_driver.EvaluateDriver_Request", full_classname_dest, 59) == 0);
  }
  arlo_interfaces__srv__EvaluateDriver_Request * ros_message = _ros_message;
  {  // weightsfile
    PyObject * field = PyObject_GetAttrString(_pymsg, "weightsfile");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->weightsfile, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // maxtime
    PyObject * field = PyObject_GetAttrString(_pymsg, "maxtime");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->maxtime = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * arlo_interfaces__srv__evaluate_driver__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EvaluateDriver_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("arlo_interfaces.srv._evaluate_driver");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EvaluateDriver_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  arlo_interfaces__srv__EvaluateDriver_Request * ros_message = (arlo_interfaces__srv__EvaluateDriver_Request *)raw_ros_message;
  {  // weightsfile
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->weightsfile.data,
      strlen(ros_message->weightsfile.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "weightsfile", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // maxtime
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->maxtime);
    {
      int rc = PyObject_SetAttrString(_pymessage, "maxtime", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "arlo_interfaces/srv/detail/evaluate_driver__struct.h"
// already included above
// #include "arlo_interfaces/srv/detail/evaluate_driver__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool arlo_interfaces__srv__evaluate_driver__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[61];
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
    assert(strncmp("arlo_interfaces.srv._evaluate_driver.EvaluateDriver_Response", full_classname_dest, 60) == 0);
  }
  arlo_interfaces__srv__EvaluateDriver_Response * ros_message = _ros_message;
  {  // time
    PyObject * field = PyObject_GetAttrString(_pymsg, "time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist2go
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist2go");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist2go = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // damage
    PyObject * field = PyObject_GetAttrString(_pymsg, "damage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->damage = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // energy
    PyObject * field = PyObject_GetAttrString(_pymsg, "energy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->energy = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist2mates
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist2mates");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist2mates = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * arlo_interfaces__srv__evaluate_driver__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EvaluateDriver_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("arlo_interfaces.srv._evaluate_driver");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EvaluateDriver_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  arlo_interfaces__srv__EvaluateDriver_Response * ros_message = (arlo_interfaces__srv__EvaluateDriver_Response *)raw_ros_message;
  {  // time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist2go
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist2go);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist2go", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // damage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->damage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "damage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // energy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->energy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "energy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist2mates
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist2mates);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist2mates", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
