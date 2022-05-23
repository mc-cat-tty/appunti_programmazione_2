#include <iostream>
#include <fstream>
#include <limits>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"


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

void print_parent_array(graph g, int *parent) {
    cout << "parent array: ";
    for (int i=0; i<g.dim; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[]) {
    cout << "File modificato" << endl;

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
    
    const unsigned int dijkstra_start_idx = 6;

    priority_queue q = nullptr;
    q = enqueue(q, 1, 10.1);
    q = enqueue(q, 2, 20.2);
    q = enqueue(q, 3, 30.3);
    q = enqueue(q, 4, 15.4);
    q = enqueue(q, 5, 25.5);
    print_queue(q);
    q = decrease_priority(q, 1, 0.5);
    q = decrease_priority(q, 5, 9.);
    q = decrease_priority(q, 3, 1.);
    print_queue(q);
    cout << "Empty? " << is_empty_queue(q) << endl;
    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;
    cout << dequeue(q) << endl;
    cout << "Empty? " << is_empty_queue(q) << endl;
    print_queue(q);

    if (d) {  // if the graph is directed
        cout << "DIJKSTRA" << endl;
        cout << "Shortest-path tree is: ";
        unsigned *parent = dijkstra(g, 1);
        for (int i=0; i<g.dim; i++)
            if (parent[i] == 0)
                cout << "\\ ";
            else
            cout << parent[i] << " ";
        cout << endl;
    }
    else {  // undirected graph
        cout << "PRIM" << endl;
        cout << "Minimum spanning tree is: ";
        unsigned *parent = prim(g, 1);
        for (int i=0; i<g.dim; i++)
            if (parent[i] == 0)
                cout << "\\ ";
            else
            cout << parent[i] << " ";
        cout << endl;
    }

    return 10;
}