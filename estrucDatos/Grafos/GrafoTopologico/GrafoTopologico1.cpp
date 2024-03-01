// Grafos04.cpp
// Determina si un grafo valorado (Matriz Ady: a) es identico a otro grafo valorado (Lista Ady: b)

using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include "utilidades.h"

int main(){
	system("color fc");							//interfaz
	GrafoMatriz a;
	GrafoLista b;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	
	GrafoMatriz ingresarVerticesM(int n1);
	void ingresarArcosValorM(GrafoMatriz *g);		//añade arcos => grafos valorados
	void imprimirGrafoM(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo

	GrafoLista ingresarVerticesL(int n1);
	void ingresarArcosValorL(GrafoLista *g);		//añade arcos => grafos valorados
	void imprimirGrafoL(GrafoLista g);			//prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso

	bool comprobarIdentidad(GrafoMatriz a, GrafoLista b);	//prototipo de la funcion que determina la identidad entre dos grafos

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON MATRIZ ADYACENCIA";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	a = ingresarVerticesM(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcosValorM(&a);					//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafoM(a);							//llamado a la funcion que imprime la matriz de adyacencia

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO REPRESENTADO CON LISTA ADYACENCIA";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	b = ingresarVerticesL(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcosValorL(&b);					//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafoL(b);							//llamado a la funcion que imprime la matriz de adyacencia

	cout << endl << "Los dos grafos ingresados " << (comprobarIdentidad(a, b) ? "SI" : "NO") << " son identicos....";

	cout << endl;
	system("pause");
}

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

void ingresarArcosValorL(GrafoLista *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;									//peso del arco
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
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafoL(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	NodoG* actual;								//apunta al nodo actual de la lista

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
}
//===========================================================
GrafoMatriz ingresarVerticesM(int n1){				//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcosValorM(GrafoMatriz *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;						//peso del arco
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			cin >> aux; 
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafoM(GrafoMatriz g){				//funcion que presenta los datos del grafo
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
				cout << endl << "\t\t--->" << x.getDato() << " > Peso: " << g.getArco(i,j);
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

bool compararArcos(GrafoMatriz a,GrafoLista b){
	int nv = a.getNumVerts();
	for (int i = 0; (i < nv); i++){
		for (int j = 0; (j < nv); j++){
			if (a.adyacente(i,j)){
				Vertice vOrigA=a.getVertice(i);
				Vertice vDestA = a.getVertice(j);
				int vOrigB = b.getNumVertice(vOrigA.getDato());
				int vDestB=b.getNumVertice(vDestA.getDato());
				if (!b.adyacente(vOrigB,vDestB)){
					return false;
				}
			}
		}	
	}
	return true;

}
bool compararPesos(GrafoMatriz a, GrafoLista b){

}

bool comprobarIdentidad(GrafoMatriz a, GrafoLista b){	//prototipo de la funcion que determina la identidad entre dos grafos
	int na;				//numero vertices grafo matriz
	int nb;				//numero vertices grafo lista

	na = a.getNumVerts();
	nb = b.getNumVerts();
	
	if (na == nb){		//los dos grafos tienen igual cantidad de vertices
		for (int i = 0; i < na; i++){	//recorrido de los vertices grafo matriz
			Vertice x = a.getVertice(i);
			TipoG aux = x.getDato();		//extraer nombre del vertice de grafo a para buscarlo entre vertices del grafo b

			bool enc = false;				//valor bandera por defecto			
			
			for (int j = 0; j < nb; j++){	//recorrido de los vertices del grafo lista
				Vertice y = b.getVertice(j);
				if (aux == y.getDato()){	//valor encontrado
					enc = true;
				}
			}
			if (!enc){				//vertice de grafo a no existe en grafo b
				return false;		//devuelve indicador de no identidad
			}
		}
	} else {		//los dos grafos poseen distinta cantidad de vertices
		return false;
	}
	// proceso de comparacionde arcos y pesos 
	if (!compararArcos(a,b)){
		return false;
	}
	return true;			//devolver condicion de identidad
};

ListaG ordenacionTopologicoH(GrafoMatriz g){
    ListaG enc ;
    int count;
    int nv = g.getNumVerts();
    
    for (int i = 0; (i < nv); i++){
		
		for (int j = 0; (j < nv); j++){
			if (i != j && g.adyacente(i, j)){		//Verifica si el vertice de llegada tiene arco con el vertice origen
                count +=1;
            }
        if (count==0)
        {
            enc.insertarAlFinal(g.getVertice(i).getDato());
        }
        }
    }   
};

ListaG EliminarAristasV(GrafoMatriz g,ListaG enc){
    int count;
    int nv = g.getNumVerts();
    
    for (int i = 0; (i < nv); i++){

		
		for (int j = 0; (j < nv); j++){
			if (i != j && ){		//Verifica si el vertice de llegada tiene arco con el vertice origen
                if (g.adyacente(j,i))
                {
                    /* code */
                }
                
            }
        if (count==0)
        {
            enc.insertarAlFinal(g.getVertice(i).getDato());
        }
    {    
};

void generarLista(GrafoLista g, ListaG *l){
	for (int i = 0; i < g.getNumVerts(); i++){
        bool adyacencia = true;
        for (int j = 0; j < g.getNumVerts(); j++){
            if (i != j && !g.adyacente(j, i)){		//Verifica si el vertice de llegada tiene arco con el vertice origen
                adyacencia = false;
                break;
                //Si no tiene arco entonces ese no es un vertice de llegada adyacente con todos los demas
            }
        }
        if (adyacencia){ 		//Tiene adyacencia de llegada con todos los vertices
        	//Se inserta en la lista
        	l->insertarAlFinal(g.getVertice(i).getDato());
        }
    }
}