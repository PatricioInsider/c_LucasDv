
#ifndef _ARBOL_AVL_H
#define _ARBOL_AVL_H
#include "NodoAVL.h"
using namespace std;
class ArbolAVL {
private: 
    NodoAVL* raiz;

	void imprimirEspacios(int c){	
		for (int i = 1; i <= c; i++){	
			cout << "   ";
	    }
	}

	NodoAVL* buscar(NodoAVL* rSub, Tipo v) {
		if (rSub == NULL) {	
			return NULL;	
		} else {		
			if (v == rSub->getDato()){	
				return rSub;
			} else {	
				if (v < rSub->getDato()){		
					return buscar(rSub->getIzq(), v);
				} else { 
					return buscar(rSub->getDer(), v);	
				}
			}
		} 
	}

public:
    ArbolAVL();
    void setRaiz(NodoAVL* v);
    NodoAVL* getRaiz();
    bool esVacio();
    void imprimirAVLJerarquia(NodoAVL* p, int n);
    int maximo(int a, int b);
    NodoAVL* nuevoNodo(int clave);
    NodoAVL* MovDer(NodoAVL* aux1);
    NodoAVL* MovIzq(NodoAVL* x);
    int obtenerFactorEquilibrio(NodoAVL* N);
    NodoAVL* insertarNodo(NodoAVL* nodo, int clave);
    NodoAVL* nodoMinimo(NodoAVL* nodo);
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

NodoAVL* ArbolAVL::MovDer(NodoAVL* aux1) {
    NodoAVL* x = aux1->getIzq();
    NodoAVL* T2 = x->getDer();
    x->setDer(aux1);
    aux1->setIzq(T2);
    aux1->setAltura(maximo(aux1->obtenerAltura(aux1->getIzq()), aux1->obtenerAltura(aux1->getDer())) + 1);
    x->setAltura(maximo(x->obtenerAltura(x->getIzq()), x->obtenerAltura(x->getDer())) + 1);
    return x;
}

NodoAVL* ArbolAVL::MovIzq(NodoAVL* x) {
    NodoAVL* aux1 = x->getDer();
    NodoAVL* T2 = aux1->getIzq();
    aux1->setIzq(x);
    x->setDer(T2);
    x->setAltura(maximo(x->obtenerAltura(x->getIzq()), x->obtenerAltura(x->getDer())) + 1);
    aux1->setAltura(maximo(aux1->obtenerAltura(aux1->getIzq()), aux1->obtenerAltura(aux1->getDer())) + 1);
    return aux1;
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
            return MovDer(nodo);
        } else if (clave > nodo->getIzq()->getDato()) {
            nodo->setIzq(MovIzq(nodo->getIzq()));
            return MovDer(nodo);
        }
    }
    if (factorEquilibrio < -1) {
        if (clave > nodo->getDer()->getDato()) {
            return MovIzq(nodo);
        } else if (clave < nodo->getDer()->getDato()) {
            nodo->setDer(MovDer(nodo->getDer()));
            return MovIzq(nodo);
        }
    }
    return nodo;
}

NodoAVL* ArbolAVL::nodoMinimo(NodoAVL* nodo) {
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
            NodoAVL* temp = nodoMinimo(raiz->getDer());
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
            return MovDer(raiz);
        } else {
            raiz->setIzq(MovIzq(raiz->getIzq()));
            return MovDer(raiz);
        }
    }
    if (factorEquilibrio < -1) {
        if (obtenerFactorEquilibrio(raiz->getDer()) <= 0) {
            return MovIzq(raiz);
        } else {
            raiz->setDer(MovDer(raiz->getDer()));
            return MovIzq(raiz);
        }
    }
    return raiz;
}

NodoAVL* ArbolAVL::buscarNodo(Tipo v){
    return buscar(getRaiz(), v);
}
#endif