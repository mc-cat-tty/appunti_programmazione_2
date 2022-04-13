/*
  Scrivere un programma per la gestione di liste doppie.
  Il programma presenta un menù all'utente che può
  - creare una lista di n valori (volendo ordinata)
  - cancellare tutti tutti gli elementi contenente un valore dato dalla lista
  - stampare la lista
  - cercare valori nella lista
  Se la lista è ordinata la ricerca deve richiamare ord_search() altrimenti search().
*/

#include <iostream>
#include <cstring>

using namespace std ;


#include "tipo.h"
#include "liste.h"
#include "fun-app.h"



/***************************************************/
/* DEFINIZIONE MODULO "funzioni dell'applicazione" */
/***************************************************/

void stampalista(lista p)
{
	cout<<"[";
	while (p != NULL) {
		print(head(p)); // stampa valore
		cout<<" ";
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}


lista crealista(int n, bool ord)
{
	char url[80];
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          cout<<"URL "<<i<<": " ;
          cin>>url;
		  elem* p = new_elem(url);
          if(ord)
        	  	  testa=ord_insert_elem(testa,p);
          else
        	  	  testa=insert_elem(testa,p);
      }
      return testa ;
}

lista cancella(lista l, tipo_inf v){
	elem* e;
	while((e=search(l,v))!=NULL){
		cout<<"Cancello un elemento con valore ";
		print(v);
		cout<<endl;
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
	    			print(head(tail(e)));
					cout<<endl;
	    			e=tail(e);}
	    else
	    		if(scelta=='B' && prev(e) !=NULL){
	    			print(head(tail(e)));
					cout<<endl;
	    			e=prev(e);}
	    		else cout<<"Elemento non esistente!!"<<endl;}		while(scelta!='S');
}

