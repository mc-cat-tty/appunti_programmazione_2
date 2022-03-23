#include <iostream>

using namespace std;

void fun(int n) {
    cout << n << endl;
    // clausola di stop: if (n == 0) -> stop
    if (n>0)
        fun(n-1);
}

int main() {
    fun(2);  // 2 1 0
    return 0;
}