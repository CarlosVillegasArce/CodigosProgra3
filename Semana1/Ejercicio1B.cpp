#include <iostream>
using namespace std;

class Personaje{
    friend void print(const Personaje& p);
private:
    string name="";
    int life;
    int attack;
    int defense;
public:
    Personaje(string n,int l,int a,int d){
        this->name=n;
        this->life=l;
        this->attack=a;
        this->defense=d;
        cout<<"this: "<<this<<endl;
    }
    
    void set_nombre(string n){this->name=n;}

    Personaje(const Personaje& pj_derecha){
        this->life=pj_derecha.life;
        this->attack=pj_derecha.attack;
        this->defense=pj_derecha.defense;
        cout<<"this: "<<this<<endl;
    }


    ~Personaje(){}
};
//puedes colocarlo afuera usando esto o adentro sin el "p." porque es seria un metodo de la clase
void print(const Personaje& p){
    cout<<"Nombre: "<<p.name<<endl;
    cout<<"Vida: "<<p.life<<endl;
    cout<<"Ataque: "<<p.attack<<endl;
    cout<<"Defensa: "<<p.defense<<endl;
}


int main(){
    Personaje p1("Carlos",100,10,5);
    print(p1);

    Personaje p2=p1;
    p2.set_nombre("Juan");
    print(p2);
    return 0;
}