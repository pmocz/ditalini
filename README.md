# ditalini

[![PyPI Version Status][pypi-badge]][pypi-link]
[![Python Package Status][workflow-package-badge]][workflow-package-link]
[![Readthedocs Status][docs-badge]][docs-link]

[pypi-link]:               https://pypi.org/project/ditalini/
[pypi-badge]:              https://img.shields.io/pypi/v/ditalini?label=PyPI&logo=pypi
[workflow-package-link]:   https://github.com/pmocz/ditalini/actions/workflows/python-package.yml
[workflow-package-badge]:  https://github.com/pmocz/ditalini/actions/workflows/python-package.yml/badge.svg?event=push
[docs-link]:               https://ditalini.readthedocs.io/en/latest/
[docs-badge]:              https://readthedocs.org/projects/ditalini/badge/


[**Philip Mocz**](https://pmocz.github.io) (2024)
Flatiron Institute

A modern template for your awesome C++ scientific computing software app/library with wrappers for Python. 
This repository sets up a project for a standalone C++ library and app, 
that is also wrapped into a Python package using [nanobind](https://github.com/wjakob/nanobind) and
[scikit-build-core](https://scikit-build-core.readthedocs.io/en/latest/index.html).
The package is set up to be publishable at [PyPI](https://pypi.org/).
Documentation is automatically generated at [readthedocs](https://ditalini.readthedocs.io/).


## Installation

The project can be installed in a few different ways.

### Get the Python Package

Obtain the published version of the package with:

```console
pip install ditalini
```

The package can then be used in your Python script

```python
import ditalini
```

### Build with pip

The project can also be built locally. Clone this repository and then do: 

```console
pip install .
```

### Build with CMake

The repository can also be build with [CMake](https://cmake.org/). Clone this repository and then do: 

```console
mkdir build
cd build
cmake ..
make
```


## Documentation

Documentation is automatically generated and hosted at [readthedocs](https://ditalini.readthedocs.io/) with each push.
First, [Doxygen](https://www.doxygen.nl/) creates documentation for the C++ Library. 
Then, [Sphinx](https://www.sphinx-doc.org/en/master/) with the [Breathe](https://breathe.readthedocs.io/en/latest/) 
extension creates a final documentation for the entire project (C++ library and Python package).


## CI

The `.github/workflows` directory contains this projects' continuous integration workflows
for GitHub Actions. 

The `python-package` workflow will automatically install Python dependencies and run tests on pushes.

The `python-publish` workflow will automatically upload this repository to PyPI when a release is created. The user must set a secret `PYPI_API_TOKEN` variable in Github.
