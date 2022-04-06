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