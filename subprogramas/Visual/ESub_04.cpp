#include <iostream>
#include <math.h>

//4.- Escribir un algoritmo mediante funciones que lea los dos números X y N y calcule la suma de la progresión geométrica:

using namespace std;
int expo(int a,int b){
    int suma,m,res;
    for(int i=1;i<=b;i++){
        m=pow(a,i);
        suma=suma+m;
    }
    res=1+suma;
    cout <<"Resultado de la suma de la serie: "<<res<<endl;
}
int main()
{
    int x,n,sd,serie;

    cout<<"Ingresa los valores: "<<endl;
    cout<<"X: ";
    cin>>x;
    cout<<"N ";
    cin>>n;

    expo(x,n);
    return 0;
}