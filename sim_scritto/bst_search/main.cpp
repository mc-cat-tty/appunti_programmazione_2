/*
Date le seguenti dichiarazioni per un binary search tree con chiave rappresentata da una stringa,
assumendo che i nodi siano ordinati in ordine alfanumerico:
struct bnode {
char* key;
bnode* left;
bnode* right;
bnode* parent;
};
typedef bnode* bst;

Scrivere il codice della primitiva per la ricerca di un nodo
bnode* bst_search(bst,char*);
in forma ricorsiva
*/

#define DEBUG

#include <iostream>
using namespace std;

#include "tipo.h"
#include "bst.h"

void print_BST(bst b){
	if(get_left(b)!=NULL)
		print_BST(get_left(b));
	print_key(get_key(b));
	cout<<"  ";
	print(get_value(b));
	cout<<endl;
	if(get_right(b)!=NULL)
	print_BST(get_right(b));

}

bnode* bst_search(const bst b, const key_t s) {
    if (b == NULL)
        return NULL;
    if (b->key == s)
        return b;
    if (s > b->key)
        return bst_search(b->right, s);
    if (s < b->key)
        return bst_search(b->left, s);
}

int main(){
	bst t=NULL;
	bool risp;
	int k;
	char i[30];
	bnode* b;

	do {
		cout << "Inserisci valore di chiave (intero): " << endl;
	       cin >> k;
	       cout << "Inserisci valore informativo (stringa): " << endl;
	       cin >> i;
	       b=bst_newNode(k,i);
	       cout<<"Nodo creato:"<<b<<get_key(b)<<get_value(b)<<endl;
	       bst_insert(t,b);
	       cout<<"Per terminare digitare 0 altrimenti 1: ";
	       cin>>risp;
	    }
	while(risp);
	print_BST(t);
	do {
			cout << "Inserisci valore di chiave da cercare: " << endl;
		       cin >> k;
		       if((b=bst_search(t,k))!=NULL){
		    	   cout<<"Nodo trovato: ";
		    	   print_key(get_key(b));
		    	   	cout<<"  ";
		    	   	print(get_value(b));
		    	   	cout<<endl;
		       }
		       else
		    	   cout<<"Nodo non trovato!!";
		       cout<<"Per terminare digitare 0 altrimenti 1: ";
		      	       cin>>risp;
		    }
		while(risp);

}
