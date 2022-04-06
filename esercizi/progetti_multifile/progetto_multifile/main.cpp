#include <iostream>
#include <cstring>

#include "helper_applicazione.h"
#include "liste_tipo.h"

using namespace std ;


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

		switch(scelta) {
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
