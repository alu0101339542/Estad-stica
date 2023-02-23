#include "orden.hpp"
//g++ -o main_orden main_orden.cpp orden.hpp -std=c++14 -g -W

int main() {
  unsigned int metodo, v_sz;
  float alfa;
  bool imprimir, aleatorio;

  //MOD
  string str = "abc", str3= "fgh", str4="klm", str5 = "opq";
  string str2 = "def", str6 = "hig", str7="knm", str8 = "rst";
  int dninum = 511, dnin2= 512, dnin3= 513, dnin4= 514;
  map<int, Dni> dnimap;

  Dni Dni1(str, dninum, str2);
  Dni Dni2(str3, dnin2, str4);
  Dni Dni3(str5, dnin3, str6);
  Dni Dni4(str7, dnin4, str8);
  Dni Dni5(str, dnin2, str8);
  int dn1= Dni1.Getvalue(), dn2= Dni2.Getvalue(), dn3= Dni3.Getvalue(), dn4 = Dni4.Getvalue(), dn5 = Dni5.Getvalue();
  dnimap.insert(pair<int, Dni>(dn1, Dni1));
  dnimap.insert(pair<int, Dni>(dn2, Dni2));
  dnimap.insert(pair<int, Dni>(dn3, Dni3));
  dnimap.insert(pair<int, Dni>(dn4, Dni4));
  dnimap.insert(pair<int, Dni>(dn5, Dni5));
  // Los valores del dni son convertidos a enteros por lo que los podemos pasar directamente con getvalue
  vector <int> vect;
  vect.push_back(dn1), vect.push_back(dn2), vect.push_back(dn3), vect.push_back(dn4), vect.push_back(dn5);
  v_sz = vect.size();
  while(!vect.empty()){
    int i = 0;
    cout <<"El valor "<< vect[i] << "se corresponde a: " << dnimap.at(i).Getdni() << endl;
    i++;
  }

 /* vector <int> vect;
  cout <<"introduzca el tamaño del vector: ";
  cin >> v_sz;
  vect.resize(v_sz);
  cout << endl << "Valores aleatorios?(0->NO, 1-> SI)"<< endl;
  cin >> aleatorio;
  if(aleatorio == 1) {
    for(unsigned int i = 0; i < v_sz; i++) 
      vect[i] = rand()%(1000-1 + 1) + 1;
  }
  else {
    for(unsigned int i = 0; i < v_sz; i++) {
      cout << endl << "introduzca el valor de la posición " << i << endl;
      cin >> vect[i];
      cout << endl;
    }
  }
  
  cout << "imprimir secuencia?(0->NO, 1-> SI): ";
  cin >> imprimir;
  Orden<int> Or(vect);
  cout <<"Seleccione el método de ordenacion" << endl << "1 -> Insercion"<< endl << "2 -> QuickSort" << endl << "3-> ShellSort" << endl;
  cin >> metodo;
  switch (metodo)
  {
  case 1:
    Or.Insertar(imprimir);
    break;
  case 2:
    Or.QuickSort(imprimir, 0, v_sz - 1);
    break;
  case 3:
    cout <<"Seleccione el valor de alfa (cte de reduccion [>0 &&< 1]) NOTA: Usar . para el decimal " << endl;
    cin >> alfa;
    Or.ShellSort(alfa, imprimir);
    //Si termina
    break;
  
  default:
    break;
  }*/

  cout << "imprimir secuencia?(0->NO, 1-> SI): ";
  cin >> imprimir;
  Orden<int> Or(vect);
  cout <<"Seleccione el método de ordenacion" << endl << "1 -> Insercion"<< endl << "2 -> QuickSort" << endl << "3-> ShellSort" << endl;
  cin >> metodo;
  switch (metodo)
  {
  case 1:
    Or.Insertar(imprimir);
    break;
  case 2:
    Or.QuickSort(imprimir, 0, v_sz - 1);
    break;
  case 3:
    cout <<"Seleccione el valor de alfa (cte de reduccion [>0 &&< 1]) NOTA: Usar . para el decimal " << endl;
    cin >> alfa;
    Or.ShellSort(alfa, imprimir);
    //Si termina
    break;
  
  default:
    break;
  }
}