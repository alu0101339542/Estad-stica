
#include <vector>
using namespace std;

template<class Key>
class List {
  public:
    List();
    bool Search(Key& X) const;
    bool Insert(const Key& X);
  private:
    vector<Key> liststruct;
};

template<class Key>
List<Key>::List() {
  //No hace nada
}

template<class Key>
bool List<Key>::Search(Key& X) const {
  for(int j = 0; j < liststruct.size(); j++) {
      if(liststruct.at(j) == X)
		    return true;
	  }
    return false;
}

template<class Key>
bool List<Key>::Insert(const Key& X) {
  if(Search(X) == true) {
    return false;
   }
  else {
    liststruct.push_back(X); 
    return true;
  }
}
