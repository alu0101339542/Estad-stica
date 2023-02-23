#include "hormiga.hpp"

vector<int> Hormiga::Desplazamiento(Mundo &world) {
  Celda celda;
  vector<int> nextpos;
  int nextx = x;
   int nexty = y;
    celda = world.Getmatrixcel(x, y);

      if(celda.Getcolor() == black) { //45º a la derecha
        world.Setmatrixcel(x, y, celda);

        switch (direccion) {
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
        world.Setmatrixcel(x, y, celda);

        switch (direccion) {
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

void Hormiga::Giro(Mundo &world) {
  Celda celda;
    celda = world.Getmatrixcel(x, y);

      if(celda.Getcolor() == black) { //45º a la derecha
        celda.Setcolor(white);
        world.Setmatrixcel(x, y, celda);

        switch (direccion) {
          case up:
            direccion = arriba_derecha;
          break;

          case left:
            direccion = arriba_izquierda;

          break;

          case right:
            direccion = abajo_derecha;
          break;

          case down:
            direccion = abajo_izquierda;

          break;

          case arriba_derecha:
            direccion = right;
          break;

          case arriba_izquierda:
            direccion = up;

          break;

          case abajo_derecha:
            direccion = down;
          break;

          case abajo_izquierda:
            direccion = left;

          break;
        }
      }

      else { //45º a la izq
        celda.Setcolor(white);
        world.Setmatrixcel(x, y, celda);

        switch (direccion) {
          case right:
            direccion = arriba_derecha;
          break;

          case up:
            direccion = arriba_izquierda;
          break;

          case down:
            direccion = abajo_derecha;

          break;

          case left:
            direccion = abajo_izquierda;

          break;

          case arriba_derecha:
            direccion = up;
          break;

          case arriba_izquierda:
            direccion = left;

          break;

          case abajo_izquierda:
            direccion = down;
          break;

          case abajo_derecha:
            direccion = right;

          break;

        }
      }
}


  

void Hormiga::Movimiento(Mundo &world) { //Si vemos que la prox posicion es la ultima llamamos al metodo de la clase mundo con polimorfismo
  vector<int> next;
  int cambiodir;
  while(1) {
    world.PrintMundo(x, y, direccion);
    next = Desplazamiento(world);
    Giro(world);
    if(next[0] == world.Getsizex())
      cambiodir = world.Boundries(1);    
    if(next[1] == world.Getsizey())
      cambiodir = world.Boundries(2);
    if(next[1] == -1)
       cambiodir = world.Boundries(3);
    if(next[0] == -1)
      cambiodir = world.Boundries(4);
    
    x = next[0];
    y = next[1];

    if(y == world.Getsizey()) {
        y = 0;
      }
      if(x == world.Getsizex()) {
        x = 0;
      }
      
      if(y == -1)
        y = world.Getsizey() - 1;
      if(x == -1)
        x = world.Getsizex() - 1;

      if(cambiodir == 1) {
        switch (direccion)
        {
        case up:
          direccion = down;
          break;
        case down:
          direccion = up;
          break;
        case left:
          direccion = right;
          break;
        case right:
          direccion = left;
          break;
        default:
          break;
        }
      }
    sleep(1);
    //usleep(500);
    system("clear");
  }

}