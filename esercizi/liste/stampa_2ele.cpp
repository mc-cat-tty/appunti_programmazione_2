#include <iostream>

using namespace std;

typedef int value_t;

struct ele {
    value_t v;
    ele *p;
};

typedef ele* list;

value_t head(list l) {
    return l->v;
}

list tail(list l) {
    return l->p;
}

void print_list(list l) {
    while (l != NULL) {
        cout << head(l) << " ";
        l = tail(l);
    }
    cout << endl;
}

int main() {
    list testa = new ele;               // building first element
    testa->v = 3;

    ele* secondo_elemento = new ele;    // building second element
    secondo_elemento->v= 7;
    secondo_elemento->p = NULL;         // ricorda il terminatore

    testa->p = secondo_elemento;        // linking

    print_list(testa);

    return 0;
}