# Parziale 2014

## Esercizio 1

``` C++
namespace N {
  struct C {
    C(int);
    C(const C&);           // Possibile convertire dal tipo della classe a un tipo built-in con operator tipo (operator int, operator char...)
  };

  void f(double d);
  void f(const C& c);
  void g(int i, double d);
  void g(int i, int j);
  void h(C* pc);

}

void f(char);
int h(const char* s = 0);
int h(const N::C* pc);

int main() {
  N::C c(5);
  f(5);
  f(c);
  N::f('a');
  // Candidate 3 e 4, la tre fa conversione std da char a double, la 4 fa conversione std a int e poi conversione a tipo C
  // Vince la 3 perchè ha meno conversioni

  g(5, 3.7);
  // Insieme delle candidate vuoto, non ho alcuna funzione utilizzabile
  // (non c'è argument dependent lookup perchè non utilizzo come parametro un tipo C)
  
  N::g(2.3, 5);
  // Candidate 5 e 6 nel namespace N, la 5 fa 2 conversioni mentre la 6 fa una conversione e un match perfetto, vince la 6
  
  N::g(5, 2.3);
  // Candidate 5 e 6, la 6 fa un match perfetto e una conversione std mentre la 5 fa 2 match perfetti. vince la 5
  
  h(&c);  // Con &c prendo l'indirizzo di c, quindi un puntatore a tipo C modificabile
  /* 
     Candidate 7, 9 e 10, 7 e 10 utilizzabili mentre la 9 no perchè non esiste una conversione da puntatore di C a puntatore di char.
     Posso però convertire il puntatore a C e convertirlo a nullptr o void che sono entrambi convertibili a qualunque tipo
     di puntatore. Nella 10 faccio una qualificazione a const mentre nella 7 c'è un match perfetto, vince la 7. Dopo la chiamata
     viene invocato il distruttore dell'oggetto c di tipo C perchè finisce lo scope del main.
  */

  // I distruttori anche se non dichiarati const possono essere chiamati anche su oggetti const.
}
```

## Esercizio 2

``` C++

//S.hh
struct S {};

//T.hh
#include "S.hh"
struct T {S s;};
  
//T.cc
#include "S.hh"
#include "T.hh"
T t;
S s;
```

Quando compilo l'unità di tradizione mi include 2 volte S, una volta esplicitamente mentre la seconda volta implicitamente perchè ho incluso S dentro T e ho inserito T. Violo la ODR. Se metto le guardie negli header file in questo modo:

``` C++
//S.hh
#ifndef S_HH_GUARD
#define S_HH_GUARD 1
struct S {};
#endif

//T.hh
#ifndef T_HH_GUARD
#define T_HH_GUARD 1
#include "S.hh"
struct T {S s;};
#endif

```

Con le guardie includo S una volta ma quando tento di includerla di nuovo implicitamente da T me lo impedisce.

# Tipi di cast in C++

``` C++
int foo(int);
int Louis_Cypher(const int& ri) {
  int& r = ri;
  // Non me lo fa fare quindi faccio così
  int& r = const_cast<int&>(ri);
  /*
    Può essere molto pericoloso, è un modo per imbrogliare (a volte è legittimo farlo). Se l'oggetto al quale voglio fare
    il const cast in origine nasceva come constante allora il compilatore sarebbe stato autorizzato a fare cose strane, come
    per esempio, nella sua architettura ci sono zone di memoria di sola lettora, avrebbe potuto allocare quella costante li
    in quel caso se faccio la const cast ma quella costante è nella memoria di sola lettura il programma va in 
    undefined behaviour.

    È possibile pensare a implementazioni lazy, quindi se creo un razionale 18/21 lui non corre a fare la semplificazione, ma lo mette
    da qualche parte e lo marca come non semplificato. Quando lo semplifica? Quando è necessario, ma quando è necessario? Non si sa
    forse quando devo stampare quel razionale allora quando deve essere stampato lo devo semplificare. Quindi invoco la routine
    di stampa che è invocata come const quindi non posso semplificare la frazione, in questo caso utilizzare il const_cast è plausibile.
  */
  
  r = 2*r + 1;
}

int main() {
  int i = (int) 5.7;
  // Cast del C; to be avoided

  (void) foo(5);
  // Uso idiomatico; consentito

  int j = static_cast<int>(5.7);
  /*
    Cast statico, tutto noto a tempo di compilazione, meglio utilizzare questo invece del primo
    perché da errore prima di andare a compile-time e perché è più chiaro e rende evidente
    dove sto facendo il cast. 
    Posso costringere il compilatore, ogni volta che vede un cast implicito, a segnalarmi un errore.
  */

  void* q = ...;
  
  int* p = reinterpreted_cast<int*>(q);
  /*
    Cast di reinterpretazione. Dico che quel puntatore è da interpretare come se fosse un intero.
    Alle volte sono necessarie (per serializzare in binario dei dati su un file) ma è brutto da utilizzare.
  */

  int k = int(5.7);
  // Cast funzionale. Si usa quasi solo con tipi definit dall'utente oppure con parametri di template.

  Base* pb = new Derived;
  Derived* p = dynamic_cast<Derived*>(pb);
  /*
    Cast dinamico. L'uso tipico è quando si fanno i downcast nelle gerarchie di ereditarietà. Funge da test a tempo di esecuzione,
    se pb è puntatore a derived allora mi da il puntatore a derived eventualmente mi da un puntatore nullo. Unico cast che non ha 
    equivalente nel C
  */
}

```

## Esercizio 3

``` C++
#include <cassert>
  
class C {
public:
  bool check_inv() const {
    
  }
  
  C(int a, int b) {
    // Implementazione del costruttore.
    assert(check_inv());
  }
  
  void foo(C& y) {
    assert(check_inv() && y.check_inv());
    // Codice che implementa il metodo foo. Prende 2 oggetti: this e y
    assert(check_inv() && y.check_inv());
    // Controllo entrambi i 2 oggetti perchè la funzione potrebbe aver modificato entrambi
  }
  
  void bar(const C& y) {
    assert(check_inv() && y.check_inv());
    // Codice che implemente il metodo bar.
    assert(check_inv());
  }
  
  void ying(const C& y) {
    assert(check_inv() && y.check_inv());
    // Codice che implementa il metodo ying.
    assert(check_inv());
    // Controllo solo this perchè y è passato come const
  }
  
  void yang(const C& y) const {
    assert(check_inv() && y.check_inv());
    // Codice che implementa il metodo yang.
    // Controllo solo all'inizio perchè entrambi gli oggetti sono passati come const
  }
  
  ~C(){
    assert(check_inv());
    // Codice che implementa il distruttore.
    // Non ha senso controllare un oggetto distrutto.
  }
  
  static void zen(int i, double d) {
    // Codice che implementa il metodo zen.
    // Non faccio alcun controllo perchè è dichiarato static, se lo static è applicato al metodo si applica alla classe e non agli
    // oggetti della classe quindi quel metodo non ha il this.
  }
  
  // ... altro codice ...
  
};

```

# Parziale 2016

## Esercizio 2

1. 12345 to const float*? Non se poffà con un cast implicito, serve un cast statico o reinterpreted
2. 0 to const float*? Da 0 posso convertire a qualunque tipo di puntatore, conversione std
3. "Hello" to std::string? Si perchè nella classe string c'è un costruttore da char a string
4. Signed Char to int? Si tramite promozione
5. 5.5 to float? Si tramite conversione std
6. int to const int&? Conversione di qualificazione
7. Array int to int*? Posso, trasformazione di lvalue (type decay da array a puntatore ad array, corrispondenza esatta)
8. Array int[5] to const int*? No perchè otteniamo un intero che non può essere trasformato in un puntatore a intero, potevo prendere l'indirizzo dell'array e in quel caso era lecito. Non era lecito neanche se ai[5] valesse zero.

## Esercizio 6

``` C++
void foo() {
  A* a1 = new A(1);
  A* a2 = new A(2);
  try {
    job1(a1, a2);
    job2(a1, new A(3));
  } catch (...) {
    delete a2;
    delete a1;
  }
}
```
In questo codice le risorse non vengono deallocate sempre, solo se c'è un eccezione quindi non va bene. Devo modificarlo ma come? Cosi:

``` C++
void foo() {
  A* a1 = new A(1);
  // a2 può lanciare eccezione, in questo caso cosa faccio? Non essendo dentro un blocco try non lancio eccezione quindi
  // esco dal programma e non viene deallocato niente 
  try {
    A* a2 = new A(2);
    try {
      job1(a1, a2);
      A* a3 = new A(3);
      try {
	job2(a1, a3);
	delete a3;
      } catch (...) {
	delete a3;
	throw;
      }
      delete a2;
      delete a1;
      // In questo modo dealloco le risorse anche se non ci sono eccezioni, così va meglio ma è perfetto? No
    } catch (...) {
      delete a2;
      throw;
    }
  } catch (...) {
    delete a1;
    throw;
    // La rilancio perchè voglio essere neutrale rispetto all'eccezione
  }
}

```

Ho messo un blocco che si apre alla prima risorsa e si chiude all'ultima. Se qualcosa va male nel catch rilancio l'eccezione, visto che l'ho fatto per tutte e tre le risorse allora sono exception safe. Anche perchè il distrutto della classe non può propagare eccezioni.

## C++ e Smart Pointer

``` C++
#include <memory>

void foo() {
  std::unique_ptr<A> a1 = new A(1);
  std::unique_ptr<A> a2 = new A(2);
  job1(a1, a2);
  job2(a1, std::unique_ptr<A>(new A(3)));    // Il puntatore di a3 è temporaneo e viene cancellato una volta finito lo scope di job2.
  job2(std::unique_ptr<A>(new A(3)), std::unique_ptr<A>(new A(4)));
}
```
Potrei avere un problema perchè non valuta con un ordine ben preciso quindi può succedere che il compilatore valuta la new di a3 ma non valuta il costruttore di questo e salta all'altra risorsa e invoca la new di a4 che lancia un'eccezione che invoca il distruttore ma in a3 era stata già allocata memoria quindi c'è memory leak.

## C++98

``` C++
std::auto_ptr<A>;
// Deprecato perché nel c++98 non c'era la copia ma solo lo spostamento quindi quando chiedevo una copia in realtà mi prendeva il valore.
```

## Esercizio 3

``` C++
struct Matrix {
  // ...
  size_type num_rows();
  size_type num_cols();
  value_type& get(size_type row, size_type col);
  Matrix& operator-();
  Matrix& operator+=(Matrix y);
  Matrix& operator+(Matrix y);
  void print(ostrem os);
  // ...
};
```

Ci sono errori, quali?

``` C++
struct Matrix {
  // ...
  size_type num_rows() const;
  size_type num_cols() const;

  value_type& get(size_type row, size_type col);
  const value_type& get(size_type row, size_type col) const;
  // Faccio due metodi get, uno per matrici costanti e uno per matrici variabili.

  Matrix operator-() const;
  // Const perché non modifica la matrice e deve restituirmene una per copia perché...

  const Matrix& operator+() const;
  
  Matrix& operator+=(const Matrix& y);
  // Const perché non voglio modificare la matrice che aggiungo.

  Matrix operator+(const Matrix& y) const;
  // Non voglio modificare ne la matrice nei parametri ne il this. Devo restituirlo per copia perchè se mi restituisce il reference poi lo perde.

  void print(ostream& os); 
  // ...
};

void foo(const Matrix& m) {
  auto n_rows = m.num_rows();
  // Nessuna conversione da matrice costante a matrice non costante, una candidata zero utilizzabli. Quindi metto la funziona costante
  // in modo da poter essere chiamata sia da oggetti costanti che da oggetti non costanti.
  auto v = m.get(1, 1);
  // Non posso farlo perchè la matrice è costante (quella passate per riferimento) ma il metodo è modificabile qunidi vedi modifiche sopra.
}

void foo(Matrix& m) {
  auto n_rows = m.num_rows();
  auto v = m.get(1, 1);

```
