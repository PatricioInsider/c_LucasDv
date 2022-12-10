/*
Se desea elaborar un programa orientado a objetos en el lenguaje de programación C++ que permita gestionar la información de los puntos, círculos y cilindros, como se muestra en el siguiente Diagrama de Clases - UML.
El programa debe permitir:
a. Leer los datos de los objetos
b. Mostrar los datos de los objetos, agregando el área y volumen de aquellas figuras que lo permitan
Patricio Quishpe
*/

#include <iostream>
#include <string.h>

using namespace std;

class Point
{
private:
    float x,y; 
public:
    Point(float a,float b);

    void data_point(void)
    {
        cout<<"x = ";
        cin>>x;
        cout<<"y = ";
        cin>>y;
    }

    void read_point(void)
    {
        cout<<"----------------"<<endl;
        cout<<"Elemento Punto"<<endl;
        cout<<"Ingresa los valores"<<endl;
        data_point();
        system("pause");
    }
    void show_point(void)
    {
        cout<<"Posicion"<<endl;
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }

    int getx(void)
    {
        return x;
    }
    int gety(void)
    {
        return y;
    }
};

class Circle: public Point{
private:
    float r;
public:

    Circle(float a, float b, float c): Point(a, b)
    {
        r=c;
    };
    void data_circle(void)
    {
        data_point();
        cout<<"r = ";
        cin>>r;
    }
    void read_circle(void)
    {
        cout<<"----------------"<<endl;
        cout<<"Figura Circulo "<<endl;
        cout<<"Ingresa los valores"<<endl;
        data_circle();
        system("pause");
    }

    float area_cir()
    {
        float a;
        a= 3.1416*(r*r);
        return a;
    }
    void show_circle()
    {
        cout<<"Posicion: "<<endl;
        cout<<"x = "<<getx()<<endl;
        cout<<"x = "<<gety()<<endl;
        cout<<"r = "<<r<<endl;
        cout<<"Area = "<<area_cir()<<endl;
    }
    //Falta agregar el area del circulo
    float getr(void)
    {
        return r;
    }
};           

class Cylinder: public Circle{

private:
    float h;
public:          
    Cylinder(float a,float b,float c,float d):Circle(a,b,c)
    {
        h=d;
    }
    void data_cylinder()
    {
        data_circle();
        cout<<"h= ";
        cin>>h;
    }
    void read_cylinder()
    {
        cout<<"----------------"<<endl;
        cout<<"Figura Cilindro"<<endl;
        cout<<"Ingresa los valores"<<endl;
        data_cylinder();
        system("pause");
    }

    float area_cyl()
    {
        float area;
        area= 2*3.1416*(getr()*(getr()+h));
        return area;
    }

    float vol_cyl()
    {
        float vol;
        vol= area_cir()*h;
        return vol;
    }

    void show_cylinder()
    {
        cout<<"Posicion: "<<endl;
        cout<<"x = "<<getx()<<endl;
        cout<<"x = "<<gety()<<endl;
        cout<<"r = "<<getr()<<endl;
        cout<<"Area= "<<area_cyl()<<endl;
        cout<<"Volumen = "<<vol_cyl()<<endl;
    }

};           

Point::Point(float a, float b)
{
    x=a;
    y=b;
}


int main (void)
{
    //Point oPoint;
    Point oPoint(0,0);
    oPoint.read_point();
    oPoint.show_point();
    //Circle oCircle;
    Circle oCircle(0,0,0);
    oCircle.read_circle();
    oCircle.show_circle();
    //Cylinder oCylinder;
    Cylinder oCylinder(0,0,0,0);
    oCylinder.read_cylinder();
    oCylinder.show_cylinder();
    return 0;
}