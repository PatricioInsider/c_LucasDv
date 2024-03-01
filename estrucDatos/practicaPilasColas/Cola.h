
typedef int Tipo; 					// definicion del tipo de adtos que contendra la estructura
#define NUM 100

class Cola{						// definicion del TDA
	private:					// atributos
		Tipo vec[NUM];			// definicion del arreglo contenedor de datos
		int frente;				// apuntador a posicion de extraccion de elemento
		int final;				// apuntador a posicion de insercion de elemento
	
	public:						// metodos
		Cola();					// constructor
		void setVec(Tipo val, int pos);					// actualizar el estado de la poscion pos del arreglo
		void setFrente(int val);						// actualiza estado del atributo del arreglo 
		void setFinal(int val);							// actualiza el estado del atributo final del arreglo
		Tipo getVec(int pos);							// devuelve el estado del atributo
		int getFrente();								// devuelve el estado del atributo
		int getFinal();									// devuelve el estado del atributo 
		
		void borraCola();								// reinicializar el valior
		bool colaVacia();
		bool colaLlena();
		int tamanioCola();								// determina la cantidad de elementos actuales en el TDA
		Tipo quitar();									// eliminar un valor del frente del TDA
		void insertar(Tipo val);						// insertar el elemento val en el TDA
		Tipo frenteCola();								// devolver valor ubicado en posicion frente
};	
Cola::Cola(){
	setFinal(-1);										// apuntador de inserccion a posicion anterior a cero
	setFrente(0);
}
void Cola::setVec(Tipo val, int pos){					// actualizar el estado de la poscion pos del arreglo
	vec[pos]=val;										// actualizar estado
}
void Cola::setFrente(int val){							// actualiza estado del atributo del arreglo 
	frente=val;											// actualizar	
}
void Cola::setFinal(int val){							// actualiza el estado del atributo final del arreglo
	final=val;											// actualizar
}
Tipo Cola::getVec(int pos){								// devuelve el estado del atributo
	return vec[pos];									// retornar estado del atr	
}
int Cola::getFrente(){									// devuelve el estado del atributo
	return frente;										// retornar estado del atr	
}
int Cola::getFinal(){									// devuelve el estado del atributo 
	return final;										// retornar estado del atr	
}
void Cola::borraCola(){
	setFinal(-1);										// apuntador de inserccion a posicion anterior a 0
	setFrente(0);										// apuntado rde eliminacion a primera ubicacion
}	
bool Cola::colaVacia(){									// determina si el TDA esta vacio
	return(getFrente()>getFinal());
}
bool Cola::colaLlena(){
	return(getFrente()>= NUM-1);
}
int Cola::tamanioCola(){
	return((final-frente)+1);
}
Tipo Cola::quitar(){
	Tipo aux;
	if(!colaVacia()){
		aux=getVec(getFrente());						// almacena temporalemten el valor del frente del TDA
		setFrente(getFrente()+1);						// incrementar apuntador frente
	}
	return aux;											// retornar el valor extraido del TDA
}
void Cola::insertar(Tipo val){
	if(!colaLlena()){
		setFinal(getFinal()+1);							// incrementar apuntador de inserccion 
		setVec(val, getFinal());						// almacena val en posicion final
	}
}
Tipo Cola::frenteCola(){
	Tipo aux;
	if(!colaVacia()){
		aux=getVec(getFrente());						// almacena temporalemten el valor del frente del TDA
	}
	return aux;		
}
