#include <iostream>
#include <math.h>

int main()
{
  const int base = 2;
  int res = 0;
  for (int i = 1; i <= 30; ++i)
    {
      res = pow(base, i);
      std::cout << i << ". " << res << "\n";
    }
}
  
