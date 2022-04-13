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


/**********************************************/
/* DEFINIZIONE MODULO "MAIN"                  */
/**********************************************/
int main()
{
    int n;
    char v[51];
    int scelta;
    bool ordinata;
    lista testa=NULL;
    elem* ris;

    do{
    		cout<< "Cosa vuoi fare?"<<endl;
    		cout<< "1: creare una lista (ordinata)"<<endl;
    		cout<<"2:cancellare valori dalla lista"<<endl;
    		cout<<"3: stampare la lista"<<endl;
    		cout<<"4:cercare valori nella lista"<<endl;
    		cout<<"5:esci"<<endl;
    		cin>>scelta;
    		switch(scelta){
    		case 1: cout << "Come vuoi creare la lista (1:ordinata,0:non ordinata)?"<<endl;
    		cin>>ordinata;
    		cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    		cin >> n;
    		testa = crealista(n,ordinata);
    		break;
    		case 2: cout<<"Inserire il valore da cancellare:"<<endl;
    		cin>>v;
    		testa=cancella(testa,v);
    		break;
    		case 3: stampalista(testa);
    		break;
    		case 4: cout << "Valore da cercare"<<endl;
    		cin>>v;
    		if(ordinata)
    			ris=ord_search(testa,v);
    		else
    			ris=search(testa,v);
    		if(ris!=NULL)
    			naviga(ris);

    		else
    			cout<<"Valore non presente"<<endl;
    		break;
    		case 5: cout<<"Ciao, ciao!!"<<endl;}
    		}while(scelta!=5);
    return 0;
}
