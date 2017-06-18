#include <iostream>
#include <list>
#include <iterator>

template <typename T, typename U>
struct Avg
{
  double operator()(const T& t, const U& u)
  {
    return ((t + u) / 2.0);
  }
};


template <typename IterIn1, typename IterIn2, typename Ostream, typename BinaryPred>
Ostream
transform(IterIn1 first1, IterIn1 last1, IterIn2 first2, Ostream out, BinaryPred pred)
{
  for( ; first1 != last1; ++first1, ++first2)
    {
      out = pred(*first1, *first2);
      ++out;
    }
  return out;
}

int main()
{
  std::list<int> l1 {2, 5, 6, 7, 8, 4};
  std::list<int> l2 {4, 12, 32, 43, 12, 14};
  
  std::ostream_iterator<double> out(std::cout, " ");

  Avg<int,int> avg;

  transform(l1.begin(), l1.end(), l2.begin(), out, avg);

  return 0;
}
