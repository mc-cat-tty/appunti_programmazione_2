# Sistemi di versionamento del codice
Il problema nasce quando più sviluppatori lavorano allo stesso progetto software: scambiare e sincronizzare le modifiche.

Anche uno sviluppatore singolo trae vantaggio dal versioning control system.

## Soluzioni naive al versionamento
 1. Scambiarsi l'intero archivio software
    Problemi:
        - se l'archivio è grande si spreca banda
        - si spreca tempo
        - soluzione non scalabile
 2. Scambiare tra gli sviluppatori solo il file su cui sono state fatte delle modifiche
    Problemi:
        - all'aumentare della dimensione del team, aumenta la probabilità che esso sia in possesso di un file obsoleto
        - approccio non scalabile con il numero di programmatori coinvolti

## Soluzione smart
 3. Scambiare solo le modifiche effettuate ad un file
    - se le modifiche non sono state effettuate sulla stessa porzione di file, possono essere ricevute e applicate in parallelo dai programmatori
    - l'approccio scala con la dimensione del progetto e dei programmatori

## Storia dei sistemi di version control
Il primo meccanismo usato per scambiarsi modifiche è stato `diff`, un programma per UNIX AT&T v5 (1974), usato ancora oggi per trovare differenze tra due file (confrontati riga per riga).

L'output di `diff` è noto con due nomi diversi:
 - diff quando si legge l'output per capire le modifiche da apportare al file
 - **patch** o toppa quando l'output viene memorizzato per essere poi applicato il file originale ottenendo quello modificato (updated version).

### Formato di una patch
La patch è un file di testo, contenente un insieme di modifiche:
 - dove avviene la modifica
 - versione originale della porzione di file
 - modifiche da fare (eliminazione, aggiunta, sostituzione)

Problemi del file patch:
 - la posizione della modifica era identificata dal numero di riga -> poco flessibile perchè un altro programmatore potrebbe aver aggiunto delle righe di codice al file
 - non si teneva conto di un eventuale cambio di nome del file
 - non si poteva produrre automaticamente la differenza tra i file di due directory

## Formato unified
Risolve i problemi del file patch. Formato con _contesto unificato_.

Ogni modifica era preceduta da una **intestazione** `--- vecchio_file data_modifica` o `+++ nuovo_file data_modifica`.

L'intestazione era seguita da una serie di blocchi o **chunk** (**change hunk**): `@@ -start_line,next_lines +start_line,next_lines @@`. Il chunk indica che bisogna partire dalla start_line del vecchio file (meno) e sostituire le prossime next_lines (meno) con le nuove next_lines (più).

Vengono inserite tre righe prima e dopo ogni modifica per identificare meglio dove si trovi.

## Esercizio
```bash
diff -ru old new > old2new.diff
```

Dove old e new sono directory.

## Il comando `patch`
Dato un file o un albero di file originale ed una patch è possibile rigenerare la verisone modificata.

Sintassi:
```bash
patch -i patch_file
```

Patch controlla che la directory attuale sia coerente con le intestazioni del *patch_file* e, nel caso in cui lo sia, applica le modifiche; altrimenti il comando patch solleva un errore e produce un file *editedfile.rej* (rejected) contenente l'hunk fallito.

### Opzioni di patch
Ogni patch va applicata alla directory corretta, corrispondente a quella di generazione.

Se invece si vuole applicare una patch al di fuori della directory originale, si può usare l'opzione `-p[num]`, che rimuove un numero di directory pari a *num*.

È possibile rimuovere una patch con l'opzione `-R` -> ripristino della versione di partenza.
```bash
patch -R < patch_file
// oppure
cat patch_file | patch -R
```

## Problemi
Non si riesce a risalire alla patch che ha introdotto il bug (la sequenza di patch non è associata ad una timeline) -> manca il **controllo di revisione**.

Il controllo di revisione è un meccanismo di memorizzazione efficiente delle diverse versioni di un progetto software.

**Revision Control System** (o **Version Control**): software preposto alla gestione delle modifiche di documenti.

Un VCS gestisce un *deposito di file* (repository). Inoltre consente l'accesso concorrente al deposito da parte di molteplici utenti (elimina la necessità della mail).

È come se eleggessi una copia centralizzata del progetto "ufficiale" -> contiene le modifiche accettate del progetto.

## Funzionalità
 - import: inserimento di un progetto software
 - checkout: scaricamento di una specifica versione del progetto nella copia locale (working copy)
 - update: aggiornamento del progetto software alla versione più recente
 - checkin, commit: inerimento di modifiche locali
 - revert: cancellazione di modifiche sbagliate
 - tagging: marcatura di versioni interessanti (commit importanti)
 - branching: creazione di versione di prova
 - merging: fusione della versione di prova con la versione ufficiale (trunk)
 - log: storia del progetto
 - diff: produzione di patch tra versioni differenti

## Rappresentazione
La storia di un progetto viene rappresentata come un DAG. Per convenzione si rappresenta in orizzontale.

Esiste un solo trunk.

## Hint
All'intero di team di sviluppo di medie/gradi dimensioni esiste l'incaricato al merge.

## Gestione dei conflitti
Gli RCS implementano dei meccanismi per la gestione dei conflitti.

Una semplice soluzione è il *locking del file*: lock-modify-unlock -> Lo sviluppatore A prende il lock sul file che intende modificare, mentre B può leggere ma non scrivere fino a che il lock del file non è stato lasciato.

Una soluzione migliore è il *merge delle modifiche* (diverso dal merge di un branch) -> A aggiorna la versione locale del file (modificato da B) facendo un merge (il RCS aggiorna le modifiche senza conflitti). Manualmente bisogna risolvere i conflitti tra modifiche "non compatibili".

## RCS centralizzati
I primi RCS centralizzati usavano un server condiviso in rete per tenere traccia delle modifiche: RCS, SCCS, SVN, CVS

### Problemi di SVN
Nasce come costola di CVS introducendo atomic commit, cambiamenti di nome e spostamenti ecc.

Il problema maggiore è che manteneva due copie del progetto: old e new.

Con il tempo il progetto cresceva di dimensioni e lo spazio occupato sul disco era doppio.

## RCS distribuiti
Come HG, BITKEEPER, BAZAAR, GIT -> non esiste un repository centralizzato, ma ogni sviluppatore mantiene localmente una copia del progetto.

Localmente viene generata la patch e condivise le modifiche (al posto che farle generare al server centralizzato).

Le modifiche effettuate vengono *pushate* - spinte - sulle repo locali degli altri sviluppatori. L'operazione di *pull* permette di importare sulla propria copia locale le modifiche apportate da un altro sviluppatore.

Approccio peer-to-peer vs client-server. Nel primo caso si ha una repository centrale per ogni sviluppatore (working copy locale).

Possono esserci più repository centrali. Il merge delle modifiche avviene secondo una _web of trust_ (persone autorizzate integrano le modifiche).

## GIT (the stupid content tracker)
Creato da Linux Torvalds durante un sabbatico di 4 settimane dalle ceneri di BitBucker. Git significa letteralmente "stupido", infatti vuole essere stupido e veloce.

Orientato allo sviluppo non lineare. Lo sviluppo non avviene serialmente in un trunk principale, ma in parallelo su più branch. Uno sviluppatore viene incaricato di fare i merge delle modifiche.

Orientato allo sviluppo distribuito. Ciascuno sviluppatore ha un proprio branch locale detto *master*. Può copiare l'intero albero delle modifiche con il comando `clone`.

Orientato da progetti di grandi dimensioni: sistema di ricerca delle differenze molto veloce.

Autenticazione crittografica nella storia: il nome di ogni commit è un hash SHA256 di tutti i file del progetto. Questo evita che vengano introdotte modifiche non volute e propagate in "avanti" all'interno della storia del progetto.

## Pull request
=> richiesta inviata al mantainer di integrare le proprie modifiche nella copia ufficiale del repository

Il maintainer può decidere se soddisfare la pull request o meno.

*Benevolent dictator*

## Pull
L'operazione di pull consiste in:
 1. fetch -> aggiorna la repo locale
 2. merge -> merge delle modifiche remote con quelle locali
