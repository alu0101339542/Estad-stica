
#include <vector>

using namespace std;

template<class Clave>
class List {
  public:
    List();
    bool Search(Clave& X) const;
    bool Insert(const Clave& X);
  private:
    vector<Clave> liststruct;
};

template<class Clave>
List<Clave>::List() {
  //No hace nada
}

template<class Clave>
bool List<Clave>::Search(Clave& X) const {
  for(int j = 0; j < liststruct.size(); j++) {
      if(liststruct.at(j) == X)
		    return true;
	  }
    return false;
}

template<class Clave>
bool List<Clave>::Insert(const Clave& X) {
  if(Search(X) == true) {
    return false;
   }
  else {
    liststruct.push_back(X); 
    return true;
  }
}

