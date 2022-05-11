#include <iostream>
#include <fstream>
#include <limits>

#include "graph.h"

using namespace std;

const int EXPECTED_ARGS = 4;

graph g_build(ifstream &file, bool directed, bool weighted) {
    int dim;
    file >> dim;
    graph g = new_graph(dim);

    void (*add_arc_edge) (graph&, int, int, float);
    if (weighted)  // register function pointer
        add_arc_edge = add_edge;
    else
        add_arc_edge = add_arc;

    int tmp_s, tmp_d, tmp_w;
    for (int i=0; i<g.dim; i++) {
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

    return 0;
}