//Patricio Quishpe 7364
//ejer 3
//Dado un AB ingresado por el usuario, devolver una lista con la rama mas larga del mismo. Si existen varias ramas respuesta,
// devolver solamente la primera

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#include "Lista.h"

// Prototipos de funciones
void leerAB(ArbolBinario *ab);
void imprimirAB(ArbolBinario ab);
void imprimirLista(Nodo* actual);
Lista encontrarRamaLarga(NodoBinario* nodo);
void ramaLarga(ArbolBinario ab);

int main() {
    system("color f0");
    ArbolBinario ab;

    // Llamado a funciones
    leerAB(&ab);
    imprimirAB(ab);
    ramaLarga(ab);

    cout << endl;
    system("pause");
}

// Función para obtener el tamaño de la lista
int tamLista(Nodo* inicio) {
    int contador = 0;
    while (inicio != nullptr) {
        contador++;
        inicio = inicio->getPunt();
    }
    return contador;
}

Lista encontrarRamaLarga(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return Lista(); // Devuelve una lista vacía si el nodo es nulo
    }

    // Recorre de forma recursiva los subárboles izquierdo y derecho
    Lista izquierda = encontrarRamaLarga(nodo->getIzq());
    Lista derecha = encontrarRamaLarga(nodo->getDer());

    // Compara las longitudes y devuelve la más larga
    if (tamLista(izquierda.getPrimero()) >= tamLista(derecha.getPrimero())) {
        izquierda.insertarAlInicio(nodo->getDato());
        return izquierda;
    } else {
        derecha.insertarAlInicio(nodo->getDato());
        return derecha;
    }
}

// Imprime la jerarquía del árbol
void imprimirAB(ArbolBinario ab) {
    cout << endl << "IMPRESION ARBOL----------" << endl;
    ab.imprimirABJerarquia(ab.getRaiz(), 0);
}

// Lee el árbol desde la entrada estándar
void leerAB(ArbolBinario *ab) {
    cout << endl << "INGRESO ARBOL--------------" << endl;
    ab->leer();
}

// Imprime la lista de nodos
void imprimirLista(Nodo* actual) {
    if (actual != nullptr) {
        cout << " >" << actual->getDato();
        imprimirLista(actual->getPunt());
    }
}

// Encuentra y muestra la rama más larga del árbol
void ramaLarga(ArbolBinario ab) {
    if (ab.esVacio()) {
        cout << endl << "El árbol está vacío" << endl;
        return;
    }

    Lista ramaLarga = encontrarRamaLarga(ab.getRaiz());

    cout << endl << "La rama más larga es: ";
    imprimirLista(ramaLarga.getPrimero());
    cout << endl;
}
