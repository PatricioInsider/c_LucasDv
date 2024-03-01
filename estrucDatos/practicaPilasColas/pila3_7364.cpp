/*Ingresar una frase y
 proceda a invertir el orden de las palabras, por medio del empleo de pilas*/
#include <iostream>
#include <sstream>
#include <stack>
#include "PilaString.h"
using namespace std;

int main(){
    void ingresoVal(Pila *);
    void imprimir(Pila);
    void invertirFrase(Pila *);
    Pila p;
    ingresoVal(&p);
    cout << "Frase inicial: " << endl;
    imprimir(p);
    cout << endl << endl << "Frase final: " << endl;
    invertirFrase(&p);
    imprimir(p);
    return 0;
}

void invertirFrase(Pila *p) {
    Tipo aux = p->pop();
    stringstream ss(aux);
    string palabra;
    Pila pilaAux;
    while (ss >> palabra) {
        pilaAux.push(palabra);
    }
    Tipo fraseInv;
    while (!pilaAux.pilaVacia()) {
        fraseInv += pilaAux.pop();
        if (!pilaAux.pilaVacia()) {
            fraseInv += " ";
        }
    }
    p->push(fraseInv);
}

void ingresoVal(Pila *p) {
    Tipo aux;
    string palabras;
    cout << endl << "Ingresa una frase: ";
    getline(cin, aux);
    p->push(aux);
}

void imprimir(Pila p) {
    Tipo aux;
    if (!p.pilaVacia()) {
        aux = p.pop();
        cout << "> " << aux;
    }
}
