#pragma once

struct elem {
    int data;
    float w;
    elem *next;
};

typedef elem* priority_queue;

priority_queue enqueue(priority_queue q, int d, float w);
int dequeue(priority_queue &q);
int min_queue(priority_queue q);
priority_queue decrease_priority(priority_queue q, int d, float w);
bool is_empty_queue(priority_queue q);
void print_queue(priority_queue q);