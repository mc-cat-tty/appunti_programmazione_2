#pragma once

#include <cstdlib>

struct adj_node {
    int node_id;
    float weight;
    adj_node *next;
};
typedef adj_node* adj_list;  /**< adj_list is a linked list of adj_node(s) */

struct graph {
    size_t dim;
    adj_list* nodes;
};

/**
 * @brief Build a new graph of n nodes and returns it
 * 
 * @param n number of nodes
 * @return graph just built graph
 */
graph new_graph(size_t n);

/**
 * @brief Add a directed arc to g
 * 
 * @param g input graph
 * @param s source node
 * @param d destination node
 * @param w weight
 */
void add_arc(graph &g, int s, int d, float w);

/**
 * @brief Add undirected edge to g
 * 
 * @param g input graph
 * @param s source node
 * @param d destination node
 * @param w weigth
 */
void add_edge(graph &g, int s, int d, float w);

/**
 * @brief Get the dim of the graph
 * 
 * @param g input graph
 * @return size_t graph's dim
 */
size_t get_dim(graph g);

/**
 * @brief Get the adj list of node id
 * 
 * @param g input graph
 * @param id node's id
 * @return adj_list adjacency list of node id
 */
adj_list get_adj_list(graph g, int id);

/**
 * @brief Get the id of node
 * 
 * @param node input adjacency node
 * @return int id stored in node
 */
int get_adj_node(adj_node *node);

/**
 * @brief Get the tail of l
 * 
 * @param l input adjacency list
 * @return adj_list tail of l
 */
adj_list get_next_adj(adj_list l);

/**
 * @brief Print graph g
 * 
 * @param g input graph
 */
void print_graph(graph g);