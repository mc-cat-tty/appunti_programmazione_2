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

