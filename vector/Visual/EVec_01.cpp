#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"Ingrese la magnitud de su vector: ";
    cin>> n;
    int v1[n];
    int v2[n];
    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = " << endl;
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;
    int j=n;
    for(int i =1;i<=n; i++){
        v2[j]=v1[i];
        j=j-1;
    }
    cout<<"Orden ingresado:"<<endl;
    for(int i =1;i<=n; i++){
        cout<< v1[i]<<", ";
    }

    cout<<" "<<endl;
    cout<<"Orden regresado:"<<endl;
    for(int i =1;i<=n; i++){
        cout<< v2[i]<<", ";
    }
}