#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Vector {
  public:
    Vector(int minvalue, int maxvalue);
    ~Vector();
    void ResizeV(const int new_size);
    int Getdimension(void);
    int Getmin(void);
    int Getmax(void);
    T& operator[](const int i); 
  private:
    int max;
    int min;
    int dimension;
    vector<T> Vect;
};