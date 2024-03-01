//Patricio Quishpe 7364
//ejer 1
//Generar todos los caminos a todas las hojas de un derivadas de cualquier nodo de un AB
// Importar el espacio de nombres estándar
using namespace std;

#include <iostream>
#include "ArbolBinario.h"

int main(){ // Programa principal
    // Configuración del color de la consola
    system("color f0");

    // Declaración del Árbol Binario (AB)
    ArbolBinario a;
    // Arreglo de nodos para almacenar un camino
    NodoBinario* camino[100];

    // Prototipos de funciones
    void lecturaAB(ArbolBinario *A); // Función para ingresar datos al AB
    void impresionAB(ArbolBinario a); // Función para imprimir el AB
    void imprimirCamino(NodoBinario* camino[], int longitud, int i); // Función para imprimir un camino
    void generarCaminosHojas(NodoBinario* nodo, NodoBinario* camino[], int longitudCamino); // Función para generar caminos hacia hojas

    // Mensaje de ingreso del Árbol Binario de Búsqueda (ABB)
    cout << endl << "INGRESO DEL ABB";
    // Llamada a la función para ingresar datos al AB
    lecturaAB(&a);

    // Llamada a la función para imprimir el AB
    impresionAB(a);

    // Llamada a la función para generar caminos hacia hojas e imprimirlos
    generarCaminosHojas(a.getRaiz(), camino, 0);

    cout << endl;
    // Pausa para visualización
    system("pause");
}

// Función para ingresar datos al Árbol Binario de Búsqueda (ABB)
void lecturaAB(ArbolBinario *A){
    cout << "\nIngreso de datos-----";
    A->leer();
}

// Función para imprimir el Árbol Binario de Búsqueda (ABB)
void impresionAB(ArbolBinario a){
    cout << endl << "IMPRESION DEL ABB" << endl;
    // Llamada a la función para imprimir el AB en jerarquía
    a.imprimirABJerarquia(a.getRaiz(), 0);
}

// Función para imprimir un camino
void imprimirCamino(NodoBinario* camino[], int longitud, int i){
    if (i < longitud){
        // Imprimir el dato del nodo actual en el camino
        cout << camino[i]->getDato() << " ";
        // Llamada recursiva para imprimir el resto del camino
        imprimirCamino(camino, longitud, ++i);
    }
}

// Función para generar caminos hacia hojas y los imprime
void generarCaminosHojas(NodoBinario* nodo, NodoBinario* camino[], int longitudCamino) {
    if (nodo == nullptr) {
        return;
    }

    // Añadir el nodo actual al camino
    camino[longitudCamino] = nodo;
    longitudCamino++;

    // Si es una hoja, imprimir el camino
    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        cout << "Camino hacia hoja: ";
        // Llamada a la función para imprimir el camino
        imprimirCamino(camino, longitudCamino, 0);
        cout << endl;
    } else {
        // Si no es una hoja, continuar explorando los caminos en los subárboles izquierdo y derecho
        generarCaminosHojas(nodo->getIzq(), camino, longitudCamino);
        generarCaminosHojas(nodo->getDer(), camino, longitudCamino);
    }
}
