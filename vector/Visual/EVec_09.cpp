#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int n, aux;
    cout<<"Ingrese la extension de v1 ";
    cin>> n;
    char v1[n];
    int nota[n], nota2[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++){
        cout<<"Ingresa el nombre del estudiante: ("<<i<< ") = ";
        gets(v1[i]);
        cout<<"Nota: ("<<i<< ") = ";
        cin>> nota[i];
        cout<<endl;
    }
    cout<< "_____________ "<<endl;

    //Primer listado
    cout<< "*************** "<<endl;
    cout<< "1_ Listado de datos ingresados"<<endl;
    cout<< "*************** "<<endl;
    cout<< "No. Nombre            Nota "<<endl;
    //Impresion de los datos
    for (int i = 1; i<=n; i++)
    {
        cout<<i<< "  "<< v1[i]<< "                "<< nota[i]<< endl;
    }

    //Orden por notas
    for (int i = 1; i<=n; i++)
    {
        nota2[i]= nota[i];
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=(n-1); j++){
            if (nota2[j] < nota2[j+1]){
                aux=nota2[j];
                nota2[j]= nota2[j+1];
                nota2[j+1] = aux;
            }
        }
    }
    cout<< "*************** "<<endl;
    cout<< "2_ Lista por nota"<<endl;
    cout<< "*************** "<<endl;
    cout<< "No. Nombre            Nota "<<endl;
    for (int i = 1; i<=n; i++){
        cout<<i<<"   ";
        for (int j = 1; j<=n; j++){
            if (nota2[i] == nota[j] )
            {
                cout << v1[j]	<< "                "<< nota[j];
            }
                
        } 
    }
}
