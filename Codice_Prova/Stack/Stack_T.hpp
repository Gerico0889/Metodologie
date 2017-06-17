#ifndef STACK_HH
#define STACK_HH

#include <cstddef> 

template<typename T>
class Stack
{
public:
  typedef std::size_t size_type;
  typedef T value_type;

  // Costruttore di default
  explicit Stack(size_type capacty_ = 16);

  // Costruttore di copia
  Stack(const Stack& other);

  // Assegnamento per copia
  Stack& operator=(const Stack& other);

  // Distruttore
  ~Stack();
  
  size_type size() const;  
  bool is_empty() const;

  void push(const value_type& val);

  value_type& top();
  const value_type& top() const;

  void pop();

  void swap(Stack& other);

  bool check_inv() const;
  
private:
  value_type* make_copy(value_type* src, size_type src_size, size_type dst_capacity); 

  size_type size_;
  size_type capacity_;
  value_type* elem_;
};

#include "Stack_T_inlines.cpp"

#endif //STACK_HH
