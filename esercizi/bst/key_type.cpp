#include "key_type.h"

int key_compare(key_t v1, key_t v2) {
    return v1-v2;
}

void key_copy(key_t &dst, key_t src) {
    dst = src;
}