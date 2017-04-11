## Constextr

* Constexpr significa far valutare un'espressione a compile-time. 
* A differenza del const, alle espressioni constexpr possono essere assegnati solo espressioni costanti, esempio:

``` c++
const int x = 7;
const string s = "asdf";
const int y = sqrt(x);
constexpr int xx = x;       // OK
constexpr string ss = s;    // errore: s non è un'espressione costante
constexpr int yy = y;       // errore: sqrt(x) non è una funzione constexpr
```
* Una classe che ha il costruttore definito come *constexpr* è chiamato *literal type*. Deve inoltre avere il corpo vuoto ed essere inizializzato da valori che sono potenzialmente espressioni costanti.
* Una funzione membro *constexpr* implicita il *const* (che rende la funzione costante).

