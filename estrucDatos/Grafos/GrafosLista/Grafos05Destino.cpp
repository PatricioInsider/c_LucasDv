
// Patricio Quishpe 
using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "Utilidades.h"

int main(){
	system("color f0");
	
	//Declaracion del objeto de tipo grafo lista
	GrafoLista b;
	ListaG lis;
	int n;				//variable para el numero de vertices
	
	//Prototipos de las funciones a usarse
	GrafoLista ingresarVerticesL(int n1);
	void ingresarArcosL(GrafoLista *g);
	void imprimirGrafoL(GrafoLista g);
	ListaG listaDestino(GrafoLista g);
	void imprimir(NodoG* act);
	
	//GRAFO IMPLEMENTADO CON LISTA DE ADYACENCIA
	cout << "\nCantidad de arcos del vertice";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	b = ingresarVerticesL(n);					
	ingresarArcosL(&b);												
	imprimirGrafoL(b);
    lis = listaDestino(b);
	cout << "\n Ingresa el vertice adyacente de llegada";
	imprimir(lis.getPrimero());
		
	cout << endl; system("pause");
	return 0;
}
//Funciones para el grafo lista
GrafoLista ingresarVerticesL(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}
void ingresarArcosL(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
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
			getline(cin, aux);
			g -> setArco(x.getDato(), aux);
		}
	}
}
void imprimirGrafoL(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	TipoG aux;
	cout << endl << "===============================================";
	cout << endl << "L I S T A    D E    A D Y A C E N C I A";

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
ListaG listaDestino(GrafoLista g) {

    int nv = g.getNumVerts();
    ListaG aux;

    for (int i = 0; i < nv; i++){
        bool bandera = true;
        for (int j = 0; j < nv; j++){
            if (i != j)
            {
                if (!g.adyacente(j, i))
                {
                   bandera = false;
                    break;
                }
            }
        }
        if (bandera){ 
        	aux.insertarAlFinal(g.getVertice(i).getDato());
        }
    }
    return aux;
}

void imprimir(NodoG* act){
    if (act != NULL){
        cout << "\n>> " << act -> getDato();
        imprimir(act -> getPunt());
    }
}
