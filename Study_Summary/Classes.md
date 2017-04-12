## Classi ##

### Default copy ###

Di default gli oggetti possono essere copiati, ovvero è possibile inizializzare un oggetto assegnandone un altro dello stesso tipo. Questo è possibile poichè di default le classi possiedono un **costruttore di copia**, il quale esegue l acopia

### class and struct ###

Il costrutto 
``` c++
class X { ... };
```
è chiamato *definizione di classe* e definisce un tipo di dato, definito da utente, chiamato X.

* una definizione di classe può essere replicata in differenti file sorgente, usando #include, senza violare la ODR.

``` c++
struct S {...};

class S {public: ...};
```
* *struct* è un modo abbreviato per definire una classe con membri di default pubblici. È meglio usare struct per classi che sono pensate come semplici strutture dati, mentre class per "tipi con invarianti".
* costruttori e funzioni di accesso a membri dato possono essere utili anche per le struct ma con lo scopo di abbreviare la scrittura e non come garanti per le invarianti.
* in una definizione di funzione è più logico dichiarare i membri pubblici prima di quelli privati, al fine di enfatizzare l'interfaccia della classe.

### Costruttori ###
* usare una funzione per inizializzare un oggetto può portare a errori, l'utente della classe infatti può dimenticarsi di inizializzare l'oggetto o inizializzarlo due volte, entrambe le situazioni possono portare a risultati disastrosi; quindi è meglio fornire una funzione con lo specifico obiettivo di inizializzare gli oggetti, questa funzione è chiamata **costruttore**.
* un costruttore ha lo stesso nome della classe e se richiede argomenti, questi vanno forniti.
* è consigliabile usare l'inizializzazione con la notazione **{  }** poichè è più esplicita rispetto a ciò che viene fatto e quindi permette di evitare potenziali errori.
* le regole di overloading per le funzioni vengono applicate anche ai costruttori.
* in un costruttore possono essere definiti anche dei valori di default per i parametri e questi dovrebbero essere all'infuori dell'insieme dei possibili valori assegnabili all'argomento, es.

``` c++
class Date {
	int d, m, y;
public:
	Date(int dd =0, int mm =0, int yy =0);
// ...
};
```
* Il costruttore semplifica l'implementazione deglle funzioni membro perché, dato un costruttore, nessuna funzione avrà la possibilità di agire su dati non inizializzati.

### Costruttori espliciti (explicit)

Di default se un costruttore con un argomento solo viene invocato, agisce da conversione implicita dal tipo del parametro al tipo del costruttore. Esempio:

``` C++
void foo(const Razionale& r) {...}
foo(123)     // Conversione legittima, mi converte implicitamente da signed int a Razionale
```
Queste conversioni implicite possono causare errori molto difficili da notare. Per evitarle è stata introdotta la parola chiave **explicit**.

* Viene messa come prefisso alla dichiarazione dei costruttori.
* Non permette una conversione implicita quando si chiamano i costruttori.
* Permette conversioni solo se esplicitamente richiesto (con dei cast per esempio)
* È consigliabile usare sempre **explicit** per i costruttori a meno che non si abbiano delle motivazioni molto forti (come per esempio la classe dei complessi)
* Se un costruttore è dichiarato **explicit** e definito all'esterno della classe, la parola chiave **explicit** non deve essere ripetuta.

Esempio:
``` C++
class Date {
   int d, m, y;
public:
   explicit Date(int dd =0, int mm =0, int yy =0);
   // ...
};
Date d1 {15};         // Ok, conversione esplicita
Date d2 = Date{15};   // Ok, conversione esplicita di 15 a Date
Date d3 = {15};       // Non ok, conversione implicita da 15 a Date
Date d4 = 15;         // Non ok
void f()
{
   my_fct(15);        // Non ok, conversione implicita
   my_fct({15});      // Non ok, conversione implicita
   my_fct(Date{15});  // Ok, conversione esplicita
   // ...
}
```
Se invece voglio evitare delle particolari conversioni implicite, devo definire il costruttore così:

``` C++
Razionale(char) = delete;
Razionale(bool) = delete;
```
Un altro modo per evitare conversioni implicite è quello di dichiarare i costruttori che non voglio siano invocati nel campo private della classe in modo tale da avere un errore a linking time se provo ad accedervi.

### Invariante di classe

* Un'affermazione di ciò che si assume essere vero per una classe è chiamata **invariante di classe**.
* A stabilire un'invariante di classe sono spesso i costruttiri, poichè inizializzano l'oggetto.
* L'invariante di classe deve essere rispettata ogni volta che una funziona membro è richiamata (all'esterno della classe).
* Spesso dichiarate come commento, che deve essere reso vero dal costruttore.

**Ma perchè dobbiamo definire un'invariante?**

* Per concentrare gli sforzi di progettazione della classe.
* Per chiarire il comportamento della classe.
* Per semplificare la definizione delle funzioni membro.
* Per chiarire la gestione delle risorse.
* Per avere una documentazione più semplice.

