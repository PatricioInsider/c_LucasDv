#include <iostream>
#include <cstdlib>
//Escribir un algoritmo usando un sub-programa que calcule el inverso de un número entero dado (1234, inverso es 4321).
using namespace std;


int invertido(int a)
{
    int b=0;
    while (a != 0)
    {
        b = b*10+a %10;
        a =a/10;
    }
    cout<<"numero ingresado: "<<b;

}
int main ()
{
    int num;
    cout<<"Ingresa el numero a invertir: ";
    cin>> num;
    invertido(num);

}
