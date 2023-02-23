#include "hormiga.hpp"

int main(void) {
  system("clear");
  /*Mundo MundoDefecto;
  Hormiga HormigaDefecto(MundoDefecto);
  HormigaDefecto.Movimiento(MundoDefecto); */
  Mundo Mundoparam(7, 7);
  //char r;
  /*Hormiga HormigaRandom(Mundoparam, r);
  HormigaRandom.Movimiento(Mundoparam);*/
  Hormiga HormigaParam(Mundoparam, 5, 5, left);
  HormigaParam.Movimientolateral(Mundoparam);
  return 0;
}
