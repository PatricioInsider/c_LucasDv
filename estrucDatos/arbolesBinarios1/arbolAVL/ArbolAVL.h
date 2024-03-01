#ifndef _ARBOL_AVL_H
#define _ARBOL_AVL_H

#include "NodoAVL.h"
using namespace std;

class ArbolAVL {
private:
    NodoAVL* raiz;

    void imprimirEspacios(int c);

    NodoAVL* buscar(NodoAVL* rSub, Tipo v);

public:
    ArbolAVL();
    void setRaiz(NodoAVL* v);
    NodoAVL* getRaiz();
    bool esVacio();
    void imprimirAVLJerarquia(NodoAVL* p, int n);
    int maximo(int a, int b);
    NodoAVL* nuevoNodo(int clave);
    NodoAVL* rotarDerecha(NodoAVL* x);
    NodoAVL* rotarIzquierda(NodoAVL* x);
    int obtenerFactorEquilibrio(NodoAVL* N);
    NodoAVL* insertarNodo(NodoAVL* nodo, int clave);
    NodoAVL* nodoConValorMinimo(NodoAVL* nodo);
    NodoAVL* eliminarNodo(NodoAVL* raiz, int clave);
    NodoAVL* buscarNodo(Tipo v);
};

ArbolAVL::ArbolAVL() {
    setRaiz(NULL);
}

void ArbolAVL::setRaiz(NodoAVL* v) {
    raiz = v;
}

NodoAVL* ArbolAVL::getRaiz() {
    return raiz;
}

bool ArbolAVL::esVacio() {
    return (getRaiz() == NULL);
}

void ArbolAVL::imprimirAVLJerarquia(NodoAVL* p, int n) {
    if (p == NULL) {
        return;
    }
    imprimirAVLJerarquia(p->getDer(), n + 1);
    imprimirEspacios(n);
    cout << p->getDato() << endl;
    imprimirAVLJerarquia(p->getIzq(), n + 1);
}

int ArbolAVL::maximo(int a, int b) {
    return (a > b) ? a : b;
}

NodoAVL* ArbolAVL::nuevoNodo(int clave) {
    NodoAVL* nodo = new NodoAVL(clave);
    nodo->setIzq(NULL);
    nodo->setDer(NULL);
    return nodo;
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* x) {
    NodoAVL* y = x->getIzq();
    NodoAVL* T2 = y->getDer();
    y->setDer(x);
    x->setIzq(T2);
    x->setAltura(maximo(x->obtenerAltura(x->getIzq()), x->obtenerAltura(x->getDer())) + 1);
    y->setAltura(maximo(y->obtenerAltura(y->getIzq()), y->obtenerAltura(y->getDer())) + 1);
    return y;
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* y) {
    NodoAVL* x = y->getDer();
    NodoAVL* T2 = x->getIzq();
    x->setIzq(y);
    y->setDer(T2);
    y->setAltura(maximo(y->obtenerAltura(y->getIzq()), y->obtenerAltura(y->getDer())) + 1);
    x->setAltura(maximo(x->obtenerAltura(x->getIzq()), x->obtenerAltura(x->getDer())) + 1);
    return x;
}

int ArbolAVL::obtenerFactorEquilibrio(NodoAVL* N) {
    if (N == NULL)
        return 0;
    return N->obtenerAltura(N->getIzq()) - N->obtenerAltura(N->getDer());
}

NodoAVL* ArbolAVL::insertarNodo(NodoAVL* nodo, int clave) {
    if (nodo == NULL) {
        return nuevoNodo(clave);
    }

    if (clave < nodo->getDato()) {
        nodo->setIzq(insertarNodo(nodo->getIzq(), clave));
    } else if (clave > nodo->getDato()) {
        nodo->setDer(insertarNodo(nodo->getDer(), clave));
    } else {
        return nodo;
    }

    nodo->setAltura(1 + maximo(nodo->obtenerAltura(nodo->getIzq()), nodo->obtenerAltura(nodo->getDer())));

    int factorEquilibrio = obtenerFactorEquilibrio(nodo);

    if (factorEquilibrio > 1) {
        if (clave < nodo->getIzq()->getDato()) {
            return rotarDerecha(nodo);
        } else if (clave > nodo->getIzq()->getDato()) {
            nodo->setIzq(rotarIzquierda(nodo->getIzq()));
            return rotarDerecha(nodo);
        }
    }

    if (factorEquilibrio < -1) {
        if (clave > nodo->getDer()->getDato()) {
            return rotarIzquierda(nodo);
        } else if (clave < nodo->getDer()->getDato()) {
            nodo->setDer(rotarDerecha(nodo->getDer()));
            return rotarIzquierda(nodo);
        }
    }

    return nodo;
}

NodoAVL* ArbolAVL::nodoConValorMinimo(NodoAVL* nodo) {
    NodoAVL* actual = nodo;
    while (actual->getIzq() != NULL) {
        actual = actual->getIzq();
    }
    return actual;
}

NodoAVL* ArbolAVL::eliminarNodo(NodoAVL* raiz, int clave) {
    if (raiz == NULL)
        return raiz;

    if (clave < raiz->getDato())
        raiz->setIzq(eliminarNodo(raiz->getIzq(), clave));
    else if (clave > raiz->getDato())
        raiz->setDer(eliminarNodo(raiz->getDer(), clave));
    else {
        if ((raiz->getIzq() == NULL) || (raiz->getDer() == NULL)) {
            NodoAVL* temp = (raiz->getIzq()) ? raiz->getIzq() : raiz->getDer();
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;
            delete temp;
        } else {
            NodoAVL* temp = nodoConValorMinimo(raiz->getDer());
            raiz->setDato(temp->getDato());
            raiz->setDer(eliminarNodo(raiz->getDer(), temp->getDato()));
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->setAltura(1 + maximo(raiz->obtenerAltura(raiz->getIzq()), raiz->obtenerAltura(raiz->getDer())));

    int factorEquilibrio = obtenerFactorEquilibrio(raiz);

    if (factorEquilibrio > 1) {
        if (obtenerFactorEquilibrio(raiz->getIzq()) >= 0) {
            return rotarDerecha(raiz);
        } else {
            raiz->setIzq(rotarIzquierda(raiz->getIzq()));
            return rotarDerecha(raiz);
        }
    }
    if (factorEquilibrio < -1) {
        if (obtenerFactorEquilibrio(raiz->getDer()) <= 0) {
            return rotarIzquierda(raiz);
        } else {
            raiz->setDer(rotarDerecha(raiz->getDer()));
            return rotarIzquierda(raiz);
        }
    }

    return raiz;
}

NodoAVL* ArbolAVL::buscarNodo(Tipo v) {
    return buscar(getRaiz(), v);
}

#endif
