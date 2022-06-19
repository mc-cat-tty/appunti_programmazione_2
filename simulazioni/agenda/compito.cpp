#include <iostream>
#include <fstream>
#include <cstring>

#include "liste.h"
#include "tipo.h"

using namespace std;

static const int ARGC_MIN = 2;  /**< minimum number of cli arguments: executable, agenda_filename */

/**
 * @brief print debug string only if DEBUG macro is defined
 * 
 * @param str debug string to print on stdout
 */
void debug_print(const char *str) {
  #ifdef DEBUG
  cout << str << endl;
  #endif
}


/**
 * @brief add appuntamento to agenda
 * 
 * @param agenda double linked list of appuntamento
 * @param a appuntamento to be added
 */
void add_agenda(lista &agenda, appuntamento a) {
  debug_print("entering agenda");
  if (search(agenda, a) != NULL) {
    cerr << "Conflitto appuntamenti" << endl;
    return;
  }

  agenda = insert_elem_sorted(agenda, new_elem(a));
  debug_print("Inserimento avvenuto con successo");
}

/**
 * @brief print the content of agenda
 * 
 * @param agenda list of item 'appunamento' to be printed
 */
void stampa(lista agenda) {
  debug_print("entering stampa");
  elem *cur = agenda;
  while (cur != NULL) {
    print(cur->inf);
    cout << endl;
    cur = cur->pun;
  }
  debug_print("exiting stampa");
}

/**
 * @brief load list of 'appuntamento' from file
 * 
 * @param filename name of file to be read
 * @param agenda output list of 'appuntamento'
 * @return true if can read from file without errors
 * @return false otherwise
 */
bool carica_appuntamenti(const char *filename, lista &agenda) {
  debug_print("entering carica appuntamenti");
  ifstream file(filename);
  if (!file.is_open())
    return false;

  while (!file.eof()) {
    appuntamento a;
    file >> a.data >> a.ora_i >> a.ora_f;
    file.ignore();
    file.getline(a.descr, DESCR_MAX_LEN);

    #ifdef DEBUG
    cout << a.data << " " << a.ora_i << " " << a.ora_f << " " << a.descr << endl;
    #endif
    
    add_agenda(agenda, a);
  }

  file.close();
  debug_print("exiting carica_appuntamenti");
  return static_cast<bool>(file.flags());  // returning file stream status
}

/**
 * @brief prints how many appointments are in 'agenda' before and after appointment a
 * 
 * @param agenda list of 'appuntamento'
 * @param a only date and ora_i fields are used
 */
void quanti(lista agenda, appuntamento a) {
  debug_print("entering quanti");
  elem *cur = agenda;
  unsigned int prima, dopo;
  prima = dopo = 0;

  while (cur != NULL) {
    if (strcmp(cur->inf.data, a.data) == 0) {
      if (compare(cur->inf, a) < 0) {  // comparing ora_i
        debug_print("prima");
        debug_print(cur->inf.descr);
        prima++;
      }
      else if (compare(cur->inf, a) > 0) {
        debug_print("dopo");
        debug_print(cur->inf.descr);
        dopo++;
      }
    }
    
    cur = cur->pun;
  }

  cout << prima << " appuntamenti prima e " << dopo << " appuntamenti dopo" << endl;

  debug_print("exiting quanti");
}

/**
 * @brief project's entry point
 * 
 * @param argc argument number
 * @param argv argument vector
 * @return int status code
 */
int main(int argc, char *argv[]) {
  lista agenda = NULL;

  if (argc < ARGC_MIN) {
    cerr << "Usage: " << argv[0] << " agenda_filename" << endl;
    return 1;
  }
  if (!carica_appuntamenti(argv[1], agenda)) {
    cerr << "Error while reading " << argv[1] << endl;
    return 2;
  }
  stampa(agenda);

  appuntamento tmp;
  cout << "Inserimento informazioni 'quanti'" << endl;
  cout << "Giorno [aammgg]: "; cin >> tmp.data;
  cout << "Ora inizio [hhmm]: "; cin >> tmp.ora_i;
  quanti(agenda, tmp);

  return 0;
}