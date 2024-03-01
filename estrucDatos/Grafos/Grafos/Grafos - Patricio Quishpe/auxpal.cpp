// Programa que determina las palabras palindromo y/o capicuas de una cadena
// Autor: Julio Santillán C.
using namespace std;

#include <iostream>
#include <ctype.h>
#include "utilidades.h"
#include "GrafoMatriz.h"
#define EXT 50		//cte que marca el tamaño maximo de estructuras
#define NMG 10		//cte que marca la cantidad maxima de grafos a procesar

int main(){			//programa principal
	system("color f0");
	int n; 				//cantidad de frases
	GrafoMatriz g[NMG];	//vector de grafos
	
	void ingresarFrases(int n, GrafoMatriz g[]);						//prototitpo de la funcion que permite ingresar n frases
	
	cout << endl << "CANTIDAD DE FRASES";
	n = leerN(1, NMG);					//lectura
	
	ingresarFrases(n, g);					//llamado a lectura
	
    comparacion(g);
    
	cout << endl;
	system("pause");
}

void transferirCaracteres(char f[], char p[][EXT], int i, int *j, int *k){
	if (i < strlen(f)){
		if (isalpha(f[i]) || isdigit(f[i])){
			p[*j][*k] = f[i];	//transferir una letra desde la cadena original a la matriz de palabras
			(*k)++;	        //posicionarse en la siguiente columna de la misma palabra
		} else {			//cuando no se encuentra una letra
			if (isalpha(f[i-1]) || isdigit(f[i-1])){	//el caracter anterior es letra
				p[*j][*k] = '\0';	//inserta el marcador de fin de cadena
				(*j)++;			//incrementa contador de filas
				*k = 0;			//marcador de columna vuelve a inicio
			}
		}
		transferirCaracteres(f, p, i+1, j, k);	//llamado recursivo
	}	
}

void pasarAPalabras(char f[], char p[][EXT], int *npal){ //funcion que divide la cadena original en arreglo de palabras
	int i, j, k;	//i para recorrer vector, j filas de matriz, k columnas de matriz

	j = k = 0; 	//inicializar posiciones en matriz

	transferirCaracteres(f, p, 0, &j, &k);

    p[j][k] = '\0';	//inserta el marcador de fin de cadena	
	j++;			//incrementa contador de filas
	*npal = j;				//para actualizar cantidad de palabras de la frase
}


void imprimirRespuestas(char pal[][EXT], int i){	//funcion para imprimir respuestas por palabras
	if (i >= 0){			//esta en fila de una palabra
		imprimirRespuestas(pal, i-1);	//llamado recursivo
		cout << endl << "La palabra ingresada es: " << pal[i];
	}
}

void llenarVertices(GrafoMatriz g, char pal[][EXT], int np){		//funcion que transfiere matriz de palabras a vertices de un grafo
	if (np > 0){				//caso base: contador de palabras positivo
		g.nuevoVertice(pal)
	}
}

void ingresarFrases(int n, GrafoMatriz g[]){						//prototitpo de la funcion que permite ingresar n frases
	char f[EXT];		//vector que contiene la cadena original
	char pal[EXT/2][EXT];	//matriz que contiene las palabras de la cadena original, una por fila
	int np;				//cantidad de palabras de la cadena

	if (n > 0){								//caso base: termina recursividad con n = 0
		ingresarFrases(n-1);			//llamado recursivo a lectura de frases
		cout << endl << "INGRESO DE FRASE No." << n;
		cout << endl << "Ingrese una cadena de caracteres: ";
		cin.getline(f,EXT,'.');			//llamado a separacion de palabras		
		pasarAPalabras(f, pal, &np);
		imprimirRespuestas(pal, np-1);
		
	}
}