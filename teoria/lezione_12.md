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

[tree_module](../esercizi/alberi/tree_module)

# Visite di alberi
Visitare un albero: attraversare tutti i nodi per esplorare come un albero è fatto. Esistono due tipologie di visite:
 - DFS - Depth First Search o visita in profondità => visito i nodi dalla radice verso le foglie
    - preordine
    - postordine
    - inordine
 - BFS - Breath First Search o visita in ambiezza => visito i nodi per livello a partire dal livello 0 alla radice

Per ogni tipologia di visita esiste una implementazione ricorsiva e una iterativa.

Esempi:
se mi serve scoprire la strada più breve per arrivare ad una foglia, uso la DFS; se devo valutare le opzioni ad un bivio uso la BFS.

## Visita DFS ricorsiva
Algoritmo:
 1. visito il nodo n
 2. per ogni figlio n' di n -> chiamo visita_dfs_ricorsiva(n')

Questo algo implementa una visita in preordine.

In *preordine* visito n e faccio le chiamate ricorsive. In *postordine* faccio le chiamate ricorsive e visito il nodo. Nel caso della visita *inordine* visito parte dei figli, visito il nodo corrente e visito i figli rimanenti.

Cosa si intende per visita? ogni operazione che coinvolga l'utilizzo dell'informazione contenuta nel nodo.

## Serializzazione di un albero
È un esempio di applicazione di visita DFS ricorsiva.

Problema: dato un albero, lo si vuole salvare su file in modo da recuperare i dati in seguito.

L'albero è una struttura dati non lineare. Lo stesso problema si presenta se vogliamo stampare a video il contenuto dei nodi di un albero.

Caratteristiche:
 - meccanismo di serializzazione non ambiguo
 - funzione biettiva o biunivoca

### Funzione di serializzazione
Ogni nodo n è associato ad una coppia di parentesi bilanciate: `(...)`.

I suoi sottoalberi sono ricorsivamente serializzati, ciascuno con una coppia di parentesi bilanciate.


Dato un albero non vuoto T, con radice n e k figli T1, ..., Tk:
```
serializzazione(n): (n serializzazione(T1), ..., serializzazione(Tk))
```

Per fare il contrario (ricostruire l'albero) => leggo la stringa serializzata a partire da sx verso dx. Il primo nodo che trovo è la radice e a seguire i suoi figli. Ricorsivamente "srotolo" la stringa serializzata.

Si implementa come una semplice visita DFS ricorsiva in preordine.

## Esercizio
Estendi il modulo _tree_ implemendando la procedura `serializza`.

## Altezza di un albero
L'altezza o profondità di un albero è la lunghezza del cammino massimio che va dalla radice alla foglie. Se T è un albero con un solo nodo n, la sua altezza è 0.

Se T è un albero con radice n e k figli, allora la sua altezza è il massimio dell'altezza dei figli più uno (perchè ho percorso un arco per fare radice-figli del primo livello). Per il calcolo dell'altezza si può usare una DFS in post-ordine.

## Esercizio
Implementare una funzione `altezza` che misura il cammino massimo che va dalla radice ad una delle foglie.

## Osservazioni sulla visita di alberi
L'esplorazione di un nodo resta aperta finchè non ho finito di esplorare tutti i suoi sottoalberi.

Nel caso della visita DFS i nodi aperti sono i figli di un nodo padre da cui riprendere la visita quanto un sottoalbero è stato esplorato. Procedo per livelli. Ad ogni livello metto in coda tutti i nodi figli.

## Visita BFS
La visita deve essere gestita con una *queue*. Visito il primo nodo, accodo i figli. Recupero il primo nodo della lista e aggiungo i suoi figli alla lista e continuo così.

Finchè non ho chiuso un livello non passo al successivo perchè ci sono altri elementi dello stesso livello in coda.

### Algoritmo
```cpp
queue q;
q.enqueue(n);
while (!q.is_empty()) {
    n = q.dequeue();
    // visita n
    for (each child of n) {
        q.enqueue(child);
    }
}
```

I _nodi di frontiera_ sono quei nodi, radice di sottoalberi, che non abbiamo ancora visitato completamente.

Vedi il modulo _coda-bfs_.

Attento perchè hai bisogno di un inserimento in coda.

## Dimensione di un albero
Le visite DFS e BFS hanno lo stesso costo, perchè ogni nodo viene visitato esattamente un volta. Quando ho alberi profondo la DFS diventa svantaggiosa, mentre con alberi ampi la BFS è più svantaggiosa.

## Esercizi per casa
Vedi slide 4.2.19