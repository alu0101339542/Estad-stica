#include "universo.hpp"
#include "mundofinito.hpp"
#include "mundoinfinito.hpp"

int main(void) {
  system("clear");
  int tipomundo, tipohormiga, xhormiga, yhormiga, xmundo, ymundo, dir;
  Mundo *mundo;
  Hormiga *horm;

  cout << "Introduzca el tipo de mundo 1 finito 2 infinito:" << endl;
  cin >> tipomundo;
  cout << "Introduzca las dimensiones del mundo x*y:" << endl;
  cin >> xmundo >> ymundo;
  if(tipomundo == 1) 
    mundo = new Mundofinito(xmundo,ymundo);
  if(tipomundo == 2)
    mundo = new Mundoinfinito(xmundo, ymundo);
  

  cout << "Introduzca el tipo de hormiga 1 hormiga de langton 2 hormiga inversa 3 hormiga c  y 4 horm d:" << endl;
  cin >> tipohormiga;
  cout << "introduzca donde va a ser ubicada la hormiga x, y:" << endl;
  cin >> xhormiga >> yhormiga;
  if(tipohormiga == 1) 
    horm = new HormigaLangton(*mundo, xhormiga, yhormiga, dir = 3);
  if(tipohormiga == 2)
    horm = new HormigaInversa(*mundo, xhormiga, yhormiga, dir = 3);
  if(tipohormiga == 3)
    horm = new HormigaC(*mundo, xhormiga, yhormiga, dir = 3);
  if(tipohormiga == 4)
    horm = new HormigaD(*mundo, xhormiga, yhormiga, dir = 3);
  
  Universo universe(*mundo, *horm);
  return 0;
}
