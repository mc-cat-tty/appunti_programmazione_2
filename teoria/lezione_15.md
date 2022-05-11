# Grafi
Classificazione:
    - pesato
    - non pesato
    
    - diretto (orientato)
    - non diretto (non orientato)


Grafo G = (V, E)

Metodi di rappresentazione: matrici di adiacenza, liste di adiacenza

Il peso (weight) è solitamente un float.

## Matrice di adiacenza
Se il grafo non è pesato inserisco 1 o 0 in base alla presenza dell'arco, altrimenti inserisco P (peso) o 0 in base alla presenza e al costo.

Se il grafo non è orientato la matrice è simmetrica rispetto alla diagonale maggiore.

Se il grafo è orientato la matrice non è simmetrica -> il dato in M[i,j] rappresenta l'arco per andare dal nodo i al nodo j.

La dimensione dell matrice di adiacenza è |V|*|V|

## Liste di adiacenza
Array _Adj_ di |V| liste (una linked list per ogni nodo). La lista Adj[i] tiene traccia dei nodi uscenti dal nodo i.
> Per ogni vertice u in V, Adj[u] contiene tutti i vertici v appartenenti a V tale che esista un arco (u, v) in E

La lunghezza della somma di tutte le liste di adiacenza è |E|.

```c
// lista di adiacenza
struct adj_node {
    int node;
    float weight;
    adj_node *next;
}
typedef adj_node* adj_list;

// grafo
struct graph {
    adj_list *nodes;
    int dim;  // numero di vertici
}
```

### Osservazioni
Le teste delle liste vengono memorizzate in un vettore dinamico, che ha dimensione |V| (=> numero di vertici)

```c
graph g;
g.dim = DIM;
g.nodes = new adl_list[g.dim];
```

NB: gli indici di g.nodes vanno da 0 a dim-1, ma gli identificativi vanno da 1 a dim.

## Primitive
- `graph new_graph(int n)`
- `void add_arc(graph &g, int s, int d, float w)`: aggiunge l'arco **orientato** (s, d) con peso w alla lista di adiacenza del nodo s
- `void add_edge(graph &g, int s, int d, float w)`: aggiunge l'arco **non orientato** (s, d) e (d, s) con peso w alla lista di adiacenza di s e di d. Viene implementato con due chiamate ad `add_edge`
- `get_dim(graph)`
- `adjlist get_adjlist(graph, int)`
- `int get_adjnode(adj_node*)`
- `adj_list get_nextadj(adj_list)`: ritorna il primo elemento nella lista di adiacenza


## Lettura da file di grafi
Solitamente un file che descrive un grafo è così strutturato:
```txt
NUMERO_NODI
NODO_SRC NODO_DST PESO
```

Il file non mi da nessuna informazione sul tipo di grafo -> utilizzo i parametri da riga di comando:
```bash
graph filename is_weighted is_directed
```

## Argomenti cmd line
```c
int main(int argc, char *argv[]) {
    // argc - args count - contiene il numero di argomenti
    // argv - args values - contiene gli argomenti
}
```

argv[0] contiene sempre il nome con cui è stato invocato l'eseguibile.

Questa soluzione permette di evitare parametri o scelte hard-coded.

Hint: quando il numero di parametri è sbagliato lancia un messaggio di errore.

## Esercizio
Implementare il modulo _graph_ e un main contenente la funzione `graph g_build(ifstream &g, bool d, bool w)` che legga dallo stream g la rappresentazione del grafo e lo costruisca, ritornandolo.

Il main deve aprire il file passato come argomento, inoltrare i parametri a g_build e costruire il grafo.