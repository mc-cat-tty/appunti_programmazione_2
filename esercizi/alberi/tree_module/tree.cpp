#include "tree.h"

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