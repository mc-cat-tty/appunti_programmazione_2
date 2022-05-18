# Visite di grafi
Dato un grafo G=(V, E) visitarlo significa, a partire da un vertice _v_, visitare tutti i vertici appartenenti a V attraverso gli archi E.

Sia la BFS che la DFS usano un array booleano ausiliario _visited_ in cui viene memorizzato se il grafo in posizione _i_ è stato visitato o meno.

## Visita BFS iterativa
Pseudocodice:
```c
visitaBFS(grafo G=(V, E), vertice r):
    visited[V] = FALSE
    new queue q
    q.enqueue(r)
    visited[r] = TRUE
    while (q.is_not_empty()):
        u = q.dequeue()
        // VISITA
        for all (u, v) € E:
            if (!visited[v]):
                visited[v] = TRUE
                q.enqueue(v)
```

## Esercizio
Implementare il modulo `queue_bfs` e il modulo `bfs` che contenga una funzione per la visita bfs e una funzione `connected` che restituisca true se il grafo è connesso.

## Componenti connesse
Dato un grafo G non orientato, una componente connessa (**connected components**) è un sottografo di G connesso e massimale di G (cioè non posso arrivare ad altri nodi, perchè quello è il massimo numero di nodi connessi a partire da un nodo di partenza).

## Albero di copertura
Durante una visita BFS si possono memorizzare i padri di ogni nodo nell'array dei padri. Se l'albero BFS include tutti i vertici di G, allora viene chiamato **spanning tree** o **albero di copertura**.

## Algoritmo di Dijkstra
Risolve il problema dei **cammini minimi** da sorgente unica in un grafo pesato (pesi non negativi): ritorna l'albero delle visite che minimizza il costo del percorso tra la src e tutti gli altri nodi.

### Tecnica del rilassamento
Usata da Dijkstra e altri algoritmi per la ricerca dei cammini minimi.

Per ogni vertica viene mantenuta la stima del cammino minimo, che rappresenta il limite superiore del peso di quel cammini minimo dalla sorgente al vertice in questione. Questo limite superiore viene aggiornato durante il processo di rilassamento, che permette di migliorare il cammino da u a v o al peggio lasciarlo invariato.

### Inizializzazione
 1. Il costo per arrivare ad ogni vertice viene posto a +inf; il costo della sorgente è zero
 2. L'insime S dei vertici il cui costo finale per arrivare dalla sorgente è stato determinato viene posto a insieme vuoto

### Iterazioni
 3. Si seleziona il vertice che fino a quel momento è raggiungibile con il minor peso
 4. Il vertice estratto sopra viene aggiunto all'insieme S
 5. Rilasso tutti gli archi

### Rilassamento
 6. Valuto se a partire dal vertice appena estratto riesco a raggiungere i vertici adiacenti con un costo migliore
    - se il costo per arrivare a v passando da u è minore rispetto a quello che avevamo prima, il costo viene sovrascritto
    - il padre di v nell'albero di copertura diventa u
    - aggiorno il costo di v nella coda con priorità

Per determinare il cammino minimo da un nodo sorgente ad un nodo destinazione conviene partire dal nodo destinazione e percorrere il vettore dei padri al contrario, fino ad arrivare alla sorgente.

### Strutture dati per l'algoritmo di Dijkstra
 - il grafo viene rappresentato con le liste di adiacenza
 - *dest* vettore dinamico di dimensione V che contiene la stima del cammino minimo
 - *parent* vetture dei padri di dimensione V
 - Q coda con priorità che contiene la coppia (vertice v, dest[v])

## Priority queue
Viene implementata come lista ordinata dove gli elementi vengono mantenuti ordinati in ordine crescente per peso w.

Primitive:
 - `priority_queue enqueue(priority_queue q, int i, float w)`: mantiene la proprietà di ordinamento
 - `int dequeue(priority_queue &q)`: ritorna l'elemento in testa alla lista e lo elimina
 - `int min_queue(priority_queue &q)`: restituisce l'elemento con peso minimo, senza eliminarlo
 - `priority_queue decrease_priority(priority_queue q, int i, float d)`: aggiorna la priorità di i con il valore d; mantiene la proprietà di ordinamento
 - `bool is_empty(priority_queue q)`: ritorna true se la coda è vuota


Dato che il valore infinito non esiste in C++ possiamo usare `FLT_MAX` della libreria `float.h`.

## Alogritmo di Prim
=> ricerca di un albero di copertura minimo (**minimum spanning tree**) a partire da un grafo non orientato e un nodo sorgente. Quindi a differenza dell'algoritmo di Dijstra trova il costo TOTALE minimo per raggiungere i nodi del grafo.

La differenza principale si trova nella funzione di rilassamento, all'interno del confronto: `dist[v] > w(u, v) ?`

