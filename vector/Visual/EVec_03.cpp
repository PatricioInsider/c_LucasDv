#include <iostream>

using namespace std;
int main (){
    
    float aux;
    aux=0;
    //Ingreso de datos
    int n;
    cout<<"Ingrese la magnitud de su vector: ";
    cin>> n;
    int v1[n];
    int v2[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;


    for (int i = 1; i<=n; i++)
    {
        v2[i]= v1[i];
    }

    //forma descendente de menor a mayor

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=(n-1); j++){
            if (v2[j] > v2[j+1]){
                aux=v2[j];
                v2[j] = v2[j+1];
                v2[j+1] = aux;
            }
        }
    }

    for (int i = 1; i<=n; i++)
    {
        if (v1[i]== v2[1]){
            cout<<"El numero menor es: "<<v1[i]<< " en la posicion "<<i<<endl;
        }
        if (v1[i]== v2[n]){
            cout<<"El numero mayor es: "<<v1[i]<< " en la posicion "<<i<<endl;
        }
        
    }
}