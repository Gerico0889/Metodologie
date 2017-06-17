struct MoreThanTen
{
  MoreThanThen();
  bool operator()(const std::string& s)
  {
    return (s.size() > 10);
  }
}

template <typename Iter, typename Pred>
int
count_if(Iter first, Iter last, Pred p)
{
  int count = 0;
  for( ; first != last; ++first)
    {
      if(p(*first))
        ++count;
    }
  return count;
}

int main()
{
  std::vector<std::string> vs {"ciaooooooo", "peppe", "dadawdada", "dfgadgassfasfs", "asas"};
  MoreThanTen t();
  std::cout << count_if(vs.begin(), vs.end(), t);
  return 0;
}
