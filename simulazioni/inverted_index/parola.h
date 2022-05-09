#pragma once

#include "liste.h"

const int P_MAXLEN = 80;

struct parola {
    char p[P_MAXLEN]; //parola
    int n_doc;  //numero di documenti che contengono la parola
    lista l;    //lista dei documenti
};
