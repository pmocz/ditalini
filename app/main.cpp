/** @file main.cpp
 *  @brief A modern template for your C++ software project
 * 
 * This is the main source file of your awesome C++ app/library
 *  @author Philip Mocz (Flatiron Institute)
 **/

#include <iostream>

#include "ditaliniConfig.h"
#include "ditalini.h"

int main(int argc, const char *argv[]) {

  std::cout << "Ditalini - modern C++ project template. © 2024 Philip Mocz. v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << std::endl;

  // Ensure the correct number of parameters are used.
  if (argc < 2) {
    std::cout << "Usage:\n\tditalini <value>\n\nDescription:\n\tComputes the square of a number.\n";
    return 1;
  }

  double val = atof(argv[1]);

  ditalini::Simulation sim = ditalini::Simulation(val);
  
  // Print the square of the input value.
  std::cout << "The square of " << val << " is " << sim.square() << ".\n";

  return 0;

}