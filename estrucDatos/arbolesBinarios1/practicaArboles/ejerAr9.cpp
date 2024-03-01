//Patricio Quishpe 7364
//ejer 9
// Dados un AB y un valor,
// determinar el nivel que contiene la máxima cantidad de valores equivalentes al ingresado

using namespace std;
#include <iostream>
#include "ArbolBinario.h"
#include "Lista.h"
#define EXT 50	
int main(){
	system("color f0");
	
	ArbolBinario a;
	Lista l[EXT];					//vector de listas 
	
	int aux = 0, mayor=0, niv=0, num;
		
	void lecturAB(ArbolBinario *a);			//funcion que permite la lectura de AB
	void impresionAB(ArbolBinario a); 		//funcion que impelementa la funcion de la impresion AB
	void niveles(ArbolBinario a, int aux,  Lista l1[]);			// Funcion para identificar el mismo nivel en un AB
	void llenarLista( NodoBinario* nodo, int nivAct, int aux,  Lista *l1 ); 			//Funcion para llenar la lista con nodos del mismo nivel
	void ImprimirLista(Nodo* act);			//funcion que permite la impresion de la lista	
	void valoresEqui( Lista l1[], int val, int aux, int x, int alto);			//funcion que permite identificar el valor con la lista 
	void equivalencia(Nodo* act, int aux, int *cont);
	
	
	lecturAB(&a);
	
	impresionAB(a);
	
	aux=a.calcularAltura(a.getRaiz()) -1 ;
	
	niveles(a, aux , l);		//Llamado a la funcion para ingresar nodos en una lista
	
    cout << endl << " Ingrese un valor: " <<endl;
	cin >> num;
	aux=a.calcularAltura(a.getRaiz())  ;
	
	valoresEqui(l , num ,aux, niv,mayor);
	
	
	cout<<endl;
	system("pause");
}

void llenarLista( NodoBinario* nodo, int nivAct, int nivDes,  Lista *l1 ){			//Funcion para llenar la lista con nodos del mismo nivel
	if (nodo == NULL ) {
        return;
    }

    if (nivAct == nivDes) {
    	l1->insertarAlFinal(nodo->getDato());
        
    }

    llenarLista(nodo->getIzq(), nivAct + 1, nivDes, l1);
    llenarLista(nodo->getDer(), nivAct + 1, nivDes, l1);
}
void ImprimirLista(Nodo* act){				//funcion que permite la impresion de la lista
	
	if(act != NULL){											//Se apunta a un Nodo
		cout<<act->getDato()<< " , ";
		ImprimirLista(act->getPunt());							//Llamado recursivo a impresion
	}	
}

void niveles(ArbolBinario a, int aux,  Lista l1[] ){		// Funcion para identificar el mismo nivel en un AB
	if(a.esVacio()){
		cout<<"  Arbol Vacio  " << endl;
		return;
	}
	
	if(aux >= 0 ){
		//cout<<endl << "Nivel:  "  << aux- 1 ;
		llenarLista(a.getRaiz(),0 ,aux, &l1[aux- 1] );
		cout<<endl << "Valores contenidos en el  nivel  " << aux <<" : " ;
		ImprimirLista( l1[aux -1 ].getPrimero());
		niveles( a ,aux -1 , l1 );
		
	}
}
void equivalencia(Nodo* act, int aux, int *cont){
	if(act != NULL){
		if(aux == act->getDato()){
			*cont = *cont + 1 ;
		//	cout <<endl << " cont: "<< cont ;
		}
		equivalencia(act->getPunt(), aux, cont);
	}
	
}
void valoresEqui( Lista l1[], int val , int aux, int x, int alto ){
	
	if(aux > 0){
		int cont=0;
		
		equivalencia( l1[aux-1 ].getPrimero(), val , &cont  );
		if( cont > alto){
			x = aux ;
			alto = cont ;
		}
		
		valoresEqui(l1, val, aux-1, x , alto );
		if (aux == 1){
			cout<<endl<<" En el nivel:  "<< x << " hay: " << alto  << " equivalencia del valor: " <<  val << endl ;
		}
	
	}
}
void lecturAB(ArbolBinario *a){			
	cout<<endl<<"INGRESO DEL ARBOL"<< endl;
	a->leer();			
}
void impresionAB(ArbolBinario a){		//funcion que impelementa la funcion de la impresion AB
	cout<<endl<<"IMPESION DEL ARBOL " << endl ;
	a.imprimirABJerarquia(a.getRaiz(), 1);				
}


