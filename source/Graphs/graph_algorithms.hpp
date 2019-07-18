#pragma once
#include "Graph.hpp"

#define UNVISITED 0
#define VISITED 1

/** solve_maze(int** maze, int n)
 * Decides whether the maze is solvable from position (0, 0) by making a call
 * to the recursive function by the same name.
 */
bool solve_maze(int** maze, int n);

/** solve_maze(int** maze, int n)
 * Recursively decides whether the maze is solvable from the given position
 * using backtracking.
 * A maze is solvable if position (n - 1, n - 1)  may be reached from the given
 * position by only moving downward and to the right, but not both at once
 * (i.e. not diagonally).
 * A position in the maze is valid to move to only if it contains a 1.
 */
bool solve_maze(int** maze, int n, int position[2]);

/** hamiltonian_cycle(Graph& G)
 * Decides whether there exists a hamiltonian cycle in G by making a call to the
 * recursive function by the same name.
 */
bool hamiltonian_cycle(Graph& G);

/** hamiltonain_cycle(Graph& G, unsigned int v, unsigned int path_len)
 * Recursively searches for a Hamiltonain cycle in G, returning true if one is
 * found and false otherwise.
 * Each call assumes that path_len number of edges have been found so far, and
 * attempts to add an unvisited vertex to the cycle.
 * A cycle is successfully found when the last unvisited node has been visited
 * (i.e. when path_len is one less than the number of nodes) and an edge is
 * found from the final node to the start node.
 * You may use VISITED and UNVISITED to mark nodes as one or the other.
 *      e.g. G.set_node(0, VISITED);
 */
bool hamiltonian_cycle(Graph& G, unsigned int v, unsigned int path_len);