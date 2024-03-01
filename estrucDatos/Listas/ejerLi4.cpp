//Autor: Patricio Quishpe

#include <iostream>
#include "Lista.h"

#define FIN 99999
#define EXT 10

using namespace std;



int main()
{
    system("color f0");
    void ingresarElementosRecursivo(Lista *lista);
    void imprimirListaRecursivo(Nodo *nodo);
    bool estaOrdenadaAscendenteRecursivo(Nodo *nodo);
    bool estaOrdenadaDescendenteRecursivo(Nodo *nodo);


    Lista listas[EXT]; // Vector para almacenar las listas
    int cantidadListas;
    int ascendente = 0;
    int descendente = 0;
    int desordenada = 0;

    cout << "Ingrese la cantidad de listas (máximo " << EXT << "): ";
    cin >> cantidadListas;

    if (cantidadListas <= 0 || cantidadListas > EXT)
    {
        cerr << "Error: La cantidad de listas debe estar entre 1 y " << EXT << "." << endl;
        return 1;
    }

    // Ingresar elementos en cada lista de manera recursiva y contar el tipo de orden
    for (int i = 0; i < cantidadListas; ++i)
    {
        cout << "Ingrese elementos para la lista " << i + 1 << ":" << endl;
        ingresarElementosRecursivo(&listas[i]);

        if (estaOrdenadaAscendenteRecursivo(listas[i].getPrimero()))
        {
            ascendente++;
        }
        else if (estaOrdenadaDescendenteRecursivo(listas[i].getPrimero()))
        {
            descendente++;
        }
        else
        {
            desordenada++;
        }
    }

    // Imprimir resultados
    cout << "Listas ordenadas ascendentemente: " << ascendente << endl;
    cout << "Listas ordenadas descendentemente: " << descendente << endl;
    cout << "Listas desordenadas: " << desordenada << endl;
     system("pause");

    return 0;
}


// Función para ingresar elementos en la lista de manera recursiva
void ingresarElementosRecursivo(Lista *lista)
{
    Tipo elemento;
    cout << "Ingrese un valor para agregar a la lista. Finalice con [" << FIN << "]: ";
    cin >> elemento;

    if (elemento != FIN)
    {
        lista->insertarAlFinal(elemento);
        ingresarElementosRecursivo(lista); // Llamada recursiva
    }
}

// Función recursiva para imprimir la lista
void imprimirListaRecursivo(Nodo *nodo)
{
    if (nodo != nullptr)
    {
        cout << "> " << nodo->getDato() << endl;
        imprimirListaRecursivo(nodo->getPunto()); // Llamada recursiva
    }
}

// Función recursiva para determinar si una lista está ordenada en forma ascendente
bool estaOrdenadaAscendenteRecursivo(Nodo *nodo)
{
    if (nodo != nullptr && nodo->getPunto() != nullptr)
    {
        if (nodo->getDato() > nodo->getPunto()->getDato())
        {
            return false;
        }

        return estaOrdenadaAscendenteRecursivo(nodo->getPunto()); // Llamada recursiva
    }

    return true;
}

// Función recursiva para determinar si una lista está ordenada en forma descendente
bool estaOrdenadaDescendenteRecursivo(Nodo *nodo)
{
    if (nodo != nullptr && nodo->getPunto() != nullptr)
    {
        if (nodo->getDato() < nodo->getPunto()->getDato())
        {
            return false;
        }

        return estaOrdenadaDescendenteRecursivo(nodo->getPunto()); // Llamada recursiva
    }

    return true;
}
