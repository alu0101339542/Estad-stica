#include "hormiga.hpp"


void Hormiga::Movimiento(Mundo &world) { //Si vemos que la prox posicion es la ultima llamamos al metodo de la clase mundo con polimorfismo
  vector<int> next;
  int cambiodir;
  while(1) {
    world.PrintMundo(x, y, Getdir());
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