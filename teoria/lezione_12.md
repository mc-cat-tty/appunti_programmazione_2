# Alberi
> Struttura dati dinamica non lineare: ogni nodo può avere più di un successore (o discendente)

La *radice* è il primo elemento dell'albero. I discendenti di un nodo sono chiamati *figli*, di un certo *padre*.
I nodi con lo stesso padre sono *fratelli*. Nodi senza discendenti sono *foglie*. Ogni nodo, tranne la radice, è la radice di un albero contenuto nell'albero di partenza, detto *sottoalbero*.

Negli alberi n-ari ogni nodo può avere al più n figli. Negli alberi *binari* ogni nodo ha al massimo due figli.

## Implementazione degli alberi
Esistono diverse rappresentazioni degli alberi in memoria:
 - vettore di padri
 - lista linkata con più puntatori al successore -> usa i puntatori ma ha il problema dello spreco di memoria
 - rappresentazione primo-figlio/fratello -> si evita lo spreco di puntatori ed è più facile aumentarne la cardinalità al bisogno

Ogni nodo contiene:
 - campo informativo
 - puntatore al primo figlio (null nel caso delle foglie)
 - puntatore al prossimo fratello

Di fatto questa rappresentazione utilizza una "lista a due dimensioni" e permette quindi di memorizzare un qualsiasi tipo di albero.

Osservazione: si può aggiungere un puntatore al padre, con maggior utilizzo di memoria. Rappresentazione padre/primo-figlio/fratello.

## Codice
```c
struct node {
    tipo_inf inf;
    node* parent;
    node* first_child;
    node* next_sibling;
}

typedef node* tree;

tree root;
```

## Primitive
```c
node *new_node(tipo_inf i);  // crea un nuovo nodo che contiene l'informazione i
void insert_child(tree p, tree c);  // inserisce il sottoalbero radicato in c come primo figlio di p
void insert_sibling(node* n, tree t);  // inserisce t come fratello successivo di n
```

Il primo parametro di `insert_child` e `insert_sibling` non è passato per riferimento perchè non devo modificare il puntatore, ma l'area di memoria da esso puntata.

## insert_child
1. aggiorno il fratello di c
2. aggiorno il padre di c
3. aggiorno il primo figlio di p

## insert_sibling
1. aggiorno il fratello di t
2. aggiorno il padre di t
3. aggiorno il fratello di n

## Esercizio
Creare il modulo albero che contiene la strutture dati e primitive per la gestione di un albero di stringhe.

