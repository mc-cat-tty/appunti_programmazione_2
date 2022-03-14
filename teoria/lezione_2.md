# Puntatori
Utilizzi:
- memorizzare indirizzi di memoria
- funzioni di ordine superiore

## Allocazione e deallocazione
Si effettua allo stesso modo dell'array, mediante `new` e `delete`

Es:
```c
int *p;
```
"/int start pi/"

Questa sintassi (sopra) permette di dichiarare un puntatore ad un oggetto singolo oppure ad un array.

Per allocare una variabile di tipo scalare faccio:
```c
p = new int;
```

### Esempi
```c
int *p;         // dichiarazione oggetto tipo int
p = new int;    // allocazione variabile intera
delete p;       // deallocazione area di memoria riservata a p
```

```c
const int *p;   // puntatore ad oggetto di tipo int non modificabile attraverso p
                // non posso modificare l'intero, ma il puntatore  sì
int * const p;  // puntatore costante ad oggetto di tipo int
                // non posso modificare il puntatore, ma l'intero contenuto sì
int * p[10];    // array di 10 puntatori a int
int (*p) [10];  // puntatore ad array di 10 interi
```

## Operatore di indirizzo
L'operatore di indirizzo & restituisce l'indirizzo di memoria dell'oggetto a cui viene applicato. È un operatore **unario e prefisso**.

Il risultato dell'operazione può essere assegnato ad un puntatore ad un oggetto dello stesso tipo.

Questo operatore torna particolarmente utile per il passaggio per riferimento.

## Puntatori a vettori
Quando faccio `int v[10]` ottengo un puntatore alla testa del vettore di 10 interi.

L'operazione `int (*p) [10] = &v` assegna a p l'indirizzo di v. Quindi p punta a v, che punta al primo elemento del vettore (p doppio puntatore a vettore di 10 elementi).

L'operzione `int *p1 = v` punta al primo elemento del vettore v.

Posso allocare un array di 10 elementi con `int *p = new int[10]`;

## Operatore di dereferenziazione
Operatore **unario prefisso** utilizzato per accedere all'oggetto riferito da un puntatore
Operatore "start": `*`.

Si dice che il puntatore viene dereferenziato.

`*p` ritorna l'oggetto puntato da p.

### Esempi
```c
int i, j;
int *p = &i;
int * const p2 = &j;

*p = 3;  // equivale a i = 3
*p2 = 4  // equivale a j = 4

int x = *p;  // equivale a x = i

i = *p2;  // equivale a i = j
```

## Memory leak e danglilng reference
L'uso dei puntatore ha molteplici vantaggi, ma allo stesso tempo è una delle aree più inclini ad errori della programmazione moderna. I problemi tipici sono:
- **dangling reference** (puntatore pendente) si verifica quando si ha un puntatore che punta ad un'area di memoria dereferenziata o non allocata.
```c
int *p1 = new int;
int *p2 = p1;
delete p1;
// il puntatore p2 punta ad un'area di memoria liberata
```
- **memory leak** si verifica quando la memoria allocata non viene liberata. Il problema si verifica sul lungo termine.

La differenza principale è che la *dangling reference* dà un errore nell'immmediato, appena si accede ad un'area di memoria non consentita dal SO.

## Stampa di puntatori
Il valore di un puntatore e un indirizzo di memoria ottenuto con l'operatore `&` può essere stampato con `<<`. Solitamente il valore del puntatore viene mostrato in base 16.

## Doppi puntatori
```c
int i;      // intero
int *p;     // puntatore a intero
int **q;    // puntatore a puntatore a intero

q = &p;     // q punta all'area di memoria di p
P = &i;     // p punta all'area di memoria di i

**q = 3;    // equivale a i = 3
```

Quindi q -> p -> i

## Puntatori a struct
```c
struct s {int a, b};
s *p;  // oggetto di tipo struttura indirizzato da un puntatore p
```

Come riferirsi ad un campo della struttura?
1. `(*p).a` le parentesi servono per dare priorità all'operatore di dereferenziazione
2. `p->a` metodo preferito

## Esempi
```c
struct s {int a, b} s1;
s *p2;
p2 = &s1;

p2->a = 3;
// oppure
(*p2).a = 3;
```

## Riferimenti
```c
int a;
int &rif = a;
```

Oltre ai puntatori, il Cpp supporta anche il concetto di **riferimento**.

Un riferimento è un *alias* ad una variabile già esistente (ulteriore nome per essa).

## Puntatori vs riferimenti
I riferimenti sono meno flessibili dei puntatori, ma anche meno pericolosi.

Il riferimento è realizzato mediante un puntatore costante e nascosto (non visibile e modificabile da programmatore).

```c
int &rif = n;
// corrisponde a
int *__ptr_rif = &n;
```
Ogni volta che viene usato `rif` esso viene sostituito con `*__ptr_rif` in automatico.

Differenze:
- i riferimenti non possono avere valore nullo (sempre inizializzati)
- i riferimenti non possono essere riassegnati

## Riferimenti e parametri
I riferimenti e i puntatori permetto il passaggio per riferimento.

<details>
<summary>Passaggio per valore</summary>
Impedisce i cambiamenti e spreca memoria per la copia.
</details>

<details>
<summary>Passaggio per riferimento</summary>
La modifica del parametrio formale viene riflessa sul parametro attuale.
</details>

Anche un oggetto di tipo **puntatore** può essere passato come **riferimento**: `int *&ref_pointer`

Il passaggio per riferimento viene usato anche quando si lavora con grandi quantità di dati, per evitare un'ulteriore copia dell'oggetto in memoria (per esempio quando si lavora con immagini).

## Puntatori ed array
Il nome di un array corrisponde ad un puntatore al primo elemento dell'array stesso. Questo puntatore è ovviamente costante (ecco perchè non è possibile l'assegnamento tra due array).

Se `x[N]` è un array di N elementi di tipo T, x equivale a `&x[0]`.
`T *p = x` punta alla stessa area di memoria dell'array

### Aritmetica degli indirizzi
I puntatori possono essere usati in espressioni aritmetiche: l'aritmetica degli indirizzi (o puntatori) è l'insieme delle regole che governano le regole effettuabili sugli indirizzi e deriva dall stretta correlazione tra puntatori e vettori.

#### Somma di un intero
Permette di far avanzare o retrocedere l'indirizzo ad un'area di memoria.

Se *p* ha come valore numerico l'indirizzo *addr* e *T* (tipo di dato) occupa *n* locazioni di memoria.
L'espressione `p+i` ha come valore numerico l'indirizzo `addr+n*i`.

#### Incremento e decremento
Sia *p* un puntatore contenente l'indirizzo di un oggetto *x* di tipo *T*.

!ricorda la differenza tra incremento prefisso e postfisso

L'espressione `p++` (o `p--`) restituisce l'indirizzo di un oggetto di tipo T che segue o precede *x* in memoria. Queste operazioni permettono di spostarmi all'elemento precedente o successivo.

#### Differenza
Utile per ottenere il numero di elementi tra due locazioni di memoria.

#### Esempio
```c
const int N = 10;
int v[N];

int *p = v;     // assegna a p l'indirizzo di v
*(p+2) = 7;     // assegna al terzo elemento di v il valore 7
```

Attenzione: `*p + 2` è diverso da quanto scritto sopra, perchè corrisponde a `(*p) + 2`, quindi ritorna il valore dell'elemento di v in posizione 0 incrementato di 2.

```c
const int N = 10;
int v[N], z[N];
*v = *z;            // equivale a v[0] = z[0]
```

## Esercizio
[stampa_array_pun.cpp](../esercizi/stampa_array_pun.cpp)