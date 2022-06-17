#include <iostream>
#include <fstream>

#include "grafi.h"
#include "node.h"
#include "coda.h"

using namespace std;

const static int MIN_ARGC = 3;  // exec, graph_filename, node_filename

void debug_print(const char *str) {
    #ifdef DEBUG
    cout << str << endl;
    #endif
}

bool load_graph(const char *filename, graph &g) {
    debug_print("entering load graph");
    ifstream file(filename);
    if (!file.is_open())
        return false;

    int dim; file >> dim;
    g = new_graph(dim);

    debug_print("g built");
    int u, v;
    while (!file.eof()) {
        file >> u; file >> v;
        add_arc(g, u, v, 1);
    }

    file.close();
    return static_cast<bool>(file.flags());  // return file status
}

bool load_data(const char *filename, node* &data, int dim) {
    ifstream file(filename);
    if (!file.is_open())
        return false;

    data = new node[dim];
    for (int i=0; i<dim; i++) {
        file.getline(data[i].cont, 81);
        file >> data[i].tipo;
        file.ignore();
        // #ifdef DEBUG
        // cout << data[i].cont << " " << data[i].tipo << endl;
        // #endif
    }

    file.close();
    return static_cast<bool>(file.flags());
}

void print_graph(graph g) {
    for (int i=0; i<g.dim; i++) {
        int v_idx = i;
        int v_id = v_idx + 1;
        cout << v_id << " goes to ";
        adj_node *cur = g.nodes[v_idx];
        while (cur != NULL) {
            cout << cur->node+1 << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

void print_graph_verbose(graph g, const node* data) {
    for (int i=0; i<g.dim; i++) {
        int v_idx = i;
        int v_id = v_idx + 1;

        adj_node *cur = g.nodes[v_idx];
        while (cur != NULL) {
            if (data[v_idx].tipo == 'U' && data[cur->node].tipo == 'U')
                cout << data[v_idx].cont << " FOLLOWS " << data[cur->node].cont;
            else if (data[v_idx].tipo == 'U' && data[cur->node].tipo == 'T')
                cout << data[v_idx].cont << " LIKED " << data[cur->node].cont;
            else if (data[v_idx].tipo == 'T' && data[cur->node].tipo == 'U')
                cout << data[cur->node].cont << " TWEETED " << data[v_idx].cont;
            cout << endl;
            cur = cur->next;
        }
    }
}

int* total_like(graph g, const node* data) {
    int *res = new int[g.dim];
    for (int i=0; i<g.dim; i++)
        res[i] = 0;
    
    for (int i=0; i<g.dim; i++) {
        int u = i;
        
        adj_node *cur = g.nodes[u];
        while (cur != NULL) {
            int v = cur->node;
            if (data[u].tipo == 'U' && data[v].tipo == 'T') {  // if user u liked tweet v
                int liked_user_idx = g.nodes[v][0].node;  // since v node has type 'T', there's just one outgoing arc from v to the user who tweeted it
                res[liked_user_idx]++;
            }
            cur = cur->next;
        }
    }
    return res;
}

int* find_mip(const int *likes, const node *data, int dim) {
    int max_idx = 0;
    for (int i=0; i<dim; i++) {
        if (likes[i] > likes[max_idx])
            max_idx = i;
    }
    
    int *res = new int[dim];
    int res_i = 0;
    for (int i=0; i<dim; i++) {
        if (likes[i] == likes[max_idx])
            res[res_i++] = i;
    }
    res[res_i] = -1;  // terminator
    return res;
}

void follow(graph g, const node* data, int start_node_id) {
    const int start_node_idx = start_node_id-1;

    if (data[start_node_idx].tipo != 'U')
        return;

    cout << "L'utente " << data[start_node_idx].cont << " segue: " << endl;

    bool *visited = new bool[g.dim];
    for (int i=0; i<g.dim; i++)
        visited[i] = false;
    visited[start_node_idx] = true;

    coda c = newQueue();
    c = enqueue(c, start_node_idx);
    while(!isEmpty(c)) {
        int u_idx = dequeue(c);
        adj_node *cur = g.nodes[u_idx];
        cout << data[u_idx].cont << endl;
        while (cur != NULL) {
            int v_idx = cur->node;
            if (!visited[v_idx] && data[v_idx].tipo == 'U') {
                visited[v_idx] = true;
                c = enqueue(c, v_idx);
            }
            cur = cur->next;
        }
    }
    
    delete[] visited;
    return;
}

int main(int argc, char* argv[]) {
    debug_print("entering main");

    if (argc < MIN_ARGC) {
        cerr << "Usage: " << argv[0] << " graph_filename node_filename" << endl;
        return 1;
    }

    debug_print("building graph");
    graph g;
    if (!load_graph(argv[1], g)) {
        cerr << "Error while reading " << argv[1] << endl;
        return 2;
    }

    debug_print("building nodes data vector");
    node *nodes_data;
    if (!load_data(argv[2], nodes_data, g.dim)) {
        cerr << "Error while reading " << argv[2] << endl;
        return 3;
    }

    debug_print("inizia stampa");
    print_graph_verbose(g, nodes_data);

    debug_print("computing likes");
    int *likes = total_like(g, nodes_data);
    for (int i=0; i<g.dim; i++){
        cout << i+1 << " has " << likes[i] << " likes" << endl;
    }

    int *mip_idx = find_mip(likes, nodes_data, g.dim);  // most influential people
    cout << "The most influential people are: " << endl;
    for (int i=0; i<g.dim && mip_idx[i] != -1; i++)
        cout << "- " << nodes_data[mip_idx[i]].cont << endl;

    int start_node_id;
    cout << "Start node id for follow function: "; cin >> start_node_id;
    follow(g, nodes_data, start_node_id);

    return 0;
}