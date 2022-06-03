#include "tree.h"
#include "cstring"
#include "../queue/queue.h"
#include <iostream>

static const int STR_DIM = 64;

node* new_node(const tipo_inf inf) {
    node* tmp_node = new node();
    tmp_node->inf = new char[STR_DIM];
    copy(tmp_node->inf, inf);
    tmp_node->parent = nullptr;
    tmp_node->first_child = nullptr;
    tmp_node->next_sibling = nullptr;
    return tmp_node;
}

void insert_child(tree p, tree c) {
    c->parent = p;
    c->next_sibling = p->first_child;
    p->first_child = c;
}

void insert_sibling(node* n, tree t) {
    t->parent = n->parent;
    t->next_sibling = n->next_sibling;
    n->next_sibling = t;    
}

char* serialize(tree t) {
    static char* res = new char[255];
    strcat(res, "(");
    strcat(res, to_string(t->inf));

    node* tmp = t->first_child;
    while (tmp != nullptr) {
        serialize(tmp);
        tmp = tmp->next_sibling;
    }
    strcat(res, ")");
    return res;
}

unsigned int depth(tree t) {    
    node* tmp = t->first_child;

    unsigned int max_depth = 0;
    unsigned int tmp_depth;
    int node_counter = 0;

    if (tmp == nullptr)
        return 0;

    while (tmp != nullptr) {
        tmp_depth = depth(tmp);
        if (tmp_depth > max_depth)
            max_depth = tmp_depth;
        tmp = tmp->next_sibling;
    }

    return max_depth+1;
}

unsigned tree_size_dfs(tree t) {
    unsigned accum = 0;
    tree tmp = t->first_child;

    while (tmp != NULL) {
        accum += tree_size_dfs(tmp);
        tmp = tmp->next_sibling;
    }

    return accum+1;
}

unsigned tree_size_bfs(tree t) {
    queue q = new_queue();
    enqueue(q, new_elem(*t));
    unsigned size = 0;
    while (!is_empty_queue(q)) {
        node n = dequeue(q);
        size++;
        node *tmp = n.first_child;
        while (tmp != NULL) {
            enqueue(q, new_elem(*tmp));
            tmp = tmp->next_sibling;
        }        
    }
    return size;
}

unsigned leaves_bfs(tree t) {
    queue q = new_queue();
    enqueue(q, new_elem(*t));
    unsigned count = 0;
    while (!is_empty_queue(q)) {
        node n = dequeue(q);
        node *tmp = n.first_child;
        if (tmp == NULL)
            count++;
        while (tmp != NULL) {
            enqueue(q, new_elem(*tmp));
            tmp = tmp->next_sibling;
        }
    }
    return count;
}

unsigned leaves_dfs(tree t) {
    node *tmp = t->first_child;
    if (tmp == NULL)
        return 1;
    
    unsigned count = 0;
    while (tmp != NULL) {
        count += leaves_bfs(tmp);
        tmp = tmp->next_sibling;
    }    
    return count;
}

node* search_dfs(tree t, tipo_inf i) {
    if (compare(t->inf, i) == 0)
        return t;

    node *tmp = t->first_child;
    while (tmp != NULL) {
        node *f = search_dfs(tmp, i);
        if (f != NULL)
            return f;
        tmp = tmp->next_sibling;
    }
    return NULL;
}