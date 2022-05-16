#include "graph.h"

#include <iostream>

static inline int convert_id_to_index(int id) {
    return (id-1);
}

static inline int convert_index_to_id(int index) {
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
    new_node->node_id = convert_id_to_index(d);
    new_node->weight = w;
    new_node->next = g.nodes[convert_id_to_index(s)];
    g.nodes[convert_id_to_index(s)] = new_node;
}

void add_edge(graph &g, int s, int d, float w) {
    using namespace std;
    add_arc(g, s, d, w);
    add_arc(g, d, s, w);
}

size_t get_dim(graph g) {
    return g.dim;
}

adj_list get_adj_list(graph g, int id) {
    return g.nodes[convert_id_to_index(id)];
}

int get_adj_node(adj_node *node) {
    return convert_index_to_id(node->node_id);
}

adj_list get_next_adj(adj_list l) {
    return l->next;
}

void print_graph(graph g) {
    using namespace std;

    for (int i=0; i<g.dim; i++) {
        cout << convert_index_to_id(i) << " connected to ";
        adj_list al = g.nodes[i];
        while (al != NULL) {
            cout << get_adj_node(al) << " ";
            al = get_next_adj(al);
        }
        cout << endl;
    }
}