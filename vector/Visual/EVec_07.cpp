#include <iostream>

using namespace std;
int main (){
    int n, aux;
    cout<<"Ingrese la extension de v1 ";
    cin>> n;
    float v1[n], v1volteado[n],v2[n],v3[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;

    for (int i = 1; i<=n; i++)
    {
        v1volteado[i]= v1[i];
		v2[i] = v1[i];
    }

    //metodo de burbuja
    //forma descendente de menor a mayor
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=(n-1); j++){
            if (v1volteado[j] < v1volteado[j+1]){
                aux=v1volteado[j];
                v1volteado[j] = v1volteado[j+1];
                v1volteado[j+1] = aux;
            }
        }
    }
    //forma descendente de mayor a menor
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
        v3[i] = v1volteado[i]*v2[i];
    }

    //EStructura de impresion para control
    cout<< "v1 /v2 /v3            Vec Original" <<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<< v1volteado[i]<<" x "<< v2[i]<<" = "<<v3[i]<< "                 "<< v1[i]<< endl;
    }
}