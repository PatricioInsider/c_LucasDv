//Patricio Quishpe 7364
//ejer 6
//Se dice que un AB1 es prefijo de un AB2 si AB1 coincide con la parte inicial de AB2 tanto en contenido y situación de sus nodos.
// Elabore un programa que determine si esta condición se cumple con dos AB ingresados por el usuario.

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
// Clase para verificar si un árbol es prefijo de otro
class Prefijo {
public:
    // Función que determina si un árbol es prefijo de otro
    bool esPrefijo(NodoBinario* ab1, NodoBinario* ab2) {
        // Caso base: AB1 es prefijo de cualquier árbol
        if (ab1 == NULL) {
            return true;
        }

        // Caso base: AB1 no puede ser prefijo si AB2 es nulo
        if (ab1 != NULL && ab2 == NULL) {
            return false;
        }

        // Verificar si los nodos actuales coinciden
        if (ab1->getDato() != ab2->getDato()) {
            return false;
        }

        // Verificar los subárboles izquierdo y derecho recursivamente
        return esPrefijo(ab1->getIzq(), ab2->getIzq()) && esPrefijo(ab1->getDer(), ab2->getDer());
    }
};

int main() {
    // Declaración e inicialización de los objetos ArbolBinario
    ArbolBinario a, b;
    void lecturaAB(ArbolBinario *a);
    void impresionAB(ArbolBinario a);

    // Ingresar nodos para el primer árbol binario
    cout << "Arbol numero 1 " << endl;
    lecturaAB(&a);
    cout << "Arbol numero 2 " << endl;
    lecturaAB(&b);

    cout << "Primer Arbol :" << endl;
    impresionAB(a);
    cout << endl;

    cout << "Segundo Arbol :" << endl;
    impresionAB(b);
    cout << endl;

    Prefijo pre;

    if (pre.esPrefijo(a.getRaiz(), b.getRaiz())) {
        cout << "El primer arbol es prefijo del segundo arbol." << endl;
    } else {
        cout << "El primer arbol no es prefijo del segundo arbol." << endl;
    }

    return 0;
}

void lecturaAB(ArbolBinario *a){
	cout<<"INGRESO DE ARBOL --------"<<endl;
	a->leer();  //llamado al metodo de lectura del AB
}
void impresionAB(ArbolBinario a){
	cout<<endl;
	cout<<endl<<"IMPRESION DE ARBOL ---------- "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);

}