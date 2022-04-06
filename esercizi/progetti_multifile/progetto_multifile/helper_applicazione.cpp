#include <iostream>
#include <cstring>

#include "helper_applicazione.h"
#include "liste.h"

using namespace std;

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

