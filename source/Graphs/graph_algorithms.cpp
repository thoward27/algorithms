#include "graph_algorithms.hpp"
#include <iostream>

bool solve_maze(int** maze, int n) {
  int start[2] = {0, 0};
  return solve_maze(maze, n, start);
}

bool solve_maze(int** maze, int n, int position[2]) {
  if (position[0] == n - 1 && position[1] == n - 1)
    return true;

  bool result;
  ++(position[1]);
  if (position[1] < n && maze[position[0]][position[1]] == 1) {
    result = solve_maze(maze, n, position);
    if (result)
      return true;
  }
  --(position[1]);
  ++(position[0]);
  if (position[0] < n && maze[position[0]][position[1]] == 1) {
    result = solve_maze(maze, n, position);
    if (result)
      return true;
  }
  --(position[0]);
  return false;
}

bool hamiltonian_cycle(Graph& G) {
  return hamiltonian_cycle(G, 0, 0);
}

bool hamiltonian_cycle(Graph& G, unsigned int v, unsigned int path_len) {
  if (path_len == G.node_count() - 1) {
    std::vector<int> neighbors = G.neighbors(v);
    for (unsigned int i = 0; i < neighbors.size(); ++i) {
      if (neighbors[i] == 0) {
        return true;
      }
    }
    return false;
  }
  G.set_value(v, VISITED);
  std::vector<int> neighbors = G.neighbors(v);
  bool result = false;
  for (unsigned int i = 0; i < neighbors.size(); ++i) {
    if (G.get_value(neighbors[i]) == UNVISITED) {
      result = hamiltonian_cycle(G, neighbors[i], ++path_len);
      if (result)
        return true;
      --path_len;
      G.set_value(neighbors[i], UNVISITED);
    }
  }
  return false;
}