#include "queue.h"

#include <cstdlib>

queue new_queue() {
    queue *q = new queue;
    q->first = q->last = NULL;
    return *q;
}

elem* new_elem(data_t data) {
    elem *tmp = new elem;
    tmp->data = data;
    tmp->next = NULL;
}

data_t dequeue(queue &q) {
    data_t tmp = q.first->data;
    elem *aux = q.first;
    
    q.first = q.first->next;
    if (q.first == NULL)
        q.last = NULL;

    delete aux;
    return tmp;
}

data_t first(queue q) {
    return q.first->data;
}

void enqueue(queue &q, elem *e) {
    e->next = q.first;
    q.first = e;
    if (q.last == NULL)
        q.last = e;
}

bool is_empty_queue(queue q) {
    if (q.first == NULL && q.last == NULL)
        return true;
    return false;
}