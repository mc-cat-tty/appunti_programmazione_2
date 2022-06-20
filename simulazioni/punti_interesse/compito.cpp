#include <iostream>
#include <fstream>

#include "tipo.h"
#include "liste.h"
#include "grafo.h"

static const int MIN_ARGC = 3;  /**< minumum args number: executable, places data, places graph (map) */

using namespace std;

void debug_print(const char *str) {
  #ifdef DEBUG
  cout << str << endl;
  #endif
}

/**
 * @brief carica una lista di punti di interesse dal file filename e ritorna il numero di pi caricati
 * 
 * @param filename nome del file da cui caricare i punti di interesse
 * @param pi parametro di output; lista di pi
 * @return int numero di punti di interesse caricati
 */
int carica(const char *filename, lista&  pi) {
  debug_print("entering carica");
  ifstream file(filename);
  if (!file.is_open())
    return 0;
  debug_print("file opened");

  int cont = 0;
  place tmp;
  while (!file.eof()) {
    file >> tmp.id;
    file.ignore();
    file.getline(tmp.nome, NOME_MAX_DIM);
    file >> tmp.tipo;
    file.ignore();
    
    // cout << tmp.id << " " << tmp.nome << " " << tmp.tipo << endl;
    
    pi = ord_insert_elem(pi, new_elem(tmp));
    cont++;
  }

  file.close();
  if (!static_cast<bool>(file.flags()))
    return 0;

  debug_print("exiting carica without errors");
  return cont;
}

/**
 * @brief cerca all'interno della lista 'pi' il punto di interesse con id 'id'
 * 
 * @param pi lista dei punti di interesse
 * @param id id da ricercare
 * @return tipo_inf punto di interesse trovato, se presente all'interno della lista; pi con id == -1 altrimenti
 */
tipo_inf search_pi(const lista pi, int id) {
  debug_print("entering search_pi");
  elem *cur = pi;
  while (cur != NULL && cur->inf.id < id) cur = cur->pun;
  if (cur == NULL || cur->inf.id != id) {  // pi non trovato
    return (place) {
      .id = -1
    };
  }
  
  debug_print("exiting search_pi");
  return cur->inf;
}

/**
 * @brief stampa la lista di punti di interesse
 * 
 * @param pi lista di punti da stampare
 */
void stampa_pi(const lista pi) {
  elem *cur = pi;
  while (cur != NULL) {
    print(cur->inf);
    cur = cur->pun;
  }
}

/**
 * @brief carica una mappa (grafo) da file
 * 
 * @param filename nome del file da cui leggere gli archi
 * @param dim numero dei punti di interesse sul grafo
 * @param g parametro di output
 * @return true se la lettura va a buon fine
 * @return false altrimenti
 */
bool mappa(const char *filename, int dim, graph &g) {
  debug_print("entering mappa");
  ifstream file(filename);
  if (!file.is_open())
    return false;

  g = new_graph(dim);
  int u, v;
  while (!file.eof()) {
    file >> u >> v;
    add_edge(g, u, v, 0);
    cout << u << " " << v << endl;
  }

  file.close();
  debug_print("exiting mappa");
  return static_cast<bool>(file.flags());
}

void stampa_mappa(graph g, lista pi) {
  debug_print("entering stampa_mappa");
  elem *cur = pi;
  while (cur != NULL) {  // for each punto di interesse
    cout << cur->inf.nome << " collegato a: ";
    adj_node *linked = get_adjlist(g, cur->inf.id);
    while (linked != NULL) {
      cout << search_pi(pi, get_adjnode(linked)).nome << ", ";
      linked = linked->next;
    }
    cout << endl;
    cur = cur->pun;
  }
  debug_print("exiting stampa mappa");
}

/**
 * @brief stampa il percorso da node a tutti gli altri punti di interesse raggingibili passando per pi dello stesso tipo
 * 
 * @param g mappa, input
 * @param node id del nodo di partenza
 * @param pi lista di pi, input
 */
void trip(graph g, int node, const lista pi, bool *visited) {
  debug_print("entering trip");
  adj_node *cur = get_adjlist(g, node);
  const char node_tipo = search_pi(pi, node).tipo;
  while (cur != NULL) {
    place tmp = search_pi(pi, get_adjnode(cur));
    if (!visited[tmp.id-1] && tmp.tipo == node_tipo) {
      cout << tmp.id << " ";
      visited[tmp.id-1] = true;
      trip(g, tmp.id, pi, visited);
    }
    cur = cur->next;
  }
  cout << endl;
  debug_print("entering trip");
}

/**
 * @brief estrae la sottolista di pi, di punti di interesse con tipo uguale a 'tipo'
 * 
 * @param pi input list
 * @param tipo tipo del punto di interesse da estrarre
 * @return lista sottolista di pi
 */
lista genera(lista pi, char tipo) {
  lista res = NULL;
  elem *cur = pi;
  while (cur != NULL) {
    if (cur->inf.tipo == tipo)
      res = ord_insert_elem(res, new_elem(cur->inf));
    cur = cur->pun;
  }
  return  res;
}

int main(int argc, char *argv[]) {
  if (argc < MIN_ARGC) {
    cerr << "Usage: " << argv[0] << " places_data_filename places_graph_filename" << endl;
    return 1;
  }

  int pi_caricati = 0;
  lista lista_pi = NULL;
  if ((pi_caricati = carica(argv[1], lista_pi)) == 0) {
    cerr << "Error while reading file " << argv[1] << endl;
    return 2;
  }

  #ifdef DEBUG
  cout << "sono stati letti " << pi_caricati << " punti di interesse" << endl;
  #endif
  stampa_pi(lista_pi);

  int id = 0;
  do {
    cout << "Id da cercare [-1 per terminare]: "; cin >> id;
    if (id == -1) break;

    place res = search_pi(lista_pi, id);
    if (res.id == -1)
      cout << "Punto di interesse inesistente" << endl;
    else
      print(res);

  } while (id != -1);

  graph g;
  if (!mappa(argv[2], pi_caricati, g)) {
    cerr << "Error while reading file " << argv[2] << endl;
    return 3;
  }

  stampa_mappa(g, lista_pi);

  bool *visited = new bool[g.dim];
  cout << "Id di partenza per trip: "; cin >> id;
  visited[id-1] = true;
  trip(g, id, lista_pi, visited);

  char tipo;
  cout << "Tipo di punto di interesse da generare [e|m|p]: "; cin >> tipo;
  lista l = genera(lista_pi, tipo);
  stampa_pi(l);

  return 0;
}