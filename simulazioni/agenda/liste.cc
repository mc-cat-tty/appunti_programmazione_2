#include <iostream>
#include <cstring>

using namespace std ;

#include "liste.h"

/*******************************/
/* DEFINIZIONE MODULO "liste" */
/*******************************/

tipo_inf head(lista p){return p->inf;}

elem* search(lista l, tipo_inf v){
	while(l!=NULL)
		if(compare(head(l),v)==0)
			return l;
		else
			l=tail(l);
	return NULL;}


elem* new_elem(tipo_inf inf){
	    elem* p = new elem ;
	    copy(p->inf,inf);
	    p->pun=p->prev=NULL;
		return p;

	}


lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	if(l!=NULL)
		l->prev=e;
	e->prev=NULL;
	return e;
}

lista delete_elem(lista l, elem* e){

		if(l==e)
			l=e->pun; // e è la testa della lista
		else // e non è la testa della lista
			(e->prev)->pun = e->pun;
		if(e->pun!=NULL)
			(e->pun)->prev=e->prev;
		delete e;
		return l;
}
