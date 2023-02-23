#include "hormiga.hpp"

vector<int> HormigaLangton::Desplazamiento(Mundo &world) {
  Celda celda;
  vector<int> nextpos;
  int nextx = GetX();
   int nexty = GetY();
    celda = world.Getmatrixcel(GetX(), GetY());

      if(celda.Getcolor() == black) { //45º a la derecha
        world.Setmatrixcel(GetX(), GetY(), celda);

        switch (Getdir()) {
          case up:
            nexty = nexty - 1;
            nextx = nextx + 1;
          break;

          case left:
            nexty = nexty - 1;
            nextx = nextx - 1;

          break;

          case right:
            nexty = nexty + 1;
            nextx = nextx + 1;
          break;

          case down:
            nexty = nexty + 1;
            nextx = nextx - 1;
          break;

          case arriba_derecha:
            nextx = nextx + 1;
          break;

          case arriba_izquierda:
            nexty = nexty - 1;
          break;

          case abajo_derecha:
            nexty = nexty + 1;
          break;

          case abajo_izquierda:
            nextx = nextx - 1;
          break;
        }
      }

      else { //45º a la izq
        world.Setmatrixcel(GetX(), GetY(), celda);

        switch (Getdir()) {
          case right:
            nexty = nexty - 1;
            nextx = nextx + 1;
          break;

          case up:
            nexty = nexty - 1;
            nextx = nextx - 1;
          break;

          case down:
            nexty = nexty + 1;
            nextx = nextx + 1;

          break;

          case left:
            nexty = nexty + 1;
            nextx = nextx - 1;
          break;

          case arriba_derecha:
            nexty = nexty - 1;
          break;

          case arriba_izquierda:
            nextx = nextx - 1;
          break;

          case abajo_izquierda:
            nexty = nexty + 1;
          break;

          case abajo_derecha:
            nextx = nextx + 1;
          break;

        }
      }
      nextpos.resize(2);
      nextpos[0] = nextx;
      nextpos[1] = nexty;
      return nextpos;
}

void HormigaLangton::Giro(Mundo &world) {
  Celda celda;
    celda = world.Getmatrixcel(GetX(), GetY());

      if(celda.Getcolor() == black) { //45º a la derecha
        celda.Setcolor(white);
        world.Setmatrixcel(GetX(), GetY(), celda);

        switch (Getdir()) {
          case up:
            Setdir(arriba_derecha) ;
          break;

          case left:
            Setdir(arriba_izquierda);

          break;

          case right:
            Setdir(abajo_derecha);
          break;

          case down:
            Setdir(abajo_izquierda);

          break;

          case arriba_derecha:
            Setdir(right);
          break;

          case arriba_izquierda:
            Setdir(up);

          break;

          case abajo_derecha:
            Setdir(down);
          break;

          case abajo_izquierda:
            Setdir(left);

          break;
        }
      }

      else { //45º a la izq
        celda.Setcolor(black);
        world.Setmatrixcel(GetX(), GetY(), celda);

        switch (Getdir()) {
          case right:
            Setdir(arriba_derecha);
          break;

          case up:
            Setdir(arriba_izquierda);
          break;

          case down:
            Setdir(abajo_derecha);

          break;

          case left:
            Setdir(abajo_izquierda);

          break;

          case arriba_derecha:
            Setdir(up);
          break;

          case arriba_izquierda:
            Setdir(left);

          break;

          case abajo_izquierda:
            Setdir(down);
          break;

          case abajo_derecha:
            Setdir(right);

          break;

        }
      }
}


  

void HormigaLangton::Movimiento(Mundo &world) { //Si vemos que la prox posicion es la ultima llamamos al metodo de la clase mundo con polimorfismo
  vector<int> next;
  int cambiodir;
  while(1) {
    world.PrintMundo(GetX(), GetY(), Getdir());
    next = Desplazamiento(world);
    Giro(world);
    if(next[0] == world.Getsizex())
      cambiodir = world.Boundries(1);    
    if(next[1] == world.Getsizey())
      cambiodir = world.Boundries(2);
    if(next[1] == -1) {
       cambiodir = world.Boundries(3);
       Sety(GetY() + 10);
       next[1] = GetY() -1;
    }
    if(next[0] == -1) {
      cambiodir = world.Boundries(4);
      Setx(GetX() + 10);
      next[0] = GetX() -1;
    }
    
    Setx(next[0]);
    Sety(next[1]);

    if(GetY() == world.Getsizey()) {
        Sety(0);
      }
      if(GetX() == world.Getsizex()) {
        Setx(0);
      }
      if(GetY() == -1)
        Sety(world.Getsizey() - 1);
      if(GetX() == -1)
        Setx(world.Getsizex() - 1);

      if(cambiodir == 1) {
        switch (Getdir())
        {
        case up:
          Setdir(down);
          break;
        case down:
          Setdir(up);
          break;
        case left:
          Setdir(right);
          break;
        case right:
          Setdir(left);
          break;
        default:
          break;
        }
      }
    sleep(1);
    //usleep(100);
    system("clear");
  }

}