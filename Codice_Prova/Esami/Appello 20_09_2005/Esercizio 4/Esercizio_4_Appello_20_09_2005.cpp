class BSoft {
private:
  // ...
public:
  void s1();
  void s2(const BSoft& y, int n);
  void s3(int n);
  // ...
};

/////////////////////////////////////////////////////////////////////

#include "Biblio.hpp"

void f(Biblio& x, const Biblio& y, int n) {
  // ...
  if (n > 0)
    x.s3(n);
  else {
    x.s1();
    n = 5;
  }
  // ...
  x.s2(y, n);
  // ...
}

//////////////////////////////////////////////////////////////////////

class BWare {
private:
  // ...
public:
  void w1();
  void w2_1(const BWare& y);
  void w2_2(int n);
  void w3(int n);
  // ... ecc.
};

//////////////////////////////////////////////////////////////////////

class Biblio {
private:
  // ...
public:
  virtual void s1() = 0;
  virtual void s2(const Biblio& y, int n) = 0;
  virtual void s3(int n) = 0;
  virtual ~Biblio() { }
};

/////////////////////////////////////////////////////////////////////

#include "Biblio.hpp"
#include "BSoft.hpp"

class BSoft_Adapter : public Biblio {
private:
  BSoft& bs;
public:
  void s1()
  {
    bs.s1();
  }
  void s2(const Biblio& y, int n)
  {
    const BSoft_Adapter& bsy = dynamic_cast<const BSoft_Adapter&>(y);
    bs.s2(bsy.bs, n);
  }
  void s3(int n)
  {
    bs.s3(n);
  }
};

/////////////////////////////////////////////////////////////////////

#include "Biblio.hpp"
#include "BWare.hpp"

classe BWare_Adapter : public Biblio {
 private:
  BWare& bw;
 public:
  void s1()
  {
    bw.w1();
  }
  void s2(const Biblio& y, int n)
  {
    const BWare_Adapter& bwy = dynamic_cast<const BWare_Adapter&>(y);
    bw.w2_1(bwy.bw);
    bw.w2_2(n);
  }
  void s3(int n)
  {
    bw.w3(n);
  }
};
