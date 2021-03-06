#include "Stack_T.hpp"
#include <iostream>
#include <string>
#include <cassert>

//#define NDEBUG


void test1(){
  Stack<std::string> s;

  s.push("ciao");
  s.push("uaglio");

  Stack<std::string> s2{s};

  assert(s2.size() == s.size());

  s2 = Stack<std::string>();

  assert(s2.is_empty());
  
  std::cout << "Test 1 OK!\n";				  
}

void test2(){
  Stack<std::string> s{4};

  for(int i = 0; i < 4; ++i){
    s.push("aaaa");
  }

  std::string& t = s.top();
  std::cout << t << '\n';
  s.pop();
  std::cout << t << '\n';
  s.push("peppe");
  std::cout << t << '\n';

  assert(s.size() == 4);

  std::cout << "Test 2 OK!\n";
}

int main()
{
  test1();
  test2();
}
