// Prueba de Vector
// Ejemplo de sobrecarga de operadores, plantilla de clases, 
// plantilla de funciones amigas.

#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include "Vector.h"
using namespace std;

template<class T> 
void testVector(int dimension, int rng) {

  Vector<T> A(dimension), B;                              // Constructor por defecto
  T Escalar = (T) (rand()%(rng*100))/100;

  for(int i=0; i<dimension; i++) {
      A[i] = (T) (rand()%(rng*100))/100;                  // Operador indexacion
    }

  B = A;                                                  // Operador de asignacion
  Vector<T> C(-A);                                        // Constructor de copia; Opuesto

  cout << "A: " << A << endl;                             // Insercion en flujo
  cout << "B: " << B << endl;
  cout << "-A: " << C << endl;
  cout << "A+B: " << A+B << endl;                         // Suma
  cout << "A-B: " << A-B << endl;                         // Resta
  cout << "A*B: " << A*B << endl;                         // Producto interno
  cout << "A*" << Escalar << ": " << A*Escalar << endl;   // Producto vector por escalar
  cout << Escalar << "*A: " << Escalar*A << endl;         // Producto vector por escalar

                                                          // Comparaciones
  cout << "¿A == B? " << (A == B) << endl;
  cout << "¿A == -A? " << (A == -A) << endl;
  cout << "¿A != -A? " << (A != -A) << endl;
  cout << "¿A != B? " << (A != B) << endl;
}

int main(int argc, char** argv)
{
  int size, rng;

  size = (argc > 1) ? atoi(argv[1]) : 5;
  rng = (argc > 2) ? atoi(argv[2]) : 10;

  cout << endl << "Test Vector<int>" << endl;
  testVector<int>(size, rng);

  cout << endl << "Test Vector<double>" << endl;
  testVector<float>(size, rng);

  return 0;
}

