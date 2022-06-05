/*
Date le seguenti dichiarazioni di albero di valori interi e relative primitive, scrivere la
funzione booleana path(node*e, int x) che restituisce true se esiste un cammino dal nodo e
un nodo con valore x, false altrimenti.
*/

struct node {
    inf_t inf;
    node* fist_child;
    node* next_sibling;
};
typedef node* tree;
inf_t get_info(node*);
node* get_first_child(node*);
node* get_next_sibling(node*);

bool path(node *n, inf_t v) {
    if (compare(get_info(n), v) == 0)
        return true;
        
    node *cur = get_first_child(n);
    while (cur != NULL) {
        if (path(cur, v))
            return true;
        cur = get_next_sibling(cur);
    }
    return false;
}