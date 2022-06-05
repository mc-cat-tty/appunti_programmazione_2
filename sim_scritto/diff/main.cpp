/*
Scrivere la procedura ricorsiva diff(lista l1, lista l2) che stampa l’elenco delle
persone che sono presenti nella lista ordinata l1 ma non nella lista ordinata l2. La
procedura deve sfruttare l’ordinamento implementando un algoritmo con complessità O(n).
*/

#include <iostream>
#include <cstring>

using namespace std ;

struct elem
{
       int inf;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

// primitive

int head(lista p){return p->inf;}

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

elem* search(lista l, int v){
	while(l!=NULL)
		if(head(l) == v)
			return l;
		else
			l=tail(l);
	return NULL;}

// funzioni

void stampalista(lista p)
{
	cout<<"[";
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")";
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}


lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
          cout<<"URL "<<i<<": " ;
          cin>>p->inf;
          p->pun=p->prev=NULL;
          testa=insert_elem(testa,p);
      }
      return testa ;
}

lista cancella(lista l, int v){
	elem* e;
	while((e=search(l,v))!=NULL){
		cout<<"Cancello un elemento con valore "<<v<<endl;
		l=delete_elem(l,e);}
	cout<<"Fine cancellazione!!"<<endl;
	return l;
}

void naviga(elem* e){
	char scelta;
	cout<< "Trovato!!";
	do{
		cout<< "Cosa vuoi fare (B per backward,F per forward, S per stop)"<<endl;
		cin>>scelta;
	    if(scelta=='F' && tail(e)!=NULL){
	    			cout<<head(tail(e))<<endl;
	    			e=tail(e);}
	    else
	    		if(scelta=='B' && prev(e) !=NULL){
	    			cout<<head(prev(e))<<endl;
	    			e=prev(e);}
	    		else cout<<"Elemento non esistente!!"<<endl;}		while(scelta!='S');
}


void diff(lista l1, lista l2) {
	elem *cur1 = l1;
	elem *cur2 = l2;

	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->inf == cur2->inf) {
			cur1 = cur1->pun;
			cur2 = cur2->pun;
		}
		else if (cur1->inf < cur2->inf) {
			cout << cur1->inf << " ";
			cur1 = cur1->pun;
		}
		else {
			cout << cur2->inf << " ";
			cur2 = cur2->pun;
		}
	}

	while (cur1 != NULL) {
		cout << cur1->inf << " ";
		cur1 = cur1->pun;
	}

	while (cur2 != NULL) {
		cout << cur2->inf << " ";
		cur2 = cur2->pun;
	}
	
	cout << endl;
}

int main() {
	int num;
	cout << "Numero elementi lista 1: "; cin >> num;
	lista l1 = crealista(num);

	cout << "Numero elementi lista 2: "; cin >> num;
	lista l2 = crealista(num);
	
	stampalista(l1);
	stampalista(l2);

	diff(l1, l2);
    return 0;
}
