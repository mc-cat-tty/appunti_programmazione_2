#include <iostream>

#include "liste.h"

using namespace std;

void debug_print(const char *str) {
    #ifdef DEBUG
    cout << str << endl;
    #endif
}

void pesca(lista &l) {
    cout << "Inserire la carta [valore seme]: ";
    carta c;
    cin >> c.valore >> c.seme;
    if (c.valore < 1 || c.valore > 13) {
        cerr << "Valore non valido" << endl;
        return;
    }
    debug_print("carta letta");
    l = ord_insert_elem(l, new_elem(c));
}

void stampa(const lista l) {
    elem *cur = l;
    while (cur != NULL) {
        print(cur->inf);
        cout << " ";
        cur = tail(cur);
    }
    cout << endl;
}

elem* scala(const lista l, int &len) {
    debug_print("entering scala");
    // scala = sequenza di almeno 3 carte consecutive, dello stesso seme
    elem *cur1 = l;
    if (cur1 == NULL)
        return NULL;
    elem *cur2 = cur1->pun;
    if (cur2 == NULL)
        return NULL;
    
    len = 0;
    elem *first_card = l;
    while (cur2 != NULL) {
        if ((cur1->inf.seme == cur2->inf.seme) && (cur1->inf.valore == cur2->inf.valore-1))
            len++;
        else
            if (len < 2) {
                len = 0;
                first_card = cur2;
            }
            else {
                len++;
                return first_card;
            }

        cur1 = cur1->pun;
        cur2 = cur2->pun; 
    }

    if (len > 2) {
        len++;
        return first_card;
    }

    debug_print("exiting scala");
    return NULL;
}

int calcola_punteggio(const elem *p, int len) {
    debug_print("entering calcola punteggio");
    int punteggio = 0;
    for (int i=0; i<len; i++) {
        punteggio += p->inf.valore;
        p = p->pun;
    }
    debug_print("exiting calcola punteggio");
    return punteggio;
}

elem* best_scala(const lista l, int &len) {
    debug_print("entering best_scala");
    elem *cur = l;
    elem *max_scala = NULL;
    int punteggio = 0;
    elem *tmp_max_scala = l;
    while (cur != NULL && tmp_max_scala != NULL) {
        debug_print("iteration");
        int tmp_len;
        tmp_max_scala = scala(cur, tmp_len);
        if (tmp_max_scala != NULL) {
            int tmp_pun = calcola_punteggio(tmp_max_scala, tmp_len);
            if (tmp_pun > punteggio) {
                punteggio = tmp_pun;
                len = tmp_len;
                max_scala = tmp_max_scala;
            }
            cur = tmp_max_scala;
            for (int i=0; i<tmp_len; i++)
                cur = cur->pun;
        }
    }
    debug_print("exiting best_scala");
    if (punteggio == 0)
        return NULL;
    return max_scala;
}

int cala(lista &l) {
    debug_print("entering cala");
    int len;
    elem *prima_carta_scala = best_scala(l, len);
    if (prima_carta_scala == NULL)
        return 0;
    int punteggio = calcola_punteggio(prima_carta_scala, len);
    for (int i=0; i<len; i++) {
        elem *tmp = prima_carta_scala->pun;
        l = delete_elem(l, prima_carta_scala);
        prima_carta_scala = tmp;
    }
    debug_print("exiting cala");
    return punteggio;
}

int main() {
    // assunzione: 2 giocatori
    cout << "Con quante carte si vuole giocare? ";
    int dim; cin >> dim;

    lista g1 = NULL;
    cout << "GIOCATORE 1" << endl;
    for (int i=0; i<dim; i++)
        pesca(g1);

    lista g2 = NULL;
    cout << "GIOCATORE 2" << endl;
    for (int i=0; i<dim; i++)
        pesca(g2);

    cout << "Carte giocatore 1: "; stampa(g1);
    cout << "Carte giocatore 2: "; stampa(g2);

    int s1_len, s2_len;
    elem *s1 = scala(g1, s1_len);
    elem *s2 = scala(g2, s2_len);
    if (s1 != NULL) {
        cout << "Prima scala G1: ";
        for(int i=0; i<s1_len; i++) {
            print(s1->inf); cout << " ";
            s1 = s1->pun;
        }
        cout << endl;
    }
    if (s2 != NULL) {
        cout << "Prima scala G2: ";
        for(int i=0; i<s2_len; i++) {
            print(s2->inf); cout << " ";
            s2 = s2->pun;
        }
        cout << endl;
    }

    int g1_pun = 0;  /**< punteggio giocatore 1 */
    int g2_pun = 0;  /**< punteggio giocatore 2 */
    const int num_turni = 2;
    for (int i=0; i<num_turni; i++) {
        cout << "TURNO " << i+1 << endl;
        
        cout << "Giocatore 1" << endl;
        pesca(g1);
        int s1_len;
        elem *s1 = best_scala(g1, s1_len);
        if (s1 != NULL) {
            cout << "Cala (migliore): ";
            for(int i=0; i<s1_len; i++) {
                print(s1->inf); cout << " ";
                s1 = s1->pun;
            }
        }
        else {
            cout << "Non cala";
        }
        cout << endl;
        g1_pun += cala(g1);
        if (g1 != NULL) {  // continua il gioco
            cout << "Carte in mano: "; stampa(g1);
            cout << "Punteggio: " << g1_pun << endl;
        }
        else {  // il giocatore 1 ha vinto
            cout << "Fine gioco! Vince il giocatore 1 con " << g1_pun << " punti" << endl;
            break;
        }

        cout << "Giocatore 2" << endl;
        pesca(g2);
        int s2_len;
        elem *s2 = best_scala(g2, s2_len);
        if (s2 != NULL) {
            cout << "Cala (migliore): ";
            for(int i=0; i<s2_len; i++) {
                print(s2->inf); cout << " ";
                s2 = s2->pun;
            }
        }
        else {
            cout << "Non cala";
        }
        cout << endl;
        g2_pun += cala(g2);
        if (g2 != NULL) {  // continua il gioco
            cout << "Carte in mano: "; stampa(g2);
            cout << "Punteggio: " << g2_pun << endl;
        }
        else {  // il giocatore 2 ha vinto
            cout << "Fine gioco! Vince il giocatore 2 con " << g2_pun << " punti" << endl;
            break;
        }
    }
    
    return 0;
}