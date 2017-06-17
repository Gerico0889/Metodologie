#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;

void f(const vect& v) {
  iter i = std::find(v.begin(), v.end(), "cioccolato");
  iter i_end = std::find(v.begin(), v.end(), "menta");

  /*
    Il problema sta nelle due istruzioni sopra, se cioccolato viene dopo menta
    il ciclo sotto accederà a zone di memoria che non c'entrano niente perché
    i non sarà mai uguale a i_end.
  */

  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}

void g(vect& v) {
  iter i = v.begin();
  iter i_end = v.end();
  *i = "cacao";
  v.insert(i, "vaniglia");

  /*
    Quando faccio la insert, gli iteratori vengono invalidati e ne vengono creati altri
    perché ho aumentato la grandezza del vector quindi devo riassegnare gli iteratori con

    i = v.begin();
    i_end = v.end();

    a questo punto il codice funzionerà.
  */
  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}
