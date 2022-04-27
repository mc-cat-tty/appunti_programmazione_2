# Documentazione
La documentazione (in campo informatico) fornisce materiale utile a comprendere caratteristiche e funzionalità di un sistema o di un software.

Esistono diversi tipi di documentazione:
 1. guide e manuali
 2. HowTo
 3. FAQ
 4. Forum

Il nostro obiettivo sarà quello di generare documentazione in modo automatico a partire dai commenti contenuti nel codice sorgente.

## Doxygen
=> tool per la generazione automatica, open-source e multipiattaforma.

L'output della documentazione può essere in diversi formati: HTML, pdf, LaTeX, man pages

Per alcuni formati è disponibile un sistema di hyperlink che permette una lettura più facile.

La documentazione prodotta riporta anche il diagramma delle classi; diverse lingue sono gestite da Doxygen.

## Come funziona
I commenti devono essere formattati in modo opportuno, all'interno del codice sorgente. Le regole di formattazione sono documentate nel manuale di Doxygen. Ad ogni modo le regole di formattazione sono analoghe a quelle di altri tool della categoria.

Il formato dei commenti è chiamato *Javadoc*.

Per ogni progetto deve esistere un *file di configurazione*

Dopo aver installato doxygen si può lanciare il comando `doxygen` oppure avviarlo attraverso il plugin *Doxygen Documentation Generation*.

Se il file di configurazione non viene passato a doxygen, viene scelto un formato di default.

## Utilizzo
 1. Genero il file di configurazione `doxygen -g` con una serie di parametri di default, che posso cambiare
    La struttura di questo file di coumentazione è `NOME_PARAMETRO = VALORE_PARAMETRO` (coppie chiave-valore)
    Il file si chiama *Doxyfile*
 2. Le opzioni di configurazione indicano a Doxygen come interpretare i commenti da noi scritti
    Se usi l'estensione modifica il setting *Doxygen_runner: Configuration_file_override*

Le `struct` vengono inserite nella documentazione come `class`

## Personalizzazione
 - PROJECT_NAME = "nome progetto"
 - GENERATE_LATEK = NO
 - OUTPUT_DIRECTORY = "nome_dir"
 - EXTRACT_ALL = YES
    Senza questa opzione le parti di codice non commentate non vengono incluse nella documentazione

## Note
La documentazione creata in automatico da doxygen non è altro che un elenco di oggetti presenti nel nostro sistema. Doxygen non aggiunge automaticamente alcuna documentazione: per ottenere documentazione di qualità è necessario inserire i commenti manualmente.

Il contenuto informativo extra viene inserito da noi

## Commenti
**Cstyle comments** (perchè inizialmente erano disponibili solo questi): `/* ... */`
**C++ comment lines** (perchè erano disponibili solo il Cpp): `//`

## Documentation block
Un blocco di documentazione speciale è un commento formattato in modo tale da essere interpretabile da Doxygen.
Esistono due tipi di documentation block:
 - breve        `/** ...text... */`
 - dettagliata
    ```
    /**
        ...text...
    */
    ```

Con il parametro *Autobrief* a *ON* la descrizione breve viene dedotta automaticamente dalla descrizione dettagliata, prendendo la prima riga di commento.

## Posizione
Se si utilizza la sintassi vista fin'ora, il documentation block va posto prima dell'itentificatore (funzione, struct, ecc.)
Nel caso delle funzioni va messo prima della dichiarazione o prima delal definizione.

Volendo si può porre il blocco di documentazione subito dopo l'oggetto da identificare, se il commento viene fatto iniziare con "<": `int maxval;  /**< valore massimo */`. Questo è utile per creare brevi descrizioni inline.

## Descrizione breve
È possibile scrivere una descrizione breve e una descrizione dettagliata che differiscono.

Oppure settare `JAVADOC_AUTOBRIEF = YES` -> la descrizione breve è quella porzione del documentation block che va dal primo carattere fino al primo "." oppure newline.

## Inclusione del codice
`INLINE_SOURCES = YES` include il codice sorgente delle dichiarazioni

## Creazione di link
Quando nel codice viene menzionato un identificatore definito da un'altra parte, si può fare in modo che doxygen linki la documentazione di questo identificatore.

Per linkare un identificatore usa "::": `Per maggiori dettagli sulle funzionalità vedere ::main`

## Altri comandi
In doxygen i comandi iniziano con "@":
 - `@author`: indico gli autori di funzioni o librerie
 - `@mainpage`
 - `@file`
 - `@param`: descrivo gli argomenti della funzione
 - `@return`: valore ritornato dalla funzoine

## Vantaggi
Uno dei maggiori vantaggi di doxygen è che la fonte della documentazione si trova insieme al codice. Quindi ogni volta che si fanno modifiche al codice sorgente è possibile cambiare comodamente la documentazione di quella porzione di codice.

Inoltre è possibile tenere conto delle diverse versioni del software.