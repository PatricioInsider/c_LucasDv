/* Programa en C++ que permita el ingreso de varios numeros
   y determine el mayor de ellos
   
   num		mayor
   -4		39
   18
   39
   0
   12
*/
#include <iostream>				//inclusion del archivo de cabecera para i/o

using namespace std;			//espacio de nombres estandar

int main(){						//inicio del programa principal
	system("color f0");

	int n;						//cantidad de valores a procesar
	int mayor;					//var de la respuesta
	int menor;					//var de respuesta
	
	int leerN();				//prototipo de la funcion que permite el ingreso de cantidad de valores a procesar
	void imprimirRespuesta(int my, int mn);	//prototipo de la funcion que presenta la respuesta en pantalla
	void determinarMayorMenor(int n1, int *mayor, int *menor);

	n = leerN();				//llamado a la funcion de ingreso de cantidad de valores a procesar
    determinarMayorMenor(n, &mayor, &menor);
	imprimirRespuesta(mayor, menor);	//llamado a la funcion que presenta la respuesta
	system("pause");
}

int leerN(){					//funcion que permite el ingreso de cantidad de valores a procesar
	int n;						//var de lectura

	do {						//ciclo de lectura y validacion de n
		cout << endl << "Ingrese la cantidad de valores a procesar [2 .. 1000]: ";
		cin >> n;				//lectura
	}while(n <= 1);				//repetir mientras se ingresen valores negativos o cero
	return n;					//devolver el valor leido
}

void imprimirRespuesta(int my, int mn){	//funcion que presenta la respuesta en pantalla
	if (my != mn){		//mayor es diferente de menor
		cout << endl << "El valor mayor es: " << my << endl;
	} else {
		cout << endl << "Todos los valores son iguales... No existe valor mayor..." << endl;
	}
}

void determinarMayorMenor(int n1, int *mayor, int *menor){
	int i;			//contadora para controlar el ciclo
	int num;					//var de lectura
	
	for (i = 1; (i <= n1); i++){	//ciclo de ingreso de numeros
		cout << endl << "Ingrese un numero: ";
		cin >> num;				//lectura
		
		if (i == 1){			//es el primer numero ingresado
			*menor = *mayor = num;	//inicializa var mayor y menor
		} else {				//no es el primer valor ingresado
			if (num > *mayor){	//el nuevo numero es mayor que el anterior mayor
				*mayor = num;	//actualiza el valor mayor
			} else {			//no es mayor que el anterior mayor
				if (num < *menor){	//el nuevo numero es menor que el anterior
					*menor = num;	//actualiza el valor menor
				}
			}
		}
	}
}