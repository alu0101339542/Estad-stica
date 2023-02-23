#ifndef MUNDOINFINITO_H
#define MUNDOINFINITO_H

#include "mundo.hpp"

using namespace std;

class Mundoinfinito: public Mundo {
  public:
    Mundoinfinito(void); //Centro
    Mundoinfinito(int sizex, int sizey);
    Mundoinfinito(char r); //random
    ~Mundoinfinito();

    int Boundries(int where);
};

#endif