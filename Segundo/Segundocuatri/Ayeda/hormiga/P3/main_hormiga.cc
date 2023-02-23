#include "universo.hpp"
#include "mundofinito.hpp"
#include "mundoinfinito.hpp"

int main(void) {
  system("clear");
  int tipomundo, xmundo, ymundo;
  Mundo *mundo;

  cout << "Introduzca el tipo de mundo 1 finito 2 infinito" << endl;
  cin >> tipomundo;
  cout << "Introduzca las dimensiones del mundo x*y" << endl;
  cin >> xmundo >> ymundo;
  if(tipomundo == 1) 
    mundo = new Mundofinito(xmundo,ymundo);
  if(tipomundo == 2)
    mundo = new Mundoinfinito(xmundo, ymundo);
  
  
  Hormiga hormiga(*mundo);
  Universo universe(*mundo, hormiga);
  return 0;
}
