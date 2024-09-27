//Lista05
//Implementacion inicial de una lista simple con valores ingresados por el usuario
//Encuentra el ultimo nodo de la lista
using namespace std;
#include <iostream>
#include "Lista.h"
#define FIN 999							//Marcardor final de lectura
int main() {							//Programa principal
    Lista l;							//Declarar un objeto de tipo lista
    Tipo x;								//Valor a ingresar dentro de la lista
	void ingresarLista(Lista *l);		//Prototipo de la funcion que permite el ingreso de la lista de valores
    void imprimirLista(Nodo* act);		//Prototipo de la funcion que imprime los elementos de la lista
	void buscarElemento(Lista l);		//Prototipo de la funcion buscar elementos de la lista
	Nodo* ultimoNodo(Nodo* act);		//Prototipo de la funcion que permite la busqueda del ultimo nodo
	Nodo* buscarNodoAnterior(Lista l,Tipo val);	//Prototipo de la funcion que devuelve apuntador al nodo anterior al que contiene el valor val
	
	ingresarLista(&l);							//Llamado a funcion lectura
	cout<<endl<<"Valores Lista"<<endl;
	imprimirLista(l.getPrimero());				//Llamado a funcion imprimir
	cout<<endl<<"Valores a Buscar"<<endl;
	buscarElemento(l);
	if(!l.esVacia()){
		cout<<endl<<"Ultimo Valor"<<endl;
		cout<<ultimoNodo(l.getPrimero())->getDato();
	}
	
	cout<<endl<<"BUSQUEDA DEL NODO ANTERIOR";
	cout<<endl<<"Ingrese el valor a ubicar dentro de la lista: ";
	cin>>x;
	if(l.buscarElemento(x)!=NULL){ 			//Si el valor existe en la lista
		Nodo* ant=buscarNodoAnterior(l,x);	//Var para contener la direccion del nodo anterior
		if(ant!=NULL){
			cout<<endl<<"El nodo anterior al valor "<<x<<" es este: "<<ant->getDato();	
		}else{
			cout<<endl<<"No existe nodo anterior al valor "<<x;
		}
	}else{					//El valor x no encontrado en la lista
		 cout<<endl<<"El valor x no existe en la lista";	
	}
    cout<<endl;
    system("pause");
    return 0;
}
void ingresarLista(Lista *l){			//Funcion que permite el ingreso de la lista de valores
	Tipo aux;							//Valor de lectura
	cout<<endl<<"Ingrese un valor para insertar en la lista. Finalice con ["<<FIN<<"]: ";
	cin>>aux;
	if(aux!=FIN){						//No se ingreso marcador de lectura
		l->insertarAlInicio(aux);		//Inserta un nuevo nodocon valor aux
		ingresarLista(l);				//Llamado recursivo a nuevos valores
	}
}
void imprimirLista(Nodo* act){				//Funcion que imprime los elementos de la lista
	if (act != NULL) {						//Se apunto a un nodo
        cout << " > " << act->getDato() << endl;
        imprimirLista(act->getPunt());		//Llamado recursivo a la funcion
    }
}
void buscarElemento(Lista l){			//Funcion buscar elementos de la lista
	Tipo aux;							//Valor de lectura
	cout<<endl<<"Ingrese un valor para buscar en la lista. Finalice con ["<<FIN<<"]: ";
	cin>>aux;
	if(aux!=FIN){						//No se ingreso marcador de lectura
		cout<<endl<<"El valor "<<aux<<((l.buscarElemento(aux)!=NULL)?" SI ":" NO ")<<"existe dentro de la lista ";
		buscarElemento(l);				//Llamado recursivo a lectura de nuevos valores
	}
}
Nodo* ultimoNodo(Nodo* act){			//Funcion que permite la busqueda del ultimo nodo
	//RECURSIVO
	if (act->getPunt() != NULL) {		     //Nodo apuntado por act no es el ultimo nodo
		return ultimoNodo(act->getPunt());	//Act apunta al siguiente nodo
	} else {
		return act;						//Devolver el apuntador al ultimo nodo
	}
	//NO RECURSIVO
	/*Nodo* act;					//Apuntador al nodo actual
	act=l.getPrimero();				//Inicializar apuntador en la lista
	while(act->getPunt()!=NULL){	//Nodo apuntado por act no es el ultimo nodo
		act=act->getPunt();}			//Act apunta al siguiente nodo
	return act;	*/					//Devolver el apuntador al ultimo nodo
} 
Nodo* buscarNodoAnterior(Lista l,Tipo val){	//Funcion que devuelve apuntador al nodo anterior al que contiene el valor val
	Nodo* act; 								//Apuntador al nodo actual
    Nodo* ant;								//Apuntador al nodo anterior
	ant = NULL;  							//Antes del 1er nodo no hay ningun valor
	act= l.getPrimero(); 					//Inicializar apuntador en la lista

    while (act != NULL && act->getDato() != val) {  //Nodo apuntado por act no es el ultimo nodo y el valor no es igual a val
        ant = act;  						//Guardar el nodo actual como el nodo anterior
        act = act->getPunt();  				//Act apunta al siguiente nodo
    }
    return ant;  							//Devolver el apuntador al nodo anterior

}