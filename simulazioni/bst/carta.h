#pragma once

static const unsigned int MAX_FULLNAME_DIM = 40;

struct tipo_inf {
    char fullname[MAX_FULLNAME_DIM];
    unsigned loyalty_points;
};


int compare(tipo_inf, tipo_inf);
void copy(tipo_inf&, tipo_inf);
void print(tipo_inf);
