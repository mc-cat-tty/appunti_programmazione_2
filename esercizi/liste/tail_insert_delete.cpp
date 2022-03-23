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

list delete_ele(list l, ele *e) {
    if (l == e) {
        l = tail(l);
    }
    else {
        ele *aux_ele = l;
        while (tail(aux_ele) != e) {
            aux_ele = tail(aux_ele);
        }
        aux_ele->p = tail(e);
    }
    delete e;
    return l;
}

list delte_tail_ele(list l) {
    if (l == NULL)
        return l;

    ele *last_ele;
    while ((l = tail(l)) != NULL) {
        last_ele = l;
    }

    return delete_ele(l, last_ele);
}

list elimina_lista(list testa) {
    while (testa != NULL) {  // finchè non ottengo la lista vuota
        testa = delete_ele(testa, testa);
    }
    return testa;
}

int main() {
    int num;
    cout << "Numero di elementi: "; cin >> num;

    list l = crea_lista(num);
    print_list(l);
    l = delte_tail_ele(l);
    print_list(l);

    l = elimina_lista(l);
    print_list(l);

    return 0;
}