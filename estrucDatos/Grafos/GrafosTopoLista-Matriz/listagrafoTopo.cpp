using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "utilidades.h"

int main(){
	system("color f0");
	GrafoLista g;
	int n;
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);
	void ingresarArcosValor(GrafoLista *g);
	void imprimirGrafo(GrafoLista g);
	void imprimirLista(GrafoLista g);
    void topologicoAux(GrafoLista g, int v, int* bandera, int* pila, int& index);
    void ordenTpologico(GrafoLista g);
    bool buscarCeroAux(GrafoLista g, int v, int* bandera, int* ruta);
    bool buscarCero(GrafoLista g);
	
	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON LISTA ADYACENCIA"<<endl;
	n = leer(1,20);
	cin.ignore();

	g = ingresarVertices(n);
	ingresarArcosValor(&g);
	imprimirGrafo(g);
	imprimirLista(g);

	if (!buscarCero(g))
	{
		ordenTpologico(g);
	}else{
		cout << "El grafo tiene ciclos. ERROR"<<endl;
	}

	cout << endl;
	system("pause");
}

GrafoLista ingresarVertices(int n1){
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux;
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){
	int nv = g -> getNumVerts();
	int na;
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<<endl;
		na = leer(0, 10);
		cin.ignore();

		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			getline(cin, aux);
			g -> setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){
	int nv = g -> getNumVerts();
	int na;
	int peso;
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




void topologicoAux(GrafoLista g, int v, int* bandera, int* pila, int& index) {
    bandera[v] = 1;

    ListaG listaAdy = g.listaAdyacencia(v);
    NodoG* actual = listaAdy.getPrimero();

    while (actual != NULL) {
        int indiceDestino = g.getNumVertice(actual->getDato());
        if (!bandera[indiceDestino]) {
            topologicoAux(g, indiceDestino, bandera, pila, index);
        }
        actual = actual->getPunt();
    }

    pila[index++] = v;
}

bool buscarCeroAux(GrafoLista g, int v, int* bandera, int* ruta) {
    bandera[v] = 1;
    ruta[v] = 1;

    ListaG listaAdy = g.listaAdyacencia(v);
    NodoG* actual = listaAdy.getPrimero();

    while (actual != NULL) {
        int indiceDestino = g.getNumVertice(actual->getDato());
        if (!bandera[indiceDestino]) {
            if (buscarCeroAux(g, indiceDestino, bandera, ruta)) {
                return true;
            }
        } else if (ruta[indiceDestino]) {
            return true;
        }

        actual = actual->getPunt();
    }

    ruta[v] = 0;
    return false;
}
void imprimirGrafo(GrafoLista g){
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
	cout << endl;
}

bool buscarCero(GrafoLista g) {
    int numVertices = g.getNumVerts();

    int* bandera = new int[numVertices];
    int* ruta = new int[numVertices];

    for (int i = 0; i < numVertices; i++) {
        bandera[i] = 0;
        ruta[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        if (!bandera[i] && buscarCeroAux(g, i, bandera, ruta)) {
            delete[] bandera;
            delete[] ruta;
            return true;
        }
    }

    delete[] bandera;
    delete[] ruta;
    return false;
}



void ordenTpologico(GrafoLista g) {
    int numVertices = g.getNumVerts();
    int* bandera = new int[numVertices];
    int* pila = new int[numVertices];
    int index = 0;

    for (int i = 0; i < numVertices; i++) {
        bandera[i] = 0;
    }

    if (buscarCero(g)) {
        cout << "Error no se puede realizar el orden Topologico" << endl;
    } else {
        for (int i = 0; i < numVertices; i++) {
            if (!bandera[i]) {
                topologicoAux(g, i, bandera, pila, index);
            }
        }

        cout << endl << "Orden Topologic -----------------------";
        while (index > 0) {
            int vertice = pila[--index];
            Vertice v = g.getVertice(vertice);
            cout << " " << v.getDato();
        }
        cout << endl;
    }

    delete[] bandera;
    delete[] pila;
}

void imprimirLista(GrafoLista g){
	int nv = g.getNumVerts();
	NodoG* actual;
    cout << endl << "===============================================";
	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();

		while (actual != NULL){
			cout << endl << "\t\t--->" << actual->getDato() << " > Peso: " << actual->getPeso();
			actual = actual->getPunt();
		}
	}
}