/** Djikstra's Shortest Path
 * Finding the shortest path through a graph.
 *
 * The function takes the initial graph, and starting vertex.
 * It then constructs the minimum spanning tree to all vertices in the graph.
 * Return the resulting minimum spanning tree.
 */

#include "../Graphs/Graph.hpp"
#include "../String/String.hpp"

Graph djikstras(Graph& G, int vertex);
