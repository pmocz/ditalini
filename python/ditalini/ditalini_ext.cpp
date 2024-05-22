#include <iostream>
#include <sstream>

#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>
#include <nanobind/stl/string.h>

#include "../../include/ditalini.h"

namespace nb = nanobind;

NB_MODULE(ditalini, m) {
  nb::class_<ditalini::Simulation>(m, "Simulation")
    .def(nb::init<double>())
    .def("square", &ditalini::Simulation::square);
}