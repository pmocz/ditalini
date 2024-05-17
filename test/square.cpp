#include "doctest/doctest.h"
#include "ditalini.h"

// Test the ditalini::Simulation().square() function

TEST_CASE("Unit Test: square function")
{
  ditalini::Simulation sim(3.0);
  CHECK(sim.square() == 9.0);
}
