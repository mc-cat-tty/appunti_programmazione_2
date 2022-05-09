#include <iostream>
#include <fstream>
#include <cstring>

#include "parola.h"
#include "liste.h"
#include "tipo.h"

using namespace std;

const char* filename = "inverted";

/**
 * @brief funzione che carica 
 * 
 * @param filename nome del file da cui caricare l'inverted index
 * @param dim parametro di uscita; viene popolato con il la dimensione del vettore di parole
 * @return parola* vettore ai parole allocato nell'heap; NULL se la lettura non è andata a buon fine
 */
parola* load(const char *filename, int &dim) {
    dim = 0;  // if the function fails dim is 0
    ifstream file(filename);
    if (!file.is_open())
        return NULL;
    
    file >> dim;
    parola* words_v = new parola[dim];

    char word_tmp[P_MAXLEN];
    int ref_count_tmp;
    tipo_inf file_index_tmp;
    for (int i=0; i<dim; i++) {
        file >> word_tmp;
        file >> ref_count_tmp;
        strcpy(words_v[i].p, word_tmp);
        words_v[i].n_doc = ref_count_tmp;
        words_v[i].l = NULL;

        for (int j=0; j<ref_count_tmp; j++) {
            file >> file_index_tmp;
            words_v[i].l = insert_elem(words_v[i].l, new_elem(file_index_tmp));
        }
    }

    file.close();
    if (!file)
        return NULL;
    return words_v;
}

/**
 * @brief funzione per la stampa di un vettore di parole
 * 
 * @param words vettore di parole passato per riferimento
 * @param dim numero di elementi contenuti nel vettore words
 */
void print(const parola *words, int dim) {
    for (int i=0; i<dim; i++) {
        cout << words[i].p << " " << words[i].n_doc << ": ";
        print_list(words[i].l);
        cout << endl;
    }
}

/**
 * @brief funzine privata per la ricerca di una parola all'interno della lista di paraole
 * 
 * @param words lista di parole originale
 * @param word parola da carcare nella lista
 * @param dim numero di elementi della lista
 * @return int indice dell'elemento se presente, -1 altrimenti
 */
static int search(const parola *words, const char *word, int dim) {
    for (int i=0; i<dim; i++) {
        if (strcmp(words[i].p, word) == 0)
            return i;
    }
    return -1;
}

/**
 * @brief funzione per aggiornare una lista di words
 * 
 * @param words puntatore per riferimento alla lista di parole
 * @param filename nome del file da cui caricare le nuove parole
 * @param dim dim di words
 * @return true if file read succedeed
 * @return false if an error occured while reading file
 */
bool update(parola* &words, const char *filename, int &dim) {
    ifstream file(filename);
    if (!file.is_open())
        return false;

    char word_tmp[P_MAXLEN];
    int id;
    file >> id;
    
    while (!file.eof()) {
        file >> word_tmp;
        int index = search(words, word_tmp, dim);
        if (index == -1) {
            dim++;  // increase size
            parola *tmp_v = new parola[dim];  // reallocate
            for (int i=0; i<dim-1; i++) {  // copy old elems
                tmp_v[i] = words[i];
            }
            delete[] words;
            words = tmp_v;

            // init struct for new word
            index = dim-1;
            strcpy(words[index].p, word_tmp);
            words[index].l = NULL;
            words[index].n_doc = 0;
        }
        words[index].l = insert_elem(words[index].l, new_elem(id));
        words[index].n_doc++;
    }

    file.close();
    return static_cast<bool>(file);
}


/**
 * @brief print id of files that contain both w1 and w2
 * 
 * @param words vector of words
 * @param w1 first word
 * @param w2 second word
 * @param dim length of words array
 */
void print_and(parola *words, const char *w1, const char *w2, int dim) {
    int index1 = search(words, w1, dim);
    int index2 = search(words, w2, dim);

    if (index1 == -1 || index2 == -1)
        return;
    
    lista l, tmp;
    if (words[index1].n_doc < words[index2].n_doc) {
        tmp = words[index1].l;
        l = words[index2].l;
    }
    else {
        tmp = words[index2].l;
        l = words[index1].l;
    }

    elem *e;
    while (tmp != NULL) {
        if ((e = search(l, head(tmp))) != NULL)
            cout << e->inf << " ";
        tmp = tail(tmp);
    }
    cout << endl;
}

/**
 * @brief entry-point del programma
 * 
 * @return int status code
 */
int main() {
    int parole_dim;
    parola* parole = load(filename, parole_dim);
    if (parole == NULL) {
        cerr << "Errore durante la lettura del file" << filename << endl;
        return 1;
    }

    print(parole, parole_dim);


    char update_file[64];
    cout << "Inserire il nome di un file con struttura 'doc': "; cin >> update_file;
    bool ok = update(parole, update_file, parole_dim);  // This time the function can fail: nothing happens to parole
    if (!ok) {
        cerr << "Errore durante la lettura del file " << update_file << endl;
        return 1;
    }
    if (parole != NULL)
        print(parole, parole_dim);

    print_and(parole, "computer", "tower", parole_dim);

    return 0;
}