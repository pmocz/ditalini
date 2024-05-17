#include "ditalini.h"
#include "doctest/doctest.h"

// Test the ditalini::Simulation().square() function

TEST_CASE("Unit Test: square function") {
  ditalini::Simulation sim(3.0);
  CHECK(sim.square() == 9.0);
}
