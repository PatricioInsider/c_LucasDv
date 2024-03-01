

//typedef int TipoG; 
typedef std::string TipoG; 			//definicion de la calidad de datos que se va a almacenar

#ifndef _VERTICE_H
#define _VERTICE_H

class Vertice{						//definicion de la clase vertice 
private:							//atributos0
	TipoG dato;						//valor contenido en el vertice
	int num;						//valor que contiene el ordinal del vertice 
	
public:								//metodos
	Vertice();
	Vertice(TipoG val);
	Vertice(TipoG v1, int v2);
	void setDato(TipoG val);		//metodo que actualiza estado del atr
	void setNum(int val);           //metodo que actualiza estado del atr
	TipoG getDato();
	int getNum();	
	bool esIgualDato(TipoG val);	//metodo que determina si val corresponde al valor contenido en atrib dato 
	bool esIgualNum(int val);
};

Vertice::Vertice(){	//constructor
	setNum(0);
}

Vertice::Vertice(TipoG val){	//constructor conociendo el dato a contener
	setNum(0);
	setDato(val);	//se actualiza es estado del atrib dato
}

Vertice::Vertice(TipoG v1, int v2){	//constructor conociendo el dato a contener y el numero de vertice
	setNum(v2);
	setDato(v1);
}

void Vertice::setDato(TipoG val){		//metodo que actualiza estado del atr
	dato=val;
}

void  Vertice::setNum(int val){           //metodo que actualiza estado del atr
	num=val;
}

TipoG  Vertice::getDato(){
	return dato;
}

int  Vertice::getNum(){
	return num;
}

bool Vertice::esIgualDato(TipoG val){
	return (getDato() == val);	//compara el atributo dato con val y devulve el resultado
}

bool Vertice::esIgualNum(int val){
	return (getNum() == val);	//compara el atributo num con val y devulve el resultado
}
	
#endif