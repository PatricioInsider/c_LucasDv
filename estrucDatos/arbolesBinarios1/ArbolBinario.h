// ArbolBinario.h

#ifndef _ARBOL_BINARIO_H
#define _ARBOL_BINARIO_H

#include "NodoBinario.h"				//acceder a metodos de nds

class ArbolBinario{						//definicion de la clase
private:
	NodoBinario* raiz;					//apuntador al nd raiz

	void imprimirEsp(int c){			//metodo privado para imprimir espacios
		for (int i = 1; i <= c; i++){	//ciclo impresion espacios
			cout << "   ";
	    }
	}

//==================================================================================================

	NodoBinario* leerNodo(int margen){	//metodo privado para ingresar AB por nds
		Tipo aux;						//var de lectura
		Tipo fin = 99999;				//marca de fin de lectura
		NodoBinario* p;					//puntero a nuevo nd
	
		cout << endl;
		imprimirEsp(margen);			//imprimir espacios
		cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
		cin >> aux;						//lectura
		
		if (aux != fin){				//no ingresa marcador de fin lectura
		   p = construirAB(aux, NULL, NULL);  	//construye nuevo nd solo con dato
		   imprimirEsp(margen);			//imprimir espacios
		   cout << "--- SUBARBOL IZQUIERDO ---";
		   p -> setIzq(leerNodo(margen+1)) ;	//puntero izq recibe direccion nuevo nd ingresado
		   imprimirEsp(margen);			//imprimir espacios
		   cout << "--- SUBARBOL DERECHO ---";
		   p -> setDer(leerNodo(margen+1)) ;	//puntero der recive direccion nuevo nd ingresado
		   return p;					//devuelve direccion nuevo nd creado
		} else {						//ingreso marcador final de lectura
			return NULL;				//no se creo el nd
		}
	}

//==================================================================================================

	void preorden(NodoBinario *r) {		//implementa Recorrido de un �rbol binario en preorden
		if (r != NULL) {
			cout << " " << r->getDato();
			preorden (r->getIzq());
			preorden (r->getDer());
		}
	}

//==================================================================================================

	void inorden(NodoBinario *r) {		//implementa Recorrido de un �rbol binario en inorden
		if (r != NULL) {
			inorden (r->getIzq());
			cout << " " << r->getDato();
			inorden (r->getDer());
		}
	}

//==================================================================================================

	void postorden(NodoBinario *r) {	//implementa Recorrido de un �rbol binario en postorden
		if (r != NULL) 	{
			postorden (r->getIzq());
			postorden (r->getDer());
			cout << " " << r->getDato();
		}
	}

//==================================================================================================

	NodoBinario* insertar(NodoBinario* rSub, Tipo v) {		//implementa la inserci�n de un nd en AB
		if (rSub == NULL) {									//no hay nds en arbol
			rSub = new NodoBinario(v);						//crea nuevo nd y lo apunta desde rsub
		} else {											//si hay nds en el arbol
			if (v < rSub->getDato()) {						//valor a insertar es menor que valor del nd actual
				NodoBinario* iz = insertar(rSub->getIzq(), v);	//tratar de insertar a la izq del nd actual
				rSub->setIzq(iz);							//actualiza apuntador
			} else {										//valor a insertar no es menor que valor nd actual
				if (v > rSub->getDato()) {					//valor a insertar es mayor que valor nd actual
					NodoBinario* dr = insertar(rSub->getDer(), v);	//tratar de insertar a derecha del nd actual
					rSub->setDer(dr);						//actualiza apuntador
				} else {									//valor a insertar ya existe en arbol
					return NULL; 							//Nodo duplicado tratamiento de repetici�n
				}			
			} 
		} 
		return rSub;										//devuelve apuntador de nd insertado
	}

//==================================================================================================

	NodoBinario* eliminar (NodoBinario *rSub, Tipo v) {		//implementa la eliminacion de un nd del AB
		if (rSub == NULL) {									//arbol no tiene nds
			return NULL; 									//No se ha encontrado el nd con el valor ingresado
		} else {											//arbol si tiene nds
			if (v < rSub->getDato()){						//valor buscado es menor que valor de nd actual
				NodoBinario* iz = eliminar(rSub->getIzq(), v);	//tratar de eliminar en subarbol izquierdo
				rSub->setIzq(iz);							//actualiza rama izq del nd raiz
			} else {										//valor buscado no es menor que valor nd actual
				if (v > rSub->getDato()){					//valor buscado es mayor que valor del nd actual
					NodoBinario* dr = eliminar(rSub->getDer(), v);	//tratar de eliminar en subarbol derecho
					rSub->setDer(dr);						//actualiza rama derecha del nd raiz
				} else { 									//Nodo encontrado con valor buscado
					NodoBinario* q = rSub; 					// nd a quitar del �rbol
					if (q->getIzq() == NULL) {				//ramal izquierdo de este nd es NULL
						rSub = q->getDer(); 				//se toma ramal derecho
					} else {								//si hay nd apuntado en ramal izquierdo
						if (q->getDer() == NULL) {			//No hay nd apuntado por ramal derecho
							rSub = q->getIzq(); 			//se toma ramal izquierdo
						} else { 							// tiene rama izquierda y derecha
							q = reemplazar(q); 				//reemplaza nd q
						}
					}
					q = NULL;								//hace que q apunte a null
				}
			}
		}
		return rSub;										//devuelve apuntador a nd actual
	}

//==================================================================================================

	NodoBinario* reemplazar(NodoBinario* act) {				//sustituye un nd por otro en AB (parte de eliminaci�n)
		NodoBinario *a, *p;
		p = act;
		a = act->getIzq();									// rama de nds menores
		while (a->getDer() != NULL) {						//mientras haya nds en ramal derecho
			p = a;											//actualiza apuntador
			a = a->getDer();								//recorre el ramal derecho
		}
		
		act->setDato(a->getDato());							// copia en act el valor del nd apuntado por a
		if (p == act) { 									// a es el hijo izquierdo de act
			p->setIzq(a->getIzq());							// enlaza subarbol izquierdo
		} else {											//a no es hijo izq de act
			p->setDer(a->getIzq()); 						//se enlaza subarbol derecho
		}
		return a;											//devuelve apuntador a nd actual
	}	

//==================================================================================================

	NodoBinario* buscar(NodoBinario* rSub, Tipo v) {		//implementa b�squeda de un nd en el AB
		if (rSub == NULL) {									//no existen nds
			return NULL;									//no encontro: devuelve apuntador a NULL
		} else {											//si hay nds
			if (v == rSub->getDato()){						//valor buscado esta en este nd
				return rSub;								//devuelve apuntador a este nd
			} else {										//valor buscado no esta en este nd
				if (v < rSub->getDato()){					//valor buscado es menor que valor del nd
					return buscar(rSub->getIzq(), v);		//repite busqueda en subarbol izquierdo
				} else {									//valor buscado no es menor que valor del nd
					return buscar(rSub->getDer(), v);		//repite busqueda en subarbol derecho
				}
			}
		} 
	}

//==================================================================================================

public:									//metodos publicos
	ArbolBinario();						//constructor

	void setRaiz(NodoBinario* v);		//metodo que actualiza el atributo
	NodoBinario* getRaiz();				//metodo que devuelve el atributo

	bool esVacio();						//metodo que determina si el AB carece de nds
	NodoBinario* construirAB(Tipo dato, NodoBinario* i, NodoBinario* d);	//metodo para construye un nd binario del AB

	void leer();						//metodo que permite el ingreso de los nds de un AB
	void imprimirABSimple(NodoBinario* p);	//metodo que imprime un AB simple (sin formato jerarquico)	
	void imprimirABJerarquia(NodoBinario *p, int n); //metodo que imprime un AB con formato jerarquico

	int contarNodos(NodoBinario *r);				//determina la cantidad de nds que posee un arbol
	int calcularAltura(NodoBinario *r);				//determina la altura de un arbol
	void verHojas(NodoBinario *r);					//visualiza las hojas de un AB

	void recorrerEnPreorden(); 						//metodo de recorrido en preorden
	void recorrerEnInorden();						//metodo de recorrido en ineorden
	void recorrerEnPostorden();						//metodo de recorrido en postorden

	void insertarNodo(Tipo valor);					//permite insertar un nuevo nd con valor v en un arbol binario
	void eliminarNodo(Tipo valor);					//permite eliminar un nd con valor v de un arbol binario
	NodoBinario* buscarNodo(Tipo v);				//permite buscar y encontrar un nd con valor v en un arbol binario

	void vaciar(NodoBinario *r);					//vacia un arbol
	NodoBinario* ndHijoIzq();						//devuelve direccion del hijo del lado izquierdo
	NodoBinario* ndHijoDer();						//devuelve direccion del hijo del lado derecho

	bool arbolLleno(NodoBinario *r);				//determina si el arbol es lleno o no
	void copiaArbol(ArbolBinario &a);				//copia una rama del arbol
	NodoBinario* copiarArbol(NodoBinario* r);		//copia un arbol recibiendo direccion del nd raiz
};

//==================================================================================================

ArbolBinario::ArbolBinario(){				//constructor
	setRaiz(NULL);							//al inicio no hay nds en el AB
}

//==================================================================================================

void ArbolBinario::setRaiz(NodoBinario* v){		//metodo que actualiza el atributo
	raiz = v;
}

//==================================================================================================

NodoBinario* ArbolBinario::getRaiz(){		//metodo que devuelve el atributo
	return raiz;
}

//==================================================================================================

bool ArbolBinario::esVacio(){				//metodo que determina si el AB carece de nds
	return (getRaiz() == NULL);				//true si raiz == null 
}

//==================================================================================================

NodoBinario* ArbolBinario::construirAB(Tipo dato, NodoBinario* i, NodoBinario* d){
	return new NodoBinario(dato, i, d);		//construye un nuevo nd con los parametros y devuelve su direccion
}

//==================================================================================================

void ArbolBinario::leer(){					//metodo que permite lectura de un AB
	setRaiz(leerNodo(0));					//actualiza raiz del AB con apuntador devuelto por nuevo nd ingresado
}

//==================================================================================================

void ArbolBinario::imprimirABSimple(NodoBinario* p){		//metodo que imprime un AB	
	if (p != NULL){
		cout << endl << "> " << p -> getDato();
		imprimirABSimple(p -> getIzq());
		imprimirABSimple(p -> getDer());
	}
	return;
}

//==================================================================================================

void ArbolBinario::imprimirABJerarquia(NodoBinario *p, int n){		//visualiza el abb 90@ a la izquierda
    if(p == NULL){	//no apunta a ningun nd
       return;
	}
    imprimirABJerarquia(p -> getDer(), n+1);	//llamado recursivo pasando subarbol derecho
    imprimirEsp(n);								//espaciar la impresion
    cout << p -> getDato() << endl;				//visualiza el valor almacenado en el nd
    imprimirABJerarquia(p -> getIzq(), n+1); 	//llamado recursivo pasando subarbol izq
}

//==================================================================================================

int ArbolBinario::contarNodos(NodoBinario *r){				//determina la cantidad de nds que posee un arbol
	if (r == NULL) {
		return 0;
	} else {
		return 1 + contarNodos(r->getIzq()) + contarNodos(r->getDer());
	}
}

//==================================================================================================

int ArbolBinario::calcularAltura(NodoBinario *r){				//determina la altura de un arbol
	if (r == NULL) {
		return 0 ;
	} else {
		int alturaIz = calcularAltura (r->getIzq());
		int alturaDr = calcularAltura (r->getDer());
		if (alturaIz > alturaDr) {								//determina si altura de subarbol izq es mayor que la de subarbol der
			return alturaIz + 1;
		} else {
			return alturaDr + 1;
		}
	}
}

//==================================================================================================

void ArbolBinario::recorrerEnPreorden() {		// recorrido en preorden
	preorden(getRaiz());						//llama a metodo interno de recorrido
}

//==================================================================================================

void ArbolBinario::recorrerEnInorden() {		// recorrido en ineorden
	inorden(getRaiz());							//llama a metodo interno de recorrido
}

//==================================================================================================

void ArbolBinario::recorrerEnPostorden() {		// recorrido en postorden
	postorden(getRaiz());						//llama a metodo interno de recorrido
}

//==================================================================================================

void ArbolBinario::verHojas(NodoBinario *r){						//metodo de recorrido de nds hoja							//visualiza las hojas de un AB
	if (r != NULL){													//nd recibido no es nulo
		if ((r -> getIzq() == NULL) && (r -> getDer() == NULL)) {	//no tiene nds hijo => hoja
			cout << endl << "> " << r -> getDato();					//visualiza dato contenido
		} else {													//si tiene nds hijo => nd rama
			verHojas(r -> getIzq());								//recorrer subarbol izq
			verHojas(r -> getDer());								//recorres subarbol der
		}
	}
	return;
}

//==================================================================================================

NodoBinario* ArbolBinario::buscarNodo(Tipo v){					//permite buscar y encontrar un nd con valor v en un arbol binario
	return buscar(getRaiz(), v);								//llama a metodo interno de b�squeda
}

//==================================================================================================

void ArbolBinario::insertarNodo(Tipo v){						//permite insertar un nuevo nd con valor v en un arbol binario
	setRaiz(insertar(getRaiz(), v));							//llama a metodo interno de insercion de nd
}

//==================================================================================================

void ArbolBinario::eliminarNodo(Tipo v){						//permite eliminar un nd con valor v de un arbol binario
	setRaiz(eliminar(getRaiz(), v));							//llama a metodo interno de eliminacion de nd
}

//==================================================================================================

void ArbolBinario::vaciar(NodoBinario *r) {
	if (r != NULL)	{
		vaciar(r->getIzq());
		vaciar(r->getDer());
		r = NULL;
	}
}

//==================================================================================================

NodoBinario* ArbolBinario::ndHijoIzq() {		//devuelve direccion del hijo del lado izquierdo
	if(getRaiz()){
		return getRaiz()->getIzq();				//devuelve valor apuntado por ramal izq
	} else {
		return NULL; 							//arbol vacio
	}
}
	
//==================================================================================================

NodoBinario* ArbolBinario::ndHijoDer() {		//devuelve direccion del hijo del lado derecho
	if(getRaiz())
		return getRaiz()->getDer();				//devuelve direccion apuntada por ramal derecjho
	else
		return NULL; 							//arbol vacio
}

//==================================================================================================

bool ArbolBinario::arbolLleno(NodoBinario *r){	//determina si el arbol es lleno o no
	if (r == NULL) {							//arbol vacio	
		return true;							//si es arbol lleno
	} else {									//si hay nds
		if (ArbolBinario::calcularAltura(r->getIzq()) != ArbolBinario::calcularAltura(r->getDer())) {	//altura de ramal izq diferente de altura ramal derecho
			return false;						//no es arbol lleno
		}
	}
	return arbolLleno(r->getIzq()) && arbolLleno(r->getDer());
}

//==================================================================================================

void ArbolBinario::copiaArbol(ArbolBinario &a) {
	a.setRaiz(copiarArbol(this->raiz));
}

//==================================================================================================

NodoBinario* ArbolBinario::copiarArbol(NodoBinario* r) {
	NodoBinario *rCop;									//nd copia
	
	if (r == NULL) {									//no hay nds en arbol
		rCop = NULL;									//en la copia pone null porque arbol esta vacio
	} else {											//arbol no vacio
		NodoBinario* izqCop, *derCop;					//dos nuevos nds
		izqCop = copiarArbol(r->getIzq());				//en nuevo izq, pone copia de ramal izq original
		derCop = copiarArbol(r->getDer());				//en nuevo der, pone copia de ramal der del original
		rCop = new NodoBinario(r->getDato(), izqCop, derCop);	//crea nuevo nd
	}
	return rCop;										//devuelve apuntador a la copa
}

//==================================================================================================
#endif
