#include <iostream>

using namespace std;

int call_counter = 0;

int fib(int n) {
    call_counter++;
    if (n == 0 || n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}

int main() {
    int num;
    cout << "Numero: "; cin >> num;
    cout << "Risultato: " << fib(num) << endl;
    cout << "Numero chiamate: " << call_counter << endl;
    return 0;
}