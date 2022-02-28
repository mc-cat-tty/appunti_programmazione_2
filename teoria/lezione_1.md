# Lezione 1 - Introduzione al corso

IDE utilizzato durante il corso: VSCode

## Obiettivi
Partire dalle conoscenze di prog1 espandendole allo sviluppo software su più file, con un occhio di riguardo a moduli e librerie.

## Syllabus
Liste:
- puntatori
- ADT e strutture dati dinamiche
- implementazione liste

Ricorsione:
- algoritmi ricorsivi
- gestione chiamate e stack
- implementazioni ricorsive a problemi notevoli

Alberi:
- alberi binari di ricerca
- alberi n-ari
- visite di alberi

Grafi:
- implementazione grafi
- visite di grafi
- ricerca dei cammini minimi

Approfondimento programmazione Cpp:
- bit vector
- funzioni di ordine superiore

> Le funzioni di ordine superiore sono funzioni che prendono in ingresso altre funzioni.
> Sono utili nei problemi di ordinamento o, per esempio, nell'implementazione di operazioni matematiche come integrale o derivata.

Debugging:
- definizione di bug
- attività di debugging
- debugging in un IDE

Moduli file:
- modularizzazione di un progetto (trasformare un progetto monolitico spezzettandolo in più moduli di più facile manutenzione)
- suddivisione in file
- header file (interfaccia verso l'esterno di un modulo)
- visibilità e scoping

Compilazione separata:
- fasi di compilaizone
- linking statico e dinamico
- makefile

> La compilazione separata è quell'operazione attraverso la quale posso compilare i moduli di un progetto più vasto indipendentemente.
> Dopo aver creato una serie di file oggetto (uno per ciscun modulo) posso dare tutto in pasto al linker.

> Il Makefile è un file che permette di definire una serie di regole di compilazione del progetto, definite attraverso una serie di target.

Documentazione (il miglior amico dell'informatico) :
- principi di documentazione del codice
- Doxygen

Version control:
- controllo versioni di un progetto
- gitLab

## Ambiente di programmazione
- VSCode
- plugin Cpp
- lldb
- git

> VSCode è un editor general-purpose che può interfacciarsi con il compilatore, il debugger e vari version control systems.

## Modalità d'esame
- Prova intermedia (metà Aprile): voto valido per i primi due appelli estivi
- Prova scritta: 6 domande toeriche (saltabili se si è superata la prova intermedia) e 3 domande pratiche
- Prova di programmazione (pratica): prova di implementazione di un progetto in laboratorio
- Orale facoltativo

Voto: 65% prova programmazione, 35% prova scritta

# VisualStudio Code
È un IDE multi-linguaggio e multi-piattaforma

## IDE
=> Integrated development environment

Un IDE è un software che, in fase di programmazione, aiuta i programmatori nello sviluppo del codice sorgente.

Componenti classici:
- editor codice
- compilatore o interprete
- tool di building automatico
- debugger

## Workspace
=> letteralmente "ambiente di lavoro"

All'interno di questo ambiente di lavoro posso gestire uno o più progetti, che fanno parte di un progetto più ampi.

All'interno di VSCode un workspace è una cartella (single-folder workspace, multi-folder workspace)

Ogni workspace porta con se una serie di impostazioni e configurazioni relative ad un progetto: addons, build task, terminali, routine, ecc.

## Build task
Opzioni:
<details>
<summary>Run Task</summary>
Esegui script e automazioni per compilare/eseguire il progetto.
</details>

<details>
<summary>Run Build Task</summary>
Quando cliccato vengono proposte una serie di compilatori e opzioni di compilazione. Viene compilato l'intero progetto. In futuro verrà utilizzato make.
</details>

<details>
<summary>Run Active File</summary>
Per eseguire programmi che vengono eseguiti attraverso un interprete.
</details>

<details>
<summary>Run Selected Text</summary>
Utilizzato per linguaggi che permettono di eseguire porzioni di codice, come per esempio il Python.
</details>