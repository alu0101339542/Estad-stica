#include <iostream>

using namespace std;

template<class Clave>
class nodoB {
  public:
    // Constructor:
    nodoB(const Clave dat, nodoB *izq=NULL,
          nodoB *der=NULL) :
          dato(dat), izdo(izq), dcho(der) {}
    // Miembros:
    Clave dato; // dato: Cualquier tipo de 
    nodoB *izdo; // valor a almacenar
    nodoB *dcho;
  };

  template<class Clave>
  class ArbolB {
  private:
  nodoB<Clave> *raiz = NULL;
  public:
  //Insertar
  void InsertaEquil(const Clave& dato);
  void InsertaEquilRama(const Clave dato, nodoB<Clave>* nodo);
  int Tam();
  int TamRama(nodoB<Clave>* nodo);
  bool Buscar(Clave data);
  bool BuscarRama(nodoB<Clave>* nodo, Clave data);
  void ImprimirArbol();
  void ImprimirRama(nodoB<Clave>* nodo, int niv);
};
