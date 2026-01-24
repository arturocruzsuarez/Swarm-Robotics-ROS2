# generated from rosidl_generator_py/resource/_idl.py.em
# with input from arlo_interfaces:msg/EstadoArlo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EstadoArlo(type):
    """Metaclass of message 'EstadoArlo'."""

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
                'arlo_interfaces.msg.EstadoArlo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__estado_arlo
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__estado_arlo
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__estado_arlo
            cls._TYPE_SUPPORT = module.type_support_msg__msg__estado_arlo
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__estado_arlo

            from nav_msgs.msg import Odometry
            if Odometry.__class__._TYPE_SUPPORT is None:
                Odometry.__class__.__import_type_support__()

            from sensor_msgs.msg import LaserScan
            if LaserScan.__class__._TYPE_SUPPORT is None:
                LaserScan.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EstadoArlo(metaclass=Metaclass_EstadoArlo):
    """Message class 'EstadoArlo'."""

    __slots__ = [
        '_sensor1',
        '_sensor2',
        '_sensor3',
        '_sensor4',
        '_odom',
        '_dist_to_mates',
    ]

    _fields_and_field_types = {
        'sensor1': 'sensor_msgs/LaserScan',
        'sensor2': 'sensor_msgs/LaserScan',
        'sensor3': 'sensor_msgs/LaserScan',
        'sensor4': 'sensor_msgs/LaserScan',
        'odom': 'nav_msgs/Odometry',
        'dist_to_mates': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'LaserScan'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'LaserScan'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'LaserScan'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'LaserScan'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nav_msgs', 'msg'], 'Odometry'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import LaserScan
        self.sensor1 = kwargs.get('sensor1', LaserScan())
        from sensor_msgs.msg import LaserScan
        self.sensor2 = kwargs.get('sensor2', LaserScan())
        from sensor_msgs.msg import LaserScan
        self.sensor3 = kwargs.get('sensor3', LaserScan())
        from sensor_msgs.msg import LaserScan
        self.sensor4 = kwargs.get('sensor4', LaserScan())
        from nav_msgs.msg import Odometry
        self.odom = kwargs.get('odom', Odometry())
        self.dist_to_mates = kwargs.get('dist_to_mates', float())

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
        if self.sensor1 != other.sensor1:
            return False
        if self.sensor2 != other.sensor2:
            return False
        if self.sensor3 != other.sensor3:
            return False
        if self.sensor4 != other.sensor4:
            return False
        if self.odom != other.odom:
            return False
        if self.dist_to_mates != other.dist_to_mates:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sensor1(self):
        """Message field 'sensor1'."""
        return self._sensor1

    @sensor1.setter
    def sensor1(self, value):
        if __debug__:
            from sensor_msgs.msg import LaserScan
            assert \
                isinstance(value, LaserScan), \
                "The 'sensor1' field must be a sub message of type 'LaserScan'"
        self._sensor1 = value

    @builtins.property
    def sensor2(self):
        """Message field 'sensor2'."""
        return self._sensor2

    @sensor2.setter
    def sensor2(self, value):
        if __debug__:
            from sensor_msgs.msg import LaserScan
            assert \
                isinstance(value, LaserScan), \
                "The 'sensor2' field must be a sub message of type 'LaserScan'"
        self._sensor2 = value

    @builtins.property
    def sensor3(self):
        """Message field 'sensor3'."""
        return self._sensor3

    @sensor3.setter
    def sensor3(self, value):
        if __debug__:
            from sensor_msgs.msg import LaserScan
            assert \
                isinstance(value, LaserScan), \
                "The 'sensor3' field must be a sub message of type 'LaserScan'"
        self._sensor3 = value

    @builtins.property
    def sensor4(self):
        """Message field 'sensor4'."""
        return self._sensor4

    @sensor4.setter
    def sensor4(self, value):
        if __debug__:
            from sensor_msgs.msg import LaserScan
            assert \
                isinstance(value, LaserScan), \
                "The 'sensor4' field must be a sub message of type 'LaserScan'"
        self._sensor4 = value

    @builtins.property
    def odom(self):
        """Message field 'odom'."""
        return self._odom

    @odom.setter
    def odom(self, value):
        if __debug__:
            from nav_msgs.msg import Odometry
            assert \
                isinstance(value, Odometry), \
                "The 'odom' field must be a sub message of type 'Odometry'"
        self._odom = value

    @builtins.property
    def dist_to_mates(self):
        """Message field 'dist_to_mates'."""
        return self._dist_to_mates

    @dist_to_mates.setter
    def dist_to_mates(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist_to_mates' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dist_to_mates' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dist_to_mates = value
