//Autor: Patricio Quishpe
#include <iostream>
#include "Lista.h"

using namespace std;
#define FIN 99999



int main()
{
    system("color f0");
    void ingresarElementosRecursivo(Lista* lista);
    void invertirListaRecursivo(Nodo* actual, Nodo** nuevoInicio);
    void invertirLista(Lista* lista);
    void imprimirListaRecursivo(Nodo* nodo);
    

    Lista lista; // Crear una lista para almacenar los valores

    // Ingresar elementos en la lista de manera recursiva
    cout << "Ingrese elementos para la lista:" << endl;
    ingresarElementosRecursivo(&lista);

    // Imprimir la lista antes de la inversión
    cout << "\nLista antes de la inversión:" << endl;
    imprimirListaRecursivo(lista.getPrimero());

    // Invertir los nodos de la lista
    invertirLista(&lista);

    // Imprimir la lista después de la inversión
    cout << "\nLista después de la inversión:" << endl;
    imprimirListaRecursivo(lista.getPrimero());
     system("pause");

    return 0;
}

// Función para ingresar elementos en la lista de manera recursiva
void ingresarElementosRecursivo(Lista* lista)
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

// Función recursiva para invertir los nodos de una lista
void invertirListaRecursivo(Nodo* actual, Nodo** nuevoInicio)
{
    if (actual == NULL)
    {
        return;
    }

    Nodo* siguiente = actual->getPunto();

    if (siguiente == NULL)
    {
        *nuevoInicio = actual;
        return;
    }

    invertirListaRecursivo(siguiente, nuevoInicio);
    siguiente->setPunto(actual);
    actual->setPunto(NULL);
}

// Función principal que inicia la recursión
void invertirLista(Lista* lista)
{
    Nodo* nuevoInicio = NULL;
    invertirListaRecursivo(lista->getPrimero(), &nuevoInicio);
    lista->setPrimero(nuevoInicio);
}

// Función para imprimir la lista de manera recursiva
void imprimirListaRecursivo(Nodo* nodo)
{
    if (nodo != NULL)
    {
        cout << "> " << nodo->getDato() << endl;
        imprimirListaRecursivo(nodo->getPunto()); // Llamada recursiva
    }
}