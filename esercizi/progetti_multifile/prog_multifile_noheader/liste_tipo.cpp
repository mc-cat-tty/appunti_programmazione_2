#include <iostream>
#include <cstring>

using namespace std ;

/****************************/
/* HEADER MODULO LISTE-TIPO */
/****************************/
const int STR_DIM = 51;

struct elem {
       char inf[STR_DIM] ;
       elem* pun ;
       elem* prev;
};

typedef elem* lista ;
char* head(lista);
elem* search(lista, char*);
elem* new_elem(char *);
lista cancella(lista, char*);

/***********************/
/* HEADER MODULO LISTE */
/***********************/
// Primitive indipendenti dal tipo di dati
lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);

/*********************************/
/* DEFINIZIONE MODULO LISTE-TIPO */
/*********************************/
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