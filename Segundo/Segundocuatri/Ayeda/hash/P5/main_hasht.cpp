#include "iostream"
#include "Hasht.hpp"
using namespace std;

int main() {
  int t_sz, func_type, menu, val;
  bool op_approved;
  DispersionFunction<int>* Disp;
  cout << "Introduzca el tamaño de la Tabla Hash: ";
  cin >> t_sz;
  cout << endl;
  cout << "1: Función de dispersión modular, 2: Función de dispersión pseudoaleatoria: ";
  cin >> func_type;
  if(func_type == 1)
    Disp = new fdModule<int>(t_sz);
  if(func_type == 2) 
    Disp = new fdPsAleatory<int>(t_sz);
  HashTable<int> T(t_sz, Disp);

  //Menu
  while(1) {
    cout <<"Pulse 1 para buscar un valor o 2 para insertarlo. Para salir pulse 3:" << endl;
    cin >> menu;
    switch (menu) {
      case 1:
        cout << "Indique el valor que quiere buscar" << endl;
        cin >> val;
        op_approved = T.Search(val);
        if(op_approved == true)
          cout << "Se encontró el valor" << endl;
        else 
          cout << "valor no encontrado" << endl;
        break;
      case 2:
        cout << "Indique el valor que quiere insertar" << endl;
        cin >> val;
        op_approved = T.Insert(val);
        if(op_approved == true)
          cout << "Se pudo insertar el valor" << endl;
        else 
          cout << "El valor no pudo ser insertado" << endl;
        break;
      case 3:
        return 0;
      
      default:
        break;
    }
  }
}