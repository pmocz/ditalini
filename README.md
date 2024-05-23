# ditalini

|PyPI Version|

**Philip Mocz** (2024)
Flatiron Institute

A modern template for your awesome C++ scientific computing software app/library with wrappers for Python. This repository sets up a project for a standalone C++ library and app, that is also wrapped into a Python package using [nanobind](https://github.com/wjakob/nanobind) and
[scikit-build-core](https://scikit-build-core.readthedocs.io/en/latest/index.html).
The package is set up to be publishable at [PyPI](https://pypi.org/).

## Installation

The project can be installed in a few different ways.

### Get the Python Package

Obtain the package with:

```console
pip install ditalini
```

The package can than be used in your Python script

```python
import ditalini
```

### Build with pip

The project can also be built locally. Clone this repository and then do: 

```console
pip install .
```

### Build with CMake

Clone this repository and then do: 

```console
mkdir build
cd build
cmake ..
make
```

Documentation can be generated with

```console
make doc
```

## CI

The `.github/workflows` directory contains this projects' continuous integration workflows
for GitHub Actions. 

The `python-package` workflow will automaticallt install Python dependencies, run tests, 
and lint with a variety of Python versions on pushes.

.. |PyPI Version| image:: https://img.shields.io/pypi/v/ditalini?label=PyPI&logo=pypi
   :target: https://pypi.org/project/ditalini/
   :alt: pypi