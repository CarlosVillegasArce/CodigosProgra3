#include <iostream>
#include <vector>
using namespace std;

class Foo{
    private:
        int *_num;
    public:
        Foo(int n){_num=new int(n); cout <<"Clase Foo: Constructor -> " <<*_num<<endl;}

        Foo(const Foo& f){this->_num=f._num; cout<<"Clase Foo: Constructor de Copia ->"<<*_num<<endl;}

        Foo(Foo&& f):_num(f._num){
            f._num=nullptr;
            cout<<"Clase Foo: Constructor de Movimiento ->"<<*_num<<endl;
        }

        ~Foo(){
            if(_num!=nullptr){
                cout<<"Clase Foo: Destructor -> "<<*_num<<endl;
                _num=nullptr;
            }
            else
                cout<<"Clase Foo: Destructor -> nullptr"<<endl;
            }

            
};

void test1(){
    Foo f1(3);
}

void test2(){
    Foo f1(3);
    Foo f2=f1;
}

void test3(){
    vector<Foo> v;
    v.push_back(Foo(4));
}

void test4(){
    Foo f1(3);
    Foo f2(move(f1));
}
int main(){
    test4();
}