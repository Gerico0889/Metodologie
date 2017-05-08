#include <iostream>
#include <array>
#include <vector>
#include <string>

template <typename Iter>
void
print_all (Iter first, Iter last) {
  for ( ; first != last; ++first) {
    std::cout << *first << ' ';
  }
  std::cout << '\n';
  return;
}


// Funziona che cerca un elemento nel container
// e ritorna l'iteratore corrispondente
template <typename Iter, typename Value>
Iter
find (Iter begin, Iter end, const Value& x) {
  for ( ; begin != end; ++begin) {
    if (*begin == x) return begin;
  }
  return end;
}

template <typename Iter>
Iter
max_elem (Iter begin, Iter end) {
  auto res = begin;
  ++begin;
  for ( ; begin != end; ++begin) {
    if (*res < *begin) res = begin;
  }
  return res;
}

template <typename Iter>
Iter
min_elem (Iter begin, Iter end) {
  auto res = begin;
  ++begin;
  for ( ; begin != end; ++begin) {
    if (*begin < *res) res = begin;
  }
  return res;
}


// Funzione oggetto, funge da predicato
template <typename T>
struct
less_than {

  less_than(const T& a) : ma_{a} {  }
  bool operator()(const T& a) const {
    return a < ma_;
  }
  
private:
  const T ma_;
};

// Funzione find che usa un predicato
template <typename Iter, typename Predicate>
Iter
find_if (Iter begin, Iter end, Predicate pred) {
  for ( ; begin != end; ++begin) {
    if (pred(*begin)) return begin;
  }
  return end;
}


int main() {
  std::vector<std::string> vs {"Banana alla mela", "Paypaia", "Mouse"};
  std::array<int, 10> ai {2, 4, 6, 3, 5, 196, 87, 54, 32, 0};
  std::string s {"L'altroieri ero al cinema a guardare un film, ha fatto cagare"};

  // print_all<>(vs.begin(), vs.end());
  // print_all<>(ai.begin(), ai.end());
  // print_all<>(s.begin() + 2, s.end());

  std::cout << find(ai.begin(), ai.end(), 9) << '\n';
  std::cout << (*max_elem(ai.begin(), ai.end())) << '\n';
  std::cout << (*min_elem(ai.begin(), ai.end())) << '\n';

  const less_than<int> lti{5};

  std::cout << (*find_if(ai.begin(), ai.end(), lti)) << '\n';

  return 0;
}
