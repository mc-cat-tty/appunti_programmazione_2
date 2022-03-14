#include <iostream>

using namespace std;

int main() {
    unsigned int k, j;
    cout << "k: "; cin >> k;
    cout << "j: "; cin >> j;
    cout << "Risultato: " << ((k << j) | (k >> (32-j))) << endl;
    return 0;
}