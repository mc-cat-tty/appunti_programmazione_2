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

/****************************/
/* DEFINIZIONE MODULO LISTE */
/****************************/
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