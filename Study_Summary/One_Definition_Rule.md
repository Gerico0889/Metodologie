# ODR

* Data una classe, template, enumerazione, variabile ecc... la ODR detta che esse devono essere **definite** solo una volta nello stesso programma.
* Se una funzione non inline viene definita più volte nella stessa unità di traduzione, il compilatore si accorgerà di questa cosa e darà errore. Se invece una funzione non inline viene definita più volte ma in differenti unità di tradizione, il compilatore non si accorgerà di questa cosa ma verrà comunque dato errore da parte del linker.

### Esempio:

Se ho un file header con una ``void foo(){}`` definita e lo includo in due diversi file cpp, il linker darà errore perchè troverà due definizioni di foo. 

* La ODR mi permette, se ho una funzione inline, di definirla (nella stessa maniera) più volte nello stesso programma. 
* La stessa cosa vale per i template; quando definiti all'interno dell'header file, la definizione di essi può essere inserita all'interno di più source file visto che le funzioni dipendono fortemente dal tipo su cui è istanziato il template e necessitano del corpo delle funzioni.
* Tutto ciò funziona **se e solo se** le definizioni di tutte le funzioni sono identiche in tutti i file sorgente. Se le definizioni sono diverse si va incontro alla ODR e, quando si utilizzano funzioni inline, template, classi, enumerazioni, il linker non si accorgerà dell'errore e il programma verrà compilato senza problemi e andrà in *undefined behavoir*.

### Esempio (da capire bene):

C'è un caso particolarmente delicato dove la ODR viene violata senza che ce ne si accorga. Poniamo per esempio questo header:

``` c++
#ifdef MODE_X
	template <class T>
		void bar(T) {/*def1*/}
#else
	template <class T>
		void bar(T) {/*def2*/}
```
Nel caso in cui tutto verrebbe compilato in un unico file exe e tutti i file sorgenti dove viene importato l'header concordano con il settaggio di MODE_X non ci sarebbe alcun problema perchè viene attribuita la stessa definizione di ``void bar(T)`` in tutti i file sorgenti.

Se invece i file sorgenti non sono uguali nel settaggio di MODE_X, la ODR viene infranta ma nè il linker nè il compilatore danno errore, quindi ci si trova con un programma che sembra funzionare ma prima o poi darà problemi. Il succo di questo esempio è:

> Quando scrivi gli header file, non farli MAI dipendere da macro per cambiare modalità (?).
