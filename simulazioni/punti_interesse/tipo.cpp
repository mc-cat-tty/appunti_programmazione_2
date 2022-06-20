#include "tipo.h"
#include <iostream>

int compare(tipo_inf x, tipo_inf y) {
  return x.id - y.id;  // ids are unique
}

void copy(tipo_inf &dst, tipo_inf src) {
  dst = src;
}

void print(tipo_inf x) {
  using namespace std;
  cout << x.id << " " << x.tipo << " " << x.nome << endl;
}