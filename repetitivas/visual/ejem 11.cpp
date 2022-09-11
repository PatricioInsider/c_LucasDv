#include <iostream>

using namespace std;
int main (){
    float inicio,final,conta;
    cout<<"Vamos a declarar un intervalo"<<endl;

    do{
        cout<<"inicio del intervalo, escribe un numero positivo: ";
        cin>>inicio;
    } while (not (inicio >0));

    do
    {
        cout<<"Finalizacion del intervalo, escribe un numero positivo(recuerda debe ser mayor al inicio): ";
        cin>>final;
    } while (not(final> inicio));

    for (int i=1; i<(final+1);i+=1){
        conta = 0;
        for (int j=1;j<=i; j+=1){
            if ((i%j) ==0){
                conta = conta +1;
            }    
        }
        if(conta==2) {
            cout<< "El numero "<< i<< " es primo"<<endl;
        }
    }
}