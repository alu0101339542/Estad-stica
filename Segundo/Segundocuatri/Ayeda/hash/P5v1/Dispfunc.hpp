#ifndef DISPERSIONFUNCTION
#define DISPERIONFUNCTION

#include <stdlib.h> 
using namespace std;

template<class Clave>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Clave& k) const = 0;//Va el virtual?
};
template<class Clave>
class fdModule: public DispersionFunction<Clave> {
  public:
    fdModule(const unsigned n): nData(n){}
    unsigned operator()(const Clave& k) const {
      return k % nData;
    }
  private:
    unsigned nData;
  };

  template<class Clave>
class fdPsAleatory: public DispersionFunction<Clave> {
  public:
    fdPsAleatory(const unsigned n): nData(n){}
    unsigned operator()(const Clave& k) const {
      int seed = static_cast<int> (k); //Cambia al tipo int en tiempo de ejecucion.
      srand(seed);
      return (rand() % nData);
    }
  private:
    unsigned nData;
  };
#endif