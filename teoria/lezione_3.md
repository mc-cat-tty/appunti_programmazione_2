# Funzioni di ordine superiore
Anche detti puntatori a funzione

I puntatori in C/Cpp possono puntare a qualsiasi oggetto, incluse le funzioni.

```c
int (* puntafun) (double, int);
```

## Esempio
Funzione di _sort_ della libreria **algorithm**:
```c
void sort(first, last, comp);
```

**comp** fornisce il comportamento della funzione di sort, quindi secondo quale logica bisogna ordinare gli elementi che vanno da _first_ a _last_. Potrebbe essere qualcosa come:
```c
bool mufunction (int i, int j) { return (i<j); }
```

## Assegnamento
I puntatori a funzione possono essere assegnati con il nome di una funzione compatibile, precedentemente dichiarata.
Una funzione è compatibile se ha gli stessi tipi di parametri di input e output.

```c
int (*puntafun) (double, int);
int f1(double, int);
int f2(double, int);

// f1 e f2 sono funzioni compatibili
if (...) puntafun = f1;
else puntafun = f2;
```

L'assegnamento corretto sarebbe `puntafun = &f1` oppure `puntafun = &f2` perchè bisognerebbe andare a prendere l'indirizzo di memoria della funzione; ma va ugualmente bene l'assegnamento senza `&`.

## Chiamata
Per chiamare la funzione puntata occorre fare:
```c
(*puntafun)(45.76, 5);
```

In realtà si può anche fare:
```c
puntafun(45.76, 5);
```

Il compilatore aiuta in questo perchè, al contrario delle variabili, solitamente non si vuole operare con il puntatore a funzione (no incremento o decremento del puntatore), ma con la funzione stessa.

## Array di puntatori a funzione
Si possono creare anche vettori di puntatori a funzione:
```c
int f1 (double, int);
int f2 (double, int);

int (*puntafun[2]) (double, int) = {f1, f2};
```

L'array di operazioni svolte è utile, per esempio, per definire una pipeline di operazioni da eseguire sui dati raccolti dalla sensoristica.

### Chiamata
```c
puntafun[0] (45.7, 2);
puntafun[1] (22.3, 3);
```

## Utilizzi
Oltre ad una pipeline di operazioni, un array di puntatori a funzione può servire per eseguire le opzioni di un menù.

## Esercizio
Scrivere un programma (usando i puntatori a funzione) che:
- richieda se effettuare un'operazione di addizione, sottrazione, moltiplicazione o divisione tra 2 interi
- a seconda dell'operazione scelta chiami la funzione desiderata
- presenti un menù per la selezione della scelta

[](../esercizi/operazioni.cpp)

## Passaggio di puntatori a funzione
Una funzione può dichiarare tra i suoi argomenti un elemento di tipo puntatore a funzione

```c
void sel_fun(int (*pfun) (double)) {
    int n;
    ...
    n = pfun(64.7);
    ...
}
```

Attenzione: _pfun_ è una funnzione che prende in ingresso un double e ritorna un intero. Quindi _sel\_fun_ non prende in input un double.

Posso omettere il nome della funzione nella dichiarazione: `void sel_fun((int*) (double))`

Nella chiamata passo a _sel\_fun_ una funzione precedentemente dichiarata e compatibile.
Attenzione: nella chiamata la funzione argomento va passata senza parentesi tonde, perchè voglio passare un puntatore a funzione, non il risultato dell'esecuzione.

Non posso fare: `sel_fun(f2(62.7))` perchè il parametro che si aspetta _sel\_fun_ non matcherebbe con quello che si aspetta.

Per passare altri parametri alla funzione devo aggiungerli alla dichiarazione della funzione stessa:
```c
void sel_fun(int(*pfun)(double), double r);
...
sel_fun(f1, 67.89);
```

## Esercizio
Programma che implementa una funzione per il calcolo della somma dei primi n valori di una generica funzione _int f(int)_:
```c
somma(f, n) = f(1) + f(2) + ... + f(n)
```

[](../esercizi/somma_funz.cpp)

## Operatori bit a bit
Ci permettono di fare operazioni sui singoli bit delle variabili.

### Notazione posizionale
Data una base _b_ (numero naturale diverso da 0 e 1), si scelgono _b_ simboli diversi a partire da zero, che chiameremo **cifre**.

Per comporre un numero si affiancano le cifre, che assumono un peso diverso in base alla posizione.

Nella notazione binaria (b=2) abbiamo 2 cifre: 0 e 1.

Quando si utilizza una base con b>10 è necessario introdurre nuovi simboli, come accade per la base 16: A, B, C, D, E, F

Con N cifre in base b posso rappresentare _b^N_ cifre, ovvero i numeri da 0 a _b^N - 1_; questo range è quello dei numeri naturali (unsigned).

Quando ho bisogno di rappresentare anche valori negativi devo shiftare il range, in modo che mi permetta di rappresentare in parte anche i valori negativi (riservo bit al segno).

La base esadecimale è largamente diffusa perchè esiste una relazione 1 a 1 tra 4 cifre in base 2 e 1 cifra in base 16. Per convertire un numero dalla base 2 alla base 16 parto da destra raggruppando i bit a 4 a 4, aggiungendo degli zero se necessario.
Esempio:
- [1101 1010]<sub>2</sub> = [C A]<sub>16</sub>

## Operatori C/Cpp
Sono operatori che permettono di ragionare sulla configurazione binaria di un numero (di una variabile); mi permettono di modificare i singoli bit. Molto utilizzati per le maschere (_bit masks_).
La maschera mi permette di associare un significato ad ogni posizione, in relazione al bit che è presente come, per esempio, 0 spento, 1 acceso.

Operatori:
|Operatore          |Simbolo    |Arietà |
|:-----------------:|:---------:|:-----:|
|AND                |&          |binario|
|OR                 |\|         |binario|
|XOR                |^          |binario|
|complemento a 1    |~          |unario |
|shift a sx         |<<         |binario|
|shift a dx         |>>         |binario|

Attenzione: l'operatore di shifting porta spesso a overflow.

## Operatori binari AND, OR, XOR
Siano x e y gli argomenti di un operatore binario bit a bit (AND, OR, XOR).
Siano x<sub>i</sub>, y<sub>i</sub> le i-esime cifre di x e y nella rappresentazione binaria dei numeri.
Sia z il risultato dell'operazione.

Calcolo z<sub>i</sub> come singolo bit secondo la seguente tabella:
- AND:
    - 0&0 = 0&1 = 1&0 = 0
    - 1&1 = 1
- OR:
    - 0|1 = 1|0 = 1|1 = 1
    - 0|0 = 0
- XOR:
    - 0^0 = 1^1 = 0
    - 0^1 = 1^0 = 1
