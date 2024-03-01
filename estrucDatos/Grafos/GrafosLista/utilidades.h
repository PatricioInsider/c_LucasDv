//utilidades.h
//archivo de cabecera con utilidades generales

int leerN(int li, int ls){
	int aux;                                  //variable de lectura
	
	cout << endl << "Ingrese la cantidad de valores(entero) a procesar comprnendida en el rango: ["<< li<<"..."<< ls<<"]: ";
	cin >> aux;
	
	if((aux<li)||(aux>ls)){
		return leerN(li, ls);
	}
	return aux;
}
