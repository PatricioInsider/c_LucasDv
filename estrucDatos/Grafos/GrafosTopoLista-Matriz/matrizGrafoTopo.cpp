//PQ-7364

using namespace std;
#include <iostream>
#include "GrafoMatriz.h"
#include "utilidades.h"

int main() {
    GrafoMatriz g;  
    int n;          
    system("color f0");
    GrafoMatriz ingresarVertices(int n1);
    void ingresarArcos(GrafoMatriz *g);        
    void imprimirGrafo(GrafoMatriz g);         
    void topologicoAux(GrafoMatriz g, int v, int* v1, int* pila, int& index);
    void ordenTpologico(GrafoMatriz g);
    bool grafoTieneCiclos(GrafoMatriz g);

    	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON MATRIZ ADYACENCIA"<<endl;

    n = leer(1, 20);  
    cin.ignore();
    //Ingreso y verificacion
    g = ingresarVertices(n);  
    ingresarArcos(&g);         
    imprimirGrafo(g);          

    ordenTpologico(g);

    cout << endl;
    system("pause");
}



void ingresarArcos(GrafoMatriz *g){				
	int nv = g -> getNumVerts();
	int na;
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leer(0, 10);
		cin.ignore();

		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux;
			g -> setArco(x.getDato(), aux);
		}
	}
}

void limp(int* arreglo) {
    delete[] arreglo;
}


GrafoMatriz ingresarVertices(int n1){				
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux;
		a.nuevoVertice(aux);
	}
	return a;
}

int* bandera(int tamano) {
    return new int[tamano];
}

void topologicoAux(GrafoMatriz g, int v, int* v1, int* pila, int& index) {
    v1[v] = 1;  

    for (int i = 0; i < g.getNumVerts(); i++) {
        if (g.getArco(v, i) != 0xFFFF && !v1[i]) {
            topologicoAux(g, i, v1, pila, index);
        }
    }

    pila[index++] = v;  
}
void imprimirGrafo(GrafoMatriz g){				
	int nv = g.getNumVerts();
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
	cout << endl;
}


bool buscarCero(GrafoMatriz g, int v, int* v1, int* ruta) {
    v1[v] = 1;       
    ruta[v] = 1;       

    for (int i = 0; i < g.getNumVerts(); i++) {
        if (g.getArco(v, i) != 0xFFFF) {
            if (!v1[i]) {
                if (buscarCero(g, i, v1, ruta)) {
                    return true;
                }
            } else if (ruta[i]) {
                return true;  
            }
        }
    }

    ruta[v] = 0;  
    return false;
}

bool grafoTieneCiclos(GrafoMatriz g) {
    int nv = g.getNumVerts();

    int* v1 = bandera(nv);
    int* ruta = bandera(nv);

    for (int i = 0; i < nv; i++) {
        v1[i] = 0;
        ruta[i] = 0;
    }

    for (int i = 0; i < nv; i++) {
        if (!v1[i] && buscarCero(g, i, v1, ruta)) {
            limp(v1);
            limp(ruta);
            return true;  
        }
    }

    limp(v1);
    limp(ruta);
    return false;  
}

void ordenTpologico(GrafoMatriz g) {
    int numVertices = g.getNumVerts();
    int* v1 = bandera(numVertices);
    int* pila = bandera(numVertices);
    int index = 0;

    for (int i = 0; i < numVertices; i++) {
        v1[i] = 0;
    }

    if (grafoTieneCiclos(g)) {
        cout << "El grafo tiene ciclos y no se puede realizar la ordenacion topologica." << endl;
    } else {
        for (int i = 0; i < numVertices; i++) {
            if (!v1[i]) {
                topologicoAux(g, i, v1, pila, index);
            }
        }

        cout << endl << "Ordenacion Topologica:";
        while (index > 0) {
            int vertice = pila[--index];
            Vertice v = g.getVertice(vertice);
            cout << " " << v.getDato();
        }
        cout << endl;
    }

    limp(v1);
    limp(pila);
}
