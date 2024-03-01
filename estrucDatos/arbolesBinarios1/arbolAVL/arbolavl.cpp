using namespace std;
#include<iostream>
#include"ArbolAVL.h"


int main() {
    system("color f0");
    ArbolAVL a;  
	void leerAVL(ArbolAVL *a);
	void impresionAVL(ArbolAVL a);
	void eliminarAVL(ArbolAVL a);
	void buscarVL(ArbolAVL a);
    leerAVL(&a);
    
	impresionAVL(a);
	eliminarAVL(a); 
	buscarVL(a);

    system("pause");

    return 0;
}

void leerAVL(ArbolAVL *a){
    Tipo FIN = 999;
    Tipo aux; 
    cout << endl;
    cout << "Ingresa un valor para el Nodo. Ingrese [" << FIN << "] para terminar: ";
    cin >> aux;	
    
    if(aux != FIN){
    
        a->setRaiz(a->insertarNodo(a->getRaiz(), aux));
        leerAVL(a); 
    }
}


void impresionAVL(ArbolAVL a){
    cout << endl << " IMPRESION DEL ARBOL --------------- " << endl;
    a.imprimirAVLJerarquia(a.getRaiz(), 0); 
}

void eliminarAVL(ArbolAVL a){ 	
	Tipo aux;	
    Tipo FIN = 999;
	cout << endl;
	cout << "Ingresa el valor a eliminar. Ingrese [" << FIN << "] para terminar: ";
	cin >> aux;	
	if (aux != FIN){ 
        a.setRaiz(a.eliminarNodo(a.getRaiz(), aux));
		impresionAVL(a);	
		eliminarAVL(a); 	
	}
}

void buscarVL(ArbolAVL a){
    Tipo v; 
    Tipo FIN = 999;
    cout << endl;
    cout << "Ingresa el valor para buscar. Ingrese [" << FIN << "] para terminar: ";
    cin >> v;	
    if (v != FIN){ 
        if(a.buscarNodo(v) != NULL){ 
            cout << "Valor encontrado ....." << endl;
        } else {
            cout << "Valor NO encontrado....." << endl;
        }
        buscarVL(a);  
    }
} 

