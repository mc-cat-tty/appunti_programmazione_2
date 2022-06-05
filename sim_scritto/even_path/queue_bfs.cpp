#include "queue_bfs.h"
#include <cstdlib>

bfs_queue new_queue() {
    return (bfs_queue) {
        .first_elem = NULL,
        .last_elem = NULL
    };
}

static elem_bfs_queue* new_elem(int node_id) {
    elem_bfs_queue *e = new elem_bfs_queue;
    e->node_id = node_id;
    e->next = NULL;
    return e;
}

bool is_empty_queue(bfs_queue q) {
    return q.first_elem == NULL;
}

bfs_queue enqueue(bfs_queue q, int node_id) {
    elem_bfs_queue *tmp_elem = new_elem(node_id);
    if (is_empty_queue(q)) {
        q.last_elem = q.first_elem = tmp_elem;
    }
    else {
        q.last_elem->next = tmp_elem;
        q.last_elem = tmp_elem;
    }
    return q;    
}

int first(bfs_queue q) {
    return q.first_elem->node_id;
}

int dequeue(bfs_queue &q) {
    const int res = first(q);
    q.first_elem = q.first_elem->next;
    return res;
}

