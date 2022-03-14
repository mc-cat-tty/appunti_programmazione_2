#include <iostream>

using namespace std;

int main() {
    unsigned int n, i;
    cout << "n: "; cin >> n;
    cout << "i: "; cin >> i;
    cout << "Risultato: " << (n>>i) << endl;
    return 0;
}