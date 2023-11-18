/* Determinar el rango de los digitos de cada numero ingresado
*/

#include <iostream>
using namespace std;

int main(){		//programa principal
	system("color fc");
	
	int leerN();		//prototipo
	void ingresarNumeros(int n1);
	
	int n;				//cantidad de valores a procesar
	
	n = leerN();		//llamado a la funcion de ingreso cant de valores
	ingresarNumeros(n);	//llamado a funcion de ingreso de valores
	
	cout << endl;
	system("pause");
}

int leerN(){		//implementacion de la funcion de ingreso cantidad de valores
	int aux;		//var de lectura
	
	cout << endl << "Ingrese cantidad de valores a procesar: ";
	cin >> aux;		//lectura
	
	if (aux <= 0){
		return leerN();	//llamado recursivo 
	}
	return aux;			//retornar el valor ingresado y validado
}

void ingresarNumeros(int n1){	//implementacion funcion que ingresa los n1 valores
	int num;			//var que contendra los valores ingresados
	int may = -1, men = 10;		//variables para contener digitos mayor y menor
	
	void individualizarDigitos(int a, int *my, int *mn);	//prototipo de la funcion que individualiza los digitos del numero
	
	cout << endl << "Ingrese un valor a procesar: ";
	cin >> num;
	
	if (num < 0){		//numero negativo
		num *= -1;
	}
	
	individualizarDigitos(num, &may, &men);	//individualizar
	cout << endl << "El digito mayor es: " << may;
	cout << endl << "El digito menor es: " << men;
	cout << endl << "El rango de digitos es: " << may - men;
	
	
	
	if (n1 > 1){					//caso base: 
		ingresarNumeros(n1 - 1);	//llamado recursivo
	}
}

void individualizarDigitos(int a, int *my, int *mn){	//funcion que individualiza los digitos del numero
	int dig;						//digitos extraidos del numero

	dig = a % 10;					//calcular ultimo digito del numero
	if (dig > *my){					//el nuevo digito es mayor que valor apuntado por my
		*my = dig;
	}
	if (dig < *mn){				//el nuevo digito es menor que valor apuntado por mn
		*mn = dig;
	}
	
	if ((a/10) != 0){					//aun hay digitos en el numero
		individualizarDigitos(a/10, my , mn);
	}
	
}