/*
  Scrivere un programma che legga da stdin due numeri naturali x ed n,
  e setti il bit in posizione n nel numero x.
*/

#include <iostream>

using namespace std;

int main() {
    unsigned int x, n;
    cout << "Immettere x: "; cin >> x;
    cout << "Immettere n: "; cin >> n;

    x |= (1<<n);

    cout << "Risultato: " << x << endl;
    return 0;
}