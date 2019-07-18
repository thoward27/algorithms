#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "hamiltoniancycle.hpp"

/** add_simple_edge(Graph& G, unsigned int v, unsigned int w)
 * Adds an undirected edge from v to w with weight 1 to G.
 */
void add_simple_edge(Graph& G, unsigned int v, unsigned int w) {
  G.add_edge(v, w);
  G.add_edge(w, v);
}

/** add_triangle(Graph& G, unsigned int u, unsigned int v, unsigned int w)
 * Adds an undirected triangle to G between vertices u, v, and w, with edge
 * weights 1.
 */
void add_triangle(Graph& G, unsigned int u, unsigned int v, unsigned int w) {
  add_simple_edge(G, u, v);
  add_simple_edge(G, v, w);
  add_simple_edge(G, u, w);
}

TEST_CASE("hamiltonian_cycle") {
  SUBCASE("Trivial - Triangle") {
    Graph G(3);
    add_triangle(G, 0, 1, 2);
    REQUIRE(hamiltonian_cycle(G));
  }

  SUBCASE("Larger Cycle") {
    Graph G(8);
    for (int i = 0; i < 7; ++i) {
      add_simple_edge(G, i, i + 1);
    }
    add_simple_edge(G, 0, 7);
    REQUIRE(hamiltonian_cycle(G));
  }

  SUBCASE("Disconnected") {
    Graph G(9);
    for (int i = 0; i < 7; ++i) {
      add_simple_edge(G, i, i + 1);
    }
    add_simple_edge(G, 0, 7);
    REQUIRE_FALSE(hamiltonian_cycle(G));
  }

  SUBCASE("Connected but Impossible") {
    Graph G(4);
    add_triangle(G, 0, 1, 2);
    add_simple_edge(G, 2, 3);
    REQUIRE_FALSE(hamiltonian_cycle(G));
  }

  SUBCASE("Complete") {
    Graph G(5);
    for (int i = 0; i < 5; ++i) {
      for (int j = i + 1; j < 5; ++j) {
        add_simple_edge(G, i, j);
      }
    }
    REQUIRE(hamiltonian_cycle(G));
  }

  SUBCASE("Complex - Possible") {
    int edges[2][16] = {{0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 7},
                        {1, 3, 5, 7, 2, 3, 3, 5, 6, 7, 5, 7, 6, 8, 8, 8}};
    Graph G(9);
    for (int i = 0; i < 16; ++i) {
      add_simple_edge(G, edges[0][i], edges[1][i]);
    }
    REQUIRE(hamiltonian_cycle(G));
  }

  SUBCASE("Complex - Impossible") {
    int edges[2][16] = {{0, 0, 0, 0, 1, 2, 2, 2, 4, 4, 5, 5, 6},
                        {1, 3, 5, 7, 2, 3, 5, 6, 5, 7, 6, 8, 8}};
    Graph G(9);
    for (int i = 0; i < 13; ++i) {
      add_simple_edge(G, edges[0][i], edges[1][i]);
    }
    REQUIRE_FALSE(hamiltonian_cycle(G));
  }
}