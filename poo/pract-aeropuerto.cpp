/*
Se desea elaborar un programa orientado a objetos en el lenguaje de programación C++ que permita gestionar la información de los aviones de un aeropuerto del que se conoce su nombre y dirección.

De los aviones de pasajeros se conoce su marca, modelo, capacidad de pasajeros VIP y capacidad de pasajeros turistas.

De los aviones de carga se conoce su marca, modelo y capacidad de carga en toneladas.

Ingresar la información del aeropuerto y sus aviones
Mostrar la información del aeropuerto y sus aviones que, cuya capacidad de pasajeros sea igual a un valor ingresado por el usuario del programa.
Mostrar los aviones de carga cuyo año de fabricación sea 2000.
Mostrar el avión que más kilómetros ha volado.
Mostrar la capacidad de carga promedio de los aviones de carga de una marca ingresada por el usuario.
NOTA:

Programar los métodos leer() y mostrar() en cada clase que lo necesite.
Asegurar que al crearse los objetos, éstos inicialicen sus atributos numéricos a 0 y las cadenas de caracteres a "".
*/
#include <iostream>
#include <string.h>

using namespace std;

class Avion
{
private:
    string marca, modelo, id;
    float kilometro;
    int fabricacion;

public:
    Avion(/* args */);
    ~Avion();

    virtual void leer()
    {
        cout << "Ingresa los siguientes datos; " << endl;
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "kilometro" << endl;
        cin >> kilometro;
        cout << "Anio de Fabricacion: " << endl;
        cin >> fabricacion;
        cout << "Identificacion: " << endl;
        cin >> id;
    }
    virtual void mostrar()
    {
        cout << marca << "\t" << modelo << "\t";
    }

    int getfabricacion()
    {
        return fabricacion;
    }
    int getkilometro()
    {
        return kilometro;
    }
    string getmodelo()
    {
        return modelo;
    }
};

Avion::Avion()
{
    marca = modelo = "";
}

Avion::~Avion()
{
}

class AvTurista : public Avion
{
private:
    int capVip, capTur;
    int tipo;

public:
    AvTurista(/* args */);
    ~AvTurista();

    void leer()
    {
        Avion::leer();
        cout << "Capacidad Vip:";
        cin >> capVip;
        cout << "Capacidad Turis:";
        cin >> capTur;
    }

    int capTotal()
    {
        return (capVip + capTur);
    }

    void mostrar()
    {
        Avion::mostrar();
        cout << capVip << "\t" << capTur << "\t" << endl;
    }
    int gettipo()
    {
        return tipo;
    }
};

AvTurista::AvTurista(/* args */)
{
    capVip = capTur = 0;
    tipo = 1;
}

AvTurista::~AvTurista()
{
}

class AvCarga : public Avion
{
private:
    float capTon;
    int tipo;

public:
    AvCarga(/* args */);
    ~AvCarga();
    void leer()
    {
        Avion::leer();
        cout << "Cantidad de carga: " << endl;
        cin >> capTon;
    }
    void mostrar()
    {
        Avion::mostrar();
        cout << capTon << "\t" << endl;
    }
    int gettipo()
    {
        return tipo;
    }
    int getcapTon()
    {
        return capTon;
    }
};

AvCarga::AvCarga(/* args */)
{
    capTon = 0;
    tipo = 2;
}

AvCarga::~AvCarga()
{
}

class Aereopuerto
{
private:
    string nombre, direccion;
    Avion *pAt[100];
    AvCarga oACarga[100];
    AvTurista oATuris[100];
    int n;

public:
    Aereopuerto(/* args */);
    ~Aereopuerto();
    // a. Ingresar la ingormacion del aereopuerto en un menu

    int menu()
    {
        int opc;
        cout << "Ingresa el tipo \n 1) Av Pasajero 2) Av Carga" << endl;
        cin >> opc;
        while (opc < 1 && opc > 2) // verificar
        {
            cout << "ingresa de nuevo la opc" << endl;
            cin >> opc;
        }

        return opc;
    }
    void leer()
    {
        cout << "Nombre: " << endl;
        cin >> nombre;
        cout << "Direccion: " << endl;
        cin >> direccion;
        cout << "Cantidad de aviones: " << endl;
        cin >> n;
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                switch (menu())
                {
                case 1:
                    cout << "Ingresa los datos del avion de turismo " << i + 1 << endl;
                    pAt[i] = new AvTurista;
                    pAt[i]->leer();
                    break;
                case 2:
                    cout << "Ingresa los datos del avion de Pasajeros " << i + 1 << endl;
                    pAt[i] = new AvCarga;
                    pAt[i]->leer();
                    break;
                default:
                    cout << "No se ingreso un dato valido" << endl;
                    break;
                }
            }
        }
    }


    void capacidad_avpasajeros()
    {
        int elemento;
        cout << "Ingresa la cantidad de asientos a buscar " << endl;
        cin >> elemento;
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                AvTurista *pAux = (AvTurista *)pAt[i];
                if (pAux->gettipo() == 1)
                {
                    if (pAux->capTotal() == elemento)
                    {
                        pAux->mostrar();
                    }
                }
            }
        }
    }

    // c. Mostrar los aviones de carga cuyo año de fabricación sea 2000
    void mostrar_fabricacion()
    {
        int elemento;
        cout << "Ingresa la cantidad de asientos a buscar " << endl;
        cin >> elemento;
        cout << "--------------------------------------------" << endl;

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                AvTurista *pAux = (AvTurista *)pAt[i];
                if (pAux->gettipo() == 2)
                {
                    if (pAux->capTotal() == elemento)
                    {
                        pAux->mostrar();
                    }
                }
            }
        }
    }

    // d. Mostrar el avión que más kilómetros ha volado
    int mas_kil()
    {
        int pos = 0;
        int aux = pAt[0]->getkilometro();
        for (int i = 0; i < n; i++)
        {
            if (aux < pAt[i]->getkilometro())
            {
                aux = pAt[i]->getkilometro();
                pos = i;
            }
        }
        return pos;
    }

    void avion_mas_kilometros()
    {
        cout << "_________________________________" << endl;
        cout << "Avion con mas kilometros" << endl;

        if (n > 0)
        {
            pAt[mas_kil()]->mostrar();
        }
    }
    // e.Mostrar la capacidad de carga promedio de los aviones de carga de una marca ingresada por el usuario.
    void capacidad_avcarga()
    {
        string elemento;
        cout << "Ingresa  la marca: " << endl;
        cin >> elemento;
        if (n > 0)
        {
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                AvCarga *pAux = (AvCarga *)pAt[i];
                if (pAux->gettipo() == 2)
                {
                    max += pAux->getcapTon();
                }
            }
            cout << max / n << endl;
        }
    }

    // f. Era Eliminar un elemento x identificador sin afectar el orden
    int ubi(string bus)
    {
        int pos = -1;
        int i = 0;
        cout << "Buscando..." << endl;
        while ((pos == -1) && (i < n))
        {
            if (pAt[i]->getmodelo() == bus)
            {
                pos = i;
            }
            i++;
        }
        return pos;
    }

    /*void re_ordenar(int a)
    {
        for (int i = a; i < n; i++)
        {
            AvCarga *pAux = (AvCarga *)pAt[i];
            if (pAt[i]->)
            {
                
            }
            
            switch (menu())
                {
                case 1:
                    cout << "Ingresa los datos del avion de turismo " << i + 1 << endl;
                    pAt[i] = new AvTurista;
                    pAt[i]->leer();
                    break;
                case 2:
                    cout << "Ingresa los datos del avion de Pasajeros " << i + 1 << endl;
                    pAt[i] = new AvCarga;
                    pAt[i]->leer();
                    break;
                default:
                    cout << "No se ingreso un dato valido" << endl;
                    break;
                }
            
            for (int j = a; i < n; i++)
            {

                
            }
            
        }
        
    }*/
    void eliminar_elemento()
    {
        string elemento;
        cout << "Ingresa  el identificador: " << endl;
        cin >> elemento;
        if (n > 0)
        {
            int aux= ubi(elemento);
            delete pAt[aux];
        }

    }
};

Aereopuerto::Aereopuerto(/* args */)
{

}

Aereopuerto::~Aereopuerto()
{
    for (int i = 0; i < n; i++)
    {
        delete pAt[i];
    }
}

int main()
{
    Aereopuerto *pCentral = new Aereopuerto;
    pCentral->leer();
    pCentral->capacidad_avpasajeros();
    pCentral->avion_mas_kilometros();
    pCentral->mas_kil();
    pCentral->capacidad_avcarga();
}