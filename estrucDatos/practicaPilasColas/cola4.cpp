#include <iostream>
#include "Cola.h"
#include "Pila.h"
#define FIN 100

using namespace std;

int main(){
	system("color fc");
	Cola v[EXT], c;											
	Pila p;
	int leerN();
	int n = leerN();
	
	void ingresarCola(Cola *c1);							
	void imprimirCola(Cola c2);								
	void imprimirPila(Pila p); 								
	void LecturaColas(int n, int i, Cola v1[EXT]);			
	void interseccionColas(int n, Cola v1[EXT], Pila *p1, int colaIndex, int valorIndex);	
	void ordenarPila(Pila *p2, int valor);								
	
	LecturaColas(n, 0, v);
	
	interseccionColas(n, v, &p, 1, 1);
	ordenarPila(&p, p.pop());

	cout << endl << "Interseccion de las colas en la Pila:";
	imprimirPila(p);
	
	cout << endl << endl;
	system("pause");
}
int leerN(){
	int x;
	cout << "Ingrese el valor de N: ";
	cin >> x;
	if(x <= 1 || x > FIN){
		return leerN();
	}
	return x;
}
void ingresarCola(Cola *c1){
	Tipo x;
	cout << "Ingrese un valor a encolar. Finalice con [" << FIN << "]: ";
	cin >> x;
	if(!c1->colaLlena()){
		if(x != FIN){
			c1->insertar(x);
			ingresarCola(c1);
		}	
	} else {
		cout << endl << "El TDA esta lleno. Imposible de agregar mas datos";
	}
}
void imprimirCola(Cola c2){
	Tipo x;
	if(!c2.colaVacia()){
		x = c2.quitar();
		cout << " " << x;
		imprimirCola(c2);
	} 
}
void imprimirPila(Pila p){
    Tipo aux;
    if(!p.pilaVacia()){
        aux = p.pop();	
        imprimirPila(p);
        cout << " " << aux;
    }
}
void LecturaColas(int n, int i, Cola v[]){
	if(n > i){
		cout << endl << "Procesamiento de la cola N." << i+1 << " del TDA: ";
		cout << endl;
		ingresarCola(&v[i]);
		cout << endl << "Elementos ingresados: " << endl << endl;
		imprimirCola(v[i]);
		cout << endl;
		LecturaColas(n, i+1, v);
	}
}
void interseccionColas(int n, Cola v[], Pila *p1, int colaIndex, int valorIndex){
	if (colaIndex < n && valorIndex > 0){
		if (v[colaIndex].colaVacia()) {
			interseccionColas(n, v, p1, 1, valorIndex);
		} else {
			Tipo valor = v[colaIndex].quitar();
			interseccionColas(n, v, p1, colaIndex, valorIndex - 1);
			Cola copia = v[colaIndex];
			bool encontrado = false;
			while (!copia.colaVacia()) {
				if (copia.quitar() == valor) {
					encontrado = true;
					break;
				}
			}
			if (encontrado) {
				p1->push(valor);
			}
			interseccionColas(n, v, p1, colaIndex + 1, v[0].tamanioCola());
		}
	}
}
void ordenarPila(Pila *pila, int valor){
	if (pila->pilaVacia() || valor < pila->cimaPila()){
		pila->push(valor);
	} else {
		int temp = pila->pop();
		ordenarPila(pila, valor);
		pila->push(temp);
	}
}
