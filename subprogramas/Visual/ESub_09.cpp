#include <iostream>
#include <cstdlib>
//Realizar un algoritmo mediante sub-programas que dado un número de cicno cifras indique si es capicúa o no. Un número capicúa es aquel que se lee igual al derecho que al revés
using namespace std;


int compa(int a,int b)
{
    if (a==b)
    {
        cout<<"EL numero "<<b<< " es capicua "<<endl;
    }else{
        cout<<"EL numero "<<b<< " NO es capicua "<<endl;
    }
}

int invertido(int a)
{
    int aux=a;
    int b=0;
    while (a != 0)
    {
        b = b*10+a %10;
        a =a/10;
    }

    compa(b,aux);

}
int main ()
{
    int num;
    cout<<"Ingresa el numero a invertir: ";
    cin>> num;
    invertido(num);

    cout<<"Ingreso";

}