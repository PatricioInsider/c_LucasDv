//Autor: Patricio Quishpe
#include <iostream>
#include "Lista.h"

#define FIN 99999

using namespace std;



int main()
{
    system("color f0");
    void ingresarElementosRecursivo(Lista *lista);
    bool esPrimo(int num);
    void separarPrimosCompuestosRecursivo(Nodo *actual, Lista *primos, Lista *compuestos);
    void imprimirListaRecursivo(Nodo *nodo);


    Lista listaEntrada;    // Lista para almacenar los valores de entrada
    Lista listaPrimos;     // Lista para almacenar números primos
    Lista listaCompuestos; // Lista para almacenar números compuestos

    // Ingresar elementos en la lista de manera recursiva
    ingresarElementosRecursivo(&listaEntrada);

    // Separar los números primos y compuestos de manera recursiva
    separarPrimosCompuestosRecursivo(listaEntrada.getPrimero(), &listaPrimos, &listaCompuestos);

    // Imprimir las listas de manera recursiva
    cout << "\nLista de números primos:" << endl;
    imprimirListaRecursivo(listaPrimos.getPrimero());

    cout << "\nLista de números compuestos:" << endl;
    imprimirListaRecursivo(listaCompuestos.getPrimero());
     system("pause");

    return 0;
}


// Función recursiva para ingresar elementos en la lista
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

// Función para verificar si un número es primo
bool esPrimo(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Función para separar los números primos y compuestos de manera recursiva
void separarPrimosCompuestosRecursivo(Nodo *actual, Lista *primos, Lista *compuestos)
{
    if (actual != nullptr)
    {
        int dato = actual->getDato();

        if (esPrimo(dato))
        {
            primos->insertarAlFinal(dato);
        }
        else
        {
            compuestos->insertarAlFinal(dato);
        }

        separarPrimosCompuestosRecursivo(actual->getPunto(), primos, compuestos); // Llamada recursiva
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