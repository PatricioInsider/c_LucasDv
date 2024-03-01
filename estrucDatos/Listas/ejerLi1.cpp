//Autor: Patricio Quishpe
#include <iostream>
#include "Lista.h"

using namespace std;
#define FIN 99999 // Definir un valor de fin para la entrada de datos


int main()
{
    system("color f0");

void ingresarElementosRecursivo(Lista* lista);
void imprimirListaRecursivo(Nodo* nodo);
Tipo calcularRangoRecursivo(Nodo* actual, Tipo minimo, Tipo maximo);
    Lista listaValores; // Crear una lista para almacenar los valores

    // Ingresar elementos en la lista de manera recursiva
    ingresarElementosRecursivo(&listaValores);

    // Imprimir la lista de manera recursiva
    cout << "\nLista ingresada:" << endl;
    imprimirListaRecursivo(listaValores.getPrimero());

    // Calcular y mostrar el rango de la lista de manera recursiva
    Tipo rango = calcularRangoRecursivo(listaValores.getPrimero(), listaValores.getPrimero()->getDato(), listaValores.getPrimero()->getDato());
    cout << "\nEl rango de la lista es: " << rango << endl;
    system("pause");
    return 0;
}

// Función recursiva para ingresar elementos en la lista
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

// Función recursiva para imprimir la lista
void imprimirListaRecursivo(Nodo* nodo)
{
    if (nodo != nullptr)
    {
        cout << "> " << nodo->getDato() << endl;
        imprimirListaRecursivo(nodo->getPunto()); // Llamada recursiva
    }
}

// Función recursiva para calcular el rango de una lista
Tipo calcularRangoRecursivo(Nodo* actual, Tipo minimo, Tipo maximo)
{
    if (actual == nullptr)
    {
        // Fin de la lista, devuelve el rango calculado
        return maximo - minimo;
    }

    Tipo dato = actual->getDato();

    // Actualizar los valores mínimo y máximo según sea necesario
    if (dato < minimo)
    {
        minimo = dato;
    }
    if (dato > maximo)
    {
        maximo = dato;
    }

    // Llamada recursiva con el siguiente nodo
    return calcularRangoRecursivo(actual->getPunto(), minimo, maximo);
}
