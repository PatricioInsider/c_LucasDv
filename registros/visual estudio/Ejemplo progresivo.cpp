//Lectura de un archivo
#include <iostream>
#include <fstream>
#include <string.h>
//Ingreso de Dstos e inicializacion de estos en la misma estructura
using namespace std;
struct autos
{
    string marca;
    int numSerie;
}auto1 = {"Honda",156451621},
auto2 = {"Volkswagen", 452624};
//aqui declaramos las variables globales llamadas auto1 auto2

int main(){
    cout<<"\tAutos"<<endl;
    cout<< "Auto1"<<endl;
    cout<<"Marca: "<<auto1.marca<<endl;
    cout<<"Numero de Serie: "<<auto1.numSerie<<endl;

    cout<< "Auto2"<<endl;
    cout<<"Marca: "<<auto2.marca<<endl;
    cout<<"Numero de Serie: "<<auto2.numSerie<<endl<<endl;

    system("pause");

}