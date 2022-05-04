# Alberi binari
Gli alberi binari sono un caso particolare degli alberi n-ari, dove il numero dei figli per ogni nodo è al massimo due.

Negli alberi binari si distringue tra figlio destro e figlio sinistro.

La struttura dati per rappresentare i nodi degli alberi binari mantiene un riferimento esplicito al figlio destro e al figlio sinistro.

```C
struct bnode {
    tipo_inf inf;
    bnode* left;
    bnode* right;
    bnode* parent;
}

typedef bnode* btree;
```

L'*albero binario di ricerca* è un albero con una peculiarità: il figlio sinistro è sicuramente minore del padre, mentre il figlio destro è sicuramente maggiore o uguale.

## Alberi di ricerca
Gli alberi di ricerca sono strutture dati dinamiche ad albero usate per localizzare velocemente chiavi all'interno di un insieme di elementi.

Esistono diversi tipi di albero di ricerca, in base alla proprietà di ordinamento che si adotta. È importante che l'ordinamento sia mantenuto per tutti gli elementi dell'albero.

Un **BST** è un albero con le seguenti proprietà:
 - ogni nodo n ha
  - contenuto informativo value(n)
  - chiave key(n) presa da un dominio totalmente ordinato
 - dato un nodo del sottoalbero sinistro di n, esso ha chiave minore di n
 - dato un nodo del sottoalbero destro di n, esso ha chiave maggiore o uguale di n

## Ribilanciamento
L'operazione di ribilanciamento parte da un albero binario di ricerca "brutto" e cambiando la radice, in modo da diminuire il numero di livelli.

## Implementazione BST
```C
typedef int tipo_key;
typedef char* tipo_inf;
struct bnode {
    tipo_key key;
    tipo_inf inf;
    // ...
}
```

## Primitive
Assunzione: supponiamo che i valori di chiave siano univoci nel BST

Le primitive associate ad un BST sono (costruzione, get, aggiornamento, accesso):
 - `bnode* new_node(tipo_key, tipo_inf)` -> costruisce il nodo associando la chiave giusta
 - ...
 - getters
 - `void bst_insert(bst&, bnode*)`  Il bst è passato per riferimento perchè nel caso dell'inserimento della radice devo modificare l'entry point.
 - `void bst_delete(bst&, bnode*)`
 - `bnode* bst_search(bst, tipo_key)`

### Insert
Devo inserire il nodo in modo tale che venga mentenuta la proprietà di ordinamento: partendo dalla radice il *percorso di scanzione* dipende dal confronto tra il nodo corrente *z* e il nodo da inserire *n*.

 - Se key(n) < key(z) -> la scansione prosegue a sinistra
 - Se key(n) >= key(z) -> la scanzione prosegue a destra

L'inserimento diventa costoso su BST corposi. L'altezza massima di nodi che visitiamo è pari all'altezza dell'albero.

Nell'inserimento mi fermo quando arrivo ad un ramo che è NULL. Quando devo inserire un valore che è uguale al valore contenuto nella foglia devo prendere una decisione in base a come è stata definita la relazione d'ordine. In generale è buona norma non avere chiavi uguali all'interno del BST. Nel caso in cui avessi chiavi uguali sono costretto a ritornare il nodo associato alla prima chiave.

## Cancellazione elemento
`void bst_delete(bst &t)`

### Nodo foglia
Lo elimino senza problemi.

### Nodo con un solo figlio

### Nodo con due figli
Voglio eliminare n

Successori di n = sottoalbero destro di n
Predecessori di n = sottoalbero sinistro di n

Trovo il minore dei successori di n: vado a destra una volta, poi sempre a sinistra (minore dei successori). Ovvero il nodo più a sinistra del sottoalbero destro.

Sostituisco il nodo n con il minore dei successori, poi elimino il minore dei successori dall'albero. Devo fare questo per mantenere la relazione d'ordine.

## Costo ricerca e aggiornamento BST
Il costo è proporzionale alla profondità dell'albero. La situazione peggiore è quella in cui ho una radice e un solo ramo che parte da essa. La situazione migliore si ha nel caso in cui l'albero sia bilanciato.

## Albero AVL
Albero bilanciato = la profondità del sottoalbero destro e sinistro differiscono di una unità.


In questa struttura dati l'albero è autobilanciato.