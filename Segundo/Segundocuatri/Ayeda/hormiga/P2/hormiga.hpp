#include <iostream>
#include <vector>
#include <assert.h>
#include <unistd.h>
#include "mundo.hpp"

using namespace std;

#define white 0
#define black 1
#define left 2
#define right 3
#define up 4
#define down 5
#define arriba_derecha 6
#define arriba_izquierda 7
#define abajo_derecha 8
#define abajo_izquierda 9


class Hormiga {
  public:
    Hormiga(Mundo world);
    Hormiga(Mundo world, int xpos, int ypos, int direc);
    Hormiga(Mundo world, char random);
    ~Hormiga();

    void Movimiento(Mundo &world);
    void Movimientolateral(Mundo &world);

    void Setx(int xpos);
    void Sety(int ypos);
    
    int GetX(void);
    int GetY(void);

  private:
    int x;
    int y;
    int direccion;
};



