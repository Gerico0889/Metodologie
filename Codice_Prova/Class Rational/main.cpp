#include <iostream>
#include "razionale.hpp"

bool test1() {
  Razionale r1;
  Razionale r2;
  std::cout << r1 << " " << r2;
  return (r1 != r2);
}

bool test2() {
  Razionale r1 {18};
  Razionale r2 {25};
  std::cout << r1 << " " << r2;
  return (r2 >= r1);
}

bool test3() {
  Razionale r1 {4, 2};
  Razionale r2 {++r1};
  std::cout << r1 << " " << r2;
  return (r1 == r2);
}

int main() {
  bool t1 = test1();
  bool t2 = test2();
  bool t3 = test3();
  std::cout << t3 << " " << t2 << " " << t1 << "\n";
  return 0;
}
