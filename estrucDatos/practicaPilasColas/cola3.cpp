using namespace std;
#include <iostream>
#include "cola.h"
#define FIN 99999 // MARCADOR DE FUNAL DE LECTUA}
#define EXT 50

int main()
{
    int N;
    Cola vec[EXT];
    void ingresarcola(Cola * c1); // prototipo que permite un valor
    void imprimircola(Cola c2);   // prototipo que visualiza el tda
    void IngresarVectorC(Cola vec[], int N);
    int NumerocolaS(int Ini, int fin);
    void unirColas(Cola vec[], int N, Cola *c1);
    void colaDuplicada(Cola * C);
    Cola C;
    N = NumerocolaS(1, EXT);
    IngresarVectorC(vec, N);
    unirColas(vec, N, &C);
    cout << "UNION DE COLAS " << endl;
    colaDuplicada(&C);
    imprimircola(C);

    return 0;
}
int NumerocolaS(int ini, int fin)
{
    int x;
    cout << "Ingrese el numero de colas que necesite: ";
    cin >> x;
    if (x < ini || x > fin)
    {
        cout << "MAXIMO DE ELEMENTOS: ";
        return NumerocolaS(ini, fin);
    }
    return x;
}
void ingresarcola(Cola *c1)
{ // funcion que permite el ingreso
    Tipo x;

    cout << "Ingrese un valor a encolar. Finalice con [" << FIN << "]: ";
    cin >> x;
    if (!c1->colaLlena())
    {
        if (x != FIN)
        {                    // aun no se ingresa marcador de final
            c1->insertar(x); // añadir x en el TDA
            ingresarcola(c1);
        }
    }
    else
    {
        cout << "Cola llena, imposible insercion" << endl;
    }
}
void imprimircola(Cola c2)
{
    // funcion que permite el ingreso
    Tipo x;

    if (!c2.colaVacia())
    {
        x = c2.quitar();
        cout << " > " << x << endl;
        imprimircola(c2);
    }
}

void IngresarVectorC(Cola vec[], int N)
{

    if (N > 0)
    {
        cout << "PROCESAMIENYO DEL TDA COLA " << N << endl;
        cout << ".................................." << endl;
        ingresarcola(&vec[N - 1]);
        cout << "elementos ingresados: " << endl;
        imprimircola(vec[N - 1]);
        IngresarVectorC(vec, N - 1);
    }
}

void unirColas(Cola vec[], int N, Cola *c1)
{
    if (N > 0)
    {
        if (!vec[N - 1].colaVacia())
        {
            c1->insertar(vec[N - 1].quitar());
            unirColas(vec, N, c1); // Llamada recursiva para continuar vaciando la cola actual
        }
        else
        {
            unirColas(vec, N - 1, c1); // Llamada recursiva para pasar a la siguiente cola
        }
    }
}

bool buscarEnCola(Cola *C, Tipo dato)
{
    if (C->colaVacia())
    {
       
        return false;
    }

    if (C->quitar() == dato)
    {
       
        return true;
    }

  
    return buscarEnCola(C, dato);
}void colaDuplicadaRecursiva(Cola *C, Cola *C1)
{
    if (C->colaVacia())
    {
        return;
    }

    Tipo dato = C->quitar(); 
    bool encontrado = false;

   
    Cola copiaC1 = *C1;
    encontrado = buscarEnCola(&copiaC1, dato);

   
    if (!encontrado)
    {
        C1->insertar(dato);
    }

   
    colaDuplicadaRecursiva(C, C1);
}
void rellenarColaOriginal(Cola *C, Cola *C1)
{
    if (C1->colaVacia())
    {
    
        return;
    }

    C->insertar(C1->quitar()); 
    rellenarColaOriginal(C, C1);
}

void colaDuplicada(Cola *C)
{
    Cola C1; 
    colaDuplicadaRecursiva(C, &C1);

    rellenarColaOriginal(C, &C1);
}