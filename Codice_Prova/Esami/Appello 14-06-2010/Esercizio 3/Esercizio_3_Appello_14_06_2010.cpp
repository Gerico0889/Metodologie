// expr.hpp

class Expr {
 public:
  virtual void print() const = 0;
  virtual double eval(const Var_Bindings& vb) const = 0;
  virtual ~Expr() { }
};

// var.hpp

class Var : public Expr {
 public:

  const str::string& name() const
  {
    // Robe
  }

  void print() const
  {
    print(name());
  }

  double eval(const Var_Bindings& vb) const
  {
    return vb[name()];
  }
};

// const.hpp

class Const : public Expr {
public:

  const double value() const
  {
    // Robe
  }

  void print() const
  {
    print(name());
  }

  double eval(const Var_Bindings& vb) const
  {
    return value();
  }
};

// add.hpp

class Add : public Expr {
public:

  const Expr& arg1()
  {
    // Ritorna arg1
  }

  const Expr& arg2()
  {
    // Ritorna arg2
  }
  
  void print() const
  {
    print(arg1());
    print(" + ");
    print(arg2());
  }

  double eval(const Var_Bindings& vb) const
  {
    return arg1().eval(vb) + arg2().eval(vb);
  }
};

// sub.hpp

class Sub : public Expr {
public:

  const Expr& arg1()
  {
    // Ritorna arg1
  }

  const Expr& arg2()
  {
    // Ritorna arg2
  }
  
  void print() const
  {
    print(arg1());
    print(" - ");
    print(arg2());
  }

  double eval(const Var_Bindings& vb) const
  {
    return arg1().eval(vb) - arg2().eval(vb);
  }
};
