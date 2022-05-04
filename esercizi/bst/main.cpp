#include <iostream>

#include "key_type.h"
#include "data_type.h"
#include "bst.h"

using namespace std;

int main() {
    key_t k;
    data_t d;
    int num;
    bst albero_ricerca = NULL;

    cout << "Quanti valori vuoi inserire? "; cin >> num;
    for (int i=0; i<num; i++) {
        cout << "Chiave: "; cin >> k;
        cout << "Informazione: "; cin >> d;

        bst_insert(albero_ricerca, bst_new_node(k, d));
    }

    cout << "Albero costruito" << endl;

    do {
        cout << "Chiave da ricercare: "; cin >> k;
        bnode* res = bst_search(albero_ricerca, k);
        if (res == NULL)
            cout << "Valore non trovato" << endl;
        else
            cout << "Il valore associato è " << res->data << endl;
        
    } while (k != -1);
}