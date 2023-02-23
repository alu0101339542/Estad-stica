#include "Vector.hpp"
template<class T>
Vector<T>::Vector(int minvalue, int maxvalue) {
  min = minvalue;
  max = maxvalue - 1;
  dimension = max - min;
  Vect.resize(dimension);
}

template<class T>
Vector<T>::~Vector() {
  Vect.resize(0);
  min = 0;
  max = 0;
  dimension= 0;
}
template<class T>
int Vector<T>::Getdimension(void) {
  return dimension;
}

template<class T>
int Vector<T>::Getmin(void) {
  return min;
}

template<class T>
int Vector<T>::Getmax(void) {
  return max;
}

template<class T>
void Vector<T>::ResizeV(const int new_size) {
  dimension = max - min;
  if(new_size < 0) {
    min = new_size;
    Vect.resize(dimension);
    rotate(Vect.begin(), Vect.end() + new_size, Vect.end());
  }
  if(new_size > 0) { 
    max = new_size;
    Vect.resize(dimension);
  }  
}

template<class T>
T& Vector<T>::operator[](const int i) {
  if((i>=0) && (i<dimension))
    return Vect[i];
}

int main() {
  Vector<int> prueba(-3,3);
  Vector<Vector<int>> malla(-3,3);
    for(int i = 0; i < malla.Getdimension(); i++ ){
      for(int j = 0; j < prueba.Getdimension(); j++ ){
        prueba[j] = j;
      }
      malla[i] = prueba;
    }
     for(int i = 0; i < malla.Getdimension(); i++ ){
      for(int j = 0; j < prueba.Getdimension(); j++ ){
        cout <<j<<" ";
      }
      cout << endl;
    }
}