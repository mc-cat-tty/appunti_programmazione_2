#include "carta.h"

#include <iostream>
#include <cstring>

int compare(tipo_inf x, tipo_inf y) {
    if ((strcmp(x.fullname, y.fullname) == 0) && (x.loyalty_points == y.loyalty_points))
        return 0;
    else
        return strcmp(x.fullname, y.fullname);
}

void copy(tipo_inf& dst, tipo_inf src) {
    dst = src;
}

void print(tipo_inf inf) {
    using namespace std;
    cout << inf.fullname << " " << inf.loyalty_points << endl;
}