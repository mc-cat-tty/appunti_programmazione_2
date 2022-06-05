/*
Data la seguente definizione di grafo:
struct adj_node { int node;
oat weight; struct
adj_node* next;
};
typedef adj_node* adj_list;
typedef struct {
adj_list* nodes;
int dim;
} graph;
Scrivere la funzione bool even_path(graph g, int x, int y) che restituisce true se esiste un cammino da x a y nel grafo che
attraversa solo nodi con id pari (esclusi x e y), false altrimenti. La funzione può far uso delle primitive per i gra de nite a
lezione.
*/

#include <iostream>
#include <fstream>
#include <limits>

#include "graph.h"
#include "queue_bfs.h"

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

bool even_path(graph g, int src_id, int dst_id) {
    bool *visited = new bool[g.dim];
    int src_idx = src_id-1;
    int dst_idx = dst_id-1;
    visited[src_idx] = true;
    bfs_queue q = new_queue();
    q = enqueue(q, src_id);

    while (!is_empty_queue(q)) {
        int u_id = dequeue(q);
        int u_idx = u_id-1;

        adj_node *tmp = g.nodes[u_idx];
        while (tmp != NULL) {
            int v_id = tmp->node_id+1;
            int v_idx = v_id-1;
            
            if (!visited[v_idx]) {
                if (v_id == dst_id)
                    return true;
                if ((v_id%2) == 0) {
                    q = enqueue(q, v_id);
                    visited[v_idx] = true;
                }
            }

                
            tmp = tmp->next;
        }
    }

    return false;
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

    cout << "Even path? " << even_path(g, 1, 7) << endl;

    return 0;
}