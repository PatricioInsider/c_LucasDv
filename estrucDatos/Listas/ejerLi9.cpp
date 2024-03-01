// Patricio Quishpe

#include <iostream>
#include <climits>
#include "LISTA.h"
using namespace std;
#define FIN 99999

int main()
{
    system("color f0");
    Lista l1; 

    void ingresarLista(Lista * l1);
    void imprimirLista(Nodo * act);
    Tipo obtenerValorNesimo(Nodo * nodo, int N);
    void encontrar(Nodo * nodo, Tipo valorNesimo, Tipo & valorMasCercano, int &diferenciaMinima);
    ingresarLista(&l1); 
    cout << "Valores de la Lista:";
    imprimirLista(l1.getPrimero()); 

    int N;
    cout << "\nIngrese la posición N para encontrar el valor más aproximado: ";
    cin >> N;

    Tipo valorNesimo = obtenerValorNesimo(l1.getPrimero(), N);
    if (valorNesimo == -1)
    {
        cout << "Nodo no encontrado." << endl;
    }
    else
    {
        Tipo valorMasCercano;
        int diferenciaMinima = INT_MAX;
        encontrar(l1.getPrimero(), valorNesimo, valorMasCercano, diferenciaMinima);
        cout << "El valor más cercano al nodo " << N << " es: " << valorMasCercano << endl;
    }

    system ("pause");
}

void ingresarLista(Lista *l1)
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
Tipo obtenerValorNesimo(Nodo *nodo, int N)
{
    if (nodo == NULL || N < 0)
    {
        
        return -1; 
    }
    if (N == 0)
    {
        return nodo->getDato();
    }
    return obtenerValorNesimo(nodo->getPunto(), N - 1);
}
void encontrar(Nodo *nodo, Tipo valorNesimo, Tipo &valorMasCercano, int &diferenciaMinima)
{
    if (nodo == NULL)
    {
        return;
    }

    int diferenciaActual = abs(nodo->getDato() - valorNesimo);
    if (diferenciaActual < diferenciaMinima)
    {
        diferenciaMinima = diferenciaActual;
        valorMasCercano = nodo->getDato();
    }

    encontrar(nodo->getPunto(), valorNesimo, valorMasCercano, diferenciaMinima);
}
