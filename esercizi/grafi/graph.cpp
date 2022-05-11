#include "graph.h"

static int convert_id_to_index(int id) {
    return (id-1);
}

static int convert_index_to_id(int index) {
    return (index+1);
}

graph new_graph(size_t n) {
    graph g = {
        .dim = n,
        .nodes = new adj_list[n]
    };
    return g;
}

void add_arc(graph &g, int s, int d, float w) {
    adj_node *new_node = new adj_node;
    new_node->node_id = convert_id_to_index(s);
    new_node->weight = w;
    new_node->next = g.nodes[convert_id_to_index(s)];
    g.nodes[convert_id_to_index(s)] = new_node;
}

void add_edge(graph &g, int s, int d, float w) {
    add_arc(g, s, d, w);
    add_arc(g, d, s, w);
}

inline size_t get_dim(graph g) {
    return g.dim;
}

inline adj_list get_adj_list(graph g, int id) {
    return g.nodes[convert_id_to_index(id)];
}

inline int get_adj_node(adj_node *node) {
    return convert_index_to_id(node->node_id);
}

inline adj_list get_next_adj(adj_list l) {
    return l->next;
}

void print_graph(graph g) {
    ;  // TODO
}