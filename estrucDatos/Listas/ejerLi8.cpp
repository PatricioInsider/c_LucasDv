//Patricio Quishpe

#include <iostream>
#include "LISTA.h"

using namespace std;
#define FIN 99999 



int main()
{
    system("color f0");


    void ingresarLista(Lista *l);
void imprimirLista(Nodo *act);
void Intercambiar(Lista *lista1, Lista *lista2);
void invertirLista(Lista *lista);
void insertar(Lista *lista1, Lista *lista2, int N);
    Lista l1, l2; 

    ingresarLista(&l1); 
    cout << "LISTA 1:";
    imprimirLista(l1.getPrimero()); 
    cout << endl;

    ingresarLista(&l2); 
    cout << "LISTA 2:";
    imprimirLista(l2.getPrimero()); 
    cout << endl;
    int N;
    cout << "Ingrese la posición N para empezar a insertar la lista 2 en la lista 1: ";
    cin >> N;

    invertirLista(&l2);
    insertar(&l1, &l2, N);

    cout << "Lista 1 después de insertar los nodos de la lista 2 invertida a partir de la posición " << N << ":";
    imprimirLista(l1.getPrimero());

    system ("pause");
}

void ingresarLista(Lista *l1)
{
    Tipo aux; // variable de lectura
    cout << endl
         << "Ingrese un valor para poner en la lista. FINALICE CON [" << FIN << "]: ";
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
        imprimirLista(act->getPunto()); 
    }
}
Nodo *invertirListaRecur(Nodo *nodo, Nodo *anterior = NULL)
{
    if (nodo == NULL)
        return anterior;
    Nodo *siguiente = nodo->getPunto();
    nodo->setPunto(anterior);
    return invertirListaRecur(siguiente, nodo);
}

void invertirLista(Lista *lista)
{
    lista->setPrimero(invertirListaRecur(lista->getPrimero()));
}
void insertar(Nodo *&actual1, Nodo *&actual2)
{
    if (actual2 == NULL)
    {
        return; 
    }

    Nodo *temp = actual2->getPunto(); 
    actual2->setPunto(actual1);      
    actual1 = actual2;                

    Nodo *siguiente = actual1->getPunto();
    insertar(siguiente, temp);
    actual1->setPunto(siguiente); 
}

void encontrar(Nodo *&actual1, Nodo *&actual2, int N)
{
    if (N == 1)
    {
        insertar(actual1, actual2); 
        return;
    }

    if (actual1 != NULL && N > 1)
    {
        Nodo *siguiente = actual1->getPunto();
        encontrar(siguiente, actual2, N - 1);
        actual1->setPunto(siguiente); 
    }
    else
    {
        cout << "La posición N es mayor que la longitud de la lista 1." << endl;
    }
}

void insertar(Lista *lista1, Lista *lista2, int N)
{
    if (N <= 0)
    {
        cout << "La posición N debe ser mayor que 0." << endl;
        return;
    }

    Nodo *actual1 = lista1->getPrimero();
    Nodo *actual2 = lista2->getPrimero();
    encontrar(actual1, actual2, N);
    lista1->setPrimero(actual1); 
}