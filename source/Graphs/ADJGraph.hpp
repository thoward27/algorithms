#pragma once
#include <vector>


/** Graph
 * A class which represents a general directed graph with edges and node values,
 * following the adjacency list method. Operates on an array of linked lists with 
 * indexs in the array representing vertices and the elements of that index's linked list
 * represent verticies that vertex has an edge with.
 */
class Graph {
private:
    std::vector<int>* list;
    std::vector<int>* weights;
    int* node_values;
    unsigned int num_nodes;
    unsigned int num_edges;

public:
    /** Constructor
     * Creates a graph with n vertices
     * each list is initalized as empty and 
     * each vertex has an intial value of 0
     */
    Graph(unsigned int n);

    /** Destructor
     * Clean up dynamically allocated memory
     */
    ~Graph();

    /** node_count()
     * Returns the number of vertices in the graph by returning 
     * the data member num_nodes 
     */
    unsigned int node_count();

    /** edge_count()
     * Returns the number of edges in the graph by returning 
     * the data member num_edges 
     */
    unsigned int edge_count();

    /** set(unsigned int vertex, int value)
     * Assigns a value to a vertex
     */
    void set_value(unsigned int v, int val);
    
    /** get_value(unsigned int vertex)
     * Returns the value of the given vertex
     */
    int get_value(unsigned int vertex);

    /** weight(unsigned int v, unsigned int w)
     * Returns the weight of the edge from node v to node w.
     * Returns 0 if the edge does not exist.
     */
    int weight(unsigned int v, unsigned int w);

    /** add_edge(unsigned int v, unsigned int w)
     * Adds an edge between vertex v and vertex w by adding the 
     * other vertex's value to their respective LinkedList
     */
    void add_edge(unsigned int v, unsigned int w, int weight = 1);

    /** remove_edge(unsigned int v, unsigned int w)
     * Removes the edge between vertex v and vertex w
     */
    void remove_edge(unsigned int v, unsigned int w);

    /** has_edge(unsigned int v, unsigned int w)
     * Returns true if there is a edge between vertex v and vertex w
     */
    bool has_edge(unsigned int v, unsigned int w);

    /** neighbors(unsigned int vertex)
     * returns the linked list at index vertex, representing all neighbors 
     * of the vertex at that index
     */
    std::vector<int> neighbors(unsigned int v);
};