#ifndef DISPERSIONFUNCTION
#define DISPERIONFUNCTION
template<class Key>
class DispersionFunction {
  public:
    unsigned operator()(const Key& k, unsigned i) const = 0;
};
template<class Clave>
class fdModulo: public FuncionDispersion<Clave> {
public:
fdModulo(const unsigned n): nDatos(n){}
unsigned operator()(const Clave& k) const {
return k % nDatos;
}
private:
unsigned nDatos;
};
#endif