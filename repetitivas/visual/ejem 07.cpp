#include <iostream>
#include <cmath>

using namespace std;
int main (){
    int n;
    float num,conta,dato;

    cout<<" a^(a-1) - 2a^(a-2) + 3a^(a-3) - ......."<<endl;
    cout<<"Numero de datos a sumar en la serie"<<endl;
    cin>>n;
    cout<<"De que numero se decea la serie"<<endl;
    cin>> num;

    conta =0;
    for(int i=1;i<(n+1);i+=1){
        dato = i*pow(num,(num-i));
        if ((i%2)==0){
            dato= dato*(-1);
        }
        cout<<"Termino n"<<i<< "= "<<  dato<<endl;
        conta= conta + dato;
    }
    cout<<"La suma de los terminos es: "<< conta;

}