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

[operazioni.cpp](../esercizi/puntatori/operazioni.cpp)

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

[somma_funz.cpp](../esercizi/puntatori/somma_funz.cpp)

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

Il C1 ribalta tutti i bit, mentre il C2 è il C1 del numero originale più 1.

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
    - 0^1 = 1^0 = 1 (vero quando sono diversi)

Servono 4 bit per rappresentare una cifra decimale (da 0 a 9).

## Operatore NOT
È un operatore unario che ribalta (inverte il valore) di ogni bit del numero di partenza.

Una configurazione con tutti i bit a 1, indipendente dalla dimensione del tipo di dato su cui è memorizzata, si può ottenere facendo: `~0`

## Operatore di shift
Operatore binario che sposta a sinistra o a destra ogni bit del primo operando di tante posizioni quante sono indicate dal secondo operando (numero intero).

Se x = 110101 (supponendo un dato a 6 bit):
 - x << 1 &rarr; 101010
 - x << 2 &rarr; 010100
 - x >> 2 &rarr; 001101
 - x >> x &rarr; 000110

La rappresentazione in b2 di `1<<n` è una sequenza di bit dove la n-esima cifra è a 1, mentre tutte le altre sono a 0. Quindi 1 seguito da n zeri. In questo modo posso creare maschere per verificare lo stato dei bit di una sequenza.

La rappresentazione in b2 di `~(1<<n)` ha tutti i bit a 1, tranne quello in posizione n.

## Maschere di bit
Terminologia:
 - *settare* un bit = assegnare il valore 1
 - *resettare* un bit = assegnare il valore 0

Le *maschere di bit* o *maschere binarie* servono per:
 - controllare il valore di specifici bit
 - settare/resettare il valore di alcuni bit
 - indicare quali bit sono significativi e quali non lo sono

Le maschere di bit tornano particolarmente utili per l'implementazione dei protocolli di rete.

### Utilizzi pratici
Per scoprire se l'i-esimo bit di un vettore *x* è settato o meno, basta fare: `x & (1<<i)`

## Esercizio
Scrivere un programma che prenda in input un numero x ed n e ritorni lo stato dell'n-esimo bit nel vettore x.
[controlla_bit.cpp](../esercizi/bitwise_op/controlla_bit.cpp)

## Controllo di più bit
Creo una maschera in cui ogni bit che mi interessa è settato: metto in OR più maschere, dove ciascuna è ottenuta shiftando a sinistra il numero 1 di n posizioni.

Attenzione: il controllo si fa più complicato, perchè come risultato non posso avere solo 0 o 1.

## Settare un bit
Per settare un bit in una specifica posizione di un vettore di bit utilizzo l'operatore OR al posto dell'AND, quindi metto in OR il numero e la maschera che contiene tutti zero a parte il bit che voglio settare.

Per settare l'i-esimo bit del vettore *x*: `x |= (1<<i)`

## Esercizio
Scrivere un programma che legga da stdin due numeri naturali x ed n, e setti il bit in posizione n nel numero x.

[setta_bit.cpp](../esercizi/bitwise_op/setta_bit.cpp)

## Resettare un bit
Dato il vettore di bit *x*, se voglio resettare il bit in posizione *n* posso fare: `x &= ~(1<<n)`

 ## Flippare un bit
 Utilizzo lo XOR: `x ^= (1<<n)`

 Lo XOR mi permette di flippare il bit. Se il bit n-esimo di x è a 0, viene portato a 1; se è a 1, diventa 0. Tutti gli altri bit non vengono modificati, perchè 0^0 = 0, 0^1 = 1.

## Operatori e altri tipi di dato
Gli operatori bitwise non operano su float e double. Possono essere utilizzati su `signed int` e `unsigned int`.

## Esercizi
1. Scrivere un programma che, preso in input da stdin un numero n, lo moltiplichi per 2 senza utilizzare l'operatore di moltiplicazione: [molt_2.cpp](../esercizi/bitwise_op/molt_2.cpp)
2. Scrivere un programma che stampi se un numero naturale n letto da stdin è pari o dispari: [pari_dispari.cpp](../esercizi/bitwise_op/pari_dispari)
3. Scrivere un programma che, dati due numeri n ed i, restituisca il risultato di n * 2^i senza utilizzare l'operatore di moltiplicaizone: [molt_2_i.cpp](../esercizi/bitwise_op/molt_2_i.cpp)
4. Scrivere un programma che, dati due numeri n ed i, restituisca il risultato di n / 2^i senza utilizzare l'operatore di divisione: [div_2_i.cpp](../esercizi/bitwise_op/div_2_i.cpp)
5. Scrivere un programma che, dati i e j, stampi il numero z ottenuto ponendo le j cifre meno significative di z uguali alle j cifre più significative di i, con il resto dei bit a 0: [msb_to_lsb.cpp](../esercizi/bitwise_op/msb_to_lsb.cpp)
6. Scrivere un programma che, dati i e j, stampi il numero z ottenuto ponendo le j cifre più significative di z uguali alle j cifre meno significative di i, con il resto dei bit a 0: [lsb_to_msb.cpp](../esercizi/bitwise_op/lsb_to_msb.cpp)
7. Scrivere un programma che, presi in input k e j, ruoti a destra di j posizione la configurazione binaria di k: [rotazione_a_destra.cpp](../esercizi/bitwise_op/rotazione_a_destra.cpp)
8. Come sopra, ma la rotazione è a sinistra: [rotazione_a_sinistra.cpp](../esercizi/bitwise_op/rotazione_a_sinistra.cpp)
9. Scrivere un programma che, dato un numero n, calcoli il più piccolo numero dispari i tale che i>=n: [to_dispari.cpp](../esercizi/bitwise_op/to_dispari.cpp)
10. Come sopra, ma i deve essere il più grande numero dispari tale che i<=n: [to_pari.cpp](../esercizi/bitwise_op/to_pari.cpp)
11. Gestire lo stato di illuminazione di una strada. La configurazione dei lampioni è rappresentata come un array di bit. Implementare le seguenti funzioni:
  - funzione guasta/ripara
  - stampa dello stato dei lampioni
  - controllo risparmio energetico
  - [lampioni.cpp](../esercizi/bitwise_op/lampioni.cpp)