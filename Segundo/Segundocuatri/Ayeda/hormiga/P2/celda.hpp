using namespace std;

class Celda {
  public: 
    Celda();
    ~Celda();
    int Getcolor();
    //int Getdirection();
    void Setcolor(int colour);
    //void Setdirection(Hormiga ant); //Inicializo a 0
  private:
    int color;
    int direction;
};
