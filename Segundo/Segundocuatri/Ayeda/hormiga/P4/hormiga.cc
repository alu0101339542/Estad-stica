#include "hormiga.hpp"

//Clase Hormiga
Hormiga::Hormiga() {
  cout <<"error"<< endl;
  exit;
}

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

void Hormiga::Setx(int xpos) {
  x = xpos;
}

void Hormiga::Sety(int ypos) {
  y = ypos;
}

void Hormiga::Setdir(int dir) {
  direccion = dir;
}

int Hormiga::GetX(void) {
  return x;
}

int Hormiga::GetY(void) {
  return y;
}

int Hormiga::Getdir(void) {
  return direccion;
}


//Hormiga inversa
HormigaInversa::HormigaInversa(Mundo world) {
  int centerx, centery;
  centerx = world.Getsizex()/2; 
  centery = world.Getsizey()/2;
  Setx(centerx - 1);
  Sety(centery - 1);
  Setdir(right);
}


HormigaInversa::HormigaInversa(Mundo world, int xpos, int ypos, int direc) {
  Setx(xpos);
  Sety(ypos);
  Setdir(direc);
}
HormigaInversa::HormigaInversa(Mundo world, char random){
  int xmax = world.Getsizex();
  int ymax = world.Getsizey();
  Setx(rand() % xmax);
  Sety(rand() % ymax);
  Setdir(right);
}

HormigaInversa::~HormigaInversa(){
  Setx(0);
  Sety(0);
}

//Hormiga Langton
HormigaLangton::HormigaLangton(Mundo world) {
  int centerx, centery;
  centerx = world.Getsizex()/2; 
  centery = world.Getsizey()/2;
  Setx(centerx - 1);
  Sety(centery - 1);
  Setdir(right);
}
HormigaLangton::HormigaLangton(Mundo world, int xpos, int ypos, int direc) {
  Setx(xpos);
  Sety(ypos);
  Setdir(direc);
}
HormigaLangton::HormigaLangton(Mundo world, char random) {
  int xmax = world.Getsizex();
  int ymax = world.Getsizey();
  Setx(rand() % xmax);
  Sety(rand() % ymax);
  Setdir(right);
}

HormigaLangton::~HormigaLangton(){
  Setx(0);
  Sety(0);
}