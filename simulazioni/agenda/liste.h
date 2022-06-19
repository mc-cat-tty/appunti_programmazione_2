#pragma once

#include "tipo.h"


struct elem {
       tipo_inf inf;
       elem* pun ;
       elem* prev;
};

typedef elem* lista ;
	
lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);

tipo_inf head(lista);
elem* new_elem(tipo_inf);
elem* search(lista, tipo_inf);

/**
 * @brief insert element in the list while keeping it sorted
 * 
 * @return lista freshly updated list
 */
lista insert_elem_sorted(lista, elem*);
