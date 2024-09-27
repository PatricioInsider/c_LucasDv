// Calcular el rango (diferencia entre valor mayor y menor) de los valores 
//que constan en una lista ingresada
#include <iostream>
#include "Lista.h"
#define EXIT 999
using namespace std;

int main(){
    
    Lista l;

    void ingresarLista(Lista *l);
    int calcularRango(Lista l);
    ingresarLista(&l); //pasamos por referncia editando la lista principal
    if (!l.esVacia())
    {
        cout<<"Calcular RANGO "<<endl;
        cout<<"El rango es :"<<calcularRango(l)<<endl;
    }

    return 0;
}


void ingresarLista (Lista *l){

    Tipo aux;
    cout<<endl<<"Ingrese el valor para insertar en la lista.Finalice["<<EXIT<<"]: ";
    cin>>aux;
    if (aux!=999)
    {
        l->insertarEnOrden(aux);
        ingresarLista(l);
    }
}

int calcularRango(Lista l){
    Tipo ini;
    Tipo fin;
    ini = l.getPrimero()->getDato();
    fin = l.ultimo()->getDato();
    return fin-ini;

}