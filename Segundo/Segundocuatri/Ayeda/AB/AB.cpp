#include "ABv0.hpp"

using namespace std;


template<class Clave>
void ArbolB<Clave>::InsertaEquil(const Clave& dato) {
  if (raiz == NULL)
    raiz = new nodoB<Clave>(dato, NULL, NULL);
  else InsertaEquilRama(dato, raiz);
}
template<class Clave>
void ArbolB<Clave>::InsertaEquilRama(const Clave dato, nodoB<Clave>* nodo) {
  if (TamRama(nodo->izdo) <= TamRama(nodo->dcho)) {
    if (nodo->izdo != NULL)
      InsertaEquilRama(dato, nodo->izdo);
    else
      nodo->izdo = new nodoB<Clave>(dato, NULL, NULL);
  }
  else {
    if (nodo->dcho != NULL)
      InsertaEquilRama(dato, nodo->dcho);
    else
      nodo->dcho = new nodoB<Clave>(dato, NULL, NULL);
  }
}

template<class Clave>
int ArbolB<Clave>::Tam() { return TamRama(raiz); }

template<class Clave>
int ArbolB<Clave>::TamRama(nodoB<Clave>* nodo) {
  //cout << nodo << endl;
  if (nodo == NULL)return 0;
  return (1 + TamRama(nodo->izdo) + TamRama(nodo->dcho) ) ;
}
template<class Clave>
bool ArbolB<Clave>::Buscar(Clave dato) { 
  return BuscarRama(raiz, dato); 
}
template<class Clave>
bool ArbolB<Clave>::BuscarRama(nodoB<Clave>* nodo, Clave data) {
if (nodo == NULL)
return false ;
if (data == nodo->dato)
  return true ;
if (data < nodo->dato )
  return BuscarRama(nodo->izdo, data);
else
  return BuscarRama(nodo->dcho, data);
} 
template<class Clave>
void ArbolB<Clave>::ImprimirArbol() {
  int niv = 1;
  nodoB<Clave>* aux = NULL;
  cout << "Nivel 0: ";
  if (raiz == NULL) 
    cout << "[.]" << endl;
  else 
    cout << raiz ->dato;
  aux = raiz;
  cout << endl << "Nivel " << niv++ << ": ";
  ImprimirRama(/***/aux, niv);
  cout << endl;
  ImprimirRama(aux->izdo, niv);
  ImprimirRama(aux->dcho, niv);
}

template<class Clave>
void ArbolB<Clave>::ImprimirRama(nodoB<Clave>* nodo, int niv) {
  nodoB<Clave>* aux2 = NULL;
  if (nodo != NULL) {
    if (nodo->izdo == NULL) 
      cout << "[.] ";
    else {
      aux2 = nodo->izdo;
      cout << "[" << aux2->dato << "]";
    }
    if (nodo ->dcho == NULL)
      cout << "[.]";
    else {
      aux2 = nodo->dcho;
      cout << "[" << aux2->dato << "]";
    }
   
    //cout << endl << "Nivel " << niv++ << ": ";
  }
    
}