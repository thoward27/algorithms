#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Graph.hpp"
#include <algorithm>

TEST_CASE("Constructor") {
  Graph G(10);
  REQUIRE_EQ(G.node_count(), 10);
  REQUIRE_EQ(G.edge_count(), 0);
  long sum = 0;
  for (int i = 0; i < 100; ++i) {
    sum += G.weight(i / 10, i % 10);
  }
  REQUIRE_FALSE(sum);
  sum = 0;
  for (int i = 0; i < 10; ++i) {
    sum += G.get_value(i);
  }
  REQUIRE_FALSE(sum);
  CHECK_THROWS(Graph G(0));
}

TEST_CASE("add_edge") {
  Graph G(10);
  G.add_edge(1, 2, 10);
  REQUIRE(G.has_edge(1, 2));
  REQUIRE_EQ(G.weight(1, 2), 10);
  REQUIRE_FALSE(G.has_edge(2, 1));
  G.add_edge(5, 9, -10);
  REQUIRE(G.has_edge(5, 9));
  REQUIRE_EQ(G.weight(5, 9), -10);
  G.add_edge(2, 1);
  REQUIRE(G.has_edge(2, 1));
  REQUIRE_EQ(G.weight(2, 1), 1);

  REQUIRE_EQ(G.edge_count(), 3);

  REQUIRE_THROWS(G.add_edge(10, 1, 80));
  REQUIRE_THROWS(G.add_edge(1, 10, 80));
  REQUIRE_THROWS(G.add_edge(0, 1, 0));
  REQUIRE_THROWS(G.add_edge(4, 4, 8));
}

TEST_CASE("remove_edge") {
  Graph G(10);
  for (int i = 0; i < 10; ++i) {
    G.add_edge(i, (i + 1) % 10);
    G.add_edge(i, (i + 5) % 10);
  }
  REQUIRE(G.has_edge(0, 1));
  G.remove_edge(0, 1);
  REQUIRE_FALSE(G.has_edge(0, 1));
  REQUIRE(G.has_edge(9, 4));
  G.remove_edge(9, 4);
  REQUIRE_FALSE(G.has_edge(9, 4));

  REQUIRE_EQ(G.edge_count(), 18);

  REQUIRE_THROWS(G.remove_edge(0, 2));
  REQUIRE_THROWS(G.remove_edge(1, 0));
  REQUIRE_THROWS(G.remove_edge(0, 0));
}

TEST_CASE("neighbors") {
  Graph G(5);
  for (int i = 0; i < 4; ++i) {
    G.add_edge(i, (i + 1) % 5);
    G.add_edge((i + 1) % 5, i);
  }
  G.add_edge(1, 3);
  G.add_edge(1, 4);
  G.add_edge(3, 0);
  G.remove_edge(3, 2);
  std::vector<int> v0_t{ 1 };
  std::vector<int> v1_t{ 0, 2, 3, 4 };
  std::vector<int> v2_t{ 1, 3 };
  std::vector<int> v3_t{ 0, 4 };
  std::vector<int> v4_t{ 3 };
  std::vector<std::vector<int>> tests{ v0_t, v1_t, v2_t, v3_t, v4_t };
  char name[9] = "Vertex -";
  for (int i = 0; i < 5; ++i) {
    name[7] = '0' + i;
    std::vector<int> result = G.neighbors(i);
    std::sort(result.begin(), result.end());
    SUBCASE(name) {
      REQUIRE_EQ(result, tests[i]);
    }
  }

  REQUIRE_THROWS(G.neighbors(6));
}

TEST_CASE("Extra out-of-bounds checks") {
  Graph G(2);
  REQUIRE_THROWS(G.get_value(2));
  REQUIRE_THROWS(G.set_value(2, 1));
  REQUIRE_THROWS(G.weight(0, 2));
  REQUIRE_THROWS(G.weight(2, 0));
  REQUIRE_THROWS(G.has_edge(0, 2));
  REQUIRE_THROWS(G.has_edge(2, 0));
}