#ifndef HASHTABLE
#define HASHTABLE

#include "Dispfunc.hpp"
#include <vector>

template<class Key>
class HashTable {
  public:
    HashTable(int table_sz, DispersionFunction<Key>* fd_);
     bool Search(const Key& X) const; /*retorna el valor booleano true si puede
                              insertar el valor X del tipo Clave en la tabla hash. En otro caso, si el valor ya está guardado en la
                              tabla, se retorna el valor booleano false.*/
    bool Insert(const Key& X);
  private:
    unsigned int nData; //contiene el tamaño de la tabla. Se especifica en el constructor
    vector<Key> vData; //es un array de nDatos posiciones en cada una de las cuales habrá un contenedor de claves.
    DispersionFunction<Key>* fd;  /*Atributo privado fd, es un puntero a la clase base FuncionDispersion<Clave> que apunta
                                  a un objeto instanciado en tiempo de ejecución para alguna de 
                                  las clases derivadas de la clase base*/
   
};

template <class Key>
HashTable<Key>::HashTable(int table_sz, DispersionFunction<Key>* fd_) {
  fd = fd_;
  nData = table_sz;
  vData.resize(nData);
}

template <class Key>
 bool HashTable<Key>::Search(const Key& X) const { //creo que deberia buscar un metodo de busqueda mas eficiente
    for(int i = 0; i < nData; i++){
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
     vData[(*fd)(X)] = X; //Metemos en la tabla en el índice devuelto por la func de disp la clave
     return true;
   }
 }
#endif