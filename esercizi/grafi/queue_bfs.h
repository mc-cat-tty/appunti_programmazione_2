#pragma once

struct elem_bfs_queue {
    int node_id;
    elem_bfs_queue *next;
};

struct bfs_queue {
    elem_bfs_queue *first_elem;
    elem_bfs_queue *last_elem;
};

bfs_queue enqueue(bfs_queue q, int node_id);
int dequeue(bfs_queue &q);  /**< return node_id */
int fist(bfs_queue q);
bfs_queue new_queue();
bool is_empty(bfs_queue q);