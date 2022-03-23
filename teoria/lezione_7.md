# Ricorsione
Due tipi di ricorsione:
- diretta -> la funzione richiama se stessa senza intermediari
- indiretta -> la ricorsione coinvolge altre funzioni (una o più funzioni che richiamano la prima)

Vedi esempio: [ricorsione1.cpp](../esercizi/ricorsione/ricorsione1.cpp)

## Vantaggi delle soluzioni ricorsive
La ricorsione è una soluzione concisa ed elegante per alcune tipologie di problemi (non tutti, come non tutti sono da risolvere con approccio iterativo).

Si utilizza nei seguenti casi:
- problemi complessi scomponibili in sottoproblemi più piccoli
- svolgere compiti ripetitivi su batch di dati
- alcuni problemi sono intrinsicamente ricorsivi: fattoriale, torre di Hanoi, Fibonacci...

## Fattoriale
f(n) = n * f(n-1)
**Clausola di stop**: n == 0 &rarr; return 1

## Clausola di stop
Attento: ricordati sempre la clausola di stop
È un elemento necessario alla ricorsione, perchè determina la fine della "catena", oppure può eseguire qualche specifica operazione. La clausola di stop verifica se siamo in presenza del *caso base*.

## Argomento di controllo
=> è il parametro che permette di controllare l'esecuzione delle chiamate ricorsive. In base al parametro di controllo distinguiamo caso base e caso ricorsivo.

Attenzione: ricordati sempre di modificare l'argomento di controllo.

La sequenza degli argomenti di controllo devono **convergere** verso il caso base, altrimenti l'esecuzione diverge.

## RdA
Il *Record di Attivazione* è una porzione di stack che viene dedicata a una funzione appena viene invocata. Una serie di informazioni vengono salvate sullo stack:
- RA - Return Address
- parametri e variabili locali

Nel caso della ricorsione vengono creati tanti RdA per la stessa funzione (diverse istanze).

## Fibonacci
fib(n) = fib(n-1) + fib(n-2)
Caso base: n=0 o n=1 -> return n

Il rapporto tra un numero di fibonacci e il suo precedente tende alla sezione aurea (1.61...)

[fibonacci.cpp](../esercizi/ricorsione/fibonacci.cpp)

La funzione di Fibonacci è un esempio di *ricorsione multipla*

Attenzione all'ordine delle chimatate

## La torre di Hanoi
La soluzione base per questo gioco è un algoritmo ricorsivo.

I paletti sono denominati: A (src), B (appoggio), C (dst)
I dischi sono (dal più piccolo al più grande): 1, 2, 3

[hanoi.cpp](../esercizi/ricorsione/hanoi.cpp)

## Iterazione vs ricorsione
Ricorsione: concisa ed elegante per problemi scomponibili
Iterazione: meno concisa ma più efficiente nello spazio e nel tempo, risolve lo stesso tipo di problemi

## Primitive delle liste ricorsive
`search` iterativa:
```c
elem* search(lista l, int v) {
    while (l != NULL) {
        if (v == head(l))  // caso base
            reutrn l;
        else
            l = tail(l);  // caso induttivo
    }
    return NULL;  // caso base, non ho trovato l'elemento
}
```

`search` ricorsiva:
```c
elem* search(lista l, int v) {
    if (l == NULL)  // se la lista è vuota (elemento non trovato)
        return l;
    if (head(l) == v)
        return l;
    return search(tail(l), v);  // cerca v skippando l'elemento corrente
}
```

## Buone pratiche
- limitare la ricorsione ad una funzione
- la ricorsione mutua può essere pericolosa

## Esercizio: calcolo della potenza
a^n = a * a^(n-1)

- [potenza.cpp](../esercizi/ricorsione/potenza.cpp)
- [stampa_n_1.cpp](../esercizi/ricorsione/stampa_n_1.cpp)
- [stampa_1_n.cpp](../esercizi/ricorsione/stampa_1_n.cpp)
- [lunghezza_lista.cpp](../esercizi/ricorsione/lunghezza_lista.cpp)
- [delete_elem_ricorsiva.cpp](../esercizi/ricorsione/delete_elem_ricorsiva.cpp)
- [merge_ricorsiva.cpp](../esercizi/ricorsione/merge_ricorsiva.cpp)
