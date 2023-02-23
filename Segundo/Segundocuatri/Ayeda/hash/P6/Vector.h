#ifndef VECTOR
#define VECTOR
template<class Key>
class Vector {
  public:
    Vector() //Inicializa el objeto vacío
    bool Search(Key& X) const; /*método público que retorna el valor boolean true si el valor X del tipo Clave está guardado en el 
                                vector . En otro caso retorna el valor false.*/
    bool Insert(const Key& X); /*retorna el valor booleano true si puede
                                insertar el valor X del tipo Clave en el vector. En otro caso, si el valor ya está guardado en la
                                tabla, se retorna el valor booleano false.*/
    bool IsFull() const;  /*retorna el valor booleano true si el vector está lleno,
                          esto es, si ya hay nSinonimos claves almacenadas. En otro caso, si hay huecos libres en el
                          vector retorna el valor booleano false.*/
  private:
    int nSinonims;
    
};
#endif