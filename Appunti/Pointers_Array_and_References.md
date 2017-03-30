## void*

* Un puntatore void* è interpretato come un puntatore a un oggetto di tipo sconosciuto.
* Un puntatore a qualsiasi tipo di oggetto può essere assegnato a un puntatore void* tranne i puntatori a funzioni e a membri.
* Un void* può essere assegnato ad un altro void\*, i void* possono essere comparati per equalità o inequalità e possono essere *esplicitamente* convertiti in altri tipi.
* Altri tipi di operazioni sarebbero non sicure in quanto non si conosce esattamente il tipo di dato puntato da void\*.

### Esempio:

```C++
void f(int* pi)
{
  void* pv = pi;
  *pv; //non posso dereferenziare un puntatore a void*
  ++pv;  //non posso incrementare perchè non so che tipo di dato è
  int* pi2 = static_cast<int*>(pv);  //conversione esplicita a int*
  double* pd1 = pv;  //non posso assegnare un void a un double
  double* pd2 = pi;  //stessa cosa
  double* pd3 = static_cast<double*>(pv);  //unsafe, implem. defined
}
```
## nullptr

* La parola chiave **nullptr** rappresenta un puntatore che non punta a nessun oggetto.
* Può essere assegnato a tutti i tipi di puntatori ma non ai tipi built-in.
* Era uso comune utilizzare 0 per denotare un puntatore nullo poichè non esiste alcun oggetto allocato nell'indirizzo 0. Essendo zero un int, viene implicitamente convertito a una costante di tipo puntatore.
* È di comune uso utilizzare la macro NULL che però differisce nelle varie implementazioni e può causare problemi. Per esempio in C, NULL = (void*)0, il che lo rende impossibile in C++ perchè non posso assegnare un tipo void\* a un altro tipo.
* Nullptr rende il codice più leggibile ed evita eventuali confusioni in caso di funzioni sovraccaricate per accettare sia puntatori che interi.

## array

* Dallo standard C++99 è stata introdotta la VLA (Variable Lenght Array) che permette di inizializzare gli array anche con variabili, cosa non possibile se si usa l'opzione -pedantic nel compilatore o si usa lo standard C++98, nel quale la dimensione dell'array deve essere una constante.

## Pointers and const

* Quando vengono usati i puntatori due oggetti vengono convolti; il puntatore e l'oggetto puntato.
* Prefissando const alla dichiarazione fa si che l'oggetto puntato, e non il puntatore, sia costante. Se voglio dichiarare il puntatore, e non l'oggetto costante, bsata utilizzare *const invece di *.
* Una costante indica solo una promessa di non modificare il valore, ma se questa è acceduta in altri modi è possibile modificarne il valore.
