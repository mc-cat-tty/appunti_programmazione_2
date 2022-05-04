#include "bst.h"
#include <stdlib.h>
#include <iostream>

bnode* bst_new_node(key_t k, data_t d) {
    bnode* tmp = new bnode;
    key_copy(tmp->key, k);
    data_copy(tmp->data, d);
    tmp->left = tmp->right = tmp->parent = NULL;
}

void bst_insert(bst &r, bnode* n) {
    bnode* tmp = r;
    bnode* prev = r;
    while ((tmp != NULL) ) {
        prev = tmp;
        if (key_compare(n->key, tmp->key) < 0)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    if (prev == NULL)
        r = n;
    else if (key_compare(n->key, tmp->key) < 0)
        prev->left = n;
    else
        prev->right = n;
    
    n->parent = prev;
}

bnode* bst_search(bst r, key_t k) {
    bnode* tmp = r;
    while ((tmp != NULL) && (key_compare(tmp->key, k) != 0)) {
        if (key_compare(k, tmp->key) < 0)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    return tmp;
}