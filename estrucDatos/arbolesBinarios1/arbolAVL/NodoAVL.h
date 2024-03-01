// NodoAVL.h
#ifndef _NODO_AVL_H
#define _NODO_AVL_H
#include<iostream>

typedef int Tipo;  // definicionde tipo de dato

// Definición de la clase NodoAVL
class NodoAVL {
private:
    Tipo dato;       // Dato almacenado en el nodo
    NodoAVL* izq;     // Puntero al hijo izquierdo
    NodoAVL* der;     // Puntero al hijo derecho

public:
    int altura;       // Altura del nodo en el árbol AVL

    // Constructores
    NodoAVL();             // Constructor por defecto
    NodoAVL(Tipo val);      // Constructor con dato inicial
    NodoAVL(Tipo val, NodoAVL* i, NodoAVL* d); // Constructor con dato y punteros iniciales

    // Métodos de acceso y modificación
    int obtenerAltura(NodoAVL* nodo);   // Método para obtener la altura de un nodo
    void setDato(Tipo val);        // Establecer el dato del nodo
    void setIzq(NodoAVL* val);     // Establecer el hijo izquierdo
    void setDer(NodoAVL* val);      // Establecer el hijo derecho
    void setAltura(int alt);     // Establecer la altura del nodo
    Tipo getDato();                // Obtener el dato del nodo
    NodoAVL* getIzq();             // Obtener el hijo izquierdo
    NodoAVL* getDer();          // Obtener el hijo derecho
};

// Constructor por defecto
NodoAVL::NodoAVL() {
    setIzq(nullptr);
    setDer(nullptr);
    setAltura(0);  // Inicialmente, la altura de un nuevo nodo es 0
}

// Constructor con dato inicial
NodoAVL::NodoAVL(Tipo val) {
    setDato(val);
    setIzq(nullptr);
    setDer(nullptr);
    setAltura(0);
}

// Constructor con dato y punteros iniciales
NodoAVL::NodoAVL(Tipo val, NodoAVL* i, NodoAVL* d) {
    setDato(val);
    setIzq(i);
    setDer(d);
    setAltura(0);
}

// Establece el valor del dato del nodo
void NodoAVL::setDato(Tipo val) {
    dato = val;
}

// Establece el puntero al hijo izquierdo del nodo
void NodoAVL::setIzq(NodoAVL* val) {
    izq = val;
}

// Establece el puntero al hijo derecho del nodo
void NodoAVL::setDer(NodoAVL* val) {
    der = val;
}

// Establece la altura del nodo
void NodoAVL::setAltura(int alt) {
    altura = alt;
}

// Obtiene el valor del dato del nodo
Tipo NodoAVL::getDato() {
    return dato;
}

// Obtiene el puntero al hijo izquierdo del nodo
NodoAVL* NodoAVL::getIzq() {
    return izq;
}

// Obtiene el puntero al hijo derecho del nodo
NodoAVL* NodoAVL::getDer() {
    return der;
}

// Método estático para obtener la altura de un nodo
int NodoAVL::obtenerAltura(NodoAVL* nodo) {
    // Si el nodo es nulo, la altura es 0; de lo contrario, devuelve la altura del nodo
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura; //retorna altura
}

#endif
