//Arbol Binario 01
//La raiz no tiene valor (no es un nodo), es de tipo apuntador para saber donde esta la raiz

using namespace std;
#include <iostream>
#include "ArbolBinario.h"

int main(){
	system("color f3");
	
	ArbolBinario a;		//Declaracion del AB(Arbol Binario)
	
	//Prototipos de las funciones a usarse
	void lecturaAB(ArbolBinario *A);		//Funcion que implementa la lectura del arbol binario
	void impresionAB(ArbolBinario A);		//Funcion que implementa la imrpesion del arbol binario
	void verDatosAB(ArbolBinario A);		//Funcion que muestra algunas operaciones que se hace con el arbol binario
	
	//Llamado a las funciones que gestion el arbol binario
	lecturaAB(&a);
	impresionAB(a);
	verDatosAB(a);
	
	cout << endl; system("pause");
	return 0;
}
void lecturaAB(ArbolBinario *A){
	cout << "\n============= Ingreso del Arbol =============";
	A -> leer();		//lectura del arbol
}
void impresionAB(ArbolBinario A){
	cout << "\n=========== IMPRESION DEL ARBOL ============";
	A.imprimirABSimple(A.getRaiz());		//envio la direccion de la raiz, imprimi en forma de lista
	cout << endl;
	A.imprimirABJerarquia(A.getRaiz(), 0);	//0 para que vaya desde el margen izquierdo (pegado al borde)
}
int sumarNodos(NodoBinario *r){
	if (r == NULL) {
		return 0;
	} else {
		return r -> getDato() + sumarNodos(r->getIzq()) + sumarNodos(r->getDer());
	}
}
void verDatosAB(ArbolBinario A){
	cout << "\n====== VER DATOS DEL ARBOL BINARIO =========";
	cout << "\nEl arbol contiene: " << A.contarNodos(A.getRaiz()) << " nodos";		//Indica cuantos nodos contiene el arbol
	cout << "\nLa suma de los valores de los nodos es: " << sumarNodos(A.getRaiz()) << ". ";
	cout << "\nEl valor mayor es: ";		//Falta implementacion de la funcion determinar el mayor valor ingresado en el arbol
	cout << "\nLa altura del arbol es: " << A.calcularAltura(A.getRaiz());
	cout << "\n====== RECORRIDO EN PREORDEN =======\n"; A.recorrerEnPreorden();
	cout << "\n====== RECORRIDO EN INORDEN =======\n"; A.recorrerEnInorden();
	cout << "\n====== RECORRIDO EN POSTORDEN =======\n"; A.recorrerEnPostorden();
}
