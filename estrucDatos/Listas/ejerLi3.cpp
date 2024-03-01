//Autor: Patricio Quishpe

#include <iostream>
#include "Lista.h"

using namespace std;
#define FIN 99999



int main()
{
    system("color f0");
    void ingresarElementosRecursivo(Lista* lista);
    void imprimirListaRecursivo(Nodo* nodo);
    void intercambiarNodosParesRecursivo(Nodo* actual1, Lista* lista1, Nodo* actual2, Lista* lista2);
    void intercambiarNodosPares(Lista* lista1, Lista* lista2);


    Lista lista1; // Crear la primera lista
    Lista lista2; // Crear la segunda lista

    // Ingresar elementos en la primera lista de manera recursiva
    cout << "Ingrese elementos para la lista 1:" << endl;
    ingresarElementosRecursivo(&lista1);

    // Ingresar elementos en la segunda lista de manera recursiva
    cout << "Ingrese elementos para la lista 2:" << endl;
    ingresarElementosRecursivo(&lista2);

    // Imprimir las listas antes del intercambio
    cout << "\nListas antes del intercambio:" << endl;
    cout << "Lista 1:" << endl;
    imprimirListaRecursivo(lista1.getPrimero());
    cout << "Lista 2:" << endl;
    imprimirListaRecursivo(lista2.getPrimero());

    // Intercambiar nodos que contienen valores pares entre las listas
    intercambiarNodosPares(&lista1, &lista2);

    // Imprimir las listas después del intercambio
    cout << "\nListas después del intercambio:" << endl;
    cout << "Lista 1:" << endl;
    imprimirListaRecursivo(lista1.getPrimero());
    cout << "Lista 2:" << endl;
    imprimirListaRecursivo(lista2.getPrimero());
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

// Función para imprimir la lista de manera recursiva
void imprimirListaRecursivo(Nodo* nodo)
{
    if (nodo != nullptr)
    {
        cout << "> " << nodo->getDato() << endl;
        imprimirListaRecursivo(nodo->getPunto()); // Llamada recursiva
    }
}

// Función recursiva para intercambiar nodos con valores pares entre dos listas
void intercambiarNodosParesRecursivo(Nodo* actual1, Lista* lista1, Nodo* actual2, Lista* lista2)
{
    if (actual1 == nullptr)
    {
        // Llegó al final de la lista 1
        return;
    }

    if (actual1->getDato() % 2 == 0)
    {
        if (actual2 == nullptr)
        {
            // La lista 2 no tiene más elementos, salir de la recursión
            return;
        }

        if (actual2->getDato() % 2 == 0)
        {
            // Intercambiar nodos que contienen valores pares
            Tipo temp = actual1->getDato();
            actual1->setDato(actual2->getDato());
            actual2->setDato(temp);
        }
    }

    // Llamadas recursivas para avanzar en ambas listas
    intercambiarNodosParesRecursivo(actual1->getPunto(), lista1, lista2->getPrimero(), lista2);
}

// Función principal que inicia la recursión
void intercambiarNodosPares(Lista* lista1, Lista* lista2)
{
    intercambiarNodosParesRecursivo(lista1->getPrimero(), lista1, lista2->getPrimero(), lista2);
}