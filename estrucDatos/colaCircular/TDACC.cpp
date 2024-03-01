#include <iostream>
#include "ColaCircular.h"

using namespace std;

// Prototipos de funciones


int main() {
    void realizarOperacion(ColaCircular& cache, int operacionNumero, int n);
    void mostrarEstadoCacheRecursiva(ColaCircular& cache, int n, int elementosMostrados);
    int leerN();
    int n = leerN();

    // Validar que el tamaño del caché sea mayor o igual a 0
    if (n == 0) {
        cout << "El tamaño del caché es 0. No se realizarán operaciones. Fin del programa." << endl;
        return 0;
    }

    ColaCircular cache;

    cout << "Simulación de Almacenamiento en Caché" << endl;

    // Llamada a la función recursiva para realizar operaciones
    realizarOperacion(cache, 1, n);

    cout << "Operaciones completadas. Fin del programa." << endl;

    return 0;
}

int leerN() {
    int n;
    cout << "Ingresa la capacidad del caché: ";
    cin >> n;

    // Validar que el tamaño del caché sea mayor o igual a 0
    if (n < 0) {
        cout << "Número inválido. Intenta de nuevo." << endl;
        return leerN();
    }

    return n;
}

void realizarOperacion(ColaCircular& cache, int operacionNumero, int n) {
    cout << "---------------------------------------------" << endl;
    cout << "Operación " << operacionNumero << ":" << endl;

    // Agregar elemento a la caché
    int nuevoElemento = operacionNumero * 10;
    cache.agregar(nuevoElemento);
    cout << "Agregado elemento " << nuevoElemento << " a la caché." << endl;

    // Mostrar el estado actual de la caché
    cout << "Estado actual de la caché: ";
    mostrarEstadoCacheRecursiva(cache, n,0);
    cout << endl;

    cout << "---------------------------------------------" << endl;

    // Llamada recursiva para la siguiente operación
    if (operacionNumero < n) {
        realizarOperacion(cache, operacionNumero + 1, n);
    }
}

void mostrarEstadoCacheRecursiva(ColaCircular& cache, int n, int elementosMostrados=0) {
    if (elementosMostrados < n && !cache.colaVacia()) {
        cout << cache.frenteCola() << " ";
        cache.quitar();
        mostrarEstadoCacheRecursiva(cache, n, elementosMostrados + 1);
    }
}
