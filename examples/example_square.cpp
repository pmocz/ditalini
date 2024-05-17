
#include <iostream>

#include "ditalini.h"

// An example showing how to use the ditalini library
// Philip Mocz (2024)

int main() {
  std::cout << "The square of 17 is: " << ditalini::Simulation(17).square()
            << std::endl;
  return 0;
}