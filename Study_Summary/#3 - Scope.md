# Scope

Una dichiarazione introduce un nome in uno scope, questo nome può essere utilizzato solo all'interno di quello scope. 

Abbiamo 6 tipi diversi di scope:

* **Scope Locale:** Uno scope locale è quello definito tra {}. Tutti i nomi dichiarati all'interno di quel blocco vengono chiamati *nomi locali*, e valgono soltanto all'interno di quel blocco.
* **Scope di Classe:** Uno scope di classe si estende dall'apertura della { (riferita alla dichiarazione della classe, all'esterno di funzioni, lambda o altri namespace) fino alla fine di essa. Un nome definito all'interno della classe viene chiamato *membro*.
* **Scope Globale/Namespace:** Lo scope globale si estende dall'inizio della dichiarazione di esso fino alle fine del file. Un nome definito all'interno dello scope globale viene chiamato *nome globale*. Lo scope globale è un esempio di scope di namespace.
* **Scope di Statement:** Lo scope di statement è definito all'interno delle () negli statement for, while, switch, if. Tutti i nomi all'interno dello scope di statement sono *nomi locali*.
* **Scope di Funzione:** nse proprio capito sinceramente.

# Ciclo di vita degli oggetti

Il ciclo di vita di un oggetto inizia quando il suo costruttore finisce e termina quando il suo distruttore finisce.

Abbiamo diversi tipi di ciclo di vita di un oggetto:

* **Automatico:** L'oggetto viene creato quando si trova la definizione e viene distrutto quando finisce lo scope dove è stato definito.
* **Statico:** Oggetti dichiarati nello scope globale oppure dichiarati con il prefisso *static*. Con il prefisso *static* gli oggetti vengono eliminati alla fine dell'esecuzione del programma, anche se sono stati dichiarati dentro scope o dentro funzioni.
* **Dinamico:** Gestiamo la creazione e la distruzione degli oggetti tramite la *new* e la *delete*. Gli oggetti vengono inseriti nell'heap.
* **Oggetti Temporanei:** Il ciclo di vita di questi oggetti (come risultati temporanei di un calcolo o la variable temporanea che mantiene il valore di un riferimento constante) dipende dal loro uso. Se l'oggetto è collegato a un riferimento, termina il suo ciclo quando il riferimento termina, in altri casi terminano quando l'espressione che li contiene finisce.
* **Oggetti sui thread:** Oggetti dichiarati *threal_local*. Vengono creati quando il loro thread viene creato ed eliminati quanodo viene eliminato.

