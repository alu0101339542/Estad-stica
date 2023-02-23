#include "hormiga.hpp"

class Universo {
  public:
    Universo(Mundo &m, Hormiga &h) {
      mundo = &m; 
      hor = &h;
      hor->Movimiento(*mundo);
    }
    ~Universo() {

    }
  private:
  Mundo *mundo;
    Hormiga *hor;
};