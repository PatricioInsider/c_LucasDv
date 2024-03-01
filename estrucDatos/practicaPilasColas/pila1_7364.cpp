/*Intercambiar, por parejas, los elementos de una pila previamente ingresada (primero con segundo, tercero con cuarto, etc.). */
#include <iostream>
#include "Pila.h"
#define FIN 99999

using namespace std;

int main(){
    //system("color fc");
    Pila p;

    void ingresarVal(Pila *p);
    void imprimirPila(Pila p2);
    void intercambiar(Pila * p, int ind);

    ingresarVal(&p);
    cout << endl;

    cout << "Pila inicial:  " << endl;
    imprimirPila(p);
    cout << endl;

    intercambiar(&p, 0);

    cout << "Pila final :" << endl;
    imprimirPila(p);

    return 0;
}

void ingresarVal(Pila *p){
    Tipo aux;
    if (!p->pilaLlena()){
        cout << "Ingrese un valor a apilar. Si deceas finalizar escribe [" << FIN << "]: ";
        cin >> aux;

        if (aux != FIN){
            p->push(aux);
            ingresarVal(p);
        }
    }else{
        cout << "No es posible.  Pila llena..." << endl;
    }
}

void imprimirPila(Pila p2){
    Tipo aux;
    if (!p2.pilaVacia()){
        aux = p2.pop();
        cout << endl << " >  " << aux;
        imprimirPila(p2);
    }
}

void intercambiar(Pila *p, int ind){
    if (ind < p->tamanioPila() - 1){
        Tipo elem1 = p->getVec(ind);
        Tipo elem2 = p->getVec(ind + 1);

        p->setVec(elem2, ind);
        p->setVec(elem1, ind + 1);

        intercambiar(p, ind + 2);
    }
}
