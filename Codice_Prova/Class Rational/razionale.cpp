#include <iostream>
#include <cassert>
#include "razionale.hpp"

#define NDEBUG

Razionale::Razionale(int num, int den) : num_{num}, den_{den} {
  assert(den_ != 0);
  normalize();
  test_invariant();
}

int Razionale::abs(int x) {
  return (x < 0 ? -x : x);
}

int Razionale::get_num() const {
  return num_;
}

int Razionale::get_den() const {
  return den_;
}

bool Razionale::test_invariant() const {
  if (den_ <= 0) return false;
  else if (num_ == 0) return (den_ == 1);
  else if (!(is_normalized(abs(num_), abs(den_)))) return false;
  return true;
}

bool Razionale::is_normalized(int x, int y) {
  int val = gcd(x, y);

  if (val == 0 || val == 1 || val == y) return true;
  return false;
}

void Razionale::normalize() {
  int x = gcd(num_, den_);
  if (x == 1) return;
  num_ /= x;
  den_ /= x;
  if (!(is_normalized(num_, den_))) normalize();
  else return;
}

Razionale Razionale::operator+() const{
  Razionale tmp {num_, den_};
  return tmp;
}

Razionale Razionale::operator-() const{
  int den = this->den_ * (-1);
  int num = this->num_ * (-1);
  Razionale tmp {num, den};
  return tmp;
}

Razionale& Razionale::operator++() {
  num_ += den_;
  normalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator--() {
  num_ -= den_;
  normalize();
  assert(this->test_invariant());
  return *this;
}

Razionale Razionale::operator++(int x) {
  Razionale tmp {*this};
  ++(*this);
  normalize();
  assert(test_invariant());
  return tmp;
}

Razionale Razionale::operator--(int x) {
  Razionale tmp {*this};
  --(*this);
  normalize();
  assert(test_invariant());
  return tmp;
}

Razionale& Razionale::operator+=(const Razionale& x) {
  assert(x.test_invariant());
  num_ = (den_ * x.num_) + (x.den_ * num_);
  den_ *= x.den_;
  normalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator-=(const Razionale& x) {
  assert(x.test_invariant());
  num_ = (den_ * x.num_) - (x.den_ * num_);
  den_ *= x.den_;
  normalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator*=(const Razionale& x) {
  assert(x.test_invariant());
  num_ *= x.num_;
  den_ *= x.den_;
  normalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator/=(const Razionale& x) {
  assert(x.test_invariant());
  num_ *= x.den_;
  den_ *= x.num_;
  normalize();
  assert(test_invariant());
  return *this;
}

bool operator==(const Razionale& x, const Razionale& y) {
  if (x.get_num() == y.get_num() && x.get_den() == y.get_den()) return true;
  return false;
}

bool operator!=(const Razionale& x, const Razionale& y) {
  return !(x == y);
}

bool operator<(const Razionale& x, const Razionale& y) {
  float a = x.get_num() / x.get_den();
  float b = y.get_num() / y.get_den();
  return (a < b);
}

bool operator>(const Razionale& x, const Razionale& y) {
  return !(x < y);
}

bool operator<=(const Razionale& x, const Razionale& y) {
  return (x == y || x < y);
}

bool operator>=(const Razionale& x, const Razionale& y) {
  return (x == y || x > y);
}

Razionale operator+(Razionale x, const Razionale& y) {
  x += y;
  return x;
}

Razionale operator-(Razionale x, const Razionale& y) {
  x -= y;
  return x;
}

Razionale operator*(Razionale x, const Razionale& y) {
  x *= y;
  return x;
}

Razionale operator/(Razionale x, const Razionale& y) {
  x /= y;
  return x;
}

std::ostream& Razionale::print(std::ostream& os) const{
  os << num_ << "/" << den_ << "\n";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Razionale& x) {
  x.print(os);
}

int Razionale::gcd(int x, int y) {
  x = abs(x);
  y = abs(y);
  //indefinito ma lo si fa per comodità
  if( x == 0 && y == 0) return 0;
  else if(x == 0 && y != 0) return abs(y);
  else if(!(x % 2)) {
    if(!(y % 2)) return 2 * gcd(x / 2, y / 2);
    else if(!(y % 1)) return gcd(x / 2, y);
  }

  else if(!(x % 1)) {
    if(!(y % 2)) return gcd(x , y / 2);
    else if(!(y % 1)) {
      if(x >= y) return gcd((x - y) / 2, y);
      else if(x < y) return gcd((y - x) / 2, x);
    }
  }
}

    
  
