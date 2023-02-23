//#include "hormiga.hpp"
#include "mundo.hpp"

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
  Celda cel;
  try{
    if(y == matrix.size() || x == matrix[0].size() || x == -1 || y == -1){
      throw 20;
    }
    cel = matrix[y].at(x); 
  }
  catch(int exc) {
    Getbound(x,y);
    cel = matrix[y].at(x);
  }
  return cel;
}


void Mundo::Setmatrixcel(int x, int y, Celda cel) {
  try {
     matrix[y].at(x) = cel;
  }
  catch(out_of_range d) {
    Getbound(x,y);
    //exit(-1);
  }
}

void Mundo::Setsizex(int new_size) {
  for(unsigned int i = 0; i < matrix.size(); i++)
    matrix[i].resize(new_size);
  size_x = new_size;
}

void Mundo::Setsizey(int new_size) {
  matrix.resize(new_size);
  size_y = new_size;
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
  ResizeDown();
  rotate(matrix.begin(), matrix.end() -10, matrix.end());
}

void Mundo::ResizeLeft() {
  ResizeRight();
  for(int i = 0; i < matrix.size(); i++) {
    rotate(matrix[i].begin(), matrix[i].end() -10, matrix[i].end());
  }
}

int Mundo::Getbound(int x, int y) {
    int kk;
    if(x == Getsizex())
      kk = Boundries(1);    
    if(y == Getsizey())
      kk = Boundries(2);
    if(y == -1) {
      kk = Boundries(3);
      /*Sety(GetY() + 10);
      y = GetY() -1;*/
    }
    if(x == -1) {
      kk = Boundries(4);
      /*Setx(GetX() + 10);
      next[0] = GetX() -1;*/
    }
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
