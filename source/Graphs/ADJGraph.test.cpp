#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "ADJGraph.hpp"

TEST_CASE("Constructor") {
    Graph test(10);
    REQUIRE(test.node_count() == 10);
    REQUIRE(test.edge_count() == 0);

    int sum = 0;
    for(int i = 0 ; i < 5 ; ++i) {
        sum += test.get_value(i);
    }

    REQUIRE(sum == 0);
}

TEST_CASE("add_edge") {
    Graph test(10);
    test.add_edge(0, 3);
    REQUIRE(test.has_edge(0, 3));
    REQUIRE_FALSE(test.has_edge(3, 0));

    test.add_edge(0, 2);
    REQUIRE(test.has_edge(0, 2));
    REQUIRE_FALSE(test.has_edge(2, 0));

    test.add_edge(4,6);
    REQUIRE(test.has_edge(4, 6));
    REQUIRE_FALSE(test.has_edge(6, 4));
    REQUIRE_THROWS(test.add_edge(10, 1));

    REQUIRE(test.edge_count() == 3);
}

TEST_CASE("add_edge w/ weights") {
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