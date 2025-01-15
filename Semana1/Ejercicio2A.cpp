#include <iostream>
#include <random>
using namespace std;

class Matriz2D{
    friend void print(const Matriz2D &m);
private:
    int **ptr;
    int filas;
    int columnas;
public:
    //Constuctor por caso general y generico asi ahorramos codigo
    Matriz2D(int f, int c):filas(f),columnas(c){
        ptr=new int* [filas];
        for(int i=0;i<filas;i++){
            ptr[i]=new int[columnas];
            for(int j=0;j<columnas;j++){
                ptr[i][j]=rand()%10;
            }
        }
    }

    Matriz2D(int l):Matriz2D(l,l){}
    Matriz2D():Matriz2D(3,3){}

};

void print(const Matriz2D &m){
    for(int i=0;i<m.filas;i++){
        for(int j=0;j<m.columnas;j++){
            cout << m.ptr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    Matriz2D m1(4,3);
    print(m1);
}