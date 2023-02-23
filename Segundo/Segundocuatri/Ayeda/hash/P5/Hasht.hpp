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
#endif