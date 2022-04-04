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

/***************************************/
/* HEADER MODULO FUNZIONI APPLICAZIONE */
/***************************************/
void stampalista(lista);
lista crealista(int);
void naviga(elem*);

/********************************************/
/* DEFINIZIONE MODULO FUNZIONI APPLICAZIONE */
/********************************************/
void stampalista(lista p) {
	cout<<"[" << endl;
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")"<<endl;
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}

lista crealista(int n) {
      lista testa = NULL ;
	  char str[STR_DIM];
      for (int i = 1 ; i <= n ; i++) {
          cout << "URL " << i << ": "; cin >> str;
          testa=insert_elem(testa, new_elem(str));
      }
      return testa ;
}

void naviga(elem* e) {
	char scelta;
	cout<< "Trovato!!" << endl;
	do{
		cout<< "Cosa vuoi fare (B per backward,F per forward, S per stop): "<<endl; cin>>scelta;
	    if(scelta=='F' && tail(e)!=NULL) {
	    			cout<<head(tail(e))<<endl;
	    			e=tail(e);}
	    else
	    		if(scelta=='B' && prev(e) !=NULL) {
	    			cout<<head(prev(e))<<endl;
	    			e=prev(e);}
	    		else cout<<"Elemento non esistente!!"<<endl;}		while(scelta!='S');
}

