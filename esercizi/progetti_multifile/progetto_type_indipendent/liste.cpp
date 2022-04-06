#include <iostream>
#include <cstring>

#include "liste.h"

using namespace std ;


lista tail(lista p) {
    return p->pun;
}

lista prev(lista p) {
    return p->prev;
}

lista insert_elem(lista l, elem* e) {
	e->pun=l;
	if(l!=NULL)
		l->prev=e;
	e->prev=NULL;
	return e;
}

lista delete_elem(lista l, elem* e) {
		if(l==e)
			l=e->pun; // e è la testa della lista
		else // e non è la testa della lista
			(e->prev)->pun = e->pun;
		if(e->pun!=NULL)
			(e->pun)->prev=e->prev;
		delete e;
		return l;
}

tipo_inf head(lista p) {
    return p->inf;
}

elem* search(lista l, tipo_inf v) {
	while(l!=NULL)
		if(strcmp(head(l),v)==0)
			return l;
		else
			l=tail(l);
	return NULL;
}

elem* new_elem(char *val) {
	elem* aux_elem = new elem;
	strcpy(aux_elem->inf, val);
	aux_elem->pun = aux_elem->prev = NULL;
	return aux_elem;
}

lista cancella(lista l, tipo_inf v) {
	elem* e;
	while((e=search(l,v))!=NULL) {
		l=delete_elem(l,e);
    }
	return l;
}