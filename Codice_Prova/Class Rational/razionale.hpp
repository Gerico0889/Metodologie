#ifndef RAZIONALE_HH
#define RAZIONALE_HH
#include <iostream>

class Razionale {
public:
  // Costruttore di default
  /*constexpr*/ Razionale(int num = 0, int den = 1);

  // Rule of five, costruttore e assegnamento per copia e spostamento
  // vanno bene anche quelli di default
  /*constexpr*/ Razionale(const Razionale&) = default;
  Razionale(Razionale&&) = default;
  Razionale& operator=(const Razionale&) = default;
  Razionale& operator=(Razionale&&) = default;

  // Operatori aritmetici unari
  Razionale operator+() const;
  Razionale operator-() const;

  // Incremento e decremento prefissi
  Razionale& operator++();
  Razionale& operator--();

  // Incremento e decremento postfisso
  Razionale operator++(int x = 0);
  Razionale operator--(int x = 0);

  // Operatori binari con assegnamento
  Razionale& operator+=(const Razionale& r);
  Razionale& operator-=(const Razionale& r);
  Razionale& operator*=(const Razionale& r);
  Razionale& operator/=(const Razionale& r);

  std::ostream& print(std::ostream& os) const;

  int get_num() const;
  int get_den() const;
  
  ~Razionale(){};
  
private:
  int num_;
  int den_;

  // Calculate GCD between two values
  static int gcd(int x, int y);

  // Calculate absolute value of x
  static int abs(int x);

  // Tests class invariant
  // den =! 0
  // number must be normalized
  bool test_invariant() const;

  // normalize the rational number
  // normalized when gdc == 1
  void normalize();

  // checks if x/y are normalized
  static bool is_normalized(int x, int y);
};

// Funzione di stampa
std::ostream& operator<<(std::ostream& os, const Razionale& r);

// Operatori di confronto
bool operator==(const Razionale& r, const Razionale& y);
bool operator!=(const Razionale& r, const Razionale& y);
bool operator<(const Razionale& r, const Razionale& y);
bool operator>(const Razionale& r, const Razionale& y);
bool operator<=(const Razionale& r, const Razionale& y);
bool operator>=(const Razionale& r, const Razionale& y);


// Operatori aritmetici binari
Razionale operator+(Razionale r, const Razionale& y);
Razionale operator-(Razionale r, const Razionale& y);
Razionale operator*(Razionale r, const Razionale& y);
Razionale operator/(Razionale r, const Razionale& y);

#endif //RAZIONALE_HH
