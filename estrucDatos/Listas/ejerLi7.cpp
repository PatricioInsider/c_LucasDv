//Patricio Quishpe

#include <iostream>
#include "LISTA.h" 
using namespace std;
#define FIN 99999


int main()
{
	system ("color f0");
    Lista Original;

void ingresarLista(Lista *l1);
void imprimirLista(Nodo *act);
int tamanio(Nodo *act);
int Nnumeros(int linferior, int lsuperior);
void eliminar(Lista *l1, int N);

    ingresarLista(&Original);

    int max = tamanio(Original.getPrimero());
    int N = Nnumeros(1, max - 1);

    eliminar(&Original, N);

    cout << "Lista después de eliminar los " << N << " menores valores: ";
    imprimirLista(Original.getPrimero());
    system ("pause");
}

int Nnumeros(int linferior, int lsuperior)
{

    int aux;
    cout << "Ingrese el numero de listas a procesar(entre " << linferior << " - " << lsuperior << "): ";
    cin >> aux;
    if (aux < linferior || aux > lsuperior)
    {
        cout << "!!!!!!Ingrese un valor correcto" << endl;
        return Nnumeros(linferior, lsuperior);
    }
    return aux;
}

void ingresarLista(Lista *l1)
{
    Tipo aux; 
    cout << "Ingrese un valor para poner en la lista. FINALICE CON [" << FIN << "]: ";
    cin >> aux;

    if (aux != FIN)
    {
        l1->insertarAlFinal(aux);
        ingresarLista(l1);
    }
}

void imprimirLista(Nodo *act)
{
    if (act != NULL)
    {
        cout << " " << act->getDato();
        imprimirLista(act->getPunto()); // llamado recursivo de la impresion de los siguientes nodos
    }
}

int tamanio(Nodo *act)
{
    if (act != NULL)
    {
        return 1 + tamanio(act->getPunto()); // llamado recursivo de la impresion de los siguientes nodos
    }
    return 0;
}
int encontrar(Lista *l1, Nodo *nodo, int &minValor)
{
    if (nodo == NULL)
    {
        l1->eliminar(minValor);
        return minValor;
    }
    if (nodo->getDato() < minValor)
    {
        minValor = nodo->getDato();
    }
    return encontrar(l1, nodo->getPunto(), minValor);
}

void eliminar(Lista *l1, int N)
{
    if (N <= 0 || l1->esVacia())
    {
        return;
    }
    int minValor;
    if (l1->getPrimero() != NULL)
    {
        minValor = l1->getPrimero()->getDato(); 
    }
    else
    {
        return; 
    }
    encontrar(l1, l1->getPrimero(), minValor);
    eliminar(l1, N - 1);
}