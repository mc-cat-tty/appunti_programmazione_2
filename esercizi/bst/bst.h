#pragma once

#include "data_type.h"
#include "key_type.h"

struct bnode {
    key_t key;
    data_t data;
    bnode* right;
    bnode* left;
    bnode* parent;
};

typedef bnode* bst;

bnode* bst_new_node(key_t k, data_t d);
void bst_insert(bst &r, bnode* n);
bnode* bst_search(bst r, key_t k);