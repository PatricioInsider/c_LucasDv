#include <iostream>
//Escribir un Algoritmo que permita el cálculo del mcd (máximo común divisor) de dos números por el algoritmo de Euclides (Dividir a entre b, se obtiene el cociente q y el resto r si es cero b es el mcd, si no se divide b entre r, y asi sucesivamente hasta encontrar un resto cero, el último divisor es el mcd)

using namespace std;

int mcd(int a,int b)
{
    
    int q, r,aux;

    for (int i = 0; i < 100; i++)
    {
        aux=b;
        q=a/b;
        r=a%b;
        a=q;
        b=r;
        if (a==0)
        {
            cout<<"El maximo comun divisor es: "<<aux<<endl;
        }
        
    }
    
}

int main(){
    int x,y;
    cout <<"Ingresa el primer numero: ";
    cin>> x;
    cout <<"Ingresa el segundo numero: ";
    cin>>y;

    mcd(x,y);
}
