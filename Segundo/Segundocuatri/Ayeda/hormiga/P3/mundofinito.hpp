#ifndef MUNDOFINITO_H
#define MUNDOFINITO_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <unistd.h>
#include "mundo.hpp"

using namespace std;

class Mundofinito: public Mundo {
  public:
    Mundofinito(void); //Centro
    Mundofinito(int sizex, int sizey);
    Mundofinito(char r); //random
    ~Mundofinito();

    int Boundries(int where);

};
class Mundotrasladarse : public Mundofinito {
  Mundotrasladarse() {
    Celda celda;
    celda.Setcolor(black);
    assert(Getsizex() > 0);
    assert(Getsizey() > 0);

    Setsizey(Getsizey());
    Setsizex(Getsizex());

    for(int i = 0; i < Getsizey(); i ++) {
        for(int j = 0; j < Getsizex(); j ++) {
          Setmatrixcel(j, i, celda);
        }
    }
  }

  int Boundries(int where) {
    //No hace nada
    return 0;
  }
};

class Mundorebota : public Mundofinito {
  Mundorebota() {
    Celda celda;
    celda.Setcolor(black);
    assert(Getsizex() > 0);
    assert(Getsizey() > 0);

    Setsizey(Getsizey());
    Setsizex(Getsizex());

    for(int i = 0; i < Getsizey(); i ++) {
        for(int j = 0; j < Getsizex(); j ++) {
          Setmatrixcel(j, i, celda);
        }
    }
  }
  int Boundries(int where) {
    return 1;
  }

};
#endif