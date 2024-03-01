// NodoAVL.h
#ifndef _NODO_AVL_H
#define _NODO_AVL_H
#include<iostream>

typedef int Tipo;  

class NodoAVL {
private:
    Tipo dato;       
    NodoAVL* izq;    
    NodoAVL* der;    

public:
    int altura;       

    NodoAVL();             
    NodoAVL(Tipo val);      
    NodoAVL(Tipo val, NodoAVL* i, NodoAVL* d); 

    int obtenerAltura(NodoAVL* nodo);   
    void setDato(Tipo val);        
    void setIzq(NodoAVL* val);     
    void setDer(NodoAVL* val);      
    void setAltura(int alt);     
    Tipo getDato();                
    NodoAVL* getIzq();             
    NodoAVL* getDer();          
};

NodoAVL::NodoAVL() {
    setIzq(nullptr);
    setDer(nullptr);
    setAltura(0);
}

NodoAVL::NodoAVL(Tipo val) {
    setDato(val);
    setIzq(nullptr);
    setDer(nullptr);
    setAltura(0);
}

NodoAVL::NodoAVL(Tipo val, NodoAVL* i, NodoAVL* d) {
    setDato(val);
    setIzq(i);
    setDer(d);
    setAltura(0);
}

void NodoAVL::setDato(Tipo val) {
    dato = val;
}

void NodoAVL::setIzq(NodoAVL* val) {
    izq = val;
}

void NodoAVL::setDer(NodoAVL* val) {
    der = val;
}

void NodoAVL::setAltura(int alt) {
    altura = alt;
}

Tipo NodoAVL::getDato() {
    return dato;
}

NodoAVL* NodoAVL::getIzq() {
    return izq;
}

NodoAVL* NodoAVL::getDer() {
    return der;
}

int NodoAVL::obtenerAltura(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura;
}

#endif
