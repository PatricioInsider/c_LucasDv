//Patricio Quishpe 7364
//ejer 4
//Dado un AB y un niv, determinar el numero de nodos que contiene,
// numero de hojas, numero de hijos izq

using namespace std;
#include <iostream>
#include "ArbolBinario.h"


int main() {
    system("color f0");
    ArbolBinario a;  //declarando el arbol binario (AB)
    int niv;
    int nodos = 0, hojas = 0, izq = 0;

	void lecturaAB(ArbolBinario *a); // Prototipos de funciones
	void impresionAB(ArbolBinario a);
    void contar(NodoBinario* n, int niv, int& nodos, int& hojas, int& izq);
    cout<<endl;
    lecturaAB(&a);   //llamado a las funciones

	
    cout << "Ingrese el niv: ";
    cin >> niv;
    contar(a.getRaiz(), niv, nodos, hojas, izq);
    impresionAB(a);
    cout<<endl<<"Datos del niv "<<niv;
    cout<<endl << "N nodos: " << nodos << endl;
    cout << "N hojas: "  << hojas << endl;
    cout << "N hijos izq: " << izq << endl;
    cout << endl;
    system("pause");
    return 0;
}
// Función para contar nodos, hojas y nodos izquierdos en un nivel específico del árbol

void contar(NodoBinario* nodo, int nivel, int& nodos, int& hojas, int& izquierdos) {
    if (nodo == nullptr) {
        return;
    }

    if (nivel == 0) {
        nodos++;
        if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
            hojas++;
        }
        if (nodo->getIzq() != nullptr) {
            izquierdos++;
        }
    } else {
        contar(nodo->getIzq(), nivel --, nodos, hojas, izquierdos);
        contar(nodo->getDer(), nivel --, nodos, hojas, izquierdos);
    }
}

void impresionAB(ArbolBinario a){
	cout<<endl;
	cout<<endl<<"IMPRESION DE AB "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);

}
// Función para leer datos e ingresarlos al árbol
void lecturaAB(ArbolBinario *a){
	cout<<"INGRESO DE DATOS"<<endl;
	a->leer();  //llamado al metodo de lectura del AB
}