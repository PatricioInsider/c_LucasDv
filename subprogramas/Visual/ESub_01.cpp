#include <iostream>
#include <string.h>
//1.-Determinar y visualizar el número más grande de dos números dados, mediante un subprograma.
using namespace std;

float mayor(float a, float b)
{
    if(a>b)
    {
    cout<<"el numero mayor es: "<<a<<endl;
    }else if(b>a)
    {
    cout<<"el numero mayor es: "<<b<<endl;        
    } else
    {    
        cout<<"Los dos numeros son iguales "<<endl;
    }
    return 0 ;
}

int main ()
{
    float x,z;
    cout <<"Ingresa el primer numero: ";
    cin>> x;
    cout <<"Ingresa el segundo numero a comparar: ";
    cin>>z;

    mayor(x,z);
}