## Overloaded Function

Il C++ offre la possibilità di definire molteplici funzioni con lo stesso nome ma che operano con un numero e/o tipo di parametri diverso. È una funzionalità più che altro di convenienza che risulta utile quando abbiamo dei nomi di funzione che descrivono bene il comportamento di essa (open, print ecc...)

## Automatic Overload Resolution

Un compilatore per sapere quale funziona chiamare quando c'è una chiamata ha dei precisi criteri confrontando i parametri formali delle funzioni con quelli attuali della chiamata e sceglie in base a questi criteri (in ordine di importanza):

1. **Match perfetto:** Non viene fatta alcuna conversione tra i parametri o se ne fanno di banali (come da nome di array a puntatore, da nome di funzione a puntatore a funzione, qualificazione di T a const T).
2. **Promozioni:** Quando si ha una promozione dei parametri attuali ai parametri formali della funzione (bool a int, char a int, short a int, float a double ecc...)
3. **Conversione Standard:** Conversioni che implicano perdita di informazione e non permettono di risalire al valore precedente alla conversione, da Derived* a Base*, T* a void*, int a unsigned int.
4. **Conversione definita da utente:** Conversioni effettuate mediante costruttori di tipi definiti da utente (classe, struct, complex<T>).

Se tra tutte le funzioni candidate per la chiamata (trovare in base al nome), si sceglie quella utilizzabile che ha il match di livello più alto. Se si hanno due utilizzabili con lo stesso livello di match la chiamata è ambigua e quindi la è rifiutata.

### Descrizione Fasi:

**Prima fase:**

Nella prima fase scelgo le funzioni in base al nome e alla visibilità, *non* vedo il numero o il tipo dei parametri

**Seconda fase:**

Controllo tra le funzioni scelte nel primo passo il numero e il tipo dei parametri che ho messo nella chiamata della funzione

**Terza fase:**

Possono esserci diverse situazioni:

* Nessuna funziona utilizzabile, da errore.
* Una sola funziona utilizzabile, la uso.
* Più funzioni utilizzabili, confronto le conversioni dei parametri:
  * Si usano le regole di risoluzione automatica dell'overloading.

Esempio:

``` C++
Razionale r = 12;
```
Le funzioni candidate sono due: il costruttore di copia e il costruttore definito da noi (non dichiarato explicit). Quale utilizzo?
Utilizzo quello definito da noi perchè il costruttore di copia creerebbe un altro oggetto ed è poco efficiente.

L'utilizzo di una funzione privata, protetta, friend ecc... non ha a che fare con la risoluzione dell'overload. Può quindi essere scelta una funziona non invocabile e quindi impossibile da utilizzare con errore a compile-time.
