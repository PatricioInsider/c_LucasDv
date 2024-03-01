//Arbol Binario 02
//Arbol binario de busqueda
//La raiz no tiene valor (no es un nodo), es de tipo apuntador para saber donde esta la raiz

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main(){			//programa principal
	system("color f0");
	ArbolBinario a;		//declaracion del AB
	
	void lecturaABB(ArbolBinario *a);		//funcion que implementa la lectura del AB
	void impresionABB(ArbolBinario a);	//funcion que implementa la impresion del AB
	void verDatosABB(ArbolBinario a);		//funcion que presenta algunos datos referentes al AB
	void buscarDatosABB(ArbolBinario a);	//funcion que implementa la busqueda de valores en el ABB
		
	cout << endl << "INGRESO DEL ABB";
	lecturaABB(&a);							//llamado a funciones

	impresionABB(a);

	verDatosABB(a);
	buscarDatosABB(a);
		
	cout << endl;
	system("pause");
}

void lecturaABB(ArbolBinario *a){		//funcion que implementa la lectura del AB
	Tipo aux;							//var de lectura
	Tipo fin = 99999;					//marca de fin de lectura
	
	cout << endl;
	cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: ";
	cin >> aux;						//lectura
		
	if (aux != fin){				//no ingresa marcador de fin lectura
		a->insertarNodo(aux);
		lecturaABB(a);
	}
}

void impresionABB(ArbolBinario a){	//funcion que implementa la impresion del AB
	cout << endl << "IMPRESION DEL ABB" << endl;
	//a.imprimirABSimple(a.getRaiz());
	a.imprimirABJerarquia(a.getRaiz(),0);
}

Tipo sumarNodos(NodoBinario *r){				//determina la suma de nodos que posee un arbol
	if (r == NULL) {
		return 0;
	} 
return r->getDato() + sumarNodos(r->getIzq()) + sumarNodos(r->getDer());
	
}

Tipo determinarMayor(NodoBinario* r,Tipo mayor){		//funcion que determinar el valor mayor contenido en un AB
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

void verDatosABB(ArbolBinario a){		//funcion que presenta algunos datos referentes al AB
	cout << endl << "VER DATOS DEL ARBOL BINARIO DE BUSQUEDA";
	cout << endl << "El arbol contiene " << a.contarNodos(a.getRaiz()) << " nodos...";
	cout << endl << "La suma de sus valores es " << sumarNodos(a.getRaiz()) << " ...";
	cout << endl << "El valor mayor es " << determinarMayor(a.getRaiz(),a.getRaiz()->getDato());
	cout << endl << "La altura del AB es " << a.calcularAltura(a.getRaiz());
	cout << endl << "RECORRIDO EN PREORDEN";
	a.recorrerEnPreorden();
	cout << endl << "RECORRIDO EN INORDEN";
	a.recorrerEnInorden();
	cout << endl << "RECORRIDO EN POSORDEN";
	a.recorrerEnPostorden();
}

void buscarDatosABB(ArbolBinario a){	//funcion que implementa la busqueda de valores en el ABB
	Tipo aux;							//var de lectura
	Tipo fin = 99999;					//marca de fin de lectura
	
	cout << endl;
	cout << "Valor a Buscar. Ingrese [" << fin << "] para terminar: ";
	cin >> aux;						//lectura
		
	if (aux != fin){				//no ingresa marcador de fin lectura
		if (a.buscarNodo(aux) != NULL){
			cout << endl << "El valor " << aux << " SI existe....";
		} else {
			cout << endl << "El valor " << aux << " NO existe....";
		}
		buscarDatosABB(a);
	}
}