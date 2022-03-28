#include <iostream>
#include <cstring>

using namespace std ;

const int STR_DIM = 51;

struct elem
{
       char inf[STR_DIM] ;
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
		cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")"<<endl;
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}

elem* new_elem(char *val) {
	elem* aux_elem = new elem;
	strcpy(aux_elem->inf, val);
	aux_elem->pun = aux_elem->prev = NULL;
	return aux_elem;
}

lista crealista(int n)
{
      lista testa = NULL ;
	  char str[STR_DIM];
      for (int i = 1 ; i <= n ; i++) {
          cout << "URL " << i << ": "; cin >> str;
          testa=insert_elem(testa, new_elem(str));
      }
      return testa ;
}

lista cancella(lista l, char* v){
	elem* e;
	while((e=search(l,v))!=NULL){
		cout<<"Cancello un elemento con valore " << v << endl;
		l=delete_elem(l,e);}
	cout<<"Fine cancellazione!!"<<endl;
	return l;
}

void naviga(elem* e){
	char scelta;
	cout<< "Trovato!!" << endl;
	do{
		cout<< "Cosa vuoi fare (B per backward,F per forward, S per stop): "<<endl; cin>>scelta;
	    if(scelta=='F' && tail(e)!=NULL){
	    			cout<<head(tail(e))<<endl;
	    			e=tail(e);}
	    else
	    		if(scelta=='B' && prev(e) !=NULL){
	    			cout<<head(prev(e))<<endl;
	    			e=prev(e);}
	    		else cout<<"Elemento non esistente!!"<<endl;}		while(scelta!='S');
}
int main()
{
    int n;
    char v[51];
    int scelta;
    lista testa=NULL;
    elem* ris;

    do{
		cout << "Cosa vuoi fare?" << endl;
		cout << "1. creare una lista" << endl;
		cout << "2. cancellare valori dalla lista" << endl;
		cout << "3. stampare la lista" << endl;
		cout << "4. cercare valori nella lista" << endl;
		cout << "5. esci"<<endl;
		cin >> scelta;

		switch(scelta){
			case 1:
				cout << "Inserire il numero di elementi da inserire nella lista: "; cin >> n;
				testa = crealista(n);
			break;
			case 2:
				cout << "Inserire il valore da cancellare: "; cin >> v;
				testa = cancella(testa,v);
				break;
			case 3:
				stampalista(testa);
				break;
			case 4:
				cout << "Valore da cercare: "; cin >> v;
				ris = search(testa,v);
				if (ris != NULL)
					naviga(ris);
				else
					cout << "Valore non presente" << endl;
				break;
			case 5:
				return 0;
		}
		cout << endl;
	} while(scelta!=5);
    return 0;
}
