#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "graph_algorithms.hpp"

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

/** free_maze(int** maze, int n)
 * Frees all memory used by maze of length n.
 */
void free_maze(int** maze, int n) {
  for (int i = 0; i < n; ++i) {
    delete[] maze[i];
  }
  delete[] maze;
}

TEST_CASE("solve_maze") {
  SUBCASE("Trivial") {
    int** maze = new int*[1];
    maze[0] = new int[1];
    maze[0][0] = 1;
    REQUIRE(solve_maze(maze, 1));
    free_maze(maze, 1);
  }

  SUBCASE("Smallest Unsolvable - No Moves") {
    int** maze = new int*[2];
    maze[0] = new int[2];
    maze[1] = new int[2];
    maze[0][0] = maze[1][1] = 1;
    maze[0][1] = maze[1][0] = 0;
    REQUIRE_FALSE(solve_maze(maze, 2));
    free_maze(maze, 2);
  }

  SUBCASE("Smallest Unsolvable - Blocked Exit") {
    int** maze = new int*[2];
    maze[0] = new int[2];
    maze[1] = new int[2];
    maze[0][0] = maze[0][1] = maze[1][0] = 1;
    maze[1][1] = 0;
    REQUIRE_FALSE(solve_maze(maze, 2));
    free_maze(maze, 2);
  }

  SUBCASE("Empty Maze") {
    int** maze = new int*[8];
    for (int i = 0; i < 8; ++i) {
      maze[i] = new int[8];
      for (int j = 0; j < 8; ++j)
        maze[i][j] = 1;
    }
    REQUIRE(solve_maze(maze, 8));
    free_maze(maze, 8);
  }

  SUBCASE("Only Solvable Going Left") {
    int** maze = new int*[5];
    for (int i = 0; i < 5; ++i) {
      maze[i] = new int[5]();
    }
    int free_cells[2][11] = {{0, 0, 0, 0, 0, 1, 2, 2, 3, 4, 4},
                             {0, 1, 2, 3, 4, 4, 4, 3, 3, 3, 4}};
    for (int i = 0; i < 11; ++i) {
      maze[free_cells[0][i]][free_cells[1][i]] = 1;
    }
    REQUIRE_FALSE(solve_maze(maze, 5));
    free_maze(maze, 5);
  }

  SUBCASE("One Path") {
    int** maze = new int*[7];
    for (int i = 0; i < 7; ++i) {
      maze[i] = new int[7]();
    }
    int free_cells[2][13] = {{0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6},
                             {0, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 6}};
    for (int i = 0; i < 13; ++i) {
      maze[free_cells[0][i]][free_cells[1][i]] = 1;
    }
    REQUIRE(solve_maze(maze, 7));
    free_maze(maze, 7);
  }

  SUBCASE("Multiple Paths - One Correct") {
    int** maze = new int*[7];
    for (int i = 0; i < 7; ++i) {
      maze[i] = new int[7]();
    }
    int free_cells[2][26] = {{0, 0, 1, 2, 3, 4, 4, 4, 5, 5, 5, 6, 4,
                              5, 6, 6, 6, 0, 0, 1, 1, 1, 1, 2, 3, 6},
                             {0, 1, 1, 1, 1, 2, 3, 4, 4, 5, 6, 6, 1,
                              1, 1, 2, 3, 2, 3, 3, 4, 5, 6, 5, 5, 4}};
    for (int i = 0; i < 26; ++i) {
      maze[free_cells[0][i]][free_cells[1][i]] = 1;
    }
    REQUIRE(solve_maze(maze, 7));
    free_maze(maze, 7);
  }

  SUBCASE("Multiple Paths - None Correct") {
    int** maze = new int*[7];
    for (int i = 0; i < 7; ++i) {
      maze[i] = new int[7]();
    }
    int free_cells[2][29] = {{0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 5, 6, 4, 5, 6,
                              6, 6, 0, 0, 1, 1, 1, 1, 2, 3, 6, 2, 3, 4},
                             {0, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 1, 1, 1,
                              2, 3, 2, 3, 3, 4, 5, 6, 5, 5, 4, 6, 6, 6}};
    for (int i = 0; i < 29; ++i) {
      maze[free_cells[0][i]][free_cells[1][i]] = 1;
    }
    REQUIRE_FALSE(solve_maze(maze, 7));
    free_maze(maze, 7);
  }
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