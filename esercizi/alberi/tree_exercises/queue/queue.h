#pragma once

#include "../tree_module/tree.h"

typedef node data_t;

struct elem {
    data_t data;
    elem *next;
};

struct queue {
    elem *first;
    elem *last;
};

queue new_queue();
elem* new_elem(data_t data);
data_t dequeue(queue &q);
data_t first(queue q);
void enqueue(queue &q, elem *e);
bool is_empty_queue(queue q);