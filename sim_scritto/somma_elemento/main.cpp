/*
Dato il tipo di dato lista semplice de nito sotto e le sue primitive, scrivere la funzione lista somma_elemento(lista,int) che
prende in ingresso una lista e un intero p, e somma il numero che si trova alla posizione p a tutti gli elementi della lista,
restituendola come risultato:
struct elem{
tipo_inf inf ;
elem* pun ;
} ;
typedef elem* lista ;
Esempio:
Lista -> 5 2 4 3
Chiamata -> somma_elemento(lista,2)
Risultato -> 9 6 8 6 (ovvero la somma dell'elemento in posizione 2 (che è 4) con tutti gli altri elementi)
*/

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

list copia_lista(list l) {
    list res = NULL;
    ele *last_ele;

    while (l != NULL) {
        // copia dell'elemento puntato da l
        ele *e = new ele;
        e->v = l->v;
        e->p = l->p;

        if (res == NULL) {  // se la lista "copia" è vuota aggiungo il primo elemento
            res = e;
        }
        else {  // se la lista non è vuota aggiungo l'elemento in ultima posizione (ordine corretto)
            last_ele->p = e;
        }
        last_ele = e;
        
        // faccio avanzare l (scorrimento)
        l = tail(l);
    }

    return res;
}

list somma_elemento(list l, int pos) {
    ele *e = l;
    for (int i=0; i<pos; i++)
        e = e->p;
    int val = e->v;

    list res = copia_lista(l);
    e = res;
    while (e != NULL) {
        e->v += val;
        e = e->p;
    }
    return res;
}

int main() {
    int num;
    cout << "Numero di elementi: "; cin >> num;

    list l = crea_lista(num);

    cout << "Lista l: " << endl;
    print_list(l);

    list res = somma_elemento(l, 2);
    print_list(res);
    // cout << endl;
    print_list(l);

    return 0;
}