#include <iostream>

using namespace std;
int main (){
    int n,m;
    //Ingreso de datos
    cout<< "Ingrese el numero de filas de la matriz m1: ";
    cin>>n;
    cout<< "Ingrese el numero de columnas de la matriz m1: ";
    cin>>m;

    int m1[n][m];
    int m2[n+1][m+1];
    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j <=m; j++) {
            cout << "Dato ("<< i<< ","<<j<<"): ";
            cin>>m1[i][j];
        }
    }

    int s=0;
    cout<<"Escribiendo resultados"<<endl;
    int suma=0;

    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j <=m+1; j++) {
            if (j==(m+1)){
                m2[i][m+1] = suma;
                cout<<suma<<endl;
                s=s+suma;
				suma=0;
            } else{
                m2[i][j] = m1[i][j];
				cout<< m2[i][j]<< ", ";
				suma = suma + m2[i][j]; 
            }
        }
    }
    
    for (int i=1 ; i<=n+1 ; i++) {
        for (int j=1; j <=m; j++) {
            suma = suma +m2[j][i];
        }
        cout<<suma<<", ";
		suma=0;
    }
    cout<< s;

}