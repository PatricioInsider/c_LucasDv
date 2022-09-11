#include <iostream>

using namespace std;
int main (){
   
   int m;
   cout<< "Ingrese el numero de columnas de la matriz m1: ";
   cin>>m;

   int m1[2][m];

   for (int i=1 ; i<=2 ; i++) 
    {
        for (int j=1; j <=m; j++) 
        {
            if ( i==1)
            {
                cout << "Dato ("<< i<< ","<<j<<"): ";
                cin>>m1[i][j];
            } else{
                m1[i][j] = m1[1][j] * m1[1][j];
            }
        }
    }
    cout<< "Resultado"<<endl;

    for (int i=1 ; i<=2 ; i++) 
    { 
        for (int j=1; j <=m; j++) 
        {
            cout << "Dato ("<< i<< ","<<j<<"): ";
            cout << m1[i][j]<<endl;
        }
    }

}