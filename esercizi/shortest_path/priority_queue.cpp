#include "priority_queue.h"

#include <iostream>

static inline elem* new_elem(int d, float w) {
    elem *e = new elem;
    e->data = d;
    e->w = w;
    e->next = nullptr;
    return e;
}

priority_queue enqueue(priority_queue q, int d, float w) {
    elem *e = new_elem(d, w);
    priority_queue original_q = q;

    if (q == nullptr) {
        return e;  // primo elemento dell'array
    }

    elem *prev = nullptr;
    while (q != nullptr) {
        if (q->w >= w) {
            if (prev != nullptr) {
                e->next = prev->next;  // inserimento in mezzo
                prev->next = e;
                return original_q;
            }
            else {
                e->next = q;  // inserimento in prima posizione
                return e;
            }
        }
        prev = q;
        q = q->next;
    }

    prev->next = e;  // inserimento in coda
    return original_q;
}

int dequeue(priority_queue &q) {
    if (q == nullptr)
        return -1;

    elem *res = q;
    q = q->next;
    return res->data;
}

int min_queue(priority_queue q) {
    return q->data;
}

bool is_empty_queue(priority_queue q) {
    return (q == nullptr);
}

priority_queue decrease_priority(priority_queue q, int d, float w) {
    priority_queue original_queue = q;
    priority_queue prev = nullptr;
    while (q != nullptr && q->data != d) {
        prev = q;
        q = q->next;
    }
    if (q == nullptr)
        return original_queue;
    if (prev == nullptr)
        original_queue = original_queue->next;
    else
        prev->next = q->next;
    return enqueue(original_queue, d, w);
}

void print_queue(priority_queue q) {
    using namespace std;
    cout << "Priority queue print: ";
    while (q != nullptr) {
        cout << "{" << q->data << " " << q->w << "}, ";
        q = q->next;
    }
    cout << endl;
}