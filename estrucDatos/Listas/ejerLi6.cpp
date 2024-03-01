//Patricio Quishpe

#include <iostream>
#include "LISTA.h"
using namespace std;
#define FIN 99999


int main()
{
    system("color f0");
void ingresarLista(Lista *l1);
void imprimirLista(Nodo *act);
void Divisores(int numero, Lista *divisores, int i = 1);
void imprimirDivisores(Lista *divisores);
void procesarLista(Nodo *nodo, int pos = 1);



    Lista l1; 

    ingresarLista(&l1);
    cout << "Valores de la lista:";
    imprimirLista(l1.getPrimero()); 

    procesarLista(l1.getPrimero()); 

    system ("pause");
}

void ingresarLista(Lista l1)
{
    Tipo aux; 
    cout << "Ingrese un valor para poner en la lista. FINALICE CON [" << FIN << "]: ";
    cin >> aux;

    if (aux != FIN)
    {
        l1->insertarAlFinal(aux);
        ingresarLista(l1);
    }
}

void imprimirLista(Nodo *act)
{
    if (act != NULL)
    {
        cout << " " << act->getDato();
        imprimirLista(act->getPunto()); 
    }
}






void Divisores(int numero, Lista *divisores, int i=0)
{
    if (i > numero)
    {
        return;
    }
    if (numero % i == 0)
    {
        divisores->insertarAlFinal(i);
    }
    Divisores(numero, divisores, i + 1);
}


void imprimirDivisores(Lista *divisores)
{
    imprimirLista(divisores->getPrimero());
}
void procesarLista(Nodo *nodo, int pos)
{
    if (nodo == NULL)
    {
        return;
    }

    Lista divisores;
    Divisores(nodo->getDato(), &divisores);
    cout << "\nDivisores del numero " << nodo->getDato() << ": ";
    imprimirDivisores(&divisores);
    

    procesarLista(nodo->getPunto(), pos + 1);
}



