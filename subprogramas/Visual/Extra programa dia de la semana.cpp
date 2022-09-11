#include <iostream>
#include <string.h>
//Escribir un algoritmo que dado el orden de un día de la semana, escribir el  día correspondiente.
using namespace std;

int diaSemana(int opc)
{
    string semana[]= {"Lunes", "Martes", "Miercoles", "Jueves","Viernes","Sabado", "Domingo"};
    
    for (int i = 0; i < 7; i++)
    {
        if ((opc-1) == i)
        {
            cout<< "El dia escogido es "<<semana[i]<<endl;
        }
        
    }
    
}
int main(){
    int opc;
    cout<< "Escribir el orden de un dia de la semana(tiene 7 dias)"<<endl;
    cin>>opc;
    diaSemana(opc);

}