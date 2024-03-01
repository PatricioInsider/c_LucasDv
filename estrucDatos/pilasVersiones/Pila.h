// Pila.h
// Implementacion del TDA pila
#include <iostream>
#include <string>
typedef std::string Tipo;			//Definicion de tipo de datos que contendra la pila
#define EXT 50				//Extension maxima de la pila

class Pila{
	private:				//Atributos
		int top;			//posicion del elemento tope o cima de la pila
		Tipo vec[EXT];		//pila: contendra los valores del TDA

	public:									//Metodos
		Pila();								//Constructor
		void set_top(int val);				//Metodo que actualiza estado del atributo
		void set_vec(Tipo val, int pos);	//Metodo que actiualiza el valor val en posicion pos de la Pila
		int get_top();						//Metodo que devuelve el estado del atributo top
		Tipo get_vec(int pos);				//Metodo que devuelve el estado del atributo
		void LimpiarPila();					//Eliminar todos los valores de una pila
		bool PilaVacia();					//Verificar si el TDA esta vacia
		bool PilaLlena();                   //Verificar si la pila esta llena
		int TamanioPila();					//Verificar el tamaño de la pila
		void push(Tipo val);				//Añadir valores al vector
		Tipo pop();							//Eliminar valores del vector
		Tipo CimaPila();					//Ver que valor esta encima :)
};

Pila::Pila(){
	set_top(-1);							//Inicializar el valor del atributo top a pos fuera del arreglo
}

void Pila::set_top(int val){
	top = val;								//Actualiza top con val
}

void Pila::set_vec(Tipo val, int pos){
	vec[pos] = val;							//Actualiza elemento de posicion pos del vector
}

int Pila::get_top(){
	return top;								//Devuelve valor del atributo
}

Tipo Pila::get_vec(int pos){
	return vec[pos];						//Devuelve valor almacenado en la posicion pos del vector
}

void Pila::LimpiarPila(){
	set_top(-1);							//Inicializar el valor del atributo top a pos fuera
}

bool Pila::PilaVacia(){
	return(get_top() == -1);					//True si top apunta a pos fuera de la pila ('pos' = -1)
}

bool Pila::PilaLlena(){
	return(get_top() == (EXT-1));				//Verificar si la pila esta llena
}

int Pila::TamanioPila(){
	return(get_top()+1);						//AUMENTAR el tamañio de la pila
}

void Pila::push(Tipo val){
	if(!PilaLlena()){
		set_top(get_top()+1);					//Incrementa el tamaño de la pila
		set_vec(val, get_top());				//Agregar el valor en el vector
	}
}

Tipo Pila::pop(){
	Tipo aux;
	if(!PilaVacia()){
		aux = get_vec(get_top());
		set_top(get_top()-1);
		return aux;
	}
	return aux;
}
Tipo Pila::CimaPila() {
    if (!PilaVacia()) {
        return get_vec(get_top());
    } 
}