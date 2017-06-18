#include <string>
#include <vector>
#include <iostream>
typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
void f(const vect& v) {
  iter i = std::find(v.begin(), v.end(), "inizio");
  iter i_end = std::find(v.begin(), v.end(), "fine");

  /*
    "inizio" può essere dopo "fine" e quindi gli iteratori
    saranno scambiati quindi il ciclo potrebbe accedere a
    memoria a cui non dovrebbe accedere.
  */

  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}

void g(vect& v) {
  iter i = v.begin(), i_end = v.end();
  v.insert(++i, "prima");

  /*
    La insert dopo non funziona perché dopo la prima gli
    iteratori vengono invalidati quindi dovrei riassegnarli

    i = v.begin(), i_end = v.end();
  */
  
  v.insert(++i, "dopo");
}
