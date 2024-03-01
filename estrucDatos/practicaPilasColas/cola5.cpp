#include <iostream>
#include "Cola.h"
#define FIN 100

using namespace std;

int main(){
    system("color F4");
    cout << endl << "    GESTION" << endl;

    Cola cola, colaPrimos;
    Tipo valor;

    void ingresarCola(Cola *cola1, Cola *colaPrimos1);
    void imprimirCola(Cola cola2);
    void divisoresPrimos(Cola *colaPrimos2, Tipo valor, int i);
    void ordenarCola(Cola *colaOrdenar);

    ingresarCola(&cola, &colaPrimos);
    ordenarCola(&colaPrimos);

    cout << endl << "==================================================" << endl << endl;
    cout << " ->";
    imprimirCola(colaPrimos);

    cout << endl << endl;
    system("pause");
}

void imprimirCola(Cola cola2){
    Tipo x;
    if(!cola2.colaVacia()){
        x = cola2.quitar();
        cout << " " << x;
        imprimirCola(cola2);
    } 
}

void insertarOrdenado(Cola *cola1, int valor){
    if (cola1->colaVacia() || valor >= cola1->getFrente()){
        cola1->insertar(valor);
        return;
    }
    int temp = cola1->quitar();
    insertarOrdenado(cola1, valor);
    cola1->insertar(temp);
}

void ordenarCola(Cola *cola1){
    if (!cola1->colaVacia()){
        int temp = cola1->quitar();
        ordenarCola(cola1);
        insertarOrdenado(cola1, temp);
    }
}

bool primo(int i, int j){
    if(j < i){
        if(i % j == 0){
            return false;
        } else {
            return primo(i, j + 1);
        }   
    }
    return true;
}

void divisoresPrimos(Cola *colaPrimos1, Tipo valor, int i){
    Tipo aux;
    Cola colaTemp;
    if(i <= valor){
        if((valor % i == 0) && primo(i, 2)){
            colaPrimos1->insertar(i);
            colaTemp.insertar(i);
        }
        divisoresPrimos(colaPrimos1, valor, i + 1);
    }
    if(!colaTemp.colaVacia()){
        cout << "-> Divisor primo: ";
        imprimirCola(colaTemp);
        cout << endl;
    }
}

void ingresarCola(Cola *cola1, Cola *colaPrimos1){
    Tipo x;
    int i = 2;
    cout << endl << "Ingrese un valor a encolar. Finalice con [" << FIN << "]: ";
    cin >> x;
    if(!cola1->colaLlena()){
        if(x != FIN && x > 0){
            cola1->insertar(x);
            cout << endl;
            if(x == 1){
                cout << "-> El numero ";
				}
		}
	}
	};
