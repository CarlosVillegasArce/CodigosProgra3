#include <iostream>
#include <cmath>
using namespace std;


class Vector3D{
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

void print(const Vector3D &v){
    cout <<"("<<v.ptr[0]<<","<<v.ptr[1]<<","<<v.ptr[2]<<")" << endl;
}

int main(){
    Vector3D v1(3.3,4.4,5.5);
    cout << v1.modulo() << endl;
    print(v1);

    Vector3D v2;
    cout << v2.modulo() << endl;
    return 0;

}