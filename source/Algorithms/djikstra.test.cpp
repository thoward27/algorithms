#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "djikstra.hpp"

TEST_CASE("Trivial") {
  Graph g(3);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 0, 100);
  Graph d = djikstras(g, 0);
  REQUIRE(d.has_edge(0, 1));
  REQUIRE(d.has_edge(1, 2));
  REQUIRE_FALSE(d.has_edge(2, 0));
}