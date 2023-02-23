// Vector.h: Ejemplo de sobrecarga de operadores, plantilla de clases, 
// plantilla de funciones amigas.
//

#include <iostream>
using namespace std;

typedef unsigned int Index_t;          // Tipo del indice

//
// Declaraciones anticipadas de las plantillas para sobrecargar operadores I/O
//
template<class Base_t> class Vector;
template<class Base_t> Vector<Base_t> operator*(const Base_t& a, const Vector<Base_t>& v);
template<class Base_t> ostream& operator<<(ostream& os, const Vector<Base_t>& v);
template<class Base_t> istream& operator>>(istream& is, Vector<Base_t>& v);

//
// Plantilla
//
template<class Base_t>
class Vector{
  private:
    Base_t* base_;                            // Array que contiene los elementos
    Index_t dimension_;                       // Número de elementos

  private:
    void build(void);                         // Reserva Memoria
    void remove(void);                        // Libera Memoria

  public:
    Vector(const Index_t size=0);             // Constructor por defecto
    Vector(const Vector& v);                  // Constructor de copia
    ~Vector(void);                            // Destructor

    Vector& operator=(const Vector& v);       // Operador de asignacion

    Index_t dimension(void) const {return dimension_;}

                                              // Operador de indexacion
    Base_t& operator[](const Index_t i);      // Variables
    Base_t operator[](const Index_t i) const; // Constantes

                                             // Operadores de comparacion
    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;

    // Funcion amiga para sobrecargar el producto escalar por vector
    friend Vector<Base_t> operator* <>(const Base_t& a, const Vector<Base_t>& v);

                                             // Operadores aritmeticos
    Vector operator-(void) const;            // Vector opuesto
    Vector operator+(const Vector& v) const; // Suma
    Vector operator-(const Vector& v) const; // Resta
    Base_t operator*(const Vector& v) const; // Producto escalar
    Vector operator*(const Base_t& a) const; // Producto vector por un escalar

    // Funciones amigas para sobrecargar operadores de E/S
    friend ostream& operator<< <>(ostream& os, const Vector<Base_t>& v);
    friend istream& operator>> <>(istream& is, Vector<Base_t>& v);

};

//
// Metodos privados para manejo de memoria dinamica
//
template<class Base_t>
void Vector<Base_t>::build(void) {
  if(dimension_ > 0) 
    base_ = new Base_t[dimension_];
  else if(dimension_ == 0)
    base_ = 0;
}

template<class Base_t>
void Vector<Base_t>::remove(void) {
  if (base_ != 0)
    delete[] base_;

  base_= 0;
  dimension_ = 0;
}

//
// Constructor
//
template<class Base_t>
Vector<Base_t>::Vector(const Index_t size): 
  dimension_(size), base_(0) {
  build();
}

//
// Constructor de copia
//
template<class Base_t>
Vector<Base_t>::Vector(const Vector<Base_t>& v) {
  dimension_ = v.dimension();
  build();

  for(Index_t i=0; i < dimension(); i++)
    (*this)[i] = v[i];
}

//
// Destructor
//
template<class Base_t>
Vector<Base_t>::~Vector(void) {
  remove();
}

//
// Operador de asignacion
//
template<class Base_t>
Vector<Base_t>& Vector<Base_t>::operator=(const Vector<Base_t>& v) {
  remove();
  dimension_ = v.dimension();
  build();

  for(Index_t i=0; i<dimension(); i++)
    (*this)[i] = v[i];

  return *this;
}

//
// Operadores de indexacion
//
template<class Base_t>
Base_t& Vector<Base_t>::operator[](const Index_t i) {
  if((i>=0) && (i<dimension()))
    return base_[i];
}

template<class Base_t>
Base_t Vector<Base_t>::operator[](const Index_t i) const {
  if((i>=0) && (i<dimension()))
    return base_[i];
}

//
// Operadores de comparacion 
//
template<class Base_t>
bool Vector<Base_t>::operator==(const Vector<Base_t>& v) const {
  if(dimension() != v.dimension())
    return false;

  bool igual = true;
  Index_t i = 0;
  while((i < dimension()) && igual) {
    if((*this)[i] != v[i])
      igual = false;
    i++;
  }
  return igual;
}

template<class Base_t>
bool Vector<Base_t>::operator!=(const Vector<Base_t>& v) const {
  return !(*this == v);
}

//
// Operador aritmetico: opuesto (menos unario)
//
template<class Base_t>
Vector<Base_t> Vector<Base_t>::operator-(void) const {
  Vector<Base_t> v(dimension());

  for(Index_t i=0; i<dimension(); i++)
    v[i] = -(*this)[i]; 
  return v;
}

//
// Operador aritmetico: suma
//
template<class Base_t>
Vector<Base_t> Vector<Base_t>::operator+(const Vector<Base_t>& v) const {
  Vector<Base_t> w(dimension());

  if(dimension() == v.dimension())
    for(Index_t i = 0; i < dimension(); i++)
      w[i] = (*this)[i] + v[i];

  return w;
}

//
// Operador aritmetico: resta (menos binario)
//
template<class Base_t>
Vector<Base_t> Vector<Base_t>::operator-(const Vector<Base_t>& v) const {
  return (*this)+(-v);
}

//
// Operador aritmetico: producto escalar o producto interno
//
template<class Base_t>
Base_t Vector<Base_t>::operator*(const Vector<Base_t>& v) const {
  Base_t resultado = 0;
 
  if(dimension() == v.dimension())
    for(Index_t i = 0; i < dimension(); i++)
      resultado += (*this)[i] * v[i];

  return resultado;
}

//
// Operador aritmetico: producto vector por escalar
//
template<class Base_t>
Vector<Base_t> Vector<Base_t>::operator*(const Base_t& a) const {
  Vector<Base_t> w(dimension());

  for(Index_t i = 0; i < dimension(); i++)
    w[i] = (*this)[i] * a;

  return w;
}

//
// Operador aritmetico: producto escalar por vector (funcion amiga)
//
template<class Base_t>
Vector<Base_t> operator*(const Base_t& a, const Vector<Base_t>& v) {
  return v * a;
}

//
// Operador de insercion en flujo (funcion amiga)
//
template<class Base_t>
ostream& operator<<(ostream& os, const Vector<Base_t>& v) {
  for(Index_t i=0; i<v.dimension(); i++)
    os << v[i] << " ";
  return os;
}

//
// Operador de extraccion en flujo (funcion amiga)
//
template<class Base_t>
istream& operator>>(istream& is, Vector<Base_t>& v) {
  v.remove();
  is >> v.dimension_;
  v.build();

  for(Index_t i=0; i<v.dimension(); i++)
    is >> v[i];

  return is;
}

