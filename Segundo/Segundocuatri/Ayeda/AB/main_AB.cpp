#ifndef AB
#define AB

#include "AB.hpp"

int main() {
  int opc, data;
  bool encontro;
  coche c1("abc12", "seat", "rojo", 1);
  coche c2("def34", "mercedes", "azul", 2);
  coche c3("hij21", "audi", "verde", 3);

  
  // 1 Generear un AB vacío
  ArbolB<int> A;
  ArbolB<coche> C;
  // 2 Menú
  C.InsertaEquil(c1);
  C.InsertaEquil(c2);
  C.InsertaEquil(c3);
  C.ImprimirArbol();
  /* do {
    cout << endl << "[0] Salir" << endl << "[1] Insertar Clave" <<
        endl << "[2] Buscar Clave" << endl;
    cin >> opc;
    switch (opc) {
      case 0:
        
        break;
      case 1:
        cout << "Introduzca el dato a insertar: ";
        cin >> data;
        cout << endl;
        A.InsertaEquil(data);
        A.ImprimirArbol();
        break;
      case 2:
        cout << "Introduzca el numero de bastidor del a buscar: ";
        cin >> data;
        cout << endl;
        encontro = A.Buscar(data);
        if(encontro == true) {
          cout << "SI se encontró el dato" << endl;
        }
        else {
          cout << "NO se encontró el dato" << endl;
        }
        break;
      
      default:
        break;
      }   
    } while(opc != 0);
    */
}
#endif