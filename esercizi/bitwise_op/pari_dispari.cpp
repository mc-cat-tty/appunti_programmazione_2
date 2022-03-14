#include <iostream>

using namespace std;

int main() {
    unsigned int n;
    cout << "Numero: "; cin >> n;
    cout << "Risultato: " << (n&0x01) << endl;
    return 0;
}