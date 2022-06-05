/*
Data una lista
l semplice di interi definita come sotto, scrivere una funzione
lista split(lista& l) che
restituisca una lista
l’ contenente gli elementi di
l con valore pari mentre nella lista l rimangono tutti gli
elementi con valore dispari. Ad esempio per la lista [1,3,2,5,6], l’ sarà così rappresentato [2,6] e l
diventerà [1,3,5]. La funzione deve far uso delle primitive specificate sotto, non deve creare o distruggere
elementi ma effettuare operazioni sui puntatori.

struct elem {
int v;
elem* pun ;
};
typedef elem* lista ;
tipo_inf head(lista);
lista tail(lista);
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

list split_even_odd(list &l) {
    list res = NULL;
    list res_tail = NULL;
    ele *tmp = l;
    ele *prev = NULL;
    while (tmp != NULL) {
        if ((tmp->v%2) == 0) {
            if (prev == NULL) {
                l = tmp->p;

                if (res == NULL)
                    res = tmp;
                else
                    res_tail->p = tmp;
                res_tail = tmp;
                tmp->p = NULL;
                
                tmp = l;
            }
            else {
                prev->p = tmp->p;

                if (res == NULL)
                    res = tmp;
                else
                    res_tail->p = tmp;
                res_tail = tmp;
                tmp->p = NULL;

                tmp = prev->p;
            }
        }
        else {
            prev = tmp;
            tmp = tmp->p;
        }
    }
    return res;
}

int main() {
    int num;
    cout << "Numero di elementi: "; cin >> num;

    list l = crea_lista(num);

    cout << "Lista l: " << endl;
    print_list(l);

    list even_l = split_even_odd(l);
    print_list(even_l);
    // cout << endl;
    print_list(l);

    return 0;
}