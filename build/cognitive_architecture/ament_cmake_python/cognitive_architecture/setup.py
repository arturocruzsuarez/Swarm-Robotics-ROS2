from setuptools import find_packages
from setuptools import setup

setup(
    name='cognitive_architecture',
    version='0.0.0',
    packages=find_packages(
        include=('cognitive_architecture', 'cognitive_architecture.*')),
)
