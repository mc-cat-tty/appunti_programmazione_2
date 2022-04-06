#include <iostream>
#include <cstring>

#include "liste_tipo.h"
#include "liste.h"

using namespace std ;

char* head(lista p) {
    return p->inf;
}

elem* search(lista l, char* v) {
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

lista cancella(lista l, char* v) {
	elem* e;
	while((e=search(l,v))!=NULL) {
		l=delete_elem(l,e);
    }
	return l;
}