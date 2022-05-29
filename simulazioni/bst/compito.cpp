#include <iostream>
#include <cstring>

#include "bst.h"

using namespace std;

enum choice_t {INSERT_CARDS = 1, PRINT_CARDS, SUM_IN_RAGE, UPDATE_CARDS, PRINT_NOT_UPDATED_CARDS, EXIT};

static const unsigned MAX_STR_LEN = 40;

choice_t menu() {
    cout
        << "1. Insert card" << endl
        << "2. Print cards" << endl
        << "3. Sum in range" << endl
        << "4. Update cards" << endl
        << "5. Print not updated cards" << endl
        << "6. Exit"
        << endl;
    
    unsigned choice;
    cout << ">> "; cin >> choice;
    return static_cast<choice_t>(choice);
}

void insert_cards(bst &cards, bst &cards_not_updated) {
    unsigned cards_num;
    cout << "Numero di carte da inserire: "; cin >> cards_num;

    tipo_key card_key;
    tipo_inf user;
    char tmp_name[MAX_STR_LEN], tmp_surname[MAX_STR_LEN], tmp_fullname[MAX_STR_LEN*2];
    for (int i=0; i<cards_num; i++) {
        cout << "Numero di carta: "; cin >> card_key;
        cout << "Nome e cognome utente: "; cin >> tmp_name >> tmp_surname;
        cout << "Numero punti: "; cin >> user.loyalty_points;

        tmp_fullname[0] = '\0';
        strcat(tmp_fullname, tmp_name);
        strcat(tmp_fullname, " ");
        strcat(tmp_fullname, tmp_surname);
        strcpy(user.fullname, tmp_fullname);

        bst_insert(cards, bst_newNode(card_key, user));
        bst_insert(cards_not_updated, bst_newNode(card_key, user));

        #ifdef DEBUG
        cout << card_key << " " << user.fullname << " " << user.loyalty_points << endl;
        #endif
    }
    #ifdef DEBUG
    cout << cards->inf.loyalty_points << endl;
    #endif
}

bool update(const bst &cards, unsigned card_number, unsigned new_points, bst &cards_not_updated) {
    bnode *f_node = bst_search(cards, card_number);
    if (f_node == NULL)
        return false;
    bnode *f_node_not_updated_cards = bst_search(cards_not_updated, card_number);
    if (f_node_not_updated_cards != NULL)
        bst_delete(cards_not_updated, f_node_not_updated_cards);
    f_node->inf.loyalty_points += new_points;
    return true;
}

unsigned totale_punti(const bst &cards, unsigned inf, unsigned sup) {
    if (cards == NULL)
        return 0;
    
    if (cards->key >= inf && cards->key <= sup)
        return totale_punti(cards->left, inf, sup) + totale_punti(cards->right, inf, sup) + cards->inf.loyalty_points;
    else
        return totale_punti(cards->left, inf, sup) + totale_punti(cards->right, inf, sup);
}

int main() {
    choice_t choice;
    bst cards = NULL;
    bst cards_not_updated = NULL;
    unsigned card_number, new_points;

    do {
        choice = menu();
        switch(choice) {
            case INSERT_CARDS:
                insert_cards(cards, cards_not_updated);
                break;
            case PRINT_CARDS:
                #ifdef DEBUG
                cout << cards->inf.loyalty_points << endl;
                #endif
                bst_dfs_print(cards);
                break;
            case SUM_IN_RAGE:
                int inf, sup;
                cout << "Inf: "; cin >> inf;
                cout << "Sup: "; cin >> sup;
                cout << "Totale: " << totale_punti(cards, inf, sup) << endl;
                break;
            case UPDATE_CARDS:
                cout << "Numero carta: "; cin >> card_number;
                cout << "Punti acquisto: "; cin >> new_points;
                if (!update(cards, card_number, new_points, cards_not_updated))
                    cout << "Errore: carta inesistente" << endl;
                break;
            case PRINT_NOT_UPDATED_CARDS:
                bst_dfs_print(cards_not_updated);
                break;
            case EXIT:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != EXIT);

    return 0;
}