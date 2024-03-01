//Patricio Quishpe 7364
//ejer 10
// Dados un AB y un valoresor X, 
//determinar la rama que contiene la mayor cantidad de contador de X
using namespace std;
#include <iostream>
#include "ArbolBinario.h"



// Funciones prototipo
void lecturaAB(ArbolBinario* a);
void impresionAB(ArbolBinario a);
void aparicionesX(NodoBinario* nodo, Tipo X, Tipo* act, int& tamanoActual, Tipo*& ramaMax, int& max);

int main() {
    system("color f0");

   
    ArbolBinario a;
    Tipo valorX;

    
    lecturaAB(&a);
   
    impresionAB(a);

    cout << endl << "Ingrese un valor: ";
    cin >> valorX;

    int max = 0;
    Tipo* ramaMax = nullptr;
    Tipo* act = new Tipo[a.contarNodos(a.getRaiz())];
    int tamanoActual = 0;

    aparicionesX(a.getRaiz(), valorX, act, tamanoActual, ramaMax, max);

    if (max > 0) {
        cout << "La rama con más apariciones de " << valorX << " es:";
        for (int i = 0; i < max; ++i) {
            cout << " " << ramaMax[i];
        }
        cout << endl;
        cout << "El número de apariciones de " << valorX << " es: " << max << endl;
    } else {
        cout << "El valor " << valorX << " no aparece en el árbol." << endl;
    }

    delete[] act;
    delete[] ramaMax;

    return 0;
}

void lecturaAB(ArbolBinario* a) {
    cout << endl << "INGRESO DEL ARBOL----------" << endl;
    a->leer();
}

void impresionAB(ArbolBinario a) {
     cout << endl << "IMPRESION JERARQUICA" << endl;
    a.imprimirABJerarquia(a.getRaiz(), 1);
}

void aparicionesX(NodoBinario* nodo, Tipo X, Tipo* act, int& actual, Tipo*& ramaMax, int& max) {
    if (nodo == nullptr) {
        return;
    }

    act[actual++] = nodo->getDato();

    if (nodo->getDato() == X) {
        if (actual > max) {
            delete[] ramaMax;
            max = actual;
            ramaMax = new Tipo[max];
            for (int i = 0; i < actual; ++i) {
                ramaMax[i] = act[i];
            }
        }
    }

    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        if (actual > max) {
            max = actual;
            delete[] ramaMax;
            ramaMax = new Tipo[max];
            for (int i = 0; i < actual; ++i) {
                ramaMax[i] = act[i];
            }
        }
    }

    aparicionesX(nodo->getIzq(), X, act, actual, ramaMax, max);
    aparicionesX(nodo->getDer(), X, act, actual, ramaMax, max);

    actual--;
}
