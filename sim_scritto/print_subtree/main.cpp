/*
Date le seguenti dichiarazioni per un binary search tree con chiave intera e le relative primitive:
typedef int tipo_key;
struct bnode {
tipo_key key;
bnode* left;
bnode* right;
bnode* parent;
};
tipo_inf get_value(bnode*); //restituisce il valore del nodo in ingresso
bst get_left(bst); //restituisce il sottoalbero sinistro dell’albero in ingresso
bst get_right(bst); //restituisce il sottoalbero destro dell’albero in ingresso
bnode* bst_search(bst,tipo_key);

Scrivere la funzione void print_subtree(bst b, int x, int y) che dato un valore intero x presente nel BST b,
stampi i valori nel sottoalbero radicato nel nodo che contiene x minori di y. La funzione
deve sfruttare le
caratteristiche del BST.
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

bnode* bst_search(const bst b, key_t s) {
    if (b == NULL)
        return NULL;
    if (b->key == s)
        return b;
    if (s > b->key)
        return bst_search(b->right, s);
    if (s < b->key)
        return bst_search(b->left, s);
}

void print_subtree(const bst b, int x, int y) {
	static bool first_run = true;
	if (first_run) {
		first_run = false;
		print_subtree(bst_search(b, x), x, y);
	}
	else {
		if (b == NULL)
			return;
		if (b->key < y) {
			cout << b->key << " ";
			print_subtree(b->left, x, y);
			print_subtree(b->right, x, y);
		}
		else if (b->key >= y)
			print_subtree(b->left, x, y);
	}
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
	    //    cout << "Inserisci valore informativo (stringa): " << endl;
	    //    cin >> i;
	       b=bst_newNode(k, "");
	       cout<<"Nodo creato:"<<b<<get_key(b)<<get_value(b)<<endl;
	       bst_insert(t,b);
	       cout<<"Per terminare digitare 0 altrimenti 1: ";
	       cin>>risp;
	    }
	while(risp);
	print_BST(t);
	int x, y;
	cout << "Inserisci x: "; cin >> x;
	cout << "Inserisci y: "; cin >> y;
	print_subtree(t, x, y);
	cout << endl;
}
