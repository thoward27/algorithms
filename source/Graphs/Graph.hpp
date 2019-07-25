#pragma once
#include <vector>

/** Graph
 * A class which represents a general directed graph with weighted edges and
 * node values. All methods that take one or more node indices will throw an
 * error if any of the nodes are out of bounds.
 */
class Graph {
 private:
  int** matrix;
  int* node_values;
  unsigned int num_nodes;
  unsigned int num_edges;

 public:
  /** Constructor
   * Creates a graph with n vertices but no edges.
   * Each vertex is initialized with a value of 0.
   *
   * Inputs:
   * @param n: an integer representing number of vertices
   *
   * Outputs:
   * Generates an adjacency matrix model for a graph
   *
   * Examples:
   * Graph test(10) makes a graph with ten vertices
   *
   * Runtime:
   * O(?)
   */
  explicit Graph(unsigned int n);

  /** Destructor
   * Clear the memory used by the adjacency matrix and node value array.
   *
   * Side Effects:
   * Frees any dynamically allocated memory
   */
  ~Graph();

  /** node_count()
   * Returns the number of nodes in the graph.
   *
   * Outputs:
   * The value of the internal data member num_nodes, representing
   * the number of nodes in the graph
   *
   * Examples:
   * Graph test(10)
   * test.node_count() == 10
   *
   * Runtime:
   * O(1)
   */
  unsigned int node_count();

  /** edge_count()
   * Returns the number of edges in the graph.
   * Two nodes connected to one another counts as two edges.
   *
   * Outputs:
   * The value of the internal data member num_edges, representing
   * the number of edges in the graph
   *
   * Examples:
   * Graph test(10);
   * test.add_edge(0, 1)
   * test.edges_count() == 1
   *
   * Runtime:
   * O(1)
   */
  unsigned int edge_count();

  /** get_value(unsigned int v)
   * Returns the value associated with node v.
   *
   * Inputs:
   * @param v: The vertex to get data from
   *
   * Outputs:
   * The integer value assigned to the vertex (default: 0)
   *
   * Examples:
   * graph test(5)
   * test.set_value(3,10)
   * test.get_value(3) == 10
   *
   * Runtime:
   * O(1)
   */
  int get_value(unsigned int v);

  /** set_value(unsigned int v, int val)
   * Sets the value of node v to val.
   *
   * Inputs:
   * @param v: vertex to assign val param to
   * @param val: value to assign to vertex v
   *
   * Side Effects:
   * Assigns vertex v with the value of val
   *
   * Examples:
   * graph test(5)
   * test.set_value(3,10)
   * test.get_value(3) == 10
   *
   * Runtime:
   * O(1)
   */
  void set_value(unsigned int v, int val);

  /** weight(unsigned int v, unsigned int w)
   * Returns the weight of the edge from node v to node w.
   * Returns 0 if the edge does not exist.
   *
   * Inputs:
   * @param v: vertex on one side of the desired edge
   * @param w: vertex on the other side of the desired edge
   *
   * Outputs:
   * The weight the edge was initialized with (default: 1)
   *
   * Examples:
   * graph test(10)
   * test.add_edge(1, 4, 10)
   * test.weight(1, 4) == 10
   *
   * Runtime:
   * O(1)
   */
  int weight(unsigned int v, unsigned int w);

  /** has_edge(unsigned int v, unsigned int w)
   * Returns true if there is an edge from node v to node w.
   * Note that has_edge(v, w) does not imply has_edge(w, v).
   *
   * Inputs:
   * @param v: vertex on one side of the desired edge
   * @param w: vertex on the other side of the desired edge
   *
   * Outputs:
   * True if an edge exists between vertex v and vertex w
   * False otherwise
   *
   * Examples:
   * graph test(10)
   * test.add_edge(1, 4)
   * test.has_edge(1, 4) == 1, test.has_edge(1, 5) == 0
   *
   * Runtime:
   * O(1)
   */
  bool has_edge(unsigned int v, unsigned int w);

  /** add_edge(unsigned int v, unsigned int w, int weight)
   * Adds an edge from node v to node w to the graph, with the given weight.
   * If no weight is specified, it defaults to 1.
   * Self-connected nodes are not permitted, so an error is thrown when v == w.
   * Will throw an error if weight == 0. Use remove_edge instead.
   *
   * Inputs:
   * @param v: vertex on one side of the desired edge
   * @param w: vertex on the other side of the desired edge
   * @param weight: value to assign to the weight of the edge
   *
   * Side Effects:
   * Creates n edge between the two vertices with the given weight
   *
   * Examples:
   * graph test(10)
   * test.add_edge(1, 4, 10)
   *
   * Runtime:
   * O(1)
   */
  void add_edge(unsigned int v, unsigned int w, int weight = 1);

  /** remove_edge(unsigned int v, unsigned int w)
   * Removes the edge from node v to node w from the graph.
   * Will throw an error if the edge does not exist.
   *
   * Inputs:
   * @param v: vertex on one side of the desired edge
   * @param w: vertex on the other side of the desired edge
   *
   * Side Effects:
   * Removes the edge between vertex v and vertex w
   *
   * Examples:
   * graph test(10)
   * test.add_edge(1, 4)
   * test.has_edge(1, 4) == 1
   * test.remove_edge(1,4)
   * test.has_edge(1, 4) == 0
   *
   * Runtime:
   * O(1)
   */
  void remove_edge(unsigned int v, unsigned int w);

  /** neighbors(unsigned int v)
   * Returns a vector containing the indices of every neighbor of the node v.
   * A node w is defined to be a neighbor of v iff there exists an edge
   * from v to w.
   *
   * Inputs:
   * @param v: vertex to return the neighbors of
   *
   * Outputs:
   * A vector representing the index of all of vertex v's
   * neighbors(vertices it shares edges with)
   *
   * Examples:
   * Graph test(10)
   * test.add_edge(1,4)
   * test.add_edge(1,5)
   * test.add_edge(1,6)
   * test.neighbors(1) == [4,5,6]
   */
  std::vector<int> neighbors(unsigned int v);
};