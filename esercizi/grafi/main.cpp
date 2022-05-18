#include <iostream>
#include <fstream>
#include <limits>

#include "graph.h"
#include "bfs_visit.h"

using namespace std;

const int EXPECTED_ARGS = 4;

graph g_build(ifstream &file, bool directed, bool weighted) {
    int dim;
    file >> dim;
    graph g = new_graph(dim);

    void (*add_arc_edge) (graph&, int, int, float);
    if (weighted)  // register function pointer
        add_arc_edge = add_arc;
    else
        add_arc_edge = add_edge;

    int tmp_s, tmp_d, tmp_w;
    while (!file.eof()) {
        file >> tmp_s >> tmp_d;
        tmp_w = 1;
        if (weighted)
            file >> tmp_w;
        else
            file.ignore(numeric_limits<streamsize>::max(), '\n');
        
        add_arc_edge(g, tmp_s, tmp_d, tmp_w);
    }

    return g;
}

void print_callback(unsigned int node_id, adj_list adj_l) {
    cout << "Node " << node_id << " is connected to ";
    while (adj_l != NULL) {
        int u_id = get_adj_node(adj_l);
        cout << u_id << " ";
        adj_l = get_next_adj(adj_l);
    }
    cout << endl;
}

void print_connected_components(unsigned int *cc, int dim) {
    for (int i=0; i<dim; i++)
        cout << i+1 << " is belongs to tree number " << cc[i] << endl;
}

void print_parent_array(graph g, int *parent) {
    cout << "parent array: ";
    for (int i=0; i<g.dim; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[]) {
    if (argc < EXPECTED_ARGS) {
        cerr << "Exptected 4 arguments" << endl;
        return 1;
    }

    ifstream f(argv[1]);
    int d = atoi(&argv[2][0]);
    int w = atoi(&argv[3][0]);
    graph g = g_build(f, d, w);

    print_graph(g);
    cout << endl;

    bfs_visit(g, 1, print_callback);
    cout << endl;
    
    const unsigned int connected_start_idx = 6;  // the graph should not be connected
    // const unsigned int connected_start_idx = 1;  // the graph should be connected
    cout << "The graph is " << (connected(g, connected_start_idx) ? "connected" : "not connected") << endl << endl;

    unsigned int connected_components_v[g.dim];
    connected_components(g, connected_components_v);
    print_connected_components(connected_components_v, g.dim);

    print_parent_array(g, bfs_tree(g, connected_start_idx));

    return 0;
}