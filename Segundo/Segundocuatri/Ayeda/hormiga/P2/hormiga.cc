#include "hormiga.hpp"

//Clase mundo
Mundo:: Mundo() {
  Celda celda;//tendría que crear tantos objetos celda como celdas de la matriz?
  celda.Setcolor(black);
  assert(size_x > 0);
  assert(size_y > 0);
  matrix.resize(size_y);
  

  for(int i = 0; i < Getsizey(); i ++)
    matrix[i].resize(size_x);

  for(int i = 0; i < Getsizey(); i ++) {
      for(int j = 0; j < Getsizex(); j ++) {
        matrix[i].at(j) = celda;
      }
  }
}
  Mundo:: Mundo(int sizex, int sizey) {
  size_x = sizex;
  size_y = sizey;
  Celda celda;
  celda.Setcolor(black);
  assert(size_x > 0);
  assert(size_y > 0);
  matrix.resize(size_y);

  for(int i = 0; i < Getsizey(); i ++)
    matrix[i].resize(size_x);

  for(int i = 0; i < Getsizey(); i ++) {
      for(int j = 0; j < Getsizex(); j ++) {
        matrix[i].at(j) = celda;
      }
  }
}

Mundo:: ~Mundo(){
  for(int i = 0; i < Getsizey(); i ++)
    matrix[i].resize(0);
  matrix.resize(0);
  assert(matrix.size() == 0);
}

int Mundo::Getsizey() {
  return size_y;
}

int Mundo::Getsizex() {
  return size_x;
}

vector<vector<Celda>> Mundo::Getmatrix() {
  return matrix;
}

Celda Mundo::Getmatrixcel(int x, int y) {
  return matrix[y].at(x);
}


 void Mundo::Setmatrixcel(int x, int y, Celda cel) {
   matrix[y].at(x) = cel;
 }


void Mundo::PrintMundo(int hormiga_x, int hormiga_y, int direccion) {
  for(int i = 0; i < Getsizey(); i++) {
    for(int j = 0; j < Getsizex(); j++) {
       if(i == hormiga_y && j == hormiga_x){
        switch (direccion) {
        case up:
          cout <<"↑";
          break;

        case down:
          cout <<"↓";
          break;

        case left:
          cout <<"←";
          break;

        case right:
          cout <<"→";
          break;
        
         case arriba_izquierda:
          cout <<"↖";
          break;

        case arriba_derecha:
          cout <<"↗";
          break;

        case abajo_izquierda:
          cout <<"↙";
          break;

        case abajo_derecha:
          cout <<"↘";
          break;
         
         default:
           break;
         }
       }
       else {
        if(matrix[i].at(j).Getcolor() == black) {
          cout << "x";
        }
        else {
          cout << " ";
        }
    }
    }
    cout << endl;
  }
}
void Mundo::ResizeRight() {
  Celda celda;
  celda.Setcolor(black);
  for(unsigned int i = 0; i < matrix.size(); i++) {
   matrix[i].resize(matrix.at(i).size() + 10);
   size_x = matrix[i].size();
   for(unsigned int j = matrix.at(i).size() -10; j < matrix[i].size(); j++)
    matrix[i].at(j) = celda;

  }
}

void Mundo::ResizeDown() {
  Celda celda;
  celda.Setcolor(black);
  matrix.resize(matrix.size() + 10);
   size_y = matrix.size();
   
  for(unsigned int j = matrix.size() -10; j < matrix.size(); j++) {
    matrix[j].resize(size_x);
    for(int k = 0; k < size_x; k++)
      matrix[j].at(k) = celda;
  }
}

void Mundo::ResizeUp() {
  Celda celda;
  celda.Setcolor(black);
  matrix.resize(matrix.size() + 10);
   size_y = matrix.size();
   
  for(unsigned int j = 0; j < matrix.size() - 10; j--) { //Arreglar hasta donde llega
    matrix[j].resize(size_x);
    for(int k = 0; k < size_x; k++)
      matrix[j].at(k) = celda;
  }
}

void Mundo::ResizeLeft() {
  Celda celda;
  celda.Setcolor(black);
  for(unsigned int i = 0; i < matrix.size(); i++) {
    matrix[i].resize(matrix.at(i).size() + 10);
    size_x = matrix[i].size();
    for(unsigned int j = 0; j < matrix[i].size(); j++)
      matrix[i].at(j) = celda;

  }
}


//Clase Celda
Celda::Celda() {
}

Celda::~Celda() {
}

void Celda:: Setcolor(int colour) {
  color = colour;
}

int Celda::Getcolor(void) {
  return color;
}

//Clase Hormiga
Hormiga::Hormiga(Mundo world) {
  int centerx, centery;
  centerx = world.Getsizex()/2; 
  centery = world.Getsizey()/2;
  x = centerx;
  y = centery;
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
}





