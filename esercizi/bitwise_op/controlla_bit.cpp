/*
  Scrivere un programma che legga da stdin due numeri naturali x ed n,
  e dica se il bit in posizione n è settato o meno nel numero x.
*/

#include <iostream>

using namespace std;

int main() {
    unsigned int x, n;
    cout << "Immettere x: "; cin >> x;
    cout << "Immettere n: "; cin >> n;
    if (x & (1<<n))
        cout << "Settato" << endl;
    else
        cout << "Non settato" << endl;
    return 0;
}
