//Patricio Quishpe 7364
//ejer 8
//Generar una lista con los valores de cada niv de un AB ingresado por el usuari

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#include "Lista.h"
#define EXT 50


int main() {
    system("color f0");

    ArbolBinario a;
    NodoBinario nodo;
    
    //prorotipos de las funciones 
    void lecturaAB(ArbolBinario* a);
	void imprimirAB(ArbolBinario a);
	void nivesImp(ArbolBinario* a);		

    lecturaAB(&a);
    imprimirAB(a);

    cout << "Listar por nives---------"<< endl ;
    nivesImp(&a);			
    cout << endl;
    system("pause");
}

void lecturaAB(ArbolBinario* a) {
    cout << endl << " INGRESAR ARBOL-----------" << endl;
    a->leer();
}

void imprimirAB(ArbolBinario a) {
    cout << endl << " IMPRIMIR ARBOL ---------" << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);
}
//funcion que permite imprimir una lista
void imprimirLista(Nodo* act) {
    if (act != NULL) {
        cout << endl << " > " << act->getDato();
        imprimirLista(act->getPunt());
    }
}

void guardar(NodoBinario* nodo, int niv, Lista vec[]) { 	
    if (nodo == NULL) {
        return;
    }

    vec[niv].insertarAlFinal(nodo->getDato()); 
    guardar(nodo->getIzq(), niv++, vec); 
    guardar(nodo->getDer(), niv++, vec); 
}

void mostrarNiv(int niv, Lista vec[], int altura){		
	if(niv<altura){
		cout <<endl<<" \nniv "<< niv <<": ";
		imprimirLista(vec[niv].getPrimero());
		mostrarNiv(niv++, vec,altura);
	}
}


void nivesImp(ArbolBinario* a) {
    if (a == NULL) {
        return;
    }
    int altura = a->calcularAltura(a->getRaiz()) ;
    cout<<altura;
    Lista vec[altura]; 

    guardar(a->getRaiz(), 0, vec); 
	mostrarNiv(0,vec,altura);			
}


