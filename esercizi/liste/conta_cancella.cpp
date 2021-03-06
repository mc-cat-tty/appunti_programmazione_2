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

list elimina_lista(list testa) {
    while (testa != NULL) {  // finchè non ottengo la lista vuota
        testa = delete_ele(testa, testa);
    }
    return testa;
}

ele* search(list l, int v) {
    while (l != NULL) {
        if (head(l) == v)
            return l;
        else
            l = tail(l);
    }
    return NULL;  // se non trovo niente ritorno NULL
}

int conta_occorrenze(list l, int v) {
    int count = 0;
    while (l != NULL) {
        l = search(l, v);
        if (l != NULL) {
            count++;
            l = tail(l);
        }
    }
    return count;
}

list cancella_occorrenze(list l, int v) {
    // list aux_ele = l;
    // list aux_ele_tail;
    // while (aux_ele != NULL) {
    //     aux_ele = search(aux_ele, v);
    //     if (aux_ele != NULL) {
    //         aux_ele_tail = tail(aux_ele);
    //         l = delete_elem(l, aux_ele);
    //         aux_ele = aux_ele_tail;
    //     }
    // }
    // return l;

    ele *e;
    while ((e = search(l, v)) != NULL) {
        l = delete_ele(l, e);
    }

    return l;
}

int main() {
    int num;
    cout << "Numero di elementi: "; cin >> num;

    list l = crea_lista(num);
    print_list(l);

    int val;
    cout << "Valore da ricercare: "; cin >> val;
    cout << "Occorrenze: " << conta_occorrenze(l, val) << endl;

    l = cancella_occorrenze(l, val);
    print_list(l);

    return 0;
}