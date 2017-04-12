# Eccezioni

Cosa succede se vi è un errore all'interno della classe a run-time? Chi deve gestirlo?

* Chi ha programmato la classe non sa cosa vuole fare l'utente (in genere non sa neanche chi o dove viene usata la sua classe). 
* L'utente non sa come rilevare l'errore (se sapesse come non causerebbe neanche errori).

La soluzione è quella di generare dei codici di errore (inseriti opportunamente dal programmatore della classe) che avvisino l'utente su che cosa ha fatto di male in modo da poterlo mettere nelle condizioni di gestire l'errore.

Per lanciare un segnale di errore, viene utilizzata la parola chiave *throw (nome errore)*, viene utilizzata all'interno di un blocco *try* dove viene scritto il codice che si pensa possa portare a errore, infine l'errore verrà gestito dal blocco di codice preceduto dalla parola chiave *catch (nome errore)* che lo risolverà o rilancerà l'eccezione.

# Invarianti

Gli errori che devono essere gestiti sono di solito quelli che violano le preecondizioni della nostra classe. Infatti quando creiamo una funzione o una classe dobbiamo considerare anche le *preecondizioni* (per esempio mantenere la size di un vettore sempre maggiore di 0) e mantenerle per tutta la durata della sua esecuzione.

Le affermazioni che facciamo nelle nostre classi vengono chiamate *invarianti di classe* o semplicemente *invarianti*.

È compito del costruttore della classe stabilire le invarianti e compito delle funzioni membro mantenerle.

La nozione di invariante è centrale nella scrittura di una classe, ci permette infatti di:

* Capire bene cosa vogliamo
* Ci forza a essere più specifici, riuscendo ad avere un codice più pulito e corretto.

---

Quando una precondizione di una funzione non è rispettata, essa non può eseguire il lavoro. Se invece un costruttore di una classe non rispetta le invarianti l'oggetto non viene creato. In questi casi ci sono diverse scuole di pensiero su come deve essere gestito il problema:

* Non gestirlo completamentee lasciare il programma scorrere in quanto è compito dell'utente assicurarsi che le precondizioni e le invarianti di classe vengano rispettate, in caso contrario gli errori verranno eliminati tramite debug e testing
* Una precondizione o un'invariante violata sono degli errori importanti e il programma non dovrebbe continuare dopo suddetti quindi è meglio terminare il programma.

Il primo approccio è di solito utilizzato per motivi di performance in quanto fare dei controlli continui sui dati per evitare e gestire errore diventerebbe molto pesante.

Il secondo approccio è utilizzato in quei programmi dove non è un problema che essi vengano terminati.

---

Abbiamo due tipi di asserzioni:

* In `<cassert>` viene fornita *assert(A)* che controlla l'asserzione A a run-time se e solo se la macro **NDEBUG** non è definita. Se l'asserzione è falsa viene dato un messaggio di errore e il programma viene terminato.
* Il linguaggio fornisce anche *static_assert(A, message)* che controlla l'asserzione A incondizionatamente a compile-time e, se falsa, manda il messaggio di errore fornito nei parametri e la compilazione fallisce.
