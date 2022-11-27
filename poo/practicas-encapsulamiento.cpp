#include <iostream>
#include <string.h>

using namespace std;

class Bus
{
private:
    string nombrePropietario,apellidoPropietario;
    int numero,cantidadAsientos;
public:
    Bus();
    ~Bus();

    void leer (void)
    {
        cout<<"Tabla de ingreso de datos del bus"<<endl;
        cout<<"Nombre del propietario: ";
        cin>>nombrePropietario;
        cout<<"Apellido del propietario: ";
        cin>>apellidoPropietario;
        cout<<"Numero del Bus: ";
        cin>>numero;
        cout<<"Cantidad de asientos : ";
        cin>>cantidadAsientos;

        system("cls");
    }
    void mostrar(void)
    {
        cout<<nombrePropietario<<"\t"<<apellidoPropietario<<"\t"<<numero<<"\t"<<cantidadAsientos<<endl;
    }

    //get y set a los atributos de la clase
    string getnombrePropietario(void)
    {
        return nombrePropietario;
    }
    string getapellidoPropietario(void)
    {
        return apellidoPropietario;
    }
    int getnumero(void)
    {
        return numero;
    }
    int getcantidadAsientos(void)
    {
        return cantidadAsientos;
    }

    int setnumero(int aux)
    {
        numero=aux;
    }

};

Bus::Bus()
{
    nombrePropietario=apellidoPropietario="";
    numero=cantidadAsientos=0;
}

Bus::~Bus()
{
}

class Cooperativa
{
private:
    string nombre;
    Bus oBus[100];
    int canBus,numCooperativa;

public:
    Cooperativa(/* args */);
    ~Cooperativa();

    void leer()
    {
        cout<<"Ingresa el nombre de la cooperativa"<<endl;
        cin>>nombre;
        cout<<"Ingresa el numero de la cooperativa: "<<endl;
        cin>>numCooperativa;
        cout<<"Ingresa la cantidad buses de la cooperativa"<<endl;
        cin>>canBus;
        while (canBus>100)
        {
            cout<<"Se sobrepaso la cantidad de buses (capacidad maxima=100)"<<endl;
            cout<<"Ingresa la cantidad de Buses: ";
            cin>>canBus;
        }
        
        for (int i = 0; i < canBus; i++)
        {
            cout<<"Datos Bus"<<i+1<<endl;
            
            oBus[i].leer();
        }
        
    }
void reso_Ant()
    {
        
        int aux,aux2;
        for (int i = 0; i < canBus; i++)
        {
            aux=oBus[i].getnumero()*1000;
            aux2=aux+numCooperativa;
            oBus[i].setnumero(aux2);
        }
           
    }

    void mostrar()
    {
        system("pause");
        cout<<"__________________________________________________"<<endl;
        cout<<"Buses con asientos mayores o iguales a 20"<<endl;
        cout<<"Nom"<<"\t"<<"Apell"<<"\t"<<"Num"<<"\t"<<"canAsientos"<<"\t"<<endl;
        for (int i = 0; i < canBus; i++)
        {
            if (oBus[i].getcantidadAsientos()>=20)
            {
                oBus[i].mostrar();
            }
        }
    }

};

Cooperativa::Cooperativa(/* args */)
{
    nombre="";
    canBus=0;
}

Cooperativa::~Cooperativa()
{
}

int main (void)
{
    Cooperativa Valle;
    Valle.leer();
    Valle.reso_Ant();
    Valle.mostrar();
    return 0;
}
