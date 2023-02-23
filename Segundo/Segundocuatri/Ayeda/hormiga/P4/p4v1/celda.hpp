#ifndef CELDA_H
#define CELDA_H

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

class Celda {
  public: 
    Celda() {

    }
    ~Celda() {

    }
    int Getcolor() {
      return color;
    }
    //int Getdirection();
    void Setcolor(int colour) {
      color = colour;
    }
    //void Setdirection(Hormiga ant); //Inicializo a 0
  private:
    int color;
    int direction;
};
#endif