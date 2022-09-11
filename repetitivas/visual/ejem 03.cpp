#include <iostream>

using namespace std;
int main (){
    int conta =0;
    int a,b,aux,n,opc;
    a=0;
    b=1;
    n =0;
    aux=0;
    opc=0;

    cout<<"Escribe los n primeros terminos que deseas de la serie "<< endl;
    cin>>n;
    cout << "Los numeros elegidos son: ";
    do{
        cout<<a<<", ";
        aux = a +b;
        a = b;
        b = aux;
        conta = conta +1;
        if(conta ==n){
            opc=1;
            
        }
    } while(opc != 1);
    
}