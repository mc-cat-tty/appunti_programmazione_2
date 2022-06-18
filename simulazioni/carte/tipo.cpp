#include "tipo.h"
#include <iostream>

int compare(tipo_inf x, tipo_inf y) {
    if (x.seme != y.seme)
        return x.seme - y.seme;
    else
        return x.valore - y.valore;
}

void copy(tipo_inf &dst, tipo_inf src) {
    dst = src;
}

void print(tipo_inf x) {
    using namespace std;
    cout << x.valore << x.seme;
}