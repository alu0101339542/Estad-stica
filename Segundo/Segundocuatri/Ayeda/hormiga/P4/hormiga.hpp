#ifndef HORMIGA_H
#define HORMIGA_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <unistd.h>
#include "mundo.hpp"



using namespace std;


class Hormiga {
  public:
    Hormiga();
    Hormiga(Mundo world);
    Hormiga(Mundo world, int xpos, int ypos, int direc);
    Hormiga(Mundo world, char random);
    ~Hormiga();

    void Setx(int xpos);
    void Sety(int ypos);
    void Setdir(int dir);
    
    int GetX(void);
    int GetY(void);
    int Getdir(void);

    virtual void Movimiento(Mundo &world);
    virtual vector<int> Desplazamiento(Mundo &world) = 0;
    virtual void Giro(Mundo &world) = 0;

  private:
    int x;
    int y;
    int direccion;
    
};

class HormigaInversa: public Hormiga {
  public:
    HormigaInversa();
    HormigaInversa(Mundo world);
    HormigaInversa(Mundo world, int xpos, int ypos, int direc);
    HormigaInversa(Mundo world, char random);
    ~HormigaInversa();

    void Movimiento(Mundo &world) override;
    vector<int> Desplazamiento(Mundo &world);
    void Giro(Mundo &world);
};

class HormigaLangton: public Hormiga {
  public:
    HormigaLangton(Mundo world);
    HormigaLangton(Mundo world, int xpos, int ypos, int direc);
    HormigaLangton(Mundo world, char random);
    ~HormigaLangton();

    void Movimiento(Mundo &world) /*override*/;
    vector<int> Desplazamiento(Mundo &world);
    void Giro(Mundo &world);
};

#endif

