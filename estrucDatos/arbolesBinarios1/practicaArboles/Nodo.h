#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
/*Nodo.h
Definicion de la clase nodo de una lista*/
#include <iostream>
using namespace std;
typedef int Tipo;  //definicion del tipo de dato que me da cada nodo

class Nodo{    //definicion de la clase
	private:   //atributos
		Tipo dato;                 //atributo que contiene el valor del nodo
		Nodo* punto;               // atributo que nos permite a puntar al siguiente nodo

	public:   //metodos
		Nodo();
		Nodo(Tipo val);               //constructor, inicializa los atributos de la clase
		Nodo(Tipo val, Nodo* p);
		void setDato(Tipo val);    //metodo que actualiza el atributo dato
		void setPunto(Nodo* val);  //metodo que actualiza el atributo punto
		Tipo getDato();            //metodo que devuelve el estado del atributo dato
		Nodo* getPunt();          //metodo que devuelve el estado del atributo punto
};


Nodo::Nodo(){                   //constructor, inicializa los atributos de la clase
	setPunto(NULL);             //inicializacion del nodo se consigue con apuntador a NULL

}

Nodo::Nodo(Tipo val){                   //constructor, inicializa los atributos de la clase
	setDato(val);
	setPunto(NULL);             //inicializacion del nodo se consigue con apuntador a NULL

}
Nodo::Nodo(Tipo val, Nodo* p){                   //constructor, inicializa los atributos de la clase
	setDato(val);
	setPunto(p);             //inicializacion del nodo se consigue con apuntador a NULL

}


void Nodo::setDato(Tipo val){   //metodo que actualiza el atributo dato
 dato=val;                      //actualiza el atributo
}

void Nodo::setPunto(Nodo* val){  //metodo que actualiza el atributo punto
punto=val;                       //actualiza el atributo
}

Tipo Nodo::getDato(){            //metodo que devuelve el estado del atributo dato
	return dato;                 //devuelve el estado del atributo
}
Nodo* Nodo::getPunt(){          //metodo que devuelve el estado del atributo punto
	return punto;                //devuelve el estado del atributo
}




#endif // NODO_H_INCLUDED
