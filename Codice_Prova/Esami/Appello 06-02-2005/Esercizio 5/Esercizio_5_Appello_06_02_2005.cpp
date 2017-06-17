template <typename Iter1, typename Iter2, typename BinPred>
Iter1
find_firt_of(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, BinPred comp) {
  for(Iter1 i = first1; i != last1; ++i) {
    for(Iter2 j = first2; j != last2; ++j) {
      if (comp(*i, *j))
	return i;
    }
  }
  return last1;
}

// Quali sono le più ampie categorie di iteratori utilizzabili per ogniuna delle due sequenze di iteratori
// Con ampio intendo che accetto più tipi di iteratori possibili quindi implemento la funzione
// con iteratori molto deboli così da poter usare quelli più powerful
// Per la prima sequenza è suffuciente l'InputIterator mentre per la seconda servono i ForwardIterator
// perché devo scorrere la sequenza più volte quindi l'InputIterator non va bene perché perdo gli elementi letti
