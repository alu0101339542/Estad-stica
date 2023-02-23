#include "hormiga.hpp"

//Clase Hormiga
Hormiga::Hormiga(Mundo world) {
  int centerx, centery;
  centerx = world.Getsizex()/2; 
  centery = world.Getsizey()/2;
  x = centerx - 1;
  y = centery - 1;
  direccion = right;
}
Hormiga::Hormiga(Mundo world, int xpos, int ypos, int direc) {
  x = xpos;
  y = ypos;
  direccion = direc;
}
Hormiga::Hormiga(Mundo world, char random){
  int xmax = world.Getsizex();
  int ymax = world.Getsizey();
  x = rand() % xmax;
  y = rand() % ymax;
   direccion = right;
}

Hormiga::~Hormiga(){
  x = 0;
  y = 0;
}





