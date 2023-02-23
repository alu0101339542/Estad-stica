#include <iostream>
#include <vector>
#include <assert.h>
#include <unistd.h>
#include "celda.hpp"

using namespace std;

class Mundo {
  public:
    Mundo(void); //Centro
    Mundo(int sizex, int sizey);
    Mundo(char r); //random
    ~Mundo();

    void PrintMundo(int hormiga_x, int hormiga_y, int direccion); 
    int Getsizex();
    int Getsizey();
    Celda Getmatrixcel(int x, int y);

    void Setsizex();
    void Setsizey();
    vector<vector<Celda>> Getmatrix();
    void Setmatrixcel(int x, int y, Celda cel);
    void ResizeRight();
    void ResizeDown();
    void ResizeUp();
    void ResizeLeft();
  
  private:
    int size_x = 10;
    int size_y = 10;
    vector<vector<Celda>> matrix;
    int min;
    int max;
};