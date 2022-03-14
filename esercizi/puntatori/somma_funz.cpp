/*
 Implementare un programma che implementa una funzione
 generale che calcoli la somma dei primi n valori per
 una data funzione f: f(1) + f(2) + f(3) + .... + f(n)
*/

#include <iostream>

using namespace std;

int quadrato(int x) {
    return x*x;
}

int cubo(int x) {
    return x*x*x;
}

int somma(int n, int(*f_p)(int)) {
    int s = 0;
    for (int i=1; i<=n; i++) {
        s += f_p(i);
    }
    return s;
}

int main() {
    int n;
    cout << "Inserisci n: ";
    cin >> n;
    cout << "Risultato con f(x) = x^2: " << somma(n, quadrato) << endl;
    cout << "Risultato con f(x) = x^3: " << somma(n, cubo) << endl;
    return 0;
}