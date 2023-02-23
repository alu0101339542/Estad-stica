#ifndef ORDEN
#define ORDEN

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<class Clave>
class Orden {
  public:
    Orden(vector<Clave> v);
    ~Orden();
    void ImprimirVect() {
      for (int i = 0; i < elem_sz; i++) {
        cout << elementos[i] << ", ";
      }
      cout << endl;
    }

    void Insertar(bool imprimir);
    void Insercion(int sec_sz, Clave new_element, bool imprimir);
    void QuickSort(bool imprimir, int ini , int fin);
    void ShellSort(float alfa, bool imprimir);
    void DeltaSort(int delta, bool imprimir);

    
  private:
    vector<Clave> elementos;
    int elem_sz;
    

};
//Modificacion
class Dni {
  public:
    Dni(string str, int ent, string str2) {
      str_ = str;
      str2_ = str;
      ent_ = ent;
      str_ = str_ + to_string(ent_) + str2_;
      int x = 0;
      while (str_[x] != '\0') {   // While the string isn't at the end... { 
        strconvert += int(str_[x]);    // Transform the char to int 
        x++; 
      } 
    }
    int Getvalue() {
      return strconvert;
    }
    string Getdni() {
      return str_;
    }

  private:
    string str_;
    string str2_;
    int ent_;
    int strconvert;
};



template<class Clave>
  Orden<Clave>:: Orden(vector<Clave> v){
    elementos = v;
    elem_sz = elementos.size();
}

template<class Clave>
  Orden<Clave>:: ~Orden(){
    elementos.clear();
    elem_sz = 0;
}

template<class Clave>
  void Orden<Clave>:: Insertar(bool imprimir) {
    if(imprimir == true)
      ImprimirVect();
    for (int sec_sz = 1; sec_sz < elem_sz; sec_sz++) {
      if(imprimir == true) {
        cout <<"# El posicion a analizar es: " << sec_sz << endl;
        cout <<"# El valor a analizar es: " << elementos[sec_sz] << endl;
      }
      Insercion(sec_sz, elementos[sec_sz], imprimir); 
    }
    }

template<class Clave>
  void Orden<Clave>::Insercion(int sec_sz, Clave new_element, bool imprimir) {
    elementos[-1] = new_element;
    int j = sec_sz - 1;
    while (new_element < elementos[j] ){
      elementos[j+1] = elementos[j] ;
      j-- ;
    }
    if(imprimir == 1)
      cout <<"#La posición en la que se va a reubicar el valor es: " << j + 1 << ". Siendo reemplazado por: " << elementos[j + 1] << endl;
    elementos[j+1] = new_element ;
    if(imprimir == 1)
      ImprimirVect();
  }

  template<class Clave>
  void Orden<Clave>::QuickSort(bool imprimir, int ini, int fin) {
  int i = ini ; int f = fin ;
  if(imprimir == true) 
    ImprimirVect();
  Clave pivote = elementos[(i+f)/2] ;
  while (i <= f){
    while (elementos[i] < pivote) i++ ;
    while (elementos[f] > pivote) f-- ;
    if (i <= f) {
      swap(elementos[i], elementos[f]) ;
      i++ ;
      f-- ;

      if (imprimir == true) {
				cout << endl << "  # El pivote es: " << pivote << ", i = " << i << ", f = " << f << endl;
			  ImprimirVect();
        cout << endl;
			}
    }
  }
  if (ini < f) QuickSort(imprimir, ini, f) ;
  if (i < fin) QuickSort(imprimir, i, fin) ;
}


template<class Clave>
void Orden<Clave>::ShellSort(float alfa, bool imprimir) {
  int del = elem_sz * alfa;
  while (del >/*=*/ 1){
    if (imprimir == true)
			cout << endl << "  # Delta: " << del << endl;
    del = del / 2;
    DeltaSort(del, imprimir); //posiblemente halla que cambiar el orden de esta linea con la anterior
  } 
}

template<class Clave>
void Orden<Clave>::DeltaSort(int delta, bool imprimir) {
 for (int i = delta; i < elem_sz; i++) {
  Clave x = elementos[i] ;
  int j = i;
  if (imprimir == true) {
			cout << "  # Subsecuencia " << i << ": " << endl;
			cout << "  # Valor de la posición " << i << ": " << elementos[i] << endl;
			cout << "  # Valor de la posición " << j - delta << ": " << elementos[j - delta] << endl;
			cout << "  # Vector en la subsecuencia " << i << ": " << endl;
			//ImprimirVect();
		}

  while ((j >= delta) && (x < elementos[j - delta])){
    elementos[j] = elementos[j - delta] ;
    j = j - delta ;
  } 
  elementos[j] = x;

  if(imprimir == true)
  ImprimirVect();
 }
}
#endif