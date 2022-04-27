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
 - `bnode* new_node(tipo_inf)` -> costruisce il nodo associando la chiave giusta
 - ...
 - getters
 - `void bst_insert(bst&, bnode*)`
 - `void bst_delete(bst&, bnode*)`
 - `bnode* bst_search(bst, tipo_key)`

### Insert
Devo inserire il nodo in modo tale che venga mentenuta la proprietà di ordinamento: partendo dalla radice il *percorso di scanzione* dipende dal confronto tra il nodo corrente *z* e il nodo da inserire *n*.

 - Se key(n) < key(z) -> la scansione prosegue a sinistra
 - Se key(n) >= key(z) -> la scanzione prosegue a destra

L'inserimento diventa costoso su BST corposi. L'altezza massima di nodi che visitiamo è pari all'altezza dell'albero.

