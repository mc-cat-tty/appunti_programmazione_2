/*
  Scrivere un programma che stampi il contenuto di un vettore di
  interi definito ed inizializzato a tempo di scrittura del programma
  stesso e che contiene almeno un elemento di valore -1. In
  particolare lo stesso vettore va stampato due volte, utilizzando
  ciascuna volta una funzione diversa. Le due funzioni di stampa
  devono avere un solo parametro formale, non devono utilizzare
  variabili globali, e devono stampare gli elementi del vettore
  fermandosi non appena incontrano l'elemento di valore -1 (senza
  stamparlo).

  La prima funzione non deve utilizzare l'operazione di selezione con
  indice, mentre la seconda non deve utilizzare né l'operazione di
  selezione con indice né alcuna variabile locale.
*/

#include <iostream>

using namespace std;

void stampa_array_1(int v[]) {
    for (int i=0; *(v+i) != -1; i++) {
        cout << *(v+i) << " ";
    }
    cout << endl;
}

void stampa_array_2(int *v) {
    while (*v != -1) {
        cout << *(v++) << " ";
    }
    cout << endl;
}

int main() {
    const int N = 5;
    int v[N] = {10, 20, 30, 40, -1};  // -1 è il terminatore
    stampa_array_1(v);
    stampa_array_2(v);
}