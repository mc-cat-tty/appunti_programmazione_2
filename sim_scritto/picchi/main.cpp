/*
Un picco di una sequenza S di valori è un elemento strettamente maggiore dei suoi due
elementi contigui o maggiore dell’elemento contiguo, se l’altro manca.
Esempio: Nella sequenza [4, 3, 3, 3, 0, −1, 3, −3, 4, 2], 4, 3 e 4 sono picchi.
Data una sequenza di valori interi memorizzati in una lista doppia dichiarata sotto, si scriva la
funzione ricorsiva int picchi(lista) che restituisce il numero di picchi contenuti nella
lista.
Esempio: Sulla sequenza [4, 3, 3, 3, 0, −1, 3, −3, 4, 2] deve restituire 3.
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


int picchi(lista l) {
	if (l == NULL)
		return 0;
	
	if ((l->prev == NULL || l->prev->inf < l->inf) && (l->pun == NULL || l->pun->inf < l->inf))
		return picchi(l->pun)+1;
	else
		return picchi(l->pun);
}

int main() {
	int num;
	cout << "Numero elementi: "; cin >> num;
	lista l = crealista(num);
	stampalista(l);

	cout << "Picchi: " << picchi(l) << endl;
    return 0;
}
