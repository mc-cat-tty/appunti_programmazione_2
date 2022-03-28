# Modularizzazione codice e sviluppo su più file
Programmi di complessità elevata, con tante righe di codice e quindi con molte interconnessioni tra i componenti del software, necessitano di uno sviluppo modulare, in modo tale da permettere al team di sviluppo di lavorare contemporaneamente.

L'attività di progettazione è il primo step nello sviluppo di un progetto di medie dimensioni:
- struttura del progetto
- algoritmi da utilizzare
- definizione funzioni

## Livello di astrazione
Le attività di progettazione che abbiamo fatto fin'ora sono a basso livello di astrazione.

Nel caso di programmi di dimensioni maggiori è necessaria una progettazione ad un **livello di astrazione** più elevato per dominare la **complessità**.

## Sviluppo sistemi software complessi
La programmazione in grane o *in the large* richiede di:
 - suddividere il lavoro tra più gruppi per contenere tempi e quindi costi di sviluppo
 - mantenere alta la qualità del software in termini di:
    - affidabilità
    - prestazioni
    - modificabilità -> codice **monolitico** vs **modulare**
    - estensibilità -> dipende dalla modificabilità
    - riutilizzo

## Programmazione modulare
> È un approccio alla programmazione *in grande* (sistemi software di medie-grandi dimensioni) che permette di gestire la complessità del sistema da realizzare suddividendolo in moduli tra loro correlati

Buone pratiche:
 - ogni **modulo** contiene un insieme di funzioni e strutture dati *logicamente correate* in base a qualche principio singificativo (la suddivisione ha senso dentro la logica del sistema software)
 - tipicamente ogni modulo fornisce una serie di **servizi** e può implementare certe **strutture dati**

La programmazione modulare richiede un *processo di astrazione* = processo che porta ad individuare le proprietà rilevanti di un'entità, ignorando in dettagli non essenziali (come i dettagli implementativi).

I tipi di dato sono un'astrazione messa a disposizione dal linguaggio di programmazione.

### Meccanismi di strazione
I più diffusi sono:
- astrazione sul *controllo* => la più utilizzata dai **linguaggio procedurali**
    > consente di astrarre una funzionalità dai dettagli della sua implementazione
- astrazione sui *dati* => utilizzata dai **linguaggi a oggetti**
    > consente di astrarre gli oggetti (entità) che costituiscono il sistema, descritti come struttra dati + funzioni (metodi)

### Esempio
Realizzare una suite di gestione delle liste costituita da un insieme di moduli, con i seguenti obiettivi:
 - separazione tra le funzionalità che realizzano l'applicazione e quelle che manipolano le liste, in modo da modificare l'implementazione della lista senza intervanire la logica dell'applicazione
 - separazione tra le funzionalità di gestione della lista e le funzionalità che manipolano il tipo di dato, così da:
    - poter cambiare il tipo di informazione gestita dalla lista
    - consentire di cambiare l'implementazione della lista

Come organizzare il progetto?
- tipo di dato
- primitive delle liste
- funzioni dell'applicazione: stampalista, cancellalista, cercacancella...

Moduli:
 1. modulo lista
 2. modulo funzioni dell'applicazione
 3. modulo main

Ci sono moduli più importanti di altri? Nì, alcuni moduli sono più utilizzati in quanto più generali, ma spesso non fanno niente da soli

## Moduli clienti
I **moduli clienti** utilizzano *servizi* e *oggetti* forniti da altri moduli. Nel nostro caso il modulo main usa il tipo di dato lista e invoca le funzioni dell'applicazione.

      .--------------.    .---------------------------------------.
      | modulo liste |    | modulo funzionalità dell'applicazione |
      '--------------'    '---------------------------------------'
            ^                                 ^
            |                                 |
            |            .------.             |
            '------------| main |-------------'
                         '------'



Questa non è l'unica soluzione possibile, i servizi possono essere divisi in moduli per "caso d'uso". Una delle difficoltà della progettazione è scegliere una soluzione. Il project manager sceglie la soluzione migliore.

La soluzione che abbiamo pensato rispetta parzialmente l'obiettivo 1: la funzione crea_lista contiene ancora delle operazioni che competono al modulo liste:
[gestione_lista_doppia_mod1.cpp](../esercizi/moduli_sofware/gestione_lista_doppia_mod1.cpp)

L'obiettivo 2 non è raggiunto perchè alcune primitive dipendono dal tipo di dato memorizzato in ogni nodo. Possibilie soluzione => suddividere il modulo *liste* in *liste* e *liste_tipo*, ristrutturanod lo schema logico in:
- liste => tail, prev, insert_elem, delete_elem
- liste_tipo => head, new_elem, search (tutte le primitive che ricevono in ingresso o ritornano il tipo di dato memorizzato in informazione)

## Realizzazione di un modulo
Dotato di una chiara separazione tra:
- interfaccia
- corpo

L'**interfaccia** specifica cosa fa il modulo e come si utilizza. Deve essere visibile dall'esterno.

Il **corpo** descrive "come" l'astrazione è realizzata, quindi è l'implementazione di funzionalità e strutture dati esportare dal modulo che sono nascoste e protette all'interno di esso.

Il modulo cliente può accedere alle funzionalità del modulo solo attraverso l'interfaccia.

L'interfaccia esporta i servizi al di fuori del modulo e ne definisce l'utilizzo. Se non si vuole esporre un servizio (tenerlo privato) basta non definire la sua interfaccia.

La struttura logica viene espressa tramite commenti e prototipi delle funzioni.
In C dichiariamo le funzioni all'interno dei file header, mentre le definiamo nell'implementazione:
```c
/***********************/
/* HEADER MODULO LISTE */
/***********************/

// ..


/****************************/
/* DEFINIZIONE MODULO LISTE */
/****************************/

// ...
```

## Parte pubblica e privata
Si definiscono:
- funzioni e strutture dati **pubbliche**: le parti accessibili dagli utenti di un modulo (offerte all'esterno)
- funzioni e strutture dati **private**: tutte le altre strutture dati e funzioni del modulo (non esposte)

L'interfaccia è costituita da:
- strutture dati pubbliche
- dichiarazione funzioni pubbliche

L'implementazione è costituito da:
- strutture dati private
- definizione di funzioni pubbliche e private

## Vantaggi
- il cliente del modulo non deve conoscere i dati implementativi
- chi costruisce il modulo è liberarlo di implementarlo come vuole, modificando anche l'implementazione dopo la scrittura, purchè non venga alterata l'interfaccia (rende il modulo retrocompatibile)

Il **changelog** tiene traccai dei cambiamenti effettuati sul modulo. Il **breaking changes** rompono la compatibilità con il codice vecchio e sono i più importanti da segnalare.

## Esempi
Internet non funzionerebbe se l'interfaccia delle comunicazioni non fosse stata standardizzata. L'implementazione di ogni webserver e ogni client può variare.

Anche i driver funzionano allo stesso modo (i driver forniscono al SO un interfaccia standard): il sistema operativo si aspetta i dati in un certo formato, indipendentemente dall'implementazione del dispositivo e viceversa il SO invia i dati allo stesso modo a dispositivi diversi.


Conclusione: definiamo chiaramente l'interfaccia ed accediamo ai servizi del modulo solo tramite l'interfaccia.

## API
Application Programming Interface = interfaccia di un modulo software. Rappresentano un insieme di procedure disponibili al programmatore, solitamente raggruppate secondo una certa logica. Diverse API sono a pagamento.

## Esercizio
[gestione_lista_doppia_mod3.cpp](../esercizi/moduli_sofware/gestione_lista_doppia_mod3.cpp)