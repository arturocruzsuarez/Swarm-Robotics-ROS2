# generated from rosidl_generator_py/resource/_idl.py.em
# with input from arlo_interfaces:srv/EvaluateDriver.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EvaluateDriver_Request(type):
    """Metaclass of message 'EvaluateDriver_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('arlo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'arlo_interfaces.srv.EvaluateDriver_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__evaluate_driver__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__evaluate_driver__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__evaluate_driver__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__evaluate_driver__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__evaluate_driver__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EvaluateDriver_Request(metaclass=Metaclass_EvaluateDriver_Request):
    """Message class 'EvaluateDriver_Request'."""

    __slots__ = [
        '_weightsfile',
        '_maxtime',
    ]

    _fields_and_field_types = {
        'weightsfile': 'string',
        'maxtime': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.weightsfile = kwargs.get('weightsfile', str())
        self.maxtime = kwargs.get('maxtime', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.weightsfile != other.weightsfile:
            return False
        if self.maxtime != other.maxtime:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def weightsfile(self):
        """Message field 'weightsfile'."""
        return self._weightsfile

    @weightsfile.setter
    def weightsfile(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'weightsfile' field must be of type 'str'"
        self._weightsfile = value

    @builtins.property
    def maxtime(self):
        """Message field 'maxtime'."""
        return self._maxtime

    @maxtime.setter
    def maxtime(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'maxtime' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'maxtime' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._maxtime = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_EvaluateDriver_Response(type):
    """Metaclass of message 'EvaluateDriver_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('arlo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'arlo_interfaces.srv.EvaluateDriver_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__evaluate_driver__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__evaluate_driver__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__evaluate_driver__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__evaluate_driver__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__evaluate_driver__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EvaluateDriver_Response(metaclass=Metaclass_EvaluateDriver_Response):
    """Message class 'EvaluateDriver_Response'."""

    __slots__ = [
        '_time',
        '_dist2go',
        '_damage',
        '_energy',
        '_dist2mates',
    ]

    _fields_and_field_types = {
        'time': 'double',
        'dist2go': 'double',
        'damage': 'double',
        'energy': 'double',
        'dist2mates': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.time = kwargs.get('time', float())
        self.dist2go = kwargs.get('dist2go', float())
        self.damage = kwargs.get('damage', float())
        self.energy = kwargs.get('energy', float())
        self.dist2mates = kwargs.get('dist2mates', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.time != other.time:
            return False
        if self.dist2go != other.dist2go:
            return False
        if self.damage != other.damage:
            return False
        if self.energy != other.energy:
            return False
        if self.dist2mates != other.dist2mates:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._time = value

    @builtins.property
    def dist2go(self):
        """Message field 'dist2go'."""
        return self._dist2go

    @dist2go.setter
    def dist2go(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist2go' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dist2go' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dist2go = value

    @builtins.property
    def damage(self):
        """Message field 'damage'."""
        return self._damage

    @damage.setter
    def damage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'damage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'damage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._damage = value

    @builtins.property
    def energy(self):
        """Message field 'energy'."""
        return self._energy

    @energy.setter
    def energy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'energy' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'energy' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._energy = value

    @builtins.property
    def dist2mates(self):
        """Message field 'dist2mates'."""
        return self._dist2mates

    @dist2mates.setter
    def dist2mates(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist2mates' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dist2mates' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dist2mates = value


class Metaclass_EvaluateDriver(type):
    """Metaclass of service 'EvaluateDriver'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('arlo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'arlo_interfaces.srv.EvaluateDriver')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__evaluate_driver

            from arlo_interfaces.srv import _evaluate_driver
            if _evaluate_driver.Metaclass_EvaluateDriver_Request._TYPE_SUPPORT is None:
                _evaluate_driver.Metaclass_EvaluateDriver_Request.__import_type_support__()
            if _evaluate_driver.Metaclass_EvaluateDriver_Response._TYPE_SUPPORT is None:
                _evaluate_driver.Metaclass_EvaluateDriver_Response.__import_type_support__()


class EvaluateDriver(metaclass=Metaclass_EvaluateDriver):
    from arlo_interfaces.srv._evaluate_driver import EvaluateDriver_Request as Request
    from arlo_interfaces.srv._evaluate_driver import EvaluateDriver_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
