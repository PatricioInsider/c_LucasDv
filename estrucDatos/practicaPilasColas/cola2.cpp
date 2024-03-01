#include <iostream>
#include "cola.h"
#define FIN 99999 // MARCADOR DE FUNAL DE LECTUA
using namespace std;
int main()
{
    Cola C;
    void ingresar(Cola * c1); // prototipo que permite un valor
    void imprimir(Cola c2);   // prototipo que visualiza el tda
    ingresar(&C);
    imprimir(C);

    return 0;
}

void moverElementos(Cola *c1, Cola *temp)
{
    if (!c1->colaVacia())
    {
        Tipo y = c1->quitar();
        temp->insertar(y);
        moverElementos(c1, temp);
    }
}

void reinsertarElementos(Cola *c1, Cola *temp, Tipo x)
{
    if (!temp->colaVacia())
    {
        Tipo y = temp->quitar();
        if (y > x)
        {
            c1->insertar(x);
            x = y;
        }
        else
        {
            c1->insertar(y);
        }
        reinsertarElementos(c1, temp, x);
    }
    else
    {
        c1->insertar(x);
    }
}

void ingresarcola(Cola *c1)
{
    Tipo x;
    Cola temp;

    cout << "Ingrese un valor a encolar. Finalice con [" << FIN << "]: ";
    cin >> x;
    if (!c1->colaLlena())
    {
        if (x != FIN)
        {
            moverElementos(c1, &temp);
            reinsertarElementos(c1, &temp, x);
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
    
    Tipo x;

    if (!c2.colaVacia())
    {
        x = c2.quitar();
        cout << x << " ";
        imprimircola(c2);
    }
}