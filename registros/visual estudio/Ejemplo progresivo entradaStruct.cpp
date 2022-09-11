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
};
//aqui declaramos las variables globales llamadas auto1 auto2

int main(){

    cout<<"Ingresar la marca del auto: ";
    cin.getline(autos.marca, "\n");

    cout<<"Ingresar el numero de serie: ";
    cin.getline(autos.numSerie, "\n")

    cout<<"\tAutos"<<endl;
    cout<< "Auto1"<<endl;
    cout<<"Marca: "<<auto1.marca<<endl;
    cout<<"Numero de Serie: "<<auto1.numSerie<<endl;;

    system("pause");

}