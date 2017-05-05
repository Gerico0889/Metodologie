#include <iostream>
#include <cassert>
#include "razionale.hpp"

#define NDEBUG

Razionale::Razionale(int num, int den) : num_{num}, den_{den} {
  assert(den_ == 0);
  normalize();
  test_invariant();
}

int Razionale::abs(int x) {
  return (x < 0 ? -x : x);
}

bool Razionale::test_invariant() const {
  if (den_ <= 0) return false;
  else if (num_ == 0) return (den == 1);
  else if (!(is_normalized(abs(num_, den_)))) return false;
  return true;
}

bool Razionale::is_normalized(int x, int y) {
  int val = gdc(x, y);

  if (val == 0 || val == 1 || val == y) return true;
  return false;
}

Razionale Razionale::operator+() const{
  return *this;
}

Razionale Razionale::operator-() const{
  int den = this->den_ * (-1);
  int num = this->num_ * (-1);
  Razionale tmp {num, den};
  return tmp;
}

Razionale& Razionale::operator++() {
  num_ += den_;
  nomalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator--() {
  num_ -= den_;
  nomalize();
  assert(this->test_invariant());
  return *this;
}

Razionale Razionale::operator++(int x) {
  Razionale tmp {*this}
  ++(*this);
  nomalize();
  assert(test_invariant());
  return tmp;
}

Razionale Razionale::operator--(int x) {
  Razionale tmp = *this;
  --(*this);
  nomalize();
  assert(test_invariant());
  return tmp;
}

Razionale& Razionale::operator+=(const Razionale& r) {
  assert(r.test_invariant());
  num_ = (den_ * r.num_) + (y.den_ * num_);
  den_ *= y.den_;
  nomalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator-=(const Razionale& r) {
  assert(r.test_invariant());
  num_ = (den_ * r.num_) - (y.den_ * num_);
  den_ *= y.den_;
  nomalize();
  assert(test_invariant());
  return *this;
}

Razionale& Razionale::operator*=(const Razionale& r) {
  assert(r.test_invariant());
  num_ *= r.num_;
  den_ *= r.den_;
  nomalize();
  assert(test_invariant());
}

Razionale& Razionale::operator/=(const Razionale& r) {
  assert(r.test_invariant());
  num_ /= r.num_;
  den_ /= r.den_;
  nomalize();
  assert(test_invariant());
}

bool Razionale::operator==(const Razionale& r,const Razionale& y) {
  if (r.num_ == y.num_ && r.den_ == y.den_) return true;
  return false;
}

bool Razionale::operator!=(const Razionale& r,const Razionale& y) {
  return !(r == y);
}

bool Razionale::operator<(const Razionale& r,const Razionale& y) {
  float a = r.num_ / r.den_;
  float b = y.num_ / y.den_;
  return (a < b);
}

bool Razionale::operator>(const Razionale& r,const Razionale& y) {
  return !(r < y);
}

bool Razionale::operator<=(const Razionale& r,const Razionale& y) {
  return (r == y || r < y);
}

bool Razionale::operator>=(const Razionale& r,const Razionale& y) {
  return (r == y || r > y);
}

Razionale Razionale::operator+(Razionale r, const Razionale& y) {
  r += y;
  return r;
}

Razionale Razionale::operator-(Razionale r, const Razionale& y) {
  r -= y;
  return r;
}

Razionale Razionale::operator*(Razionale r, const Razionale& y) {
  r *= y;
  return r;
}

Razionale Razionale::operator/(Razionale r, const Razionale& y) {
  r /= y;
  return r;
}

std::ostream& print(ostream& os) {
  os << num_ << "/" << den_ << "\n";
  return os;
}

std::ostream& operator<<(ostream& os, const Razionale& r) {
  print(os);
}

int Razionale::gcd(int x, int y) {
  x = abs(x);
  y = abs(y);
  //indefinito ma lo si fa per comodità
  if( x == 0 && y == 0) return 0;
  else if(x == 0 && y != 0) return abs(y);
  else if(!(x % 2)) {
    if(!(y % 2)) return 2 * mcd(x / 2, y / 2);
    else if(!(y % 1)) return mcd(x / 2, y);
  }

  else if(!(x % 1)) {
    if(!(y % 2)) return mcd(x , y / 2);
    else if(!(y % 1)) {
      if(x >= y) return mcd((x - y) / 2, y);
      else if(x < y) return mcd((y - x) / 2, x);
    }
  }
}

    
  
