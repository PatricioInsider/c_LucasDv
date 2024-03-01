
using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "utilidades.h"

int main(){
	GrafoLista g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear

    cout << endl << "\t ===============================================";
	cout << endl << "\t          GRAFO CON LISTA DE ADYACENCIA";
	cout << endl << "\t ==============================================="<<endl;
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//a�ade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);		//a�ade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoLista g);			//prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
    void ordenacionTopologicaAux(GrafoLista g, int v, int* v1, int* pila, int& indicePila);// Funci�n auxiliar para la ordenaci�n topol�gica
    void ordenacionTopologica(GrafoLista g); // Funci�n principal para la ordenaci�n topol�gica
    bool tieneCiclosAux(GrafoLista g, int v, int* v1, int* ruta);// Funci�n auxiliar para la detecci�n de ciclos
    bool tieneCiclos(GrafoLista g);// Funci�n principal para verificar si el grafo tiene ciclos

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO"<<endl;
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();

	g = ingresarVertices(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	//ingresarArcos(&g);							//llamado a la funcion que ingresa los arcos del grafo
	ingresarArcosValor(&g);					//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);							//llamado a la funcion que imprime la matriz de adyacencia
	imprimirLista(g);

    // Nuevos llamados
    cout << endl << "Verificando si el grafo tiene ciclos..."<<endl;
    if (tieneCiclos(g)) {
        cout << "El grafo tiene ciclos. No es posible realizar la ordenacion topologica." << endl;
    } else {
        cout << "El grafo no tiene ciclos. Realizando ordenacion topologica..." << endl;
        ordenacionTopologica(g);
    }


	cout << endl;
	system("pause");
}

GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los v�rtices de un grafo
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux;
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<<endl;
		na = leerN(0, 10);
		cin.ignore();

		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			getline(cin, aux);
			g -> setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;									//peso del arco
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<< endl;
		na = leer(0, 10);
		cin.ignore();

		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux;
			cout << endl << "PESO DEL ARCO: ";
			peso = leer(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafo(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	int na;
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
	cout << endl << "===============================================";
	cout << endl;
}

void imprimirLista(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	NodoG* actual;								//apunta al nodo actual de la lista
    cout << endl << "===============================================";
	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista

		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "\t\t--->" << actual->getDato() << " > Peso: " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
	cout << endl << "===============================================";
}

void ordenacionTopologicaAux(GrafoLista g, int v, int* v1, int* pila, int& indicePila) {
    v1[v] = 1;  // Marcamos el v�rtice como v1

    ListaG listaAdy = g.listaAdyacencia(v);
    NodoG* actual = listaAdy.getPrimero();

    while (actual != NULL) {
        int indiceDestino = g.getNumVertice(actual->getDato());
        if (!v1[indiceDestino]) {
            ordenacionTopologicaAux(g, indiceDestino, v1, pila, indicePila);
        }
        actual = actual->getPunt();
    }

    pila[indicePila++] = v;  // Apilamos el v�rtice
}

bool tieneCiclosAux(GrafoLista g, int v, int* v1, int* ruta) {
    v1[v] = 1;       // Marcamos el v�rtice como v1
    ruta[v] = 1;       // Marcamos el v�rtice como parte del camino actual

    ListaG listaAdy = g.listaAdyacencia(v);
    NodoG* actual = listaAdy.getPrimero();

    while (actual != NULL) {
        int indiceDestino = g.getNumVertice(actual->getDato());
        if (!v1[indiceDestino]) {
            if (tieneCiclosAux(g, indiceDestino, v1, ruta)) {
                return true;
            }
        } else if (ruta[indiceDestino]) {
            return true;  // Se encontr� un ciclo
        }

        actual = actual->getPunt();
    }

    ruta[v] = 0;  // Desmarcamos el v�rtice al salir del camino
    return false;
}

bool tieneCiclos(GrafoLista g) {
    int numVertices = g.getNumVerts();

    int* v1 = new int[numVertices];
    int* ruta = new int[numVertices];

    for (int i = 0; i < numVertices; i++) {
        v1[i] = 0;
        ruta[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        if (!v1[i] && tieneCiclosAux(g, i, v1, ruta)) {
            delete[] v1;
            delete[] ruta;
            return true;  // El grafo tiene ciclos
        }
    }

    delete[] v1;
    delete[] ruta;
    return false;  // El grafo es ac�clico
}

void ordenacionTopologica(GrafoLista g) {
    int numVertices = g.getNumVerts();
    int* v1 = new int[numVertices];
    int* pila = new int[numVertices];
    int indicePila = 0;

    for (int i = 0; i < numVertices; i++) {
        v1[i] = 0;
    }

    if (tieneCiclos(g)) {
        cout << "El grafo tiene ciclos y no se puede realizar la ordenacion topologica." << endl;
    } else {
        for (int i = 0; i < numVertices; i++) {
            if (!v1[i]) {
                ordenacionTopologicaAux(g, i, v1, pila, indicePila);
            }
        }

        cout << endl << "ORDENACION TOPOLOGICA:";
        while (indicePila > 0) {
            int vertice = pila[--indicePila];
            Vertice v = g.getVertice(vertice);
            cout << " " << v.getDato();
        }
        cout << endl;
    }

    delete[] v1;
    delete[] pila;
}
