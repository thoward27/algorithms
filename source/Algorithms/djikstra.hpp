/** Djikstra's Shortest Path
 * Finding the shortest path through a graph.
 *
 * The function takes the initial graph, and starting vertex.
 * It then constructs the minimum spanning tree to all vertices in the graph.
 * Return the resulting minimum spanning tree.
 */

#include "../Functions/functions.hpp"
#include "../Graphs/Graph.hpp"
#include "../String/String.hpp"

Graph dijkstras(Graph& G, unsigned int vertex) {
  // Initialize helpers.
  bool *kwn = new bool[G.node_count()]();
  long int cst[G.node_count()], pth[G.node_count()];

  for (unsigned int i = 0; i < G.node_count(); ++i) {
    cst[i] = INT_MAX;
    pth[i] = -1;
  }

  // Set our vertex cost to 0.
  cst[vertex] = 0;

  // Process all nodes.
  while (!all(kwn, G.node_count())) {
    kwn[vertex] = true;
    std::vector<int> neigh;
    neigh = G.neighbors(vertex);  // Start at 0

    for (int i : neigh) {
      if (!kwn[i] &&
          cst[vertex] + G.weight(vertex, i) < cst[i]) {
        cst[i] = cst[vertex] + G.weight(vertex, i);
        pth[i] = vertex;
      }
    }

    long int tmp = INT_MAX;
    for (unsigned int i = 0; i < G.node_count(); ++i) {
      if (!kwn[i] && cst[i] < tmp) {
        tmp = i;
      }
    }
    // Update vertex
    vertex = tmp;
  }

  // Build minimum spanning tree.
  Graph tmp(G.node_count());
  for (unsigned int i = 1; i < G.node_count(); ++i) {
    if (!tmp.has_edge(pth[i], i)) {
      tmp.add_edge(pth[i], i, G.weight(pth[i], i));  // 1, 0,
    }
  }

  delete[] kwn;
  return tmp;
}