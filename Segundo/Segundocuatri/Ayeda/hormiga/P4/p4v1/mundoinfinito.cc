#include "mundoinfinito.hpp"
//#include "hormiga.hpp"


//Clase Mundoinfinito
Mundoinfinito::Mundoinfinito() {
  Celda celda;//tendría que crear tantos objetos celda como celdas de la matriz?
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
  Mundoinfinito:: Mundoinfinito(int sizex, int sizey) {
  Celda celda;
  celda.Setcolor(black);

  Setsizey(sizey);
  Setsizex(sizex);
  assert(Getsizex() > 0 && Getsizey() > 0);

  for(int i = 0; i < Getsizey(); i ++) {
      for(int j = 0; j < Getsizex(); j ++) {
        Setmatrixcel(j, i, celda);
      }
  }
}

Mundoinfinito:: ~Mundoinfinito(){
  Setsizey(0);
  Setsizex(0);
  assert(Getsizex() == 0 && Getsizey() == 0);
}


int Mundoinfinito::Boundries(int where) {
  //cout << "Entra"<< endl;
  if(where == 1)
    ResizeRight();
  if(where == 2)
    ResizeDown();
  if(where == 3)
    ResizeUp();
  if(where == 4)
    ResizeLeft();
  return 0;
}