//Patricio Quishpe 7364
//ejer 2
//Ingresados un AB y una lista simple, 
// determinar si la lista coincide con alguna rama completa del AB

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#include "Lista.h"

int main(){
    system("color f0");

    // Declaración de objetos ÁrbolBinario y Lista
    ArbolBinario miArbol;
    Lista miLista;

    // Prototipos de funciones
    void ingresarArbolBinario(ArbolBinario *arbol);
    void ingresarLista(Lista *lista);
    bool ramasIguales(ArbolBinario *arbol, Lista *lista);

    // Llamado a las funciones
    ingresarArbolBinario(&miArbol);
    cout << "\nINGRESA LISTA";
    ingresarLista(&miLista);
    cout << "\nLa lista " << ((ramasIguales(&miArbol, &miLista)) ? " SI " : " NO " ) << " coincide con alguna rama completa del árbol";

    system("pause");
    return 0;
}

bool comparar(NodoBinario* ndArbol, Nodo* ndLista){
    // Caso base: si ambos son nulos, coinciden
    if (ndArbol == nullptr && ndLista == nullptr) {
        return true;
    }
    // Si uno de ellos es nulo o los datos no coinciden, no coinciden
    if (ndArbol == nullptr || ndLista == nullptr || ndArbol->getDato() != ndLista->getDato()) {
        return false;
    }
    // Llamado recursivo para verificar la comparación en las ramas izquierda y derecha
    return comparar(ndArbol->getIzq(), ndLista->getPunt()) && comparar(ndArbol->getDer(), ndLista->getPunt());
}
bool ramasIguales(ArbolBinario *arbol, Lista *lista){
    Nodo* ndLista = lista->getPrimero();
    return comparar(arbol->getRaiz(), ndLista);
}



void ingresarArbolBinario(ArbolBinario *arbol){
    cout << "\nINGRESA ÁRBOL";
    arbol->leer();
}

void ingresarLista(Lista *lista){
    Tipo FIN = 99999;
    Tipo aux;
    cout << "\nIngrese el valor para la lista... Finalice con [" << FIN << "]: "; cin >> aux;
    if (aux != FIN){
        lista->insertarAlFinal(aux);
        ingresarLista(lista);
    }
}