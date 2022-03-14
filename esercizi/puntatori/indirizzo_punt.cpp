/* 
   Scrivere un programma che definisca una variabile a di tipo int ed
   una variabile p di tipo puntatore ad int.  Successivamente si
   assegni un valore ad a e si assegni a p l'indirizzo di a. Infine si
   stampino, rispettivamente, l'indirizzo di a, il valore di a, il
   valore di p ed il valore della variabile a cui punta p.
*/

#include <iostream>

using namespace std;

int main() {
    int a;
    int *p;
    a = 32;
    p = &a;

    cout
        << "Indirizzo di a: " << &a << endl
        << "Valore di a: " << a << endl
        << "Valore di p: " << p << endl
        << "Valore della var a cui punta p: " << *p << endl;

    return 0;
}