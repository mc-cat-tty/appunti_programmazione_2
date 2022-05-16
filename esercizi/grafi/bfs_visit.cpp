#include "bfs_visit.h"
#include "queue_bfs.h"

bool* bfs_visit(graph g, unsigned int start_id, const bfs_visit_callback_t c) {
    unsigned int start_idx = start_id-1;
    size_t dim = get_dim(g);
    bool *visited = new bool[dim];
    for (int i=0; i<dim; i++) {
        visited[i] = false;
    }

    bfs_queue q = new_queue();
    q = enqueue(q, start_idx);
    visited[start_idx] = true;
    while (!is_empty(q)) {
        int u_idx = dequeue(q);
        int u_id = u_idx+1;

        adj_list u_adj = get_adj_list(g, u_id);
        if (c != NULL)
            c(u_id, u_adj);  // visita

        while (u_adj != NULL) {
            int w_id = get_adj_node(u_adj);
            int w_idx = w_id-1;
            if (!visited[w_idx]) {
                visited[w_idx] = true;
                q = enqueue(q, w_idx);
            }
            u_adj = get_next_adj(u_adj);
        }
    }

    return visited;
}

bool connected(graph g, unsigned int start_id) {
    bool *visited = bfs_visit(g, start_id, NULL);

    for (int i=0; i<g.dim; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}

void connected_components(graph g, unsigned int *v) {
    bool done = false;
    unsigned int tree_id = 1; /**< incremental value that will be used as id inside output vector */
    bool global_visited[g.dim];
    for (int i=0; i<g.dim; i++)
        global_visited[i] = false;

    while (!done) {
        bool *visited = bfs_visit(g, tree_id, NULL);

        done = true;
        int next_tree_id = tree_id;
        for (int i=0; i<g.dim; i++) {
            if (!global_visited[i]) {
                if (visited[i]) {
                    v[i] = tree_id;
                    global_visited[i] = true;
                }
                else {
                    done = false;
                    next_tree_id = i+1;
                }
            }
        }

        tree_id = next_tree_id;
    }
}