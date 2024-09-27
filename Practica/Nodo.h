//Lista hecha en Clases - Creacion del Nodo
typedef int Tipo;			//Definicion del tipo de datos que contendra la lista
using namespace std;
#ifndef _NODO_H
#define _NODO_H ///
class Nodo{					//Definicion de la clase
	private:				//Atributos
	Tipo dato;				//Atr que contiene el valor del nodo
    Nodo* punt;				//Atr que permite apuntar al siguiente Nodo
	public:					//Metodos
		//CONSTRUCTORES
		Nodo();				//Constructor
		Nodo(Tipo val);				//conociendo el valor a contener
		Nodo(Tipo val, Nodo* p);	//conociendo el valor y direccion del nodo a apuntar
		
		void setDato(Tipo val);		//Metodo que actualiza el atr dato
		void setPunt(Nodo* val);	//Metodo que actualiza el atr punt
		Tipo getDato();				//Metodo que devuelve estado el atr dato
		Nodo* getPunt();			//Metodo que devuelve estado el atr punt
};
//Lista00
Nodo::Nodo(){						//Constructor
	setPunt(NULL);					//inializacion del nodo se consigue con apuntador a null
}
//Lista01
Nodo::Nodo(Tipo val){						//Constructor
	setDato(val);					//inicializa el nodo con el valor recibido
	setPunt(NULL);					//inializacion del nodo se consigue con apuntador a null
}
//Lista02
Nodo::Nodo(Tipo val, Nodo* p){						//Constructor
	setDato(val);					//inicializa el nodo con el valor recibido
	setPunt(p);					//inializacion del nodo se consigue con apuntador a p
}
void Nodo::setDato(Tipo val){		//Metodo que actualiza el atr dato
	dato=val;						//Actualiza el atr
}
void Nodo::setPunt(Nodo* val){		//Metodo que actualiza el atr punt
	punt=val;						//Actualiza el atr
}
Tipo Nodo::getDato(){				//Metodo que devuelve estado el atr dato
	return dato;					//Devuelve el estado del atr
}
Nodo* Nodo::getPunt(){				//Metodo que devuelve estado el atr punt
	return punt;					//Devuelve el estado del atr
}
#endif