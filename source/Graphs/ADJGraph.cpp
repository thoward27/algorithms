#include "ADJGraph.hpp"

Graph::Graph(unsigned int size) {
    if (!size) throw "Graph cannot contain zero vertices";
    list = new std::vector<int>[size];
    weights = new std::vector<int>[size];
    node_values = new int[size]();
    num_nodes = size;
    num_edges = 0;
}

Graph::~Graph() {
    delete[] list;
    delete[] weights;
    delete[] node_values;
}

unsigned int Graph::node_count(){
    return num_nodes;
}

unsigned int Graph::edge_count() {
    return num_edges;
}

void Graph::set_value(unsigned int v, int value) {
    if (v >= num_nodes) throw "Vertex out of bounds";
    node_values[v] = value;
}

int Graph::get_value(unsigned int vertex) {
    if (vertex >= num_nodes) throw "Vertex out of bounds";
    return node_values[vertex];
}

int Graph::weight(unsigned int v, unsigned int w) {
    if(v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
    std::vector<int>::iterator iter = list[v].begin();
    std::vector<int>::iterator weightiter = weights[v].begin();
    for(iter, weightiter ; iter != list[v].end() ; ++iter, ++weightiter) {
        if(*iter == w) {
            break;
        }
    }
    if(weightiter == weights[v].end()) throw "Edge does not exist";
    return *weightiter;
}

void Graph::add_edge(unsigned int v, unsigned int w, int weight) {
    if(v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
    if(v == w) throw "Self-connected edges are not permitted";
    if (!weight) throw "Weight cannot be zero";
    list[v].push_back(w);
    weights[v].push_back(weight);
    ++num_edges;
}

void Graph::remove_edge(unsigned int v, unsigned int w) {
    if(v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
    std::vector<int>::iterator iter = list[v].begin();
    std::vector<int>::iterator weightiter = weights[v].begin();
    for(iter, weightiter ; iter != list[v].end() ; ++iter, ++weightiter) {
        if(*iter == w) {
            break;
        }
    }
    if(iter == list[v].end()) throw "Edge does not exist";
    list[v].erase(iter);
    weights[v].erase(weightiter);
    --num_edges;
}

bool Graph::has_edge(unsigned int v, unsigned int w) {
    if(v >= num_nodes || w >= num_nodes) throw "Vertex out of bounds";
    std::vector<int>::iterator iter = list[v].begin();
    for(iter ; iter != list[v].end() ; ++iter) {
        if(*iter == w) {
            break;
        }
    }
    return (iter == list[v].end()) ? false : true;
}

std::vector<int> Graph::neighbors(unsigned int v) {
    if (v >= num_nodes) throw "Vertex out of bounds";
    return list[v];
}
