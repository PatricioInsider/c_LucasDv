#include <iostream>
using namespace std;

class ColaCircular
{

private:
    int n;
    int *cola;
    int frente, final;

public:
    ColaCircular(int tamano)
    {
        n = tamano;
        cola = new int[n];
        frente = final = -1;
    }
    ~ColaCircular()
    {
        delete[] cola;
    }
    bool estaVacia()
    {
        return frente == -1;
    }
    bool estaLlena()
    {
        return (final + 1) % n == frente;
    }
    void agregar(int elemento)
    {
        if (estaLlena())
        {
            cout << "La cola esta llena." << endl;
        }
        else
        {
            if (estaVacia())
            {
                frente = 0;
            }
            final = (final + 1) % n;
            cola[final] = elemento;
            cout << "Se agrego el elemento " << elemento << "." << endl;
        }
    }
    void desagregar()
    {
        if (estaVacia())
        {
            cout << "No se puede desagregar. Revisa la capacidad de la cola parece estar vacia" << endl;
        }
        else
        {
            int aux = cola[frente];
            if (frente == final)
            {
                frente = final = -1;
            }
            else
            {
                frente = (frente + 1) % n;
            }
            cout << "se elimino el elemento" << aux << "." << endl;
        }
    }
};

int main(){

    system("Color 7a");
    cout<<"Asistencia de turnos IESS"<<endl;
    cout<<"turnos calcelados y agregados, con capacidad limitada"<<endl;
    ColaCircular turno(4);
    turno.agregar(1);
    turno.agregar(2);
    turno.agregar(3);
    turno.agregar(4);
    turno.agregar(5);
    turno.agregar(6); //capacidad excedida
    turno.desagregar();
    turno.desagregar();
    turno.agregar(8);
    turno.agregar(9);
    system("pause");
    return 0;
}