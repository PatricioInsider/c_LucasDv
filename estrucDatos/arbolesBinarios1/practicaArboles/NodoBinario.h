//Implementacion del TDA nodo binario para un arbol

#ifndef _NODO_BINARIO_H			//evitar la duplicidad de llamado en un programa
#define _NODO_BINARIO_H

typedef int Tipo;			//definicion del tipo de valores que contendra cada nodo

class NodoBinario{		//definicion de la clase
	private:
		Tipo dato;				//atributo que contiene el valor a almacenar en el nodo
		NodoBinario* izq;		//apuntador al subarbol izquierdo
		NodoBinario* der;		//apuntador al subarbol derecho
	public:
		NodoBinario();		//constructor por defecto
		NodoBinario(Tipo val);		//constructor conociendo el dato a almacenar
		NodoBinario(Tipo val, NodoBinario* i, NodoBinario* d);	//constructor conociendo el dato y los apuntadores
		void setDato(Tipo val);		//metodo que actualiza el estado del atributo dato
		void setIzq(NodoBinario* val);		//metodo que actualiza el estado del apuntador izquierdo
		void setDer(NodoBinario* val);		//metodo que actualiza el estado del apuntador derecho
		Tipo getDato();				//devuelve un valor del tipo definido(dato)
		NodoBinario* getIzq();		//devuelve el estado del apuntador izquierdo
		NodoBinario* getDer();		//devuelve el estado del apuntador derecho
};

NodoBinario::NodoBinario(){
	//empieza apuntando a null a cada subarbol (izquierdo y derecho)
	setIzq(NULL);
	setDer(NULL);
}
//versiones sobrecargadas de los metodos constructores
NodoBinario::NodoBinario(Tipo val){
	setDato(val);
	setIzq(NULL);
	setDer(NULL);
}
NodoBinario::NodoBinario(Tipo val, NodoBinario* i, NodoBinario* d){
	//actualiza los valores con los parametros recibidos
	setDato(val);
	setIzq(i);
	setDer(d);
}
void NodoBinario::setDato(Tipo val){
	dato = val;		//almacena el parametro en el atributo
}
void NodoBinario::setIzq(NodoBinario* val){
	izq = val;		//actualiza el apuntador izquierdo
}
void NodoBinario::setDer(NodoBinario* val){
	der = val;		//actualiza el apuntador derecho
}
Tipo NodoBinario::getDato(){
	return dato;	//devuelve el valor contenido en el atributo
}
NodoBinario* NodoBinario::getIzq(){
	return izq;		//devuelve el apuntador de la izquierda
}
NodoBinario* NodoBinario::getDer(){
	return der;		//devuelve el apuntador de la derecha
}

#endif
