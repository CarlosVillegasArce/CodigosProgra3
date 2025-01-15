#include <iostream>
using namespace std;

class Dados{
private:
    int *ptr;
    int n;
public:

    Dados(int n):n(n){
        ptr=new int[n];
    }

    //Constructor de Copia:copia los recursos dinamicos de un objeto a otro
    Dados(const Dados& d){
        n=d.n;
        ptr=new int[n];
    }

    //Constructor por Movimiento:mueve los recursos dinamicos de un objeto a otro y luego desecho el anterior
            //ptr es el nuevo y d.ptr es el anterior del cual estoy tomando los recursos
    Dados(Dados&& d):ptr(d.ptr),n(d.n){
        d.ptr=nullptr;//anulamos el puntero del anterior
        d.n=0;
    }


    void lanzar(){
        for(int i=0;i<n;i++){
            ptr[i]=rand()%6+1;
        }
    }
    void promedio(){
        int suma=0;
        for(int i=0;i<n;i++){
            suma+=ptr[i];
        }
        cout<<"Promedio: "<<float(suma/n)<<endl;
        if(float(suma/n)>3) cout<<"Ganaste"<<endl;
        else cout<<"Perdiste"<<endl;
    }

    ~Dados(){
        delete[] ptr;
        ptr=nullptr;
    }
};


int main(){
    //al no usar el operador new, se quedan en el stack y cuando salimos del metodo main, se ilimina
    Dados d1(3);
    d1.lanzar();
    d1.promedio();
    
    cout<<"Dado 2:"<<endl;
    Dados d2=d1;
    d2.lanzar();
    d2.promedio();

    cout<<"Dado 3:"<<endl;
    Dados d3=move(d1);
    d3.lanzar();
    d3.promedio();

    return 0;
}