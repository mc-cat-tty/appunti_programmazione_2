#pragma once

#include "graph.h"

/**
 * @brief Runs Dijkstra algorithm on graph g and returns the shortest path tree
 * 
 * @param g input graph
 * @param s_id source node's id
 * @return unsigned* pointer to parent vector of size g.dim
 */
unsigned* dijkstra(graph g, unsigned s_id);

/**
 * @brief Runs Prim algorithm on undirected graph g and returns minimum spanning tree
 * 
 * @param g input graph
 * @param s_id source node's id
 * @return unsigned* pointer to parent vector of size g.dim
 */
unsigned* prim(graph g, unsigned s_id);