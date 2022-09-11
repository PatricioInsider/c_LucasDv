#include <iostream>

using namespace std;
int main (){
    int n,m,num;
    //Ingreso de datos
    cout<< "Ingrese el numero de filas de la matriz m1: ";
    cin>>n;
    cout<< "Ingrese el numero de columnas de la matriz m1: ";
    cin>>m;

    int m1[n][m];
    for (int i=1 ; i<=n ; i++) 
    {
        for (int j=1; j <=m; j++) 
        {
            cout << "Dato ("<< i<< ","<<j<<"): ";
            cin>>m1[i][j];
        }
    }

    for (int i=1 ; i<=n ; i++) 
    {
        for (int j=1; j<=m; j++) 
        {
            m1[i][j]= m1[i][j]*2;
        }
    }

    cout<<"___________________"<<endl;
    for (int i=1 ; i<=n ; i++) 
    {
        for (int j=1; j<=m; j++) 
        {
            cout << "Dato ("<< i<< ","<<j<<"): "<<m1[i][j]<<endl;

        }
    }

}