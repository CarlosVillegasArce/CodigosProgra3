#include <iostream>
#include <cmath>
#include <random>
using namespace std;

class Vector3D{
    friend class Matriz2D;
    friend void print(const Vector3D &v);
    private:
        double *ptr;
    public:
    Vector3D(double x, double y, double z){
        ptr = new double[3];
        ptr[0] = x;
        ptr[1] = y;
        ptr[2] = z;
    }
    Vector3D(){
        ptr = new double[3];
        ptr[0] = 0;
        ptr[1] = 0;
        ptr[2] = 0;
    }

    double modulo(){
        return sqrt(ptr[0]*ptr[0] + ptr[1]*ptr[1] + ptr[2]*ptr[2]);
    }

    ~Vector3D(){
        delete[] ptr;
        ptr=nullptr;
    }
};

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

    Matriz2D(const Vector3D& v,int k):Matriz2D(3,k){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                ptr[i][j]=v.ptr[i];
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
    Vector3D v1(3.3,4.4,5.5);
    Matriz2D m1(v1,10);
    print(m1);
}