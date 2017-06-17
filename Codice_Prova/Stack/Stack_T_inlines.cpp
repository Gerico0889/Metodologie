#ifndef STACK_T
#define STACK_T
#include "Stack_T.hpp"
#include <iostream>
#include <utility>
#include <cstddef>
#include <cassert>

//#define NDEBUG

template<typename T>
Stack<T>::Stack(size_type capacity)
  : size_{0},
    capacity_{capacity == 0 ? 16 : capacity},
    elem_{new value_type[capacity == 0 ? 16 : capacity]}
{
  std::cout << "mannaggia a chi t'èmmuort" << '\n';
  assert(check_inv());
}

template<typename T>
Stack<T>::Stack(const Stack& other) :
  size_{other.size_},
  capacity_{other.size_ == 0 ? 1 : other.size_},
  elem_{make_copy(other.elem_, other.size_,(other.size_ * 2))}
{
  assert(check_inv());
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
  assert(other.check_inv());
  Stack tmp(other);
  this->swap(tmp);
  assert(this->check_inv());
  return *this;
}

template <typename T>
Stack<T>::~Stack(){
  delete[] elem_;
}

template<typename T>
typename Stack<T>::value_type*
Stack<T>::make_copy(value_type* src,
		    size_type src_size,
		    size_type dst_capacity)
{
  assert(src_size <= dst_capacity);

  value_type* temp = new value_type[dst_capacity];

  try{
    for(size_type i = 0; i != src_size; ++i){
      temp[i] = src[i];
    }
  }
  catch(...){
    delete [] temp;
    throw;
  }return temp;
  
}

template <typename T>
void Stack<T>::push(const value_type& val){
  elem_[size_] = val;
  ++size_;
  assert(this->check_inv());
}

template <typename T>
void Stack<T>::pop(){
  --size_;
}

template <typename T>
typename Stack<T>::value_type& Stack<T>::top(){
  assert(this->check_inv());
  return elem_[size_ - 1];
}

template <typename T>
const typename Stack<T>::value_type& Stack<T>::top() const{
  assert(this->check_inv());
  return elem_[size_ - 1];
}

template <typename T>
void Stack<T>::swap(Stack<T>& other){
  std::swap(capacity_, other.capacity_);
  std::swap(size_, other.size_);
  std::swap(elem_, other.elem_);
}

template <typename T>
typename Stack<T>::size_type Stack<T>::size() const{
  return size_;
}

template <typename T>
bool Stack<T>::is_empty() const{
  return size_ == 0;
}
  
template <typename T>
bool Stack<T>::check_inv() const{
  if(capacity_ == 0){
  #ifndef NDEBUG
    std::cerr << "Stack dichiarato con capacita' nulla!\n";
  #endif
    return false;
  }
  if(capacity_ < size_){
  #ifndef NDEBUG
    std::cerr << "Capacita' dello stack minore degli elementi\n";
  #endif
    return false;
  }
  if(elem_ == nullptr){
  #ifndef NDEBUG
    std::cerr << "Non e' stato allocato niente\n";
  #endif
    return false;
  }
  
  return true;
}

#endif //STACK_HH
