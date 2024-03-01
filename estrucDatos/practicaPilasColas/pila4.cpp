#include <iostream>
#include "Pila.h"
#define FIN 999		
using namespace std;

int main() {
    system("color fc");
    Pila p;

    void ingresarValoresPila(Pila *p);              
    void imprimirPila(Pila p2);
    int obtenerNumeroDesplazamientos();
    void Desplazar(Pila *p, int n);
    void insertarAlInicio(Pila *p, Tipo valor);
    void insertarAlFondo(Pila *p, Tipo valor);

    ingresarValoresPila(&p);
    cout << "Pila original" << endl;  
    imprimirPila(p);

    int numeroDesplazamientos = obtenerNumeroDesplazamientos();
    Desplazar(&p, numeroDesplazamientos);
    cout << "Pila con desplaazamiento" << endl;
    imprimirPila(p);

    return 0;
}

void ingresarValoresPila(Pila *p){
    Tipo aux;
    if (!p->pilaLlena()){ 
        cout << "Ingrese un valor a apilar. Finalice con [" << FIN << "]: "; // Solicitar al usuario que ingrese un valor para apilar
        cin >> aux;

        if (aux != FIN){ 
            p->push(aux); 
            ingresarValoresPila(p);
        }
    }else{
        cout << "Error... Pila llena..." << endl; 
    }
}

void imprimirPila(Pila p2){	
	Tipo aux;				

	if (!p2.pilaVacia()){		
		aux = p2.pop();
		cout << endl << " >  " << aux;		
		imprimirPila(p2);				
	}
}

int obtenerNumeroDesplazamientos() {
    int desplazamientos;
    cout << "Ingrese el n�mero de desplazamientos: ";
    cin >> desplazamientos;  
    return desplazamientos;
}

void insertarAlInicio(Pila *p, Tipo valor) {
    if (!p->pilaVacia()) {  
        p->push(valor); 
    } else {
        Tipo temp = p->pop();  
        p->push(valor);
        insertarAlInicio(p, temp);
    }
}

void insertarAlFondo(Pila *p, Tipo valor) {
    if (p->pilaVacia()) {
        p->push(valor);     
    } else {
        Tipo temp = p->pop();  
        insertarAlFondo(p, valor);
        p->push(temp);   
    }
}

void Desplazar(Pila *p, int n) {
    int tamano = p->tamanioPila();
    n = n % tamano; 

    if (n < 0){
        n = tamano + n; 
    }

    if (n != 0) {
        Tipo valor = p->pop();  
        insertarAlFondo(p, valor);  
        Desplazar(p, n - 1);
    }
}

