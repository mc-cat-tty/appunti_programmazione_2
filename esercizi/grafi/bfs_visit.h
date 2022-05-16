#pragma once

#include "graph.h"

/**
 * @brief Callback function that will be called inside the infix bfs visit.
 * 
 */
typedef void (*bfs_visit_callback_t) (unsigned int node_id, adj_list al);

/**
 * @brief Infix BFS visit implementation.
 * 
 * @param g input graph
 * @param start_id id of start node
 * @param c callback function that will be called inside the infix bfs visit. Can be NULL if nothing to do
 * @return array of bool (g.dim size), aka visisted
 */
bool* bfs_visit(graph g, unsigned int start_id, const bfs_visit_callback_t c);

/**
 * @brief Modified BFS visit to figure out if the g graph is connected.
 * 
 * @param g input graph
 * @param start_id id of start node
 * @return true if the graph is connected
 * @return false otherwise
 */
bool connected(graph g, unsigned int start_id);

/**
 * @brief Procedure to figure out connected components of g graph (the trees of the forest).
 * 
 * @param g input graph
 * @param v output vector (the size must be equal to g.dim) of connected components. Nodes that belong to the same tree have the same id inside v vector.
 */
void connected_components(graph g, unsigned int *v);