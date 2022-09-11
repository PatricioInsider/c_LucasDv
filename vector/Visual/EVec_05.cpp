#include <iostream>

using namespace std;
int main (){
   float aux,suma;
    //Ingreso de datos
    int n;
    cout<<"Ingrese la extension de v1 ";
    cin>> n;
    int v1[n],guardado[n],gua[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;

    //proceso de conteo
    for (int i =1; i <= n; i++) {
        suma =0;
        for (int j =1; j<= n; j++) {
            if (v1[i] ==v1[j]) {
                suma = suma+1;

            }  
        }
        gua[i]= suma;
    }
    
    for (int i = 1; i<=n; i++){
        guardado[i] = gua[i];
    }
    //metodo de burbuja
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=(n-1); j++){
            if (guardado[j] < guardado[j+1]){
                aux=guardado[j];
                guardado[j] = guardado[j+1];
                guardado[j+1] = aux;
            }
        }
    }

    for (int i = 1; i<=n; i++){
        if (guardado[1] == gua[i]) {
            cout<< "El dato "<<v1[i]<< " se repite "<< guardado[i]<< " y este se ve por primera vez en la posicion "<< i<<endl;
            break;        
        }
    }

}