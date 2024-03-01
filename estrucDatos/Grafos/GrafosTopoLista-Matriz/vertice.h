//Vertice.h
//permite definicion de la clase que origina los vertices de grafos

#include <iostream>
typedef std::string TipoG;  //definicion de la calidad de datos

#ifndef _VERTICE_H
#define _VERTICE_H

class Vertice{  //definicion de la clase vertice
	private:  //atributos
		TipoG dato;    //valor contenido en el vertice
		int num;    //valor que contiene el ordinal del vertice, ver1,ver2,...

	public:   //metodos
		Vertice(); //constructor
		Vertice(TipoG v1);// constructor sabiendo el valor a contener
		Vertice(TipoG v1,int v2); //costructor conociendo el dato ye el numero de orden del vertice
		void setDato(TipoG val); //metodo que actualiza el estado del atributo
		void setNum(int val);  //metodo que actualiza el estado del atributo
		TipoG getDato();  //metodo que devuelve estado del atributo
		int getNum();    //metodo que devuelve estado del atributo
		bool esIgualDato(TipoG val);//metodo que determina si val corresponde al valor congenido en atributo dato
		bool esIgualNum(int val);//metodo que determina si val corresponde al valor congenido en atributo numero
};

Vertice::Vertice(){
	setNum(0);  //inicializacion del vertice
}

Vertice::Vertice(TipoG v1){
	setDato(v1);//actualiza el estado del atributo dato
	setNum(0);//inicializacion del vertice
}
Vertice::Vertice(TipoG v1,int v2){
	setDato(v1);//actualiza el estado del atributo dato
 	setNum(v2);//inicializacion del vertice
 }


void Vertice::setDato(TipoG val){
	dato=val;
}

void Vertice::setNum(int val){
	num=val;
}

TipoG Vertice::getDato(){
	return dato;
}

int Vertice::getNum(){
	return num;
}

bool Vertice::esIgualDato(TipoG val){
	return (getDato()==val); // compara el atributo dato con val y devuel el resultado
}
bool Vertice::esIgualNum(int val){
	return (getNum()==val); // compara el atributo num con val y devuel el resultado
}
#endif

