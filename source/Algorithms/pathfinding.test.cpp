#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "pathfinding.hpp"

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