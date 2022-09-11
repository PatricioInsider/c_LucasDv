#include <iostream>
#include <string.h>
//3.- Realice un Algoritmo que calcule el mayor y el menor de tres números, usando sub-programas.
using namespace std;

float mayor(float a, float b,float c)
{

    if(a>b && a>c)
    {
        cout<<"el numero mayor es: "<<a<<endl;
    }
    if(b>c && b>a)
    {
        cout<<"el numero mayor es: "<<b<<endl;        
    }
    if(c>b && c>a)
    {
        cout<<"el numero mayor es: "<<c<<endl;        
    }
    if (a==b)
    {
        cout<<"Los numeros iguales son: "<<a<<endl;
    }
    if (a==c)
    {
        cout<<"Los numeros iguales son: "<<a<<endl;
    }
    if (b==c)
    {
        cout<<"Los numeros iguales son: "<<a<<endl;
    }
  
    return 0;
}

int main ()
{
    float x,z,y;
    cout <<"Ingresa el primer numero: ";
    cin>> x;
    cout <<"Ingresa el segundo numero: ";
    cin>>z;
    cout <<"Ingresa el tercer numero: ";
    cin>>y;

    mayor(x,z,y);
}