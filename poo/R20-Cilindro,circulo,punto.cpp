#include <iostream>
#include <string.h>

using namespace std;

class Punto
{
private:
    int x,y;
public:
    Punto(/* args */);
    ~Punto();

    virtual void leer()
    {
        cout<<"Ingresa los valores"<<endl;
        cout<<"x = ";
        cin>>x;
        cout<<"y = ";
        cin>>y;
    }

    virtual void mostrar(void)
    {
        cout<<"Posicion"<<endl;
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }

};

class Circulo : public Punto
{
private:
    int r;
public:
    Circulo(/* args */);
    ~Circulo();
    void leer()
    {
        Punto::leer();
        cout<<"r = ";
        cin>>r;
    }
};

Circulo::Circulo(/* args */)
{
    int r=0;
}

Circulo::~Circulo()
{
}

class Cilindro
{
private:
    int h;
public:
    Cilindro(/* args */);
    ~Cilindro();
};

Cilindro::Cilindro(/* args */)
{
    h=0;
}

Cilindro::~Cilindro()
{
}



Punto::Punto(/* args */)
{
    x=y=0;
}

Punto::~Punto()
{
}
