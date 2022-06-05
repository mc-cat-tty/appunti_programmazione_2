/*
Si scriva la funzione lista sposta(lista& l, int soglia) che sposta dalla lista l
tutti gli elementi i cui valori sono sotto il valore soglia e restituisce la lista degli elementi
spostati. La funzione non deve fare allocazioni. Ad esempio data la lista [1,2,3,4] e il valore di
soglia 3 la funzione restituisce la testa della lista [1,2] mentre l diventa [3,4].
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
		cout<< "Cosa vuoi fare (B per backward, F per forward, S per stop)"<<endl;
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


lista sposta(lista &l, int threshold) {
	lista res = NULL;
	elem *res_last = NULL;
	elem *cur = l;
	elem *prev = NULL;

	while (cur != NULL) {
		if (cur->inf < threshold) {
			if (prev == NULL) {
				l = l->pun;
				cur->pun = res;

				if (res==NULL) {
					res = res_last = cur;
				}
				else {
					res_last->pun = cur;
					res_last = cur;
				}
				res_last->pun = NULL;

				cur = l;
			}
			else {
				prev->pun = cur->pun;
				cur->pun = res;

				if (res==NULL) {
					res = res_last = cur;
				}
				else {
					res_last->pun = cur;
					res_last = cur;
				}
				res_last->pun = NULL;

				cur = prev->pun;
			}
		}
		else {
			prev = cur;
			cur = cur->pun;
		}
	}

	return res;
}

int main() {
	int num;
	cout << "Numero elementi: "; cin >> num;
	lista l = crealista(num);
	
	stampalista(l);

	lista under_threshold = sposta(l, 50);
	stampalista(l);
	stampalista(under_threshold);
    return 0;
}
