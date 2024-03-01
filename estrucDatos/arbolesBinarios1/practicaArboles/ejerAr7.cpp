//Patricio Quishpe 7364
//ejer 7
// Dado un AB y un niv,
// determinar la lista de Nodos de dicho niv que contienen el valor ingresado.

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main(){

    system("color f0");
    ArbolBinario ab;
    //prototipos
    void lecturaAB(ArbolBinario *a);
    void impresionAB(ArbolBinario a);
    void listarNodos(NodoBinario* node, int niv, int valor, bool& aux);
    void valores(ArbolBinario ab);

    lecturaAB(&ab);
	impresionAB(ab);

    valores(ab);
    system("pause");
    return 0;
}

void lecturaAB(ArbolBinario *a){
	cout << "Ingreso del ARBOL-----------";
	a->leer();
}
void impresionAB(ArbolBinario a){
	cout << endl << "IMPRESION DEL ARBOL---------" << endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
}
void listarNodos(NodoBinario* node, int niv, int valor, bool& aux) {
    if (node == NULL){
        return;
	}
    if (niv == 0){
        if (node->getDato() == valor) {
            cout << node->getDato() << " ";
            aux = true;
        }
    }else{
        listarNodos(node->getIzq(), niv--, valor, aux);
        listarNodos(node->getDer(), niv--, valor, aux);
    }
}

void valores(ArbolBinario ab){
    
    int niv, valor;
    cout<<"Ingresa los siguientes valores: ";
    cout << "Niv: ";cin >> niv;
    cout << "Valor: ";cin >> valor;

    //enlistar de los datos
    bool aux = false;
    cout << "Los nodos encontrados son:  ";
    listarNodos(ab.getRaiz(), niv, valor, aux);

    if (!aux)
        cout << "Ninguno";
    cout << endl;
}