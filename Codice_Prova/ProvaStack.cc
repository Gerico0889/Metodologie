#include "Stack.hh"

#include <iostream>
#include <string>

typedef std::string T;

void prova(){
  Stack s1;
  assert(s1.size() == 0);
  assert(s1.isempty());

  std::cerr << "\n\n ### fine fase 1 ### \n\n";

  Stack s2(s1);
  assert(s1.size() == 0 && s2.size() == 0);

  std::cerr << "\n\n ### fine fase 2 ### \n\n";

  s2.push("aaa");
  
  /* Visto che s2 è una copia di s1, con la assert sotto mi assicuro che  il valore sia stato copiato e non passato per riferimento
  */
  
  assert(s1.size() == 0 && s2.size() == 1);

  std::cerr << "\n\n ### fine fase 3 ### \n\n";

  T& t = s2.top();
  assert(t == "aaa");
  t = "bbb";
  assert(s2.top() == "bbb");

  std::cerr << "\n\n ### fine fase 4 ### \n\n";

  Stack s3 = s2;
  assert(s2.size() == 1 && s3.size() == 1 && s3.top() == s2.top());

  std::cerr << "\n\n ### fine fase 5 ### \n\n";

  s3 = s2 = s1;     //Assegnamento concatenabile
  assert(s1.empty() && s2.empty() && s3.empty());

  std::cerr << "\n\n ### fine fase 6 ### \n\n";

}  


