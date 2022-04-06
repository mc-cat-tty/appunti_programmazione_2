#include "tipo.h"

typedef elem* lista;

const int STR_DIM = 51;

struct elem {
       char inf[STR_DIM] ;
       elem* pun ;
       elem* prev;
};

tipo_inf head(lista);
elem* search(lista, tipo_inf);
elem* new_elem(tipo_inf);
lista cancella(lista, tipo_inf);

// Primitive indipendenti dal tipo di dati
lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);