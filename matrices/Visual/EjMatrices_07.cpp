#include <iostream>

using namespace std;
int main (){
   
    int n,opc,m,l;
   
    do{
        cout<<"Escribe un numero para generar un vector, recuerda que este se multiplicara por si mismo: "<< endl;
        cout<<"(no puede ser 1): "<< endl;
        cin>>n;
    } while (n ==1);

    int v1[n*n];
    int m1[n][n];

    m=n*n;
    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=m; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;
    cout<< "Tu vector ahora es una matriz::"<<endl;
    cout<< "Organizar: 1)Columnas 2)Filas"<<endl;
    cin>>opc;

    if (opc == 1)
    {
        cout<<"Orden por columnas"<<endl;
        l=1;
        for (int i=1 ; i<=n ; i++) {
            for (int j=1; j<=n; j++) {
                m1[j][i] = v1[l];
                l = l+1;
                
            }
        }

        //Impresion de datos
        cout<<"Matriz resultado"<<endl;
        for (int i=1 ; i<=n ; i++) {
            for (int j=1; j<=n; j++) {
                cout<< m1[i][j]<<", ";
                l = l+1;
            }
            cout<<endl;
        }
    } else if (opc == 2)
    {
        cout<<"Orden por filas"<<endl;
        l=1;
        for (int i=1 ; i<=n ; i++) {
            for (int j=1; j<=n; j++) {
                m1[i][j] = v1[l];
                l = l+1;
                
            }
        }

        //Impresion de datos
        cout<<"Matriz resultado"<<endl;
        for (int i=1 ; i<=n ; i++) {
            for (int j=1; j<=n; j++) {
                cout<< m1[i][j]<<", ";
                l = l+1;
            }
            cout<<endl;
        }
    }  else{
        cout<<"No se ha encontrado un metodo de organizabion aceptable"<<endl;
    }

}