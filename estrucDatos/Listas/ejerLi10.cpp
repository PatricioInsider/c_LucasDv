//Patricio Quishpe

using namespace std;
#include <iostream>
#include "Lista.h" 
#define FIN 99999 


int main() {

    Lista l1,l2; 


    void ingLista(Lista *); 
void printLista(Nodo *); 
void invertir(Lista *); 
Nodo *invertirNodos(Nodo *, Nodo *); 
void suma(Nodo *, Nodo *, Tipo &); 
    Tipo sumTot = 0; 

    cout << "LISTA 1" << endl; 
    ingLista(&l1); 
    cout << "LISTA 2" << endl; 
    ingLista(&l2); 

    cout << endl << "IMPRESION LISTA 1" << endl;
    printLista(l1.getPrimero()); 
    cout << endl << "IMPRESION LISTA 2" << endl;
    printLista(l2.getPrimero()); 

    invertir(&l2);

    cout << endl << "=== SUMA CRUZADA ===" << endl;
    Nodo *nodo1 = l1.getPrimero();
    Nodo *nodo2 = l2.getPrimero();
    suma(l1.getPrimero(), l2.getPrimero(), sumTot);

    cout << " = " << sumTot << endl;

    return 0;
}


void ingLista(Lista *l) {
    Tipo aux; 
    cout << "Ingrese un valor a la lista (FINALICE CON " << FIN << "): ";
    cin >> aux;
    if (aux != FIN) { 
        l->insertarAlFinal(aux);
        ingLista(l);  
    }
}

void printLista(Nodo* act) {
    if (act != NULL) { 
        cout << " > " << act->getDato(); 
        printLista(act->getPunto());  
    }
}
 
Nodo *invertirNodos(Nodo *nodo, Nodo *ant = NULL) {
    if (nodo != NULL) {
        
        Nodo *next = nodo->getPunto();
        
        nodo->setPunto(ant);
       
        return invertirNodos(next, nodo);
    }
    return ant;
}

void invertir(Lista *l) {
    
    l->setPrimero(invertirNodos(l->getPrimero(), NULL));
}

void suma(Nodo *l1, Nodo *l2, Tipo &sumaTotal) {
    if (l1 != NULL || l2 != NULL) { 
        
        Tipo sumPar = 0;
        
        if (l1 != NULL) {
            sumPar += l1->getDato();
            l1 = l1->getPunto();
        }
        
        if (l2 != NULL) {
            sumPar += l2->getDato();
            l2 = l2->getPunto();
        }
        
        sumaTotal += sumPar;
        
        cout << sumPar << " + ";
        
        suma(l1, l2, sumaTotal);
    }
}