o/*#include "orden.hpp"

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
  void Orden<Clave>::Insercion(int sec_sz, Clave new_element) {
    elementos[-1] = new_element;
    int j = sec_sz - 1;
    while (new_element < elementos[j] ){
      elementos[j+1] = elementos[j] ;
      j-- ;
    }
    elementos[j+1] = new_element ;
  }

  template<class Clave>
  void Orden<Clave>::QuickSort(bool imprimir, int ini, int fin) {
  int i = ini ; int f = fin ;
  Clave pivote = elementos[(i+f)/2] ;
  while (i <= f){
    while (elementos[i] < pivote) i++ ;
    while (elementos[f] > pivote) f-- ;
    if (i <= f) {
      swap(elementos[i], elementos[f]) ;
      i++ ;
      f-- ;
    }
  }
  if (ini < f) Qsort(ini, f) ;
  if (i < fin) Qsort(i, fin) ;
}


template<class Clave>
void Orden<Clave>::ShellSort(float alfa, bool imprimir) {
  int del = elem_sz * alfa;
  while (del >/*=*//* 1){
    del = del / 2 ;
    DeltaSort(del); //posiblemente halla que cambiar el orden de esta linea con la anterior
  } 
}

template<class Clave>
void Orden<Clave>::DeltaSort(int delta) {
 for (int i = delta; i < elem_sz; i++) {
  Clave x = elementos[i] ;
  int j = i ;
  while ((j >= delta) && (x < elementos[j - delta])){
    elementos[j] = elementos[j - delta] ;
    j = j - delta ;
  } 
  elementos[j] = x ;
 }
}*/