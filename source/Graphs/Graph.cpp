#include "Graph.hpp"
#include <iostream>

Graph::Graph(unsigned int n)
{
    if (n <= 0)
    {
        throw "Error";
    }
    count_edge = 0;
    count_node = n;
    value = new unsigned int[n];
    for (size_t i = 0; i < count_node; i++)
    {
        value[i] = 0;
    }

    for (size_t i = 0; i < n; i++)
    {
        std::vector<unsigned int> temp;
        for (size_t i = 0; i < n; i++)
        {
            temp.push_back(0);
        }
        array.push_back(temp);
    }
}

/** Destructor
   * Clear the memory used by the adjacency matrix and node value array.
   */
Graph::~Graph()
{
    array.clear();
    delete[] value;
    count_edge = 0;
    count_node = 0;
}
/** node_count()
   * Returns the number of nodes in the graph.
   */
unsigned int Graph::node_count()
{
    return count_node;
}

void Graph::print()
{
    for (size_t i = 0; i < array.size(); i++)
    {
        for (size_t j = 0; j < array[i].size(); j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/** edge_count()
   * Returns the number of edges in the graph.
   * Two nodes connected to one another counts as two edges.
   */
unsigned int Graph::edge_count()
{
    return count_edge;
}

/** get_value(unsigned int v)
   * Returns the value associated with node v.
   */
int Graph::get_value(unsigned int v)
{
    if (v >= count_node)
    {
        throw "Error";
    }
    return value[v];
}

/** set_value(unsigned int v, int val)
   * Sets the value of node v to val.
   */
void Graph::set_value(unsigned int v, int val)
{
    if (v >= count_node)
    {
        throw "Error";
    }
    value[v] = val;
}

/** weight(unsigned int v, unsigned int w)
   * Returns the weight of the edge from node v to node w.
   * Returns 0 if the edge does not exist.
   */
int Graph::weight(unsigned int v, unsigned int w)
{
    if (v >= count_node || w >= count_node)
    {
        throw "Error";
    }
    return array[v][w];
}

/** has_edge(unsigned int v, unsigned int w)
   * Returns true if there is an edge from node v to node w.
   * Note that has_edge(v, w) does not imply has_edge(w, v).
   */
bool Graph::has_edge(unsigned int v, unsigned int w)
{
    if (v >= count_node || w >= count_node)
    {
        throw "Error";
    }
    if (array[v][w] > 0)
        return 1;
    return 0;
}

/** add_edge(unsigned int v, unsigned int w, int weight)
   * Adds an edge from node v to node w to the graph, with the given weight.
   * If no weight is specified, it defaults to 1.
   * Self-connected nodes are not permitted, so an error is thrown when v == w.
   * Will throw an error if weight == 0. Use remove_edge instead.
   */
void Graph::add_edge(unsigned int v, unsigned int w, int weight)
{
    if (v == w || weight == 0 || v >= count_node || w >= count_node)
    {
        throw "Error";
    }
    array[v][w] = weight;
    count_edge++;
}

/** remove_edge(unsigned int v, unsigned int w)
   * Removes the edge from node v to node w from the graph.
   * Will throw an error if the edge does not exist.
   */
void Graph::remove_edge(unsigned int v, unsigned int w)
{
    if (v >= count_node || w >= count_node)
    {
        throw "Error";
    }
    if (!has_edge(v, w))
    {
        throw "No edge";
    }
    array[v][w] = 0;
    count_edge--;
}

/** neighbors(unsigned int v)
   * Returns a vector containing the indices of every neighbor of the node v.
   * A node w is defined to be a neighbor of v if there exists an edge
   * from v to w.
   */
std::vector<int> Graph::neighbors(unsigned int v)
{

    std::vector<int> hood;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (has_edge(v, i))
        {
            hood.push_back(i);
        }
    }
    return hood;
}