#include "tree.h"
#include "cstring"

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