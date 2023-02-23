#include "hormiga.hpp"

void Hormiga::Movimiento(Mundo &world) {
  Celda celda;

  while(1) {
    celda = world.Getmatrixcel(x, y);
    world.PrintMundo(x,y, direccion);

    if(celda.Getcolor() == black) { //90º a la derecha
      celda.Setcolor(white);
      world.Setmatrixcel(x, y, celda);
      switch (direccion) {
      case left:
        y = y - 1;
        direccion = up;
        break;
      case right:
        y = y + 1;
        direccion = down;
        break;
      case up:
        x = x + 1;
        direccion = right;
        break;
      case down:
        x = x - 1;
        direccion = left;
        break;
      
      default:
        cout << "Ha ocurrido un error" << endl;
        return;
        break;
      }
    }
    else {
      celda.Setcolor(black);
      world.Setmatrixcel(x, y, celda);
      switch (direccion) {
      case right:
        y = y - 1;
        direccion = up;
        break;
      case left:
        y = y + 1;
        direccion = down;
        break;
      case down:
        x = x + 1;
        direccion = right;
        break;
      case up:
        x = x - 1;
        direccion = left;
        break;
      
      default:
        cout << "Ha ocurrido un error" << endl;
        return;
        break;
      }
    }
    assert(y <= world.Getsizey() && x <= world.Getsizex());
    /*if(y == world.Getsizey())
      y = 0;
    if(x == world.Getsizex())
      x = 0; */
  
    if(y == world.Getsizey())
      world.ResizeDown();
    if(x == world.Getsizex()) 
      world.ResizeRight(); 
      
    if(y == -1)
      y = world.Getsizey() - 1;
    if(x == -1)
      x = world.Getsizex() - 1;
    sleep(1);
    //usleep(500);
    system("clear");
  }
}


//Movimientos laterales.
void Hormiga::Movimientolateral(Mundo &world) {
  Celda celda;
  while (1) {
    celda = world.Getmatrixcel(x, y);
      world.PrintMundo(x,y, direccion);

      if(celda.Getcolor() == black) { //45º a la derecha
        celda.Setcolor(white);
        world.Setmatrixcel(x, y, celda);

        switch (direccion) {
          case up:
            y = y - 1;
            x = x + 1;
            direccion = arriba_derecha;
          break;

          case left:
            y = y - 1;
            x = x - 1;
            direccion = arriba_izquierda;

          break;

          case right:
            y = y + 1;
            x = x + 1;
            direccion = abajo_derecha;
          break;

          case down:
            y = y + 1;
            x = x - 1;
            direccion = abajo_izquierda;

          break;

          case arriba_derecha:
            x = x + 1;
            direccion = right;
          break;

          case arriba_izquierda:
            y = y - 1;
            direccion = up;

          break;

          case abajo_derecha:
            y = y + 1;
            direccion = down;
          break;

          case abajo_izquierda:
            x = x - 1;
            direccion = left;

          break;
        }
      }

      else { //45º a la izq
        celda.Setcolor(black);
        world.Setmatrixcel(x, y, celda);

        switch (direccion) {
          case right:
            y = y - 1;
            x = x + 1;
            direccion = arriba_derecha;
          break;

          case up:
            y = y - 1;
            x = x - 1;
            direccion = arriba_izquierda;
          break;

          case down:
            y = y + 1;
            x = x + 1;
            direccion = abajo_derecha;

          break;

          case left:
            y = y + 1;
            x = x - 1;
            direccion = abajo_izquierda;

          break;

          case arriba_derecha:
            y = y - 1;
            direccion = up;
          break;

          case arriba_izquierda:
            x = x - 1;
            direccion = left;

          break;

          case abajo_izquierda:
            y = y + 1;
            direccion = down;
          break;

          case abajo_derecha:
            x = x + 1;
            direccion = right;

          break;

        }
      }
      //assert(y <= world.Getsizey() && x <= world.Getsizex());
      /*if(y == world.Getsizey())
        y = 0;
      if(x == world.Getsizex())
        x = 0; */

      if(y == world.Getsizey()) {
        world.ResizeDown();
      }
      if(x == world.Getsizex()) {
        world.ResizeRight();
      }
        
      if(y == -1)
        y = world.Getsizey() - 1;
      if(x == -1)
        x = world.Getsizex() - 1;
      sleep(1);
      //usleep(500);
      system("clear");
  }
}