#include <iostream>
#include <math.h>

//4.- Escribir un algoritmo mediante funciones que lea los dos números X y N y calcule la suma de la progresión geométrica:

using namespace std;

void calcular_area(float a, float b, float c,float& x);

int main()
{
    float l1,l2,l3, res=0;
    cout<< "Area del triangulo en cm "<<endl;
    cout<< "L1 = ";
    cin>>l1;
    cout<< "L2 = ";
    cin>>l2;
    cout<< "L3 = ";
    cin>>l3;

    calcular_area(l1,l2,l3,res);
    cout<<"El area del triangulo es: "<<res<< " cm2"<<endl;

}

void calcular_area(float a, float b, float c, float& x )
{
    int s=(a+b+c)/2;

    x= sqrt(s*(s-a)*(s-b)*(s-c));
}