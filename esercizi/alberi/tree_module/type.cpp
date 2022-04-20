#include "type.h"
#include <string.h>
#include <iostream>

int compare(const tipo_inf first, const tipo_inf second) {
    return strcmp(first, second);
}

void copy(tipo_inf dst, const tipo_inf src) {
    strcpy(dst, src);
}

void print(const tipo_inf data) {
    std::cout << data;
}

char* to_string(const tipo_inf data) {
    char *res = new char[STR_MAX_DIM];
    strcpy(res, data);
    return res;
}