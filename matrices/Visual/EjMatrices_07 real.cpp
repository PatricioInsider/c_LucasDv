#include <iostream>

using namespace std;
int main (){
   int n,x;
   cout<< "Determinas una matriz diagonal"<<endl;
   cout<<"Ingresa el numero de columnas y filas, para la matriz cuadrada: ";
   cin>>n;

   int m1[n][n];

    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j <=n; j++) {
            cout << "Dato ("<< i<< ","<<j<<"): ";
            cin>>m1[i][j];
        }
    }
    int s=s+1;

    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j <=n; j++) {
            cout<<m1[i][j]<< ", ";
            if (i==j)
            {
                if (m1[i][j] >0 )
                {
                    x=x+1;
                }
                
            } else{
                s=s+1;
            }
            
        }
        cout<<endl;
    }


    
    
    if ((x==n) && ((s+x) == (n*n)))
    {
        cout<<"Si es una Matriz diagonal"<<endl;
    } else{
        cout<<"No es una Matriz diagonal"<<endl;
    }
}