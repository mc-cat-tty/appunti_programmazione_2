# Compilazione automatica
L'operazione di compilazione "a mano" è scomoda ed error-prone, soprattutto quando il progetto è suddiviso su più file. Esistono tool automatici che permettono di definire regole di compilazione automatica.

## GNU make
Consente all'utente di buildare e installare un software senza conoscerne i dettagli, perchè automatizza il processo di _creazione di file che dipendono da altri file_, ovvero il processo che coinvolge: file sorgente, translation unit, file oggetto e file esegubile (linkato).

Cosa fa?
- esplicita e risolve le dipendenze tra file, tenendo conto dell'ordine di creazione dei file e invocando, se necessario, comandi esterni
- si basa su data e ora di ultima modifica per effettuare la ricompilazione selettiva dei file
- non è limitato ai linguaggi C/C++

### Makefile
GNU make prende in input un file di testo, chiamata **Makefile** (solitamente con M maiuscola, ma non fa differenza se passato esplicitamente a make). Questo file contiene un insieme di reogle, scritte usanto il *make scripting language*.

Viene preso in input un **target** che definisce l'obiettivo da raggiungere. Make segue le regole di compilazione per arrivare al target.

### Regole
Il nome del target è arbitrario, nonostante esistano delle convenzioni che definiscono i target più comuni.

```
target: [<i>prerequisito1</i>] [<i>prerequisito2</i>]
    comando1
    comando2
    ...
```

Il *target* può essere:
 - il nome di una *azione* da eseguire
 - il nome di un *file* da generare o aggiornare

I *prerequisiti* sono opzionali. Tra i prerequisiti si possono inserire altri target. Una volta risolti i prerequisisti vengono eseguiti i comandi.

Quando vengono eseguiti i *prerequisiti*? se il target non esiste, oppure se è più vecchio di uno dei target. Esempio: se eseguo "target", poi cambio "prerequisito.o" e riprovo ad eseguire "target", devo rieseguirlo effettivamente perchè è cambiato uno dei prerequisiti.

## Invocazione
`make [-f makefile_name] [target(s)]`

Se l'argomento `-f` non viene usato, make assume che le regole siano salvate nel file `Makefile`, `makefile` o `GNUmakefile`, nella directory corrente.

Se nessun target viene specificato, viene eseguito il primo target, chiamato anche _defualt\_target_.

[web_list](../esercizi/compilazione_automatica/web_list)

## IDE vs Make
Gli IDE spesso includono tool che permettono la compilazione automatica, nella maggior parte dei casi generano un Makefile ed eseguono `make`.

## Dettagli del Makefile
Normalmente i comandi che si trovano sotto ad un target sono passati alla shell così come sono scritti (_verbatim_)

Si possono inserire commenti anteponendo `#`.

È possibile spezzare le righe di un comando usano il backslash `\`.

## Phony target
Spesso si vuole ripulire la directory di file temporanei (come i file oggetto).

I _Phony target_ sono semplici azioni da eseguire e non target da buildare.

Esempi tipici sono:
```
clean:
    rm *.o    
cleanall:
    rm Web-list *.o
```

I phony target sono eseguiti solo quando viene richiesto esplicitamente (spesso i phony target non hanno requisiti): `make clean`. Ovviamente non devono esistere file con lo stesso nome del phony target, perchè il make potrebbe interpretare l'azione in modo errrato. Nel caso in cui si volesse comunque mantere un file con lo stesso nome di un phony target si può fare così:
```
.PHONY:
    target1
    target2
    ...
```

## Variabili
I makefile sono **duplication-prone**: se, ad esempio, volessi ripetere la stessa stringa più volte potrei usare delle variabili, definite una volta e utilizzate tutte le volte che servono. Non sono propriamente delle variabili, ma degli *alias*.a

```
# Definizione
variable_name = string

# Sostituzione
$(variable_name)
```

Esempio:
```
OBJ = ogg1.o ogg2.o

TARGET: $OBJ
    g++ -o output $(OBJ)
```

## Esercizio
Introduci i phony target nel Makefile precedente: [Makefile2](../esercizio/compilazione_automatica/Makefile2)

Usa le variabili per definire i file oggetto: [Makefile3](../esercizio/compilazione_automatica/Makefile3)

## Regole implicite
Problema, anche usando le variabili elencare tutti i file oggetto può essere scomodo.

Make mette a disposizione un set di regole implicite. Una delle più utilizzate è la seguente:
_se i comandi per un file target **name.o** sono omessi, allora make cerca un file di nome name.c o name.cc e se lo trova invoca `gcc/g++ -c` sul file sorgente per generare il file oggetto_

Questo peremtte di semplificare la scrittura di Makefile, omettendo le descrizioni "ovvie".

Si possono evitare i comandi ovvi e i prerequisiti ovvi.

Esempio:
```
main.o: tipo.h liste.h fun-app.h # Senza file .cc
```

### Modifica regole implicite
Vedi _implicit rules_ sulla documentazione.

## Generazione prerequisiti
Grazie alle regole implicite, molte regole che necessitano di essere scritte in un _makefile_ spesso si riducono a dire che un determinao file oggetto dipende da alcuni header file. -> meglio della versione completa, ma ancora error-prone.

Per la generazione dei prerequisiti si può usare `g++ -M`, oppure `g++ -MM` per omettere i file di sistema. L'output di questo programma può essere redirezionato su un file con `>`, che poi includeremo nel _Makefile_.

## Inclusione file di testo
Per includere i file di testo si può usare la direttiva `include file1 file2 ...`

## Esercizio
1. Rimouvere tutte le regole di dipendenza tranne quella di _Web-list_. La compilazione dovrebbe comunque andare a buon fine grazione alle regole implicite: _Makefile4_

2. Modificare il Makefile in modo che fornisca un phony target per la generazione delle dipendenza; usare questo file per compilare il programma (attenzione: il target di compilazione deve dipendere dal file delle dipendenza): _Makefile4_

## Tips pratici
Per la fase di traduzione è meglio aggiungere `-Wall`. Vogliamo usare questo flag mantenendo le regole impliclite:
```
CXXFLAGS = -Wall
```

Questa variabile viene passata in automatico a _g++_.

## Variabili automatiche
Sono variabili speciali espanze nella lista dei comandi, quindi non utilizzabili nei target e nei prerequisiti:
 - `$@` variabile che prende il nome del target nella lista dei comandi
 - `$<` primo prerequisito
 - `$?` prerequisito più nuovo del target
 - `$^`

Esempio:
```
outputfile: file1.o file2.o file3.o file4.o
g++ -o $@ $^
```

## Istruzioni condizionali
Utilizzate per:
 - deciedere quali parte del Makefile usare
 - wildcard 