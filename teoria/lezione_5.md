# Liste
## Struttura dati
1. modo sintetico per organizzare i dati
2. insieme di operatori (o primitive) per la manipolazione degli elementi di una struttura

## Problematiche degli array
> Un **arrray** è una struttura dati che memorizza elementi *omogenei* in *sequenza* (memoria contigua), ad *accesso diretto*, che ha *dimensione fissa*.

### Dimensioni
Fin'ora per memorizzare una serie di dati omogenei abbiamo usato gli array.

Nel caso di array statici era necessario connoscere la dimensione a tempo di scrittura del codice, mentre con gli array dinamici era necessario conoscere la dimensione a priori, a tempo di esecuzione del programma.

Un soluzione è quella di **sovrastimare** il numero di elementi e allocare quella quantità, utilizzando effettivamente meno posizioni di quelle che sono state allocate &rarr; spreco di memoria. L'array si potrebbe **saturare**.

### Inserimento
Se, per esempio, volessimo inserire un elemento in un array ordinato mantenendolo tale, dovremmo **shiftare** tutti gli elementi della parte a destra/sinistra dell'array. Poco efficiente dal punto di vista del costo temporale.

## Compendio limiti array
- scarsa flessibilità
- gli elementi devono essere contigui -> dover allocare una grande quantità di memoria tutta di fila (celle contigue) non può essere sempre possibile (constringi il SO a riallocare l'array)

## Soluzioni
> La **lista** è una sequenza a dimensione variabile di elementi omogenei ad accesso sequenziale

### Caratteristiche
- dimensione variabile: la dimensione può variare durante l'esecuzione
- accesso sequenziale: non posso accedere all'i-esimo elemento di una lista in tempo costante
- elementi omogenei

## Implementazione delle liste
In C/Cpp non esiste un'implementazione std delle liste: implementeremo una **linked list**.

Implementazione con:
- allocazione dinamica
- puntatori

Per aggiungere un elemento si alloca un nuovo elemento. Per estrarlo lo deallochiamo. Gli elementi della lista non occupano posizione contigue, ma teniamo traccia della lista grazie ai puntatori.

L'informazione memorizzata dalla lista non deve essere un tipo di dato primitivo, potrebbe essere un oggetto o una struttura dati.

Ciascun elemento della lista contiene un **campo informazione** e un **campo puntatore**. L'ultimo elemento è individuato dalla presenza del puntatore a `NULL`.

### Elemento
```c
struct elem {
    int inf;  // informazione memorizzata
    elem *p;  // puntatore ad una struttura dati dello stesso tipo
}
// ...
```

### Terminologia
> La *testa* (o *head*) della lista è il primo elemento della lista. Se perdo il primo elemento perdo tutti gli altri. Si accede alla lista attraverso il puntatore alla testa della lista. Non devo perdere questo valore, altrimenti non riesco a visitare gli altri elementi.

> La *coda* (o *tail*) della lista è costituita da tutti gli elementi successivi alla testa della lista. Quindi non è l'ultimo elemento.

```c
// ...
elem *testa;  // mantengo un riferimento alla testa della lista

// OPPURE

typedef elem* lista;  // si preferisce questo metodo
lista testa;
```

### Osservazioni
```c
// Il seguente modo non crea un elemento della lista
elem *p;

// devo allocare l'elemento
p = new elem;
// a questo punto posso accedere ad entrambi i campi dell'elemento
// p->inf
// p->pun
```

Osservazione: prima di dereferenziare un puntatore assicurarsi che punti ad un elemento dinamicamente allocato (evitare di deallocare un pending pointer).

## Terminologia
La **lista semplice** o singolarmente concantenata (*singly linked list*): ogni ele contiene un solo puntatore all'elemento successivo. Non posso tornare indietro senza scorrere di nuovo tutta la lista.

La **lista doppia** o doppiamente concatenata (*doubly linked list*): ogni ele contiene due puntatori, uno all'elemento precedente e uno al successivo. Non è sempre megli della lista semplice, perchè occupa più spazio; dipende dalla tipologia del problema.

La **lista vuota** (*empty list*): lista senza elementi identificata da un puntatore alla testa della lista, che ha il valore `NULL`.

## Caratteristiche di una lista semplice
Gli elementi in memoria occupano posizioni non sequenziali.
L'ordine della lista è determinato da un puntatore ad ogni elemento, non dagli indici. Posso modificarlo facendolo puntare ad un altro elemento.
Per determinare la fine della lista è necessario il *segnale di fine lista*: `NULL`. Per visitare tutti gli elementi della lista si utilizza il ciclo while.
La scansione è possibile in un solo verso (da un elemento versio il suo successivo); non è possibile accedere in tempo costante all'antecedente.

## Primitive di una lista semplice
Per accedere agli elementi della lista sono sufficienti due primitive:
- tail: restituisce il puntatore agli elementi successivi a quello passato
- head: ritorna il valore del primo elemento della lista

```c
int head(lista l) {
    return l->inf;
}

lista tail(lista l) {
    return l->punt;
}
```

Per ora utilizzeremo liste non generali, quindi il tipo di dato ritornato da head dipende da quello che è stato memorizzato all'interno della struttura elem. Più avanti vedremo le strutture di dati *agnostiche* al tipo di dato che si vuole memorizzare.

## Scansione di una lista semplice
```c
void stampa_lista(lista l) {
    while (l != NULL) {         // esco quando ho raggiunto l'ultimo elemento della lista
        cout << head(l) << " "; // stampa del valore memorizzato in l
        l = tail(l);            // spostamento lungo la lista
    }
    cout << endl;
}
```

## Esercizio
Scrivere un programma in cui:
- sia definita una lista formata da due elementi, contenenti 3 e 7.
- si stampi il contenuto della lista mediante una funzione
[stampa_2ele.cpp](../esercizi/liste/stampa_2ele.cpp)

## Inserimento di un elemento
Primitiva `insert_elem`:
```c
lista insert_elem(lista l, ele* e);
```
È una funziona che aggiunge e a l e restituisce la lista aggioranta.

L'inserimento può avvenire:
- in testa: mi evito la scansione di tutta la lista, che è necessaria per inserire l'elemento in coda. Modalità più semplice ed efficiente, ma gli elementi compaiono in ordine inverso rispetto all'ordine di inserimento. Inserimento in tempo costante: O(1)
- in coda: richiede di scorrere tutta la lista, ma gli elementi della lista compaiono in *ordine diretto* rispetto all'ordine di inserimento. Costo: O(n)

Di base si preferisce l'inserimento in testa.

Cosa deve fare questa primitiva:
- prende l'elemento e
- fa puntare e alla testa della lista
- si ritorna il puntatore a e

### Implementazione
```c
lista insert_elem(lista l, elem *e) {
    e->p = l;
    return e;
}
```

### Raccomandazioni
- e deve essere allocato prima di essere inserito nella lista
- nell'inserimento in testa non è necessario fare `ele->pun = NULL`, ma è necessario se faccio l'inserimento in coda

## Esercizio
Scrivere un programma che chieda all'utente quanti interi vuole inserire e creare una lista di n elementi, presi in input da stdin:
[crea_stampa_lista.cpp](../esercizi/liste/crea_stampa_lista.cpp)

## Cancellazione di un elemento
=> funzione che cancella l'elemento e da l e restituisce la lista aggiornata.

Devo ritornare una lista, perchè se elimino la testa della lista avrei una situzione inconsistente.

```c
lista delete_ele(lista l, ele *e) {
    if (l == e) {
        l = tail(l);
    }
    else {
        lista l_aux;
        while (tail(l_aux) != e) {
            l_aux = l;
        }
        l_aux->pun = tail(e);
    }

    delete e;
    return l;
}

```

Assunzioni:
- l non è vuoto
- e è presente in l

Operazioni:
1. aggiorno l sscollegando e dalla lista
2. deallocare e

Casi speciali:
- e coincide con la testa di l:
    - l punta al secondo elemento
    - dealloco il primo elemento
- e si trova nella coda della lista:
    - ricerco l'elemento che punta a e
    - lo faccio puntare al successivo

## Esercizio
Scrivere una funzione che elimini un'intera lista attraverso la primitiva `delete_elem`:
[crea_stampa_elim_lista.cpp](../esercizi/liste/crea_stampa_elim_lista.cpp)

## Ricerca di un elemento
```c
elem* search(lista l, int v) {
    while (l != NULL ) {
        if (head(l) == v)
            return l;
        else
            l = tail(l);
    }
    return NULL;
}
```
È una funzione che cerca in l il valore v e ritorna il puntatore a tale elemento (la prima occorrenza che contiene v), se esite, altrimenti NULL.

## Esercizio
Scrivere una funzione `int conta(lista l, int v)` che restituisce il numero di occorrenze di v in l:
[conta.cpp](../esercizi/liste/conta.cpp)

Utilizzo search in modo iterativo, lanciando search a partire da `tail(l)`.

Scrivere un programma che elimini tutte le occorrenze di v in l:
[conta_cancella.cpp](../esercizi/liste/conta_cancella.cpp)

## Copy
- inizializzo la lista l a NULL
- per ogni valore di l copio l'elemento e lo appendo alla lista

## Esercizi
- funzione che elimina l'ultimo elemento della lista
- primitiva che inserisce l'elemento in fondo alla lista, al posto che in testa
- date due liste che implementano valori interi, implementare le funzioni insiemistiche union, difference, intersect.