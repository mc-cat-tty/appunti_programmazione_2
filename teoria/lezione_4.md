# Debugging
> Software bug: errore o guasto che porta al malfunzionamento del software (errore logico, subdolo).

Spesso la causa di bug è un errore nel codice sorgente.

Il **bug report** è una relazione che dettaglia i bug di un programma. Alcune distro linux gestiscono i bug report dei software installati sul computer.

## Tipologie di bug
- syntax error: come la dimenticanza di un ";"
    - errore commesso in fase di scrittura
    - bug non rilasciato, perchè il software non compila
    - segnalato dal compilatore
- logic error
    - errori che si commettono nella fase di progettazione dell'algoritmo o della sua codifica
    - l'algoritmo fornisce un output inatteso
    - difficili da individuare, spesso richiedono l'aiuto di un debugger (utilizzeremo *gdb* o *lldb*)
    - potrebbe non presentarsi per ogni istanza di dati di input
- runtime error
    - errori che si verificano nella fase di esecuzione del programma
    - l'algoritmo e la codifica potrebbero essere corretti
    - spesso sono relativi all'utilizzo errato della memoria
    - si verificano soprattutto nell'utilizzi dei puntatori e in programmazione dinamica

## Effetti dei bug
Alcuni bug hanno un effetto sottile e limitato sulla funzionalità del programma, mentre altri possono causare il **crash** o il blocco (**freeze**) del programma.

I bug di sicurezza non inficiano il funzionamento del programma, ma permettono ad utenti non autorizzati di ottenere privilegi non previsti.

### Crash
Condizione in cui il programma si interrompe o viene interrotto dal SO.

Esempi: divisione per zero, accesso ad un'area di memoria non destinata al programma.

Se questo bug è presente nel kernel del sistema operativo o in una libreria da esso utilizzata, l'intero SO si potrebbe bloccare.

### Freeze
Condizione del programma in cui non risponde agli input. È necessario killare il processo oppure spegnere o riaccendere la macchina.

## Debugging
debugging = togliere i bug

> **processo metodico** che serve a trovare e ridurre il numero di bug di un programma.

Generalmente il debugging richiede molto tempo: la parte più difficile del debuggin è *trovare i bug*.

Un bug in una sezione di un programma può causare errore in una sezione completamente diversa (eg: libreria).

A volte, un bug non è isolato, ma rappresenta un errore di pensiero/pianificazione, quindi risulta molto diffcile correggerlo.

In alcuni casi i bug sono dovuti all'hardware sottostante (eg: errore lettura di un setttore del disco).

## Processo di debug
1. Il primo passo per individuare un bug è riprodurlo, in modo affidabile. Spesso è quindi necessario ricostruire la situazione che ha causato il bug (consocere i valori in input che sono stati forniti).
2. Quando si ha un *bug stabile* (condizioni per farlo avvenire) si può utilizzare un debugger per monitorare l'esecuzione del programma e trovare il punto in cui il software diverge rispetto a quello che ci si aspettava.

Attenzione: in alcuni casi i bug potrebbero scomparire quando il programma viene eseguito con il debugger. Vedi **Heisenbug** (https://en.wikipedia.org/wiki/Heisenbug).

## Debugger
GDB - Gnu Debugger
Un debugger è un software che aiuta i programmatori ad individuare i bug tramite funzionalità specifiche:
- esecuzione **step-by-step**
- monitoraggio valori delle variabili
- fermare l'esecuzione del programma in presenza di determinate condizioni

### Funzionamento
Solitamente il debugger prende in input l'eseguibile del software (codice complilato, non sorgente) da testare.
È necessario che il programma sia compilato con i *simboli di debug* (informazioni che permettono di mettere in relazione ciascun dato o istruzione con le corrispondenti righe o dati del codice sorgente).

Per usare gdb su un eseguibile è necessario che l'eseguibile sia compilato in modalità debug: aggiungi il flag `-g`

Su VSCode vai su *run con lo scarafaggio* -> "Run and Debug". La configurazione di debug viene memorizzata nel file *launch.json*.
In modalità debug hposso vedere:
- variables: valore di tutte le variabili del programma, inclusi i registri
- watch: elenco delle espressioni che l'utente vuole osservare
- call stack: lista di chiamate a funzioni
- breakpoints: punti di pausa. Il programma esegue normalmente finchè non hitta la riga desiderata

Serve almeno 1 breakpoint per debuggare un programma.

### Interfaccia VSCode
- **continue**: esegue il programma fino al prossimo breakpoint
- **step over**: esecuzione step-by-step. Quando incontra una funzione la chiama senza entrarci dentro.
- **step into**: esecuzione step-by-step. Quando incontra una funziona la chiama e continua l'esecuzione step-by-step all'interno della funzione.
- **step out**: esce dal codice della funzione corrente.

## Esercizio
Debugging di [debug_test.cpp](../esercizi/debugging/debug_test.cpp)

## Input
Se non funziona setta a *true* il parametro di `externalConsole` all'interno di *launch.json*

Hint: si può eseguire il ciclo for una iterazione alla volta con il tasto step-over.

## Esercizi
Eseguire il debug di:
- [memoria.cpp](../esercizi/debugging/memoria.cpp)
- [potenze.cpp](../esercizi/debugging/potenze.cpp)
- [calcola_meta.cpp](../esercizi/debugging/calcola_meta.cpp)
- [variabili_input_ciclo.cpp](../esercizi/debugging/variabili_input_ciclo.cpp)