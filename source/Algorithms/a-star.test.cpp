#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "a-star.hpp"

TEST_CASE("Trivial") {
  int maze[4][4] = {
      {0, 1, 2, 3},
      {1, 0, 0, 4},
      {0, 0, 0, 5},
      {0, 0, 0, 6},
  };
  REQUIRE(a_search(maze).compare(
      "(0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3), (3, 3)"));
}