// Fornire il prototipo e l’implementazione della funzione templatica average, che prende come unico
// argomento un (non meglio identificato) contenitore sequenziale della libreria standard e restituisce
// come risultato la media aritmetica degli elementi contenuti. Elencare i requisiti imposti da tale
// funzione sul tipo degli elementi del contenitore.
// Riscrivere la funzione average facendo in modo che prenda come argomenti due iteratori che
// identificano la sequenza in ingresso. Per quale motivo questa seconda versione è più generale della
// precedente ?


template <typename Cont>
typename Cont::value_type
average(Cont cont)
{
  typedef typename Cont::value_type value_type;

  auto begin = cunt.begin();
  auto end = cunt.end();

  value_type media {};

  if (cont.size() == 0)
    return media;

  for( ; begin != end; ++begin)
    media += *begin;

  return  media /= cont.size();
}

// La funzione può essere istanziata solo su contenitori numerici
// (int, bool, char, float, double, long e tutte le controparti signed e unsigned)

template <typename Iter>
typename Iter::value_type
average (Iter begin, Iter end)
{
  typedef typename Iter::value_type value_type;

  value_type media {};

  auto difference = std::difference(begin, end);

  if(difference == 0)
    return media;

  for( ; begin != end; ++begin)
    media += *begin;

  return  media /= difference;
}
