#include <iostream>

using namespace std;

/**
 * @brief calcola b^e in modo ricorsivo
 * 
 * @param b base
 * @param e esponente
 */
int pot(int b, int e) {
    if (e == 0)
        return 1;
    
    return b * pot(b, e-1);
}

int main() {
    int b, e;
    cout << "Base: "; cin >> b;
    cout << "Esponente: "; cin >> e;
    cout << "Potenza: " << pot(b, e) << endl;
}