/*
Data la seguente de nizione di lista doppia intera, scrivere la funzione booleana palindroma(lista l) che restituisce true se l
è palindroma ovvero le sequenze dei valori della lista lette dal primo all'ultimo e dall'ultimo al primo sono le stesse, false
altrimenti (ad esempio [1,4,2,4,1] è palindroma, [1,4,2,3,1] non è palindroma)
*/

#include <iostream>
#include <cstring>

using namespace std ;

struct elem
{
       char inf[51];
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

// primitive

char* head(lista p){return p->inf;}

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

elem* search(lista l, char* v){
	while(l!=NULL)
		if(strcmp(head(l),v)==0)
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

lista cancella(lista l, char* v){
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

bool palindroma(lista l) {
	elem *r = l;
	while (r->pun != NULL)
		r = r->pun;
	elem *f = l;
	while (f != NULL) {
		if (strcmp(f->inf, r->inf) != 0)
			return false;
		f = f->pun;
		r = r->prev;
	}
	return true;
}

void stampa_ric(lista l) {
	if (l == NULL)
		return;
	cout << l->inf << " ";
	stampa_ric(l->pun);
	cout << endl;
}

int main() {
	int num;
	cout << "Numero elementi: "; cin >> num;
	lista l = crealista(num);
	stampalista(l);
	cout << palindroma(l) << endl;
	stampa_ric(l);
    return 0;
}
