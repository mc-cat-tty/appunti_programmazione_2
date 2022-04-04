# Progetti su più file

## Motivazione


## Linking
### Internal linking
La nozione di collegamento si riferisce all'accessibilità dell'entità associata ad un identificatore.
Un identificatore ha un *internal linking* (collegamento interno) se si riferisce ad una entità a cui si può accedere solo all'interno del file in cui l'identificatore (e quindi l'entità) è stato dichiarato.

### External linking
Un identificatore ha un *external linking* (collegamento esterno) se è associato ad una entità a cui si può accedere da file diversi da quello in cui l'entità è stata definita => in tal caso si dice che l'entotà è **globale** al programma (quindi deve essere anche **unica**).

Tale entità può essere *dichiarata* su più file, ma può essere *definita* in un solo file. Tutti gli altri file saranno consapevoli che l'entità esiste, ma uno solo la implementa.

### Linking
Di default:
- gli identificatori di entità definite a *livello di blocco* (come in una funzione) *non* hanno collegamento
- gli identificatori di entità definite a *livello di file* hanno *collegamento esterno*

## Include
Ogni volta che si incontra la direttiva `#include <XXX>` il precompilatore include tutte le dichiarazioni contenute nel file.

L'errore `use of undeclared identifier` si riferisce al caso in cui non viene dichiarato l'identificatore.

### Extern
Per rendere visibile in *fileX.cpp* un `id` definito in *fileY.cpp*:
1. `id` deve avere un collegamento esterno (definizione a livello di file)
2. si deve *ridichiarare* l'identificatore in *fileX.cpp*
    - se è una variabile
        ```c
        extern int id;
        ```
    - se `id` si riferisce ad una funzione, basta ripeterne la dichiarazione


`extern` viene usata per dichiarare un identificatore all'interno di un file, l'entità associata a questo identificatore si trova all'interno di un altro file, quindi è necessario che esista almeno 1 file in cui l'identificatore sia stato definito. Permette quindi di fare la *ridichiarazione* di un identificatore.

Le scritture `int fun(void);` e `extern int fun(void);` sono equivalenti, quindi `extern` non è necessario per ridichiarare una funzione.

### Esercizio
[primo_prog_multifile](../esercizi/progetti_multifile/primo_prog_multifile)

## Static
Dichiarando una variabile come `static` non viene linkata esternamente, quindi non è possibile recuperare l'identificatore neanche con extern. Quindi in generale `static` serve a definire un collegamento interno a livello di file.

Questo attributo può essere usato anche a livello di blocco, con il seguente comportamento:
- un id di entità (variabile) definita a livello di blocco non ha collegamento (neanche interno)
- esso ha tempo di vita pari a quello del blocco
- con `satic`
    - il collegamento non varia
    - l'entità è visibile solo all'interno del blocco
    - il tempo di vita diventa statico, quindi pari all'intero tempo di vita del programma
    - l'entità è inizializzata una sola volta

## Scope e linkage
La *visibilità* è gestita dal **compilatore**, perchè se qualcosa non è visibile non server neanche chiedersi a cosa deve essere collegato, quindi il compilatore segnala errori di questo tipo.
Il *collegamento* è gestito dal **linker**. Ad esempio se definisco un identificatore con lo stesso nome in due file distinti appartenenti allo stesso progetto i due file compilano, ma il linker ritorna un errore (errore gestito da `ld`).

## Typedef
Con `typedef` vengono dichiarati nuovi tipi di dato:
```c
typedef elem* lista;
```
Per utilizzare un oggetto che appartiene ad un certo tipo non primitivo (enum, struct, union) in un altro file bisogna ripetere la stessa identica definizione di tipo nel file in questione. I due tipi devono essere equivalenti, ovvero devono avere lo stesso nome (se hanno campi diversi compila senza problemi, ma non funzionerà correttamente, quindi devono avere lo stesso numeoro di campi, con lo stesso tipo e lo stesso nome).

## Dalla struttura logica alla struttura fisica
La struttura logica di un programma (divisione in *moduli*) può essere realizzata attraverso la suddivisione del codice su più *file sorgente*.

Distribuiamo il codice dell'esercizio sulle liste su 4 file sorgente, ognuno dei quali rappresenta un modulo:
 - main
 - funzioni applicazione
 - liste tipo
 - liste

Attenzione: quando fai l'include di un file sorgente, viene copiato pari pari, quindi avrei una doppia dichiarazione delle funzioni.

Ho bisogno di usare una interfaccia -> che può essere ripetuta in entrambi i file senza problemi.

I file header vengono usati perchè in questo modo si può ripetere facilmente la dichiarazione di ogni funzione all'inizio di ogni modulo cliente.

## Include
`#include` è una direttiva al preprocessore (come tutti i comandi preceduti da cancelletto) che copia l'intero file incluso nel file che lo include.

`#include <nomefile>` cerca *nomefile* all'interno di un insieme di directory di sistema dove sono contenute le librerie standard del linguaggio.

`#include "nomefile"` permette di includere file che sono locali al progetto, a partire dalla directory dove si trova il file corrente.

## Moduli e header
Per ogni modulo applichiamo la seguente suddivisione:
 - *modulo.cpp* contiene l'implementazione del modulo
 - *modulo.h* contiene l'interfaccia del modulo

L'implementazione di ogni modulo importa l'interfaccia di "se stesso", perchè sono contenute le strutture dati comuni.

