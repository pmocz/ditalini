/** @file ditalini.cpp
 *  @brief Main library functions
 *
 * Return the result of the Simulation class.
 *  @author Philip Mocz (Flatiron Institute)
 **/

#include "ditalini.h"

namespace ditalini {

Simulation::Simulation(double val) : value_(val) {}

double Simulation::square() { return value_ * value_; }

}  // namespace ditalini