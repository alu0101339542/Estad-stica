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
    Clave dato; // dato: Cualquier tipo de //Cambiar dato de int a template
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

class coche {
  public:
    coche(string matricul, string marc, string col, int bastidor){
    matricula = matricul;
    marca = marc;
    color = col;
    bastidor = n_bastidor;
    }
    bool operator == (coche& coche);
    bool operator < (coche& coche); 
    bool operator > (coche& coche);
    friend ostream& operator<<(ostream& os, const coche& c);
    operator int();

  private:
  string matricula;
  string marca;
  string color;
  int n_bastidor;
};

bool coche::operator==(coche& coche) {
  if(n_bastidor == coche.n_bastidor)return true;
  else return false;
}

bool coche::operator < (coche& coche) {
  if(n_bastidor < coche.n_bastidor)return true;
  else return false;
}

bool coche::operator > (coche& coche) {
  return (n_bastidor > coche.n_bastidor);
}

coche::operator int() {
   return n_bastidor;
}

ostream& operator<<(ostream& os, const coche& c) {
    os << c.marca << '/' << c.matricula << '/' << c.color;
    return os;
}


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

  cout << endl << "Nivel " << niv++ << ": ";
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