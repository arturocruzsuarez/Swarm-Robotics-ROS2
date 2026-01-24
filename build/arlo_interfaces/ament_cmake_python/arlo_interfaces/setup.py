from setuptools import find_packages
from setuptools import setup

setup(
    name='arlo_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('arlo_interfaces', 'arlo_interfaces.*')),
)
