//Nombre: Patricio Quishpe 7364

#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    system("color 3f");

    Vector obA; //declaracion del objeto tipo TDA
    
    //ingresar
    cout << "INSERTAR VALORES N" << endl;
    obA.ingresarE();
    //imprimir
    cout<<"IMPRIMIR VALORES"<<endl;
    obA.imprimirE();
	//ordenar
    cout<<"ORDENAR VALORES"<<endl;
    obA.ordenarE();
	//calcular-menor-mayor
    cout << "IMPRIMIR VALOR MENOR Y MAYOR" << endl;
    obA.calcularMenMay();
	//insertar
    cout<<"INSERTAR NUEVOS VALORES"<<endl;
    obA.insertarE();
	//eliminar
    cout<<"ELIMINAR VALORES"<<endl;
    obA.eliminarE();
	//buscar
    cout<<"BUSCAR ELEMENTO"<<endl;
    obA.buscarE();
    
    //cierre del programa 
    cout << endl; 
    system("pause");
	return 0;
}

