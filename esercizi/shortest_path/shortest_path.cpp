#include "shortest_path.h"

#include "priority_queue.h"

#include <iostream>
#include <limits>

static void initialize(unsigned *dist, unsigned *parent_ids, size_t dim) {
    for (int i=0; i<dim; i++) {
        parent_ids[i] = 0;
        dist[i] = std::numeric_limits<unsigned>::max();
    }
}

static void dijkstra_relax(int current_node_id, int dest_node_id, int edge_weight, const graph g, unsigned *parent_ids, unsigned *dist, priority_queue &q_ids) {
    int dest_node_idx = dest_node_id-1;
    int current_node_idx = current_node_id-1;

    if (dist[dest_node_idx] > dist[current_node_idx]+edge_weight) {
        dist[dest_node_idx] = dist[current_node_idx]+edge_weight;
        parent_ids[dest_node_idx] = current_node_id;
        q_ids = decrease_priority(q_ids, dest_node_id, dist[dest_node_idx]);
    }
}

static void prim_relax(int current_node_id, int dest_node_id, int edge_weight, const graph g, unsigned *parent_ids, unsigned *dist, priority_queue &q_ids) {
    int dest_node_idx = dest_node_id-1;
    int current_node_idx = current_node_id-1;

    if (dist[dest_node_idx] > edge_weight) {
        dist[dest_node_idx] = edge_weight;
        parent_ids[dest_node_idx] = current_node_id;
        q_ids = decrease_priority(q_ids, dest_node_id, dist[dest_node_idx]);
    }
}

unsigned* dijkstra(graph g, unsigned s_id) {
    unsigned *parent_ids = new unsigned[g.dim];
    unsigned *dist = new unsigned[g.dim];

    unsigned s_idx = s_id-1;
    initialize(dist, parent_ids, g.dim);
    dist[s_idx] = 0;

    priority_queue q_ids = nullptr;
    for (int i=0; i<g.dim; i++) {
        q_ids = enqueue(q_ids, i+1, dist[i]);  // i+1 because we want ids inside the queue and not indexes
    }

    while (!is_empty_queue(q_ids)) {
        int u_id = dequeue(q_ids);
        int u_idx = u_id-1;
        adj_node *v = g.nodes[u_idx];
        while (v != NULL) {  // for all (u, v) € E
            int v_id = get_adj_node(v);
            dijkstra_relax(u_id, v_id, v->weight, g, parent_ids, dist, q_ids);
            v = get_next_adj(v);
        }
    }
    
    delete[] dist;
    return parent_ids;
}

unsigned* prim(graph g, unsigned s_id) {
    unsigned *parent_ids = new unsigned[g.dim];
    unsigned *dist = new unsigned[g.dim];

    unsigned s_idx = s_id-1;
    initialize(dist, parent_ids, g.dim);
    dist[s_idx] = 0;

    priority_queue q_ids = nullptr;
    for (int i=0; i<g.dim; i++) {
        q_ids = enqueue(q_ids, i+1, dist[i]);  // i+1 because we want ids inside the queue and not indexes
    }

    while (!is_empty_queue(q_ids)) {
        int u_id = dequeue(q_ids);
        int u_idx = u_id-1;
        adj_node *v = g.nodes[u_idx];
        while (v != NULL) {  // for all (u, v) € E
            int v_id = get_adj_node(v);
            prim_relax(u_id, v_id, v->weight, g, parent_ids, dist, q_ids);
            v = get_next_adj(v);
        }
    }

    delete[] dist;
    return parent_ids;
}