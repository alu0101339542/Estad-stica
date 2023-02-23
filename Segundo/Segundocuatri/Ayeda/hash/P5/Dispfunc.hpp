#ifndef DISPERSIONFUNCTION
#define DISPERIONFUNCTION

#include <stdlib.h> 
using namespace std;

template<class Key>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Key& k) const = 0;//Va el virtual?
};
template<class Key>
class fdModule: public DispersionFunction<Key> {
  public:
    fdModule(const unsigned n): nData(n){}
    unsigned operator()(const Key& k) const {
      return k % nData;
    }
  private:
    unsigned nData;
  };

  template<class Key>
class fdPsAleatory: public DispersionFunction<Key> {
  public:
    fdPsAleatory(const unsigned n): nData(n){}
    unsigned operator()(const Key& k) const {
      int seed = static_cast<int> (k); //Cambia al tipo int en tiempo de ejecucion.
      srand(seed);
      return (rand() % nData);
    }
  private:
    unsigned nData;
  };
#endif