#include <iostream>
#include <math.h>
using namespace std;
     int elevacion(int a,int b){
         int sum,m;
      for(int i=1;i<=b;i++){
         m=pow(a,i);
         sum=sum+m;
    }
    return sum;
     }
     int resultado(int f){
         int suma;
         suma=1+f;
         return suma;
     }
int main()
{
    int x,n,sd,serie;
    cout<<" escribir el valor de X "<<endl;
    cin>>x;
    cout<<" escribir el valor de N "<<endl;
    cin>>n;

    sd=elevacion(x,n);
    serie= resultado(sd);
    cout<<" "<<endl;
    cout <<"El resultado de la serie es: "<<serie<<endl;

    return 0;
}