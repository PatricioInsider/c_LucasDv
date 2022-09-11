#include <iostream>
#include <cstdlib>

using namespace std;
int main (){

   int n,m,num;
   //Ingreso de datos
   cout<< "Ingrese el numero de filas de la matriz m1: ";
   cin>>n;
   cout<< "Ingrese el numero de columnas de la matriz m1: ";
   cin>>m;

   int m1[n][m];

    for (int i = 1;i <= n;i++) 
    {
        for (int j = 1;j <= m;j++) 
        {
            num = rand()%101;
            m1[i][j]= num;
        }
    }

    int suma=0;
    for (int i = 1;i <= n;i++) 
    {
        for (int j = 1;j <= m;j++) 
        {
            cout<< "Dato ("<<i<<","<<j<<")"<<m1[i][j]<<endl;
        }
    }
    cout<< "Suma de  las filas y las columnas"<< suma;
}