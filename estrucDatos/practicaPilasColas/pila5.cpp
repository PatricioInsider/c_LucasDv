#include <iostream>
#include "Pila.h"
#define FIN 99999		
using namespace std;

int main(){
    system("color f0");
    Pila p;
    void ingresarValoresPila(Pila *p);                 
    void imprimirPila(Pila p2);
    void intercalarValores(Pila *p, int ind);

    ingresarValoresPila(&p);
    cout << "pila:  " << endl;  
    imprimirPila(p);
    cout << endl;
    intercalarValores(&p, 0);

    cout << "pila alterada" << endl;
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
        cout << "Error. Intentelo mas tarde" << endl; 
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
void intercalarValores(Pila *p, int ind){
    if (ind < p->tamanioPila() / 2){
        Tipo elem1 = p->getVec(ind);
        Tipo elem2 = p->getVec(p->tamanioPila() - ind - 1);
        p->setVec(elem2, ind);
        p->setVec(elem1, p->tamanioPila() - ind - 1);
        intercalarValores(p, ind + 1);
    }
}
