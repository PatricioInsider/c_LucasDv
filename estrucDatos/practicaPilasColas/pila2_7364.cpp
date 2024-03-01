/*Ingresar una pila de elementos entre los cuales se admite únicamente hasta N valores
 repetidos (Si se alcanza dicho valor, se aceptarán solamente valores únicos).*/
#include <iostream>
#include "Pila.h"
#define FIN 99999
#define LIM 30

using namespace std;

int main() {
    system("color f0");
    Pila p;
    int limite;
    void ingresarVal(Pila *p, int Nlim);
    int leerLimite(int li, int ls);
    int contarRep(Pila * p, int val, int i);
    void imprimirPila(Pila p2);

    int n = leerLimite(1, LIM);

    ingresarVal(&p, n);
   
    cout << "Valores en pila ;;" << endl;
    imprimirPila(p);
    return 0;
}

int leerLimite(int li, int ls)
{
    int n;
    cout << "Ingrese el limite de valores repetidos permitidos [ 1 hasta " << ls << "]: ";
    cin >> n;
    if ((n <= li) || (n > ls)){
        cout << "Numero fuera de rango... " << endl;
        return leerLimite(li, ls);
    }

    return n;
}

int contarRep(Pila *p, int val, int i = 0)
{
    if (i > p->getTop()){
        return 0;
    }else{
        return (p->getVec(i) == val) + contarRep(p, val, i + 1);
    }
}

void ingresarVal(Pila *p, int Nlim){
    Tipo aux;
    if (!p->pilaLlena()){
        cout << " Ingrese un valor a apilar. Finalice con [" << FIN << "]: ";
        cin >> aux;
        if (aux != FIN){
            if (contarRep(p, aux) < Nlim){
                p->push(aux);
            }else{
                cout << aux << " limite de repeticiones (" << Nlim << "). Ingrese otro valor...." << endl;
            }
            ingresarVal(p, Nlim);
        }
    }else{
        cout << "Error... Pila llena..." << endl;
    }
}

void imprimirPila(Pila p2){
    Tipo aux;
    if (!p2.pilaVacia()){
        aux = p2.pop();
        cout << endl << "  >  " << aux;
        imprimirPila(p2);
    }
}
