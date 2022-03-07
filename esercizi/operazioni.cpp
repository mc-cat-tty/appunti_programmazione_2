/* 
 Scrivere un programma che:
 - Richieda di effettuare un'operazione di addizione, sottrazione, moltiplicazione o divisione tra due interi
 - A seconda dell'operazione scelta, invochi una funzione che fornisca il risultato corretto
 - La selezione della funzione avvenga senza costrutti if, switch, etc.
*/

#include <iostream>

using namespace std;

enum choice_t {ADD, SUB, MOLT, DIV, CHOICE_DIM};

int __add(int a, int b) {
    return a+b;
}

int __sub(int a, int b) {
    return a-b;
}

int __molt(int a, int b) {
    return a*b;
}

int __div(int a, int b) {
    return a/b;
}

choice_t menu() {
    int scelta;
    cout
        << "0. Addizione" << endl
        << "1. Sottrazione" << endl
        << "2. Moltiplicazione" << endl
        << "3. Divisione" << endl
        << endl;
    cout << ">> ";
    cin >> scelta;
    return static_cast<choice_t>(scelta);
}

int main() {
    int (* callbacks[CHOICE_DIM]) (int, int) = {
        &__add,
        &__sub,
        &__molt,
        &__div
    };
    int x, y;
    int scelta = menu();
    cout << "Inserisci due numeri: ";
    cin >> x >> y;
    cout << "Risultato: " << (*callbacks[scelta])(x, y) << endl;
    return 0;
}