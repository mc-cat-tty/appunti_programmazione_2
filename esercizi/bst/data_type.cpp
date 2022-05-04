#include "data_type.h"

int data_compare(data_t v1, data_t v2) {
    return v1-v2;
}

void data_copy(data_t &dst, data_t src) {
    dst = src;
}