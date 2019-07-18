#include "Graph.hpp"
#include <iostream>

Graph::Graph(unsigned int n) {
  if (!n)
    throw "Graph cannot contain zero vertices";
  matrix = new int*[n];
  // Note: new int[n]() initializes values to zero
  for (unsigned int i = 0; i < n; ++i) {
    matrix[i] = new int[n]();
  }
  node_values = new int[n]();
  num_nodes = n;
  num_edges = 0;
}

Graph::~Graph() {
  delete[] node_values;
  for (unsigned int i = 0; i < num_nodes; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

unsigned int Graph::node_count() {
  return num_nodes;
}

unsigned int Graph::edge_count() {
  return num_edges;
}

int Graph::get_value(unsigned int v) {
  if (v >= num_nodes)
    throw "Vertex out of bounds";
  return node_values[v];
}

void Graph::set_value(unsigned int v, int val) {
  if (v >= num_nodes)
    throw "Vertex out of bounds";
  node_values[v] = val;
}

bool Graph::has_edge(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  return matrix[v][w];
}

int Graph::weight(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  return matrix[v][w];
}

void Graph::add_edge(unsigned int v, unsigned int w, int weight) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  if (!weight)
    throw "Weight cannot be zero";
  if (v == w)
    throw "Self-connected edges are not permitted";
  matrix[v][w] = weight;
  ++num_edges;
}

void Graph::remove_edge(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  if (!matrix[v][w])
    throw "Edge does not exist";
  matrix[v][w] = 0;
  --num_edges;
}

std::vector<int> Graph::neighbors(unsigned int v) {
  if (v >= num_nodes)
    throw "Vertex out of bounds";
  std::vector<int> neighbor_nodes;
  for (unsigned int i = 0; i < num_nodes; ++i) {
    if (matrix[v][i])
      neighbor_nodes.push_back(i);
  }
  return neighbor_nodes;
}