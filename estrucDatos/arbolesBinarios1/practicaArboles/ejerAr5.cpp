//Patricio Quishpe 7364
//ejer 5
//Un AB es 2-equilibrado si el AB es vacío o su subárbol izquierdo y derecho son 2-equilibrados, 
//y la cantidad de nodos de grado 2 del subárbol izquierdo es igual al número de nodos de grado 2 del subárbol derecho


using namespace std;
#include <iostream>
#include "ArbolBinario.h"

class Equi {
public:
    bool validar(NodoBinario* nodo) {
        if (nodo == NULL) {
            return true;
        }

        int izq = contar(nodo->getIzq());
        int der = contar(nodo->getDer());

        return (izq == der) && validar(nodo->getIzq()) && validar(nodo->getDer());
    }

private:
    int contar(NodoBinario* nodo) {
        if (nodo == NULL) {
            return 0;
        }

        int grado2 = (nodo->getIzq() != NULL && nodo->getDer() != NULL) ? 1 : 0;

        grado2 += contar(nodo->getIzq()) + contar(nodo->getDer());

        return grado2;
    }
};

int main() {

    system("color f0");
    ArbolBinario a;

    void lecturaAB(ArbolBinario *a);
    lecturaAB(&a);

    cout << "Arbol Binario:" << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);
    cout << endl;

    Equi eq;
    if (eq.validar(a.getRaiz())) {
        cout << "El Arbol es equilibrado" << endl;
    } else {
        cout << "El Arbol no es equilibrado" << endl;
    }

    system("pause");
    return 0;
}

void lecturaAB(ArbolBinario *a){
	cout<<"INGRESO DE ARBOL --------"<<endl;
	a->leer();  //llamado al metodo de lectura del AB
}