//Ejercicio 2: Generar un listado de los vértices aislados de un grafo (son aquellos vértices sin arcos).
//Por: Patricio Quishpe

using namespace std;
#include <iostream>
#include "GrafoMatriz.h"
#include "utilidades.h"

int main(){
	system("color c0");
	
	GrafoMatriz g;			//declaracion de un objeto grafo
	int n;					//cantidad de vertices
	
	GrafoMatriz ingresarVertices(int n1);		//prototipo de la funcion que ingresa vertices en el grafo
	void ingresarArcos(GrafoMatriz *g);			//añade arcos => grafos no valorados
	void imprimirGrafo(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo
	void verticesAislados(GrafoMatriz g);
	
	cout << "\n===== CANTIDAD DE VERTICES ======\n";
	n = leerN(1,20);					//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);			//llamado a funcion de ingreso de vertices
	ingresarArcos(&g);					//llamado a la funcion de ingreso de arcos
	imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
	verticesAislados(g);				//llamdo a la funcion que lista los vertices aislados
	
	
	cout << endl;
	system("pause");
	return 0;
}

GrafoMatriz ingresarVertices(int n1){				//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}
void ingresarArcos(GrafoMatriz *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux; 
			g -> setArco(x.getDato(), aux);
		}
	}
}
void imprimirGrafo(GrafoMatriz g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	int na;
	TipoG aux;
	cout << endl << "===============================================";
	cout << endl << "M A T R I Z     D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getDato();
			}
		}
	}
	cout << endl << "===============================================" << endl;
}
void verticesAislados(GrafoMatriz g){
    int n = g.getNumVerts();
    bool conArcos;

    cout << "\n===============================================";
    cout << "\nVERTICES AISLADOS DEL GRAFO";
    for (int i = 0; i < n; i++){
        Vertice x = g.getVertice(i);
        conArcos = false;
        for (int j = 0; j < n; j++){
            if (g.adyacente(i, j)){
                conArcos = true;
                break;
            }
        }
        if (!conArcos){
            cout << endl << "Vertice (" << x.getNum()+1 << "): " << x.getDato();
        }
    }
    cout << endl << "===============================================" << endl;
}
