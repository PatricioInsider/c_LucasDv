#include <iostream>

using namespace std;
int main (){
    float n,pri,aux,aux2,contador,suma,multi,razon;
    cout<<"Numero de datos que deseas imprimir: ";
    cin>>n;
    cout<<"Escribe el primer termino: ";
    cin>>pri;
    aux=pri;
    cout<<"EScribir la razon de la progresion: ";
    cin>>razon;
    aux2=razon;
    contador=0;

    cout<<"Progresion aritmetica: ";
    while (contador !=n)
    {
        cout<<pri<<", ";
        pri = pri*razon;
        contador= contador +1;
    }

    cout<<" "<<endl;
    contador = 0;
    suma=0;
    pri = aux;
	razon=aux2;
    cout<<"Suma: ";
    while (contador !=n)
    {
        cout<<pri<<"+ ";
        suma= suma+pri;
        pri = pri+razon;
        contador= contador +1;
    }
    cout<<"= "<<suma<<endl;
    contador = 0;
    multi=1;
    pri =aux;
    razon=aux2;

    cout<<"Multiplicacion: ";
    while (contador !=n)
    {
        cout<<pri<<" * ";
        multi=multi*pri;
        pri = pri*razon;
        contador= contador +1;
    }
    cout<<"= "<<multi<<endl;
}
















