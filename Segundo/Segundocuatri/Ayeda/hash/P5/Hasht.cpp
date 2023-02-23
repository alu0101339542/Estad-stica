#include "Hasht.hpp"
template <class Key>
HashTable<Key>::HashTable(int table_sz, DispersionFunction<Key>* fd_) {
  fd = fd_;
  nData = table_sz;
  vData.resize(nData);
}

template <class Key>
 bool HashTable<Key>::Search(const Key& X) const { //creo que deberia buscar un metodo de busqueda mas eficiente
    for(unsigned int i = 0; i < nData; i++){
      if(vData.at(i) == X)
		    return true;
	  }
    return false;
}

template <class Key>
 bool HashTable<Key>::Insert(const Key& X) {
   if(Search(X) == true) {
     return false;
   }
   else {
     vData[fd(X)] = X; //Metemos en la tabla en el índice devuelto por la func de disp la clave
     return true;
   }
 }