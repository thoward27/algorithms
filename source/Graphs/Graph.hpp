#pragma once
#include <vector>

/** Graph
 * A class which represents a general (di)graph with weighted edges and node
 * values. Uses an adjacency matrix to store edge connections/weights.
 * All methods that take one or more node indices will throw an error if any of
 * the nodes are out of bounds.
 */
class Graph {
 private:
 public:
  /** Constructor
   * Creates a graph with n vertices but no edges.
   * Each vertex is initialized with a value of 0.
   */
  Graph(unsigned int n);

  /** Destructor
   * Clear the memory used by the adjacency matrix and node value array.
   */
  ~Graph();

  /** node_count()
   * Returns the number of nodes in the graph.
   */
  unsigned int node_count();

  /** edge_count()
   * Returns the number of edges in the graph.
   * Two nodes connected to one another counts as two edges.
   */
  unsigned int edge_count();

  /** get_value(unsigned int v)
   * Returns the value associated with node v.
   */
  int get_value(unsigned int v);

  /** set_value(unsigned int v, int val)
   * Sets the value of node v to val.
   */
  void set_value(unsigned int v, int val);

  /** weight(unsigned int v, unsigned int w)
   * Returns the weight of the edge from node v to node w.
   * Returns 0 if the edge does not exist.
   */
  int weight(unsigned int v, unsigned int w);

  /** has_edge(unsigned int v, unsigned int w)
   * Returns true if there is an edge from node v to node w.
   * Note that has_edge(v, w) does not imply has_edge(w, v).
   */
  bool has_edge(unsigned int v, unsigned int w);

  /** add_edge(unsigned int v, unsigned int w, int weight)
   * Adds an edge from node v to node w to the graph, with the given weight.
   * If no weight is specified, it defaults to 1.
   * Self-connected nodes are not permitted, so an error is thrown when v == w.
   * Will throw an error if weight == 0. Use remove_edge instead.
   */
  void add_edge(unsigned int v, unsigned int w, int weight = 1);

  /** remove_edge(unsigned int v, unsigned int w)
   * Removes the edge from node v to node w from the graph.
   * Will throw an error if the edge does not exist.
   */
  void remove_edge(unsigned int v, unsigned int w);

  /** neighbors(unsigned int v)
   * Returns a vector containing the indices of every neighbor of the node v.
   * A node w is defined to be a neighbor of v iff there exists an edge
   * from v to w.
   */
  std::vector<int> neighbors(unsigned int v);
};