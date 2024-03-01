
#ifndef UTILIDADES_H
#define UTILIDADES_H
//utilidades.h
//Archivo de cabecera con utilidades generales
#include <iostream>
using namespace std;

int leer(int li, int ls){
	int aux;    //variable de lectura
	cout<<"Ingrese la cantidad de valores a procesar: ";
	cin>>aux;
	if ((aux<li) || (aux>ls)){
		return leer(li,ls);
	}
	return aux;
}

#endif //
