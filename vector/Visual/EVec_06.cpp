#include <iostream>

using namespace std;

int main (){
   
    int n, aux;
    cout<<"Ingrese la extension de v1 ";
    cin>> n;
    int v1[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;

    //metodo de burbuja
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=(n-1); j++){
            if (v1[j] < v1[j+1]){
                aux=v1[j];
                v1[j]= v1[j+1];
                v1[j+1] = aux;
            }
        }
    }

    cout<< "Datos ordenados de mayor a menor"<<endl;
    for (int i = 1; i<=n; i++){
        cout << v1[i]<< ", ";
    }

    cout<< " "<<endl;
    cout<< "Datos ordenados de menor a mayor"<<endl;
    for (int i = n; i>0; i--){
        cout << v1[i]<< ", ";
    }
}