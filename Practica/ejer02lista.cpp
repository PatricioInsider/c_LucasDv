//Permitir el ingreso de una lista de valores, y con éstos, 
//formar una lista con los valores primos y otra con los valores compuestos que contiene

#include <iostream>
#include "Lista.h"
#define FIN 999	
using namespace std;

int main(){
    Lista l;
    void ingresarLista(Lista *l);
    ingresarLista(&l);

}

void ingresarLista(Lista *l){

    Tipo aux;
    cout<<"Ingrese el valor a ingresar en la lista. Terminar ["<<FIN<<"]"<<endl;

    if (aux != FIN)
    {
        l->insertarAlInicio(aux);
        ingresarLista(l);
    }
}


