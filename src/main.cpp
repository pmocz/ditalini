/** @file ditalini.cpp
 *  @brief A modern template for your C++ software project
 * 
 * This is the main source file of your awesome C++ app/library
 *  @author Philip Mocz (Flatiron Institute)
 **/

#include "ditalini.hpp"
#include <iostream>
#include <stdio.h>

int main(int argc, const char *argv[]) {

  std::cout << "\nDitalini - modern C++ project template. © 2024 Philip Mocz.\n" << std::endl;

  // ensure the correct number of parameters are used.
  if (argc < 2) {
    std::cout << "Usage:\n\tditalini <value>\n\nDescription:\n\tComputes the square of a number.\n";;
    return 1;
  }

  double val = atof(argv[1]);
  
  std::cout << "The square of " << val << " is " << ditalini::square(val) << "." << std::endl;

  return 0;
}