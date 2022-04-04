#include <iostream>

using namespace std;

int var;

extern void fun(void);

int main() {
    cout << "Valore di var: "; cin >> var;
    fun();
    return 0;
}