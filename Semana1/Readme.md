# CODIGO de Semana 1 de Progra 3
## Aprendimos a POO1

### Session A:


Usamos la funcion Friend que se encarga de darle autorizacion a una funcion externa de la clase, a usar sus atributos o metodos de una clase amiga.

```C++
friend void print(const Vector3D &v);
```

Tambien a generar un constructor por defecto, sera util para ahorrar lineas de codigo, ya que solo pondriamos un constructor por defecto y el resto se genera con otro constructor con otros valores

```C++
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
```

### Session B:
Usamos Conceptos de Getters y Setters, ademas tambien aprendimos a usar conceptos de Lvalue: copia todo y gasta recursos y Rvalue: un translado de todo a otro y lo eliminamos, 

En este caso en el Constructor de copia de la clase Dados, se entrega por argumento el dado1, del cual el n y ptr, van a copiar del dado1 y lo guardan a otro dado que en este caso es dado2.

```C++
    Dados(const Dados& d){
        n=d.n;
        ptr=new int[n];
    };

    int main(){
        Dados d1(2);
        Dados d2=d1;// o tambien d2(d1)
    }
```
En este caso, el constructor de Movimiento de la clase Dados, recibe como argumento al dado1 y el constructor va a entregar los recursos que se usan en el dado1 pero no tendra la misma direccion de ese atributo para el dado2.

```C++
    //Constructor por Movimiento:mueve los recursos dinamicos de un objeto a otro y luego desecho el anterior
        //ptr es el nuevo y d.ptr es el anterior del cual estoy tomando los recursos
    Dados(Dados&& d):ptr(d.ptr),n(d.n){
        d.ptr=nullptr;//anulamos el puntero del anterior
        d.n=0;
    }

    int main(){
        Dados d1;
        Dados d2=move(d1);
    }
```




