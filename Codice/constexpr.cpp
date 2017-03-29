#include <iostream>
#include <stdexcept>

int main()
{
  const int dm = 17;
  int var = 18;
  constexpr double max1 = 1.4 * (dm * dm); //le constexpr accettano solo costanti
  
  constexpr int gcc = dm + dm; //compila
  /*constexpr int gsc = var;*/ //non compila
  
  return 0;
}
