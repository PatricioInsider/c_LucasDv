// ArbolBinario02.cpp
// Implementa un ABB

using namespace std;
#include <iostream>
#include <limits>
#include "ArbolBinario.h"
#include <cstdlib>

int main(){			//programa principal
	system("color f0");
	ArbolBinario a;		//declaracion del AB
	void lecturaAB(ArbolBinario *a);		//funcion que implementa la lectura del AB
	void impresionAB(ArbolBinario a);	//funcion que implementa la impresion del AB
	void verDatosAB(ArbolBinario a);		//funcion que presenta algunos datos referentes al AB
	//bool comprobarmenmay(NodoBinario *r);
	void sumarRamasDesdeNodo(ArbolBinario a);
	bool recEnInordenAscendente(NodoBinario *r);
	bool verificarInordenAscendente(ArbolBinario a);
	NodoBinario* buscarNodoPorValor(NodoBinario* r, Tipo valor);
	void sumarSubArboles(ArbolBinario a);
	int altura(NodoBinario* nodo);
	bool esEquiponderado(NodoBinario* nodo); //hecho por el presi, si sirve
	bool ComprobaresEquiponderado(NodoBinario* n);  //funcion que determina que el AB es equiponderado, tanto por izquierda y derecha
	
	cout << endl << "INGRESO DEL ABB";
	lecturaAB(&a);							//llamado a funciones
	impresionAB(a);
	//verDatosAB(a);
	sumarSubArboles(a);
	if (esEquiponderado(a.getRaiz())) {
        cout << "El arbol es equiponderado." << endl;
    } else {
        cout << "El arbol no es equiponderado." << endl;
    }
    
    cout<<endl<<"El arbol binario ingresado "<<(ComprobaresEquiponderado(a.getRaiz())?" SI ":" NO ")<<" es EQUIPONDERADO" <<endl;
	cout << endl;
	system("pause");
}
void lecturaAB(ArbolBinario *a) {
	cout << "Ingreso del AB";
	a->leer();
}
void impresionAB(ArbolBinario a){
	cout << endl << "IMPRESION DEL AB" << endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
}
Tipo sumarNodos(NodoBinario *r){
	if (r == NULL) {
		return 0;
	} else {
		return r->getDato() + sumarNodos(r->getIzq()) + sumarNodos(r->getDer());
	}
}
NodoBinario* buscarNodoPorValor(NodoBinario* r, Tipo valor) {
    if (r == NULL || r->getDato() == valor) {
        return r;
    }

    if (valor < r->getDato()) {
        return buscarNodoPorValor(r->getIzq(), valor);
    } 
	if (valor > r->getDato()){
        return buscarNodoPorValor(r->getDer(), valor);
    }
}
void sumarSubArboles(ArbolBinario a) {
    Tipo valor;
    cout << "Ingrese el valor a buscar: ";
    cin >> valor;
    NodoBinario* nodoEncontrado = buscarNodoPorValor(a.getRaiz(), valor);
    if (nodoEncontrado != NULL) {
        cout << "SUMA ARBOL IZQUIERDO = " << sumarNodos(nodoEncontrado->getIzq()) << endl;
        cout << "SUMA ARBOL DERECHO = " << sumarNodos(nodoEncontrado->getDer()) << endl;
    } else {
        cout << "El valor " << valor << " no ha sido encontrado en el árbol." << endl;
    }
}
Tipo determinarMayor(NodoBinario* r,Tipo mayor){
	if(r==NULL)	{
		return mayor;
	}
	if(r->getDato() > mayor){
		mayor=r->getDato();
	}
	Tipo mayorIzquierdo=determinarMayor(r->getIzq(),mayor);
	Tipo mayorDerecho=determinarMayor(r->getDer(),mayor);
	
	if(mayorIzquierdo > mayor){
		mayor = mayorIzquierdo;
	}
	
	if(mayorDerecho > mayor){
		mayor = mayorDerecho;
	}
	
	return mayor;
}
bool recEnInordenAscendente(NodoBinario *r) {
    static Tipo ultimoValor = numeric_limits<Tipo>::min();  // Valor mínimo posible del tipo Tipo
    if (r != NULL) {
        if (!recEnInordenAscendente(r->getIzq())) {
            return false;
        }
        if (r->getDato() <= ultimoValor) {
            return false;
        }
        ultimoValor = r->getDato();
        if (!recEnInordenAscendente(r->getDer())) {
            return false;
        }
    }
    return true;
}
bool verificarInordenAscendente(ArbolBinario a) {
    return recEnInordenAscendente(a.getRaiz());
}

int altura(NodoBinario* nodo) {
    if (nodo == NULL) {
        return 0;
    }

    int alturaIzquierda = altura(nodo->getIzq());
    int alturaDerecha = altura(nodo->getDer());

    return 1 + max(alturaIzquierda, alturaDerecha);
}

bool esEquiponderado(NodoBinario* nodo) {
    if (nodo == NULL) {
        return true;
    }

    int alturaIzquierda = altura(nodo->getIzq());
    int alturaDerecha = altura(nodo->getDer());

    if (abs(alturaIzquierda - alturaDerecha) > 1) {
        return false;
    }

    return esEquiponderado(nodo->getIzq()) && esEquiponderado(nodo->getDer());
}

bool ComprobaresEquiponderado(NodoBinario* n){
	if(n==NULL){
		return true;
	}
	
	return (sumarNodos(n->getIzq())==sumarNodos(n->getDer())) &&  ComprobaresEquiponderado(n->getIzq()) && ComprobaresEquiponderado(n->getDer());

}

void verDatosAB(ArbolBinario a){
	cout << endl << "VER DATOS DEL ARBOL BINARIO DE BUSQUEDA";
	cout << endl << "El arbol contiene " << a.contarNodos(a.getRaiz()) << " nodos...";
	cout << endl << "RECORRIDO EN INORDEN";
	a.recorrerEnInorden();
	cout << endl;
	if (verificarInordenAscendente(a)) {
	    cout << "El arbol ingresado es de Busqueda"<<endl;
	} else {
	    cout << "El arbol ingresado NO es de Busqueda"<<endl;
	}
}
