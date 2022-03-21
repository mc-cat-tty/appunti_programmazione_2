# Liste doppie
Ogni struct contiene sia il puntatore all'elemento successivo che il puntatore al precedente. A partire da un elemento posso accedere a tutti gli altri andando avanti o indietro.

## Implementazione
Ogni struct contiene:
- valore dell'elemento
- puntatore al precedente
- puntatore al successivo

L'interfaccia delle primitive non cambia, la loro implementazione sì.

Es:
- inserimento: bisogna aggiornare il puntatore al precedente, oltre che al successivo
- cancellazione: aggiorno entrambi i pupntatori

## Particolarità
All'intero della double linked list ho due NULL: il puntatore all'elemento successivo dell'ultimo elemento e il puntatore all'elemento precedente del primo elemento.

## Struct elem
```c
struct elem {
    int value;
    elem *next;
    elem *prev;
};
typedef elem* lista;
```

## Inserimento
Inserimento in testa:
```c
lista insert_elem(lista l, elem *e) {
    e->next = l;
    if (l != NULL) {  // se la lista non è vuota
        l->prev = e;
    }
    e->prev = NULL;
    return e;
}
```

## Eliminazione
Non è più necessario scorrere tutta la lista per trovare l'elemento che contiene come puntatore al successivo l'elemento che si vuole eliminare.

```c
lista delete_elem(lista l, elem *e) {
    if (l==e)  // se voglio eliminare la testa
        l = tail(l);
    else  // e non è la testa della lista
        (e->prev)->next = e->next;
    if (e->next != NULL)
        (e->next)->prev = e->prev;
    delete e;
    return l;
}
```

## Vantaggi e svantaggi
Lo svantaggio principale delle double linked list è che occupano più spazio rispetto alle single linked list, ma sono più ottimizzate dal punto di vista algoritmico.

Dove sono usate le linked list (di entrambi i tipi, dato che cambia solo l'implementazione a basso livello):
- Rappresentazione dei mazzi di carte nei giochi online
- Cache del browser (back and forward)
- MRU - most recently used
- Azioni di _undo_ e _redo_ sui software come Word
- Implementazione di altre strutture dati, come gli alberi di ricerca

## Exercizi
`gestione_lista_doppia.cpp`


# Lista circolare
Lista che non ha fine. Il puntatore _next_ dell'ultimo elemento non punta a NULL, ma alla testa della lista.