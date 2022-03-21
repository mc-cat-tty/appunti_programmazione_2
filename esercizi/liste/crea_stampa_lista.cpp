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

list insert_ele(list l, ele *e) {
    e->p = l;
    return e;
}

list crea_lista(int n) {
    list l = NULL;  // lista vuota
    for (int i=0; i<n; i++) {
        ele *e = new ele;
        cout << "Valore elemento " << i << ": "; cin >> e->v;
        // e->p = NULL;
        l = insert_ele(l, e);
    }
    return l;
}

int main() {
    int num;
    cout << "Numero di elementi: "; cin >> num;

    list l = crea_lista(num);
    print_list(l);

    return 0;
}