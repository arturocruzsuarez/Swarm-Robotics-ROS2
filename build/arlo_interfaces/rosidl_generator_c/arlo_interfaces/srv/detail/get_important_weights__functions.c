// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arlo_interfaces:srv/GetImportantWeights.idl
// generated code does not contain a copyright notice
#include "arlo_interfaces/srv/detail/get_important_weights__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
arlo_interfaces__srv__GetImportantWeights_Request__init(arlo_interfaces__srv__GetImportantWeights_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
arlo_interfaces__srv__GetImportantWeights_Request__fini(arlo_interfaces__srv__GetImportantWeights_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
arlo_interfaces__srv__GetImportantWeights_Request__are_equal(const arlo_interfaces__srv__GetImportantWeights_Request * lhs, const arlo_interfaces__srv__GetImportantWeights_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
arlo_interfaces__srv__GetImportantWeights_Request__copy(
  const arlo_interfaces__srv__GetImportantWeights_Request * input,
  arlo_interfaces__srv__GetImportantWeights_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

arlo_interfaces__srv__GetImportantWeights_Request *
arlo_interfaces__srv__GetImportantWeights_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__srv__GetImportantWeights_Request * msg = (arlo_interfaces__srv__GetImportantWeights_Request *)allocator.allocate(sizeof(arlo_interfaces__srv__GetImportantWeights_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arlo_interfaces__srv__GetImportantWeights_Request));
  bool success = arlo_interfaces__srv__GetImportantWeights_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arlo_interfaces__srv__GetImportantWeights_Request__destroy(arlo_interfaces__srv__GetImportantWeights_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arlo_interfaces__srv__GetImportantWeights_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arlo_interfaces__srv__GetImportantWeights_Request__Sequence__init(arlo_interfaces__srv__GetImportantWeights_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__srv__GetImportantWeights_Request * data = NULL;

  if (size) {
    data = (arlo_interfaces__srv__GetImportantWeights_Request *)allocator.zero_allocate(size, sizeof(arlo_interfaces__srv__GetImportantWeights_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arlo_interfaces__srv__GetImportantWeights_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arlo_interfaces__srv__GetImportantWeights_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
arlo_interfaces__srv__GetImportantWeights_Request__Sequence__fini(arlo_interfaces__srv__GetImportantWeights_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      arlo_interfaces__srv__GetImportantWeights_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

arlo_interfaces__srv__GetImportantWeights_Request__Sequence *
arlo_interfaces__srv__GetImportantWeights_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__srv__GetImportantWeights_Request__Sequence * array = (arlo_interfaces__srv__GetImportantWeights_Request__Sequence *)allocator.allocate(sizeof(arlo_interfaces__srv__GetImportantWeights_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arlo_interfaces__srv__GetImportantWeights_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arlo_interfaces__srv__GetImportantWeights_Request__Sequence__destroy(arlo_interfaces__srv__GetImportantWeights_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arlo_interfaces__srv__GetImportantWeights_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arlo_interfaces__srv__GetImportantWeights_Request__Sequence__are_equal(const arlo_interfaces__srv__GetImportantWeights_Request__Sequence * lhs, const arlo_interfaces__srv__GetImportantWeights_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arlo_interfaces__srv__GetImportantWeights_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arlo_interfaces__srv__GetImportantWeights_Request__Sequence__copy(
  const arlo_interfaces__srv__GetImportantWeights_Request__Sequence * input,
  arlo_interfaces__srv__GetImportantWeights_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arlo_interfaces__srv__GetImportantWeights_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arlo_interfaces__srv__GetImportantWeights_Request * data =
      (arlo_interfaces__srv__GetImportantWeights_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arlo_interfaces__srv__GetImportantWeights_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arlo_interfaces__srv__GetImportantWeights_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arlo_interfaces__srv__GetImportantWeights_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `weightsfile`
#include "rosidl_runtime_c/string_functions.h"

bool
arlo_interfaces__srv__GetImportantWeights_Response__init(arlo_interfaces__srv__GetImportantWeights_Response * msg)
{
  if (!msg) {
    return false;
  }
  // weightsfile
  if (!rosidl_runtime_c__String__init(&msg->weightsfile)) {
    arlo_interfaces__srv__GetImportantWeights_Response__fini(msg);
    return false;
  }
  return true;
}

void
arlo_interfaces__srv__GetImportantWeights_Response__fini(arlo_interfaces__srv__GetImportantWeights_Response * msg)
{
  if (!msg) {
    return;
  }
  // weightsfile
  rosidl_runtime_c__String__fini(&msg->weightsfile);
}

bool
arlo_interfaces__srv__GetImportantWeights_Response__are_equal(const arlo_interfaces__srv__GetImportantWeights_Response * lhs, const arlo_interfaces__srv__GetImportantWeights_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // weightsfile
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->weightsfile), &(rhs->weightsfile)))
  {
    return false;
  }
  return true;
}

bool
arlo_interfaces__srv__GetImportantWeights_Response__copy(
  const arlo_interfaces__srv__GetImportantWeights_Response * input,
  arlo_interfaces__srv__GetImportantWeights_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // weightsfile
  if (!rosidl_runtime_c__String__copy(
      &(input->weightsfile), &(output->weightsfile)))
  {
    return false;
  }
  return true;
}

arlo_interfaces__srv__GetImportantWeights_Response *
arlo_interfaces__srv__GetImportantWeights_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__srv__GetImportantWeights_Response * msg = (arlo_interfaces__srv__GetImportantWeights_Response *)allocator.allocate(sizeof(arlo_interfaces__srv__GetImportantWeights_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arlo_interfaces__srv__GetImportantWeights_Response));
  bool success = arlo_interfaces__srv__GetImportantWeights_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arlo_interfaces__srv__GetImportantWeights_Response__destroy(arlo_interfaces__srv__GetImportantWeights_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arlo_interfaces__srv__GetImportantWeights_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arlo_interfaces__srv__GetImportantWeights_Response__Sequence__init(arlo_interfaces__srv__GetImportantWeights_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__srv__GetImportantWeights_Response * data = NULL;

  if (size) {
    data = (arlo_interfaces__srv__GetImportantWeights_Response *)allocator.zero_allocate(size, sizeof(arlo_interfaces__srv__GetImportantWeights_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arlo_interfaces__srv__GetImportantWeights_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arlo_interfaces__srv__GetImportantWeights_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
arlo_interfaces__srv__GetImportantWeights_Response__Sequence__fini(arlo_interfaces__srv__GetImportantWeights_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      arlo_interfaces__srv__GetImportantWeights_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

arlo_interfaces__srv__GetImportantWeights_Response__Sequence *
arlo_interfaces__srv__GetImportantWeights_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arlo_interfaces__srv__GetImportantWeights_Response__Sequence * array = (arlo_interfaces__srv__GetImportantWeights_Response__Sequence *)allocator.allocate(sizeof(arlo_interfaces__srv__GetImportantWeights_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arlo_interfaces__srv__GetImportantWeights_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arlo_interfaces__srv__GetImportantWeights_Response__Sequence__destroy(arlo_interfaces__srv__GetImportantWeights_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arlo_interfaces__srv__GetImportantWeights_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arlo_interfaces__srv__GetImportantWeights_Response__Sequence__are_equal(const arlo_interfaces__srv__GetImportantWeights_Response__Sequence * lhs, const arlo_interfaces__srv__GetImportantWeights_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arlo_interfaces__srv__GetImportantWeights_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arlo_interfaces__srv__GetImportantWeights_Response__Sequence__copy(
  const arlo_interfaces__srv__GetImportantWeights_Response__Sequence * input,
  arlo_interfaces__srv__GetImportantWeights_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arlo_interfaces__srv__GetImportantWeights_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arlo_interfaces__srv__GetImportantWeights_Response * data =
      (arlo_interfaces__srv__GetImportantWeights_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arlo_interfaces__srv__GetImportantWeights_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arlo_interfaces__srv__GetImportantWeights_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arlo_interfaces__srv__GetImportantWeights_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
