#include <iostream>
#include <locale.h>

using namespace std;

// Clase base que representa un avion
class cAvion
{
private:
    string Marca, Modelo, ID;
    int Tipo;

public:
    // Constructor por defecto
    cAvion()
    {
        ID = Marca = Modelo = "";
        setTipo(0);
    }

    // Método virtual para ingresar informacion del avion
    virtual void leer()
    {
        cout << "\nIngrese la Identificacion: ";
        cin >> ID;
        cout << "Ingrese la Marca: ";
        cin >> Marca;
        cout << "Ingrese la Modelo: ";
        cin >> Modelo;
    }

    // Método virtual para mostrar informacion detallada del avion
    virtual void mostrar()
    {
        cout << "Identificacion del avion: " << ID << endl;
        cout << "Marca: " << Marca << endl;
        cout << "Modelo: " << Modelo << endl;
    }

    // Métodos de obtencion y modificacion del tipo del avion
    string getID()
    {
        return ID;
    }

    string getMarca()
    {
        return Marca;
    }

    int getTipo()
    {
        return Tipo;
    }

    void setTipo(int t)
    {
        Tipo = t;
    }
};

// Clase derivada que representa un avion de carga
class cCarga : public cAvion
{
private:
    int Cap_C;

public:
    // Constructor por defecto, inicializa el tipo y la capacidad de carga
    cCarga()
        : cAvion()
    {
        setTipo(2);
        Cap_C = 0;
    }

    // Sobrescribe el método de lectura para incluir la capacidad de carga
    void leer()
    {
        cAvion::leer();
        cout << "Ingrese la Capacidad de Carga: ";
        cin >> Cap_C;
    }

    // Sobrescribe el método de mostrar para incluir la capacidad de carga
    void mostrar()
    {
        cAvion::mostrar();
        cout << "Capacidad de Carga: " << Cap_C << endl;
    }

    // Método de obtencion de la capacidad de carga
    int getCap_C()
    {
        return Cap_C;
    }
};

// Clase derivada que representa un avion de pasajeros
class cPasajero : public cAvion
{
private:
    int Cap_Vip, Cap_Tur;

public:
    // Constructor por defecto, inicializa el tipo y la capacidad de pasajeros
    cPasajero()
        : cAvion()
    {
        Cap_Tur = Cap_Vip = 0;
        setTipo(1);
    }

    // Sobrescribe el método de lectura para incluir la capacidad de pasajeros
    void leer()
    {
        cAvion::leer();
        cout << "Ingrese la Capacidad de pasajeros VIP: ";
        cin >> Cap_Vip;
        cout << "Ingrese la Capacidad de pasajeros Turistas: ";
        cin >> Cap_Tur;
    }

    // Sobrescribe el método de mostrar para incluir la capacidad de pasajeros
    void mostrar()
    {
        cAvion::mostrar();
        cout << "Capacidad de pasajeros VIP: " << Cap_Vip << endl;
        cout << "Capacidad de pasajeros Turistas: " << Cap_Tur << endl;
    }

    // Método de obtencion de la cantidad total de pasajeros
    int Cant_Pas()
    {
        return Cap_Tur + Cap_Vip;
    }
};

// Clase que representa un aeropuerto y gestiona aviones
class cAeropuerto
{
private:
    string Nombre, Direccion;
    int Cant_Aviones;
    cAvion* pA[100];

public:
    // Constructor por defecto
    cAeropuerto()
    {
        Nombre = Direccion = "";
        Cant_Aviones = 0;
    }

    // Método para ingresar informacion del aeropuerto y agregar aviones
    void Leer()
    {
        cout << "Nombre del Aeropuerto: ";
        cin >> Nombre;
        cout << "Direccion: ";
        cin >> Direccion;
        nuevoAvion();
    }

    // Método para agregar un nuevo avion al aeropuerto
    void nuevoAvion()
    {
        if (Cant_Aviones < 100)
        {
            bool b = true;
            do
            {
                int tipo = menu();
                switch (tipo)
                {
                case 1:
                    pA[Cant_Aviones] = new cPasajero();
                    cout << Cant_Aviones + 1 << " Avion de pasajeros: " << endl;
                    pA[Cant_Aviones++]->leer();
                    break;
                case 2:
                    pA[Cant_Aviones] = new cCarga();
                    cout << Cant_Aviones + 1 << " Avion de carga: " << endl;
                    pA[Cant_Aviones++]->leer();
                    break;
                case 3:
                    b = false;
                    cout << "Saliendo del programa....." << endl;
                    break;
                }
            } while (Cant_Aviones < 100 && b == true);
        }
    }

    // Método para mostrar un menú y obtener la opcion del usuario
    int menu()
    {
        int n;
        cout << "\n\t Menú" << endl;
        cout << " [1] Avion de Pasajeros:" << endl;
        cout << " [2] Avion de Carga:" << endl;
        cout << " [3] Salir:" << endl;
        do
        {
            cout << " Ingrese la Opcion: ";
            cin >> n;
        } while (n < 1 || n > 3);
        return n;
    }

    // Método para mostrar informacion detallada de aviones de pasajeros con capacidad mayor o igual a un valor ingresado
    void MostrarCapPas()
    {
        cout << "\n\tNombre" << Nombre << endl;
        cout << "Direccion: " << Direccion << endl;
        cout << "\n\t---AVIONES CON CANTIDAD DE PASAJEROS MAYOR IGUAL AL VALOR INGRESADO---" << endl;
        int Valor = LeerValor();
        for (int i = 0; i < Cant_Aviones; i++)
        {
            if (pA[i]->getTipo() == 1)
            {
                cPasajero* pAp = (cPasajero*)pA[i];
                if (pAp->Cant_Pas() >= Valor)
                {
                    cout << endl;
                    pA[i]->mostrar();
                }
            }
        }
    }

    // Método para obtener un valor ingresado por el usuario
    int LeerValor()
    {
        int Valor;
        cout << "\nIngrese un valor_ Usuario: ";
        cin >> Valor;
        return Valor;
    }

    // Método para eliminar un avion
    void EliminarAvion()
    {
        int pos = buscar();
        if (pos == -1)
        {
            cout << "Avion no eliminado" << endl;
        }
        else
        {
            delete pA[pos];
            pA[pos] = pA[--Cant_Aviones];
            cout << "Avion eliminado" << endl;
        }
    }

    // Método para leer la identificacion de un avion
    string leerID()
    {
        string id;
        cout << "\nIngrese la Identificacion del Avion Accidentado: ";
        cin >> id;
        return id;
    }

    // Método para buscar la posicion de un avion por su identificacion
    int buscar()
    {
        string id = leerID();
        int pos = -1, i = 0;
        while (i < Cant_Aviones && pos == -1)
        {
            if (pA[i]->getID() == id)
            {
                pos = i;
            }
            i++;
        }
        return pos;
    }

    // Destructor que libera la memoria de los aviones
    ~cAeropuerto()
    {
        for (int i = 0; i < Cant_Aviones; i++)
        {
            delete pA[i];
        }
    }
};

// Funcion principal
int main()
{
    setlocale(LC_ALL, "");
    cAeropuerto* pAe = new cAeropuerto();

    // Operaciones principales
    pAe->Leer();
    pAe->MostrarCapPas();
    pAe->EliminarAvion();
    pAe->nuevoAvion();

    // Liberar memoria al finalizar
    delete pAe;

    return 0;
}