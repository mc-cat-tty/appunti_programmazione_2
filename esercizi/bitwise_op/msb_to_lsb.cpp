#include <iostream>

using namespace std;

int main() {
    unsigned int i, j, z;
    cout << "i: "; cin >> i;
    cout << "j: "; cin >> j;
    z = (i >> (32-j));
    cout << "Risultato: " << z << endl;
    return 0;
}