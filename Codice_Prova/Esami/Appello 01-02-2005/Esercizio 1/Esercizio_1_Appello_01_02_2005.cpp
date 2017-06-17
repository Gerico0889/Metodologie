#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Reverse
{
  bool operator()(const std::string& s1,const std::string& s2)
  {
    return s1 > s2;
  }
};

void f(const std::vector<std::string>& vs, const char c)
{
  std::vector<std::string> tmp(vs);

  Reverse rvs;
  std::sort(tmp.begin(), tmp.end(), rvs;

  auto first = tmp.begin();
  auto last = tmp.end();
  
  for( ; first != last; ++first)
    {
      if((*first)[0] == 'c')
        std::cout << *first << ' ';
    } 
}

int main()
{
  std::vector<std::string> vs {"cigno", "mi chiamo", "oggi", "ciao", "orzo", "cz", "cazzo", "farro", "cena", "mare", "forse"};
  char c = 'c';
  f(vs, c);
  return 0;
}
