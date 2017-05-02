# Iteratori

Di solito i container forniscono qualche iteratore, come il ``begin()`` e ``end()`` che costituiscono rispettivamente l'inizio del container e un elemento dopo la fine del container creando un insieme del tipo [begin; end).

Oltre ai container anche molti algoritmi ritornano iteratori. Per esempio la funzione ``find()`` che cerca un elemento all'interno di un range e, se lo trova, ritorna l'iteratore corrispondente a quell'elemento.

``` C++
bool has_c(const string& s, char c)
{
  auto p = find(s.begin(),s.end(),c);
  if (p!=s.end())
    return true;
  else
    return false;
}
```

Questa funzione ritorna l'iteratore ``end()`` se non è stata trovata alcuna occorrenza del char c nella stringa s. Viene utilizzato ``end()`` perché è un iteratore che va di un posto oltre il range del container e che implicitamente dice che non è stata trovata alcuna occorrenza esatta.

Gli iteratori e gli algoritmi standard possono essere utilizzati in tutti i tipi di contaniner che permettono la comparazione (anche se diversi l'uno dall'altro), possiamo infatti generalizzare un iteratore in questo modo:

``` C++
template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v)
{
  vector<typename C::iterator> res;
  for (auto p = c.begin(); p!=c.end(); ++p)
    if (∗p==v)
      res.push_back(p);
  return res;
}
// Funzione templatica find_all, ho bisogno di dichiarare C come typename per far capire al compilatore
// che è un tipo e non un valore
```

>Gli iteratori sono usati per separare gli algoritmi dai container. Un algoritmo lavora sui suoi dati attraverso gli iteratori ma non sa **niente** riguardo al container che contiene i dati. Conseguentemente il container non sa nulla sugli algoritmi che lavorano sui suoi elementi, tutto ciò che fa è fornire degli iteratori (begin() e end()) su richiesta. La separazione del data storage dagli algoritmi permette di avere un software più generale e flessibile.

## Tipi di Iteratori

Ogni particolare iteratore è un oggetto di qualche tipo. Deve infatti contenere informazioni che gli permettono di svolgere le operazioni di un particolare tipo di container.

Per esempio un possibile iteratore di un vector potrebbe essere un semplice puntatore, giusto perché è conveniente utilizzare puntatori per riferirci agli elementi del vector, alternativamente l'iteratore del vector può essere implementato anche con un offset, ciò ci permette di utilizzare il range checking

È importante rendere noto che la semantica e il nome degli operatori sono comuni a **tutti** i tipi di iteratori (++ porta a un iteratore che si riferisce al prossimo elemento, * porta al valore al quale si riferisce l'iteratore). Difatti **OGNI** oggetto che soddisfa queste regole è un iteratore, l'iteratore è solo un *concetto*. Inoltre, l'utente ha raramente bisogno di sapere il tipo dell'iteratore in quanto tutti i container della STL lo forniscono e lo mettono a disposizione sotto il nome di ``iterator`` e ``const_iterator``

## Predicati negli iteratori

Molti algoritmi hanno già di loro l'azione che dovranno compiere per ogni elemento di una sequenza. Se invece vogliamo descrivere noi quell'azione e aggiungerla come parametro all'algoritmo possiamo farlo attraverso i **predicati**, vogliamo quindi cercare un elemento che soddisfa una particolare condizione. Il parametro del predicato deve essere un oggetto che soddisfa le caratteristiche di una funzione (quindi non per forza una funzione vera e propria):

* Puntatori a funzioni.
* Lambda expression (qualcosa che assomiglia a una funzione ma che non è una funzione, si scrivono in una riga sola).
* Oggetti funzione (cosa sono?). Istanze di tipo struct o class che possono comportarsi come se fossero delle funzioni.

**Esempio oggetto funzione**

``` C++
struct Lungo_Sei {
  // Per poter essere usato come funzione, devo ridefinire l'op di chiamata a funzione
  bool operator()(const std::string& v) const {
    retur s.size() == 6;
  }
};
```
**Esempio Lambda Expression**

``auto p = find_if(m.begin(), m.end(), [](const pair<string,int>& r) { return r.second>42; });``

**Un predicato non deve mai modificare l'oggetto al quale è applicato**

