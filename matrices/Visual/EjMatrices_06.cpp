#include <iostream>

using namespace std;
int main (){
    int n;
    cout<<"Ingresa la longitud de la matriz transpuesta: ";
    cin>>n;

    int m1[n][n], m2[n][n];
    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j <=n; j++) {
            cout << "Dato ("<< i<< ","<<j<<"): ";
            cin>>m1[i][j];
        }
    }

    //Impresion de una matriz
    cout<<"Matriz ingresante "<<endl;
    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j<=n; j++) {
            cout<< m1[i][j]<<", ";
        }
        cout<<endl;
    }

    cout<<" "<<endl;
    cout<<"Matriz ingresante "<<endl;
    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j<=n; j++) {
            m2[j][i]=m1[i][j];
        }
    }
    cout<<" "<<endl;
    cout<<"Matriz resultado "<<endl;
    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j<=n; j++) {
            cout<< m2[i][j]<<", ";
        }
        cout<<endl;
    }

}