#include <iostream>

using namespace std;
int main (){

   int n,suma;
    cout<<"Ingrese la extension de v1 ";
    cin>> n;
    int v1[n], cont[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;

    for (int i = 1; i<=n; i++) {
        suma =0;
        for (int j = 1; j<=n; j++) {
            if (v1[i] == v1[j] ) {
                suma= suma+1;
            }  
        }
        
        cont[i]=suma;  
    }
//Impresion de resultados
    cout << "Valor  /  Frecuencia"<<endl;
    for (int i = 1; i<=n; i++) {
        cout<<v1[i]<<"   /    "<<cont[i]<<endl;
    }

}