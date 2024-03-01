#include <iostream>
#include "Cola.h"
using namespace std;
#define FIN 999  

int main() {
    //system("color fc");

    Cola c;   
    void ingresarCola(Cola *c1);  
    void imprimirCola(Cola c2);
    bool contieneElemento(Cola c, Tipo elemento);
    void eliminarRepetidos(Cola *c3, Cola *colaResultado);

    ingresarCola(&c);  
    cout<<" Cola original"<<endl;
    imprimirCola(c);   
    Cola colaResultado;
    eliminarRepetidos(&c, &colaResultado);  
    cout << " Cola: valores repetidos eliminados:" << endl;
    imprimirCola(colaResultado); 
    system("pause");
    return 0;
}

void ingresarCola(Cola *c1){
	Tipo x;                      
	if(!c1->colaLlena())  {
		cout<< "Ingrese un valor a encolar. Finalice con [" << FIN << "]: ";
		cin >> x;				 
		if (x!=FIN){             
			c1->insertar(x);  
			ingresarCola(c1);   
		}
	}  else{                    
		cout << endl << "Cola llena.. Imposible ingreso de nuevos valores...";
	}

}
void imprimirCola(Cola c2){
	Tipo x;
	if(!c2.colaVacia()){
		x=c2.quitar();     
		cout<<"   > "<< x<<endl;
		imprimirCola (c2);
	}
}

bool contieneElemento(Cola c, Tipo elemento) {
    if (c.colaVacia()) {
        return false;
    }

    Tipo x = c.quitar();
    if (x == elemento) {
        return true;
    }

    return contieneElemento(c, elemento);
}

void eliminarRepetidos(Cola *c3, Cola *colaResultado) {
    if (!c3->colaVacia()) {
        Tipo elemento = c3->quitar();

        if (!contieneElemento(*colaResultado, elemento)){    
            colaResultado->insertar(elemento);
        }

        eliminarRepetidos(c3, colaResultado); 
    }
}
