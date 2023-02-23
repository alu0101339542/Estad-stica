#include "hormiga.hpp"

class Universo {
  public:
    Universo(Mundo mundo, Hormiga hormiga) {
      hormiga.Movimiento(mundo);
    }
    ~Universo() {

    }
  private:
  int tipomundo;
};