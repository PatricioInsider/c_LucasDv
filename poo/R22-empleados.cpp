#include <iostream>
#include <string>

using namespace std;

class Trabajador
{
private:
    string ci, nom, ape;
    int tipo;

public:
    Trabajador(/* args */);
    ~Trabajador();
    virtual void leer()
    {
        cout << "Ci: " << endl;
        cin >> ci;
        cout << "Nombre; " << endl;
        cin >> nom;
        cout << "Apellido:" << endl;
        cin >> ape;
    }

    virtual void mostrar()
    {
        cout << "Ci: " << ci << endl;
        cout << "Nombre; " << nom << endl;
        cout << "Apellido:" << ape << endl;
    }
    void settipo(int newtipo)
    {
        tipo = newtipo;
    }
    int gettipo()
    {
        return tipo;
    }
};

Trabajador::Trabajador(/* args */)
{
    tipo = 0;
}

Trabajador::~Trabajador()
{
}

class TraContratado : public Trabajador
{
private:
    float canHora, valHora;

public:
    TraContratado(/* args */);
    ~TraContratado();
    void leer()
    {
        Trabajador::leer();
        cout << "Cantidad de horas trabajadas: " << endl;
        cin >> canHora;
        cout << "Valor por hora" << endl;
        cin >> valHora;
    }

    void mostrar()
    {
        Trabajador::mostrar();
        cout << "Cantidad de horas trabajadas: " << canHora << endl;
        cout << "Valor por hora" << valHora << endl;
        cout << "A Pagar: " << aPagar() << endl;
    }

    float aPagar()
    {
        return (canHora * valHora);
    }
    float getvalHora()
    {
        return valHora;
    }
};

TraContratado::TraContratado(/* args */)
{
    settipo(1);
}

TraContratado::~TraContratado()
{
}

class TraNombramiento : public Trabajador
{
private:
    float salario, des;

public:
    TraNombramiento(/* args */);
    ~TraNombramiento();
    void leer()
    {
        Trabajador::leer();
        cout << "Salario: " << endl;
        cin >> salario;
        cout << "descuentos: " << endl;
        cin >> des;
        while(des<0)
        {
            cout << "De no tener descuento ingresa 0, pero no se puede ingresar un valor negativo"<<endl;
            cout << "descuentos: " << endl;
        cin >> des;
        }
    }

    float aPagar()
    {
        return (salario - des);
    }
    void mostrar()
    {
        Trabajador::mostrar();
        cout << "Salario: " << salario << endl;
        cout << "descuentos: " << des << endl;
        cout << "A Pagar: " << aPagar() << endl;
    }
    float getdes()
    {
        return des;
    }
};

TraNombramiento::TraNombramiento(/* args */)
{
    settipo(2);
}

TraNombramiento::~TraNombramiento()
{
}

class TraDestajo : public Trabajador
{
private:
    float canVendida, salario, porGanancia;

public:
    TraDestajo(/* args */);
    ~TraDestajo();
    void leer()
    {
        Trabajador::leer();
        cout << "Salario: " << endl;
        cin >> salario;
        cout << "cantidad vendida en el mes (en dólares)" << endl;
        cin >> canVendida;
        while(canVendida<0)
        {
            cout << "De no tener descuento ingresa 0, pero no se puede ingresar un valor negativo"<<endl;
            cout << "descuentos: " << endl;
        cin >> canVendida;
        }
        cout << "porciento de ganancia: " << endl;
        cin >> porGanancia;
    }
    float aPagar()
    {
        float aux;
        aux = salario + (canVendida * (porGanancia / 100));
        return (aux);
    }
    void mostrar()
    {
        Trabajador::mostrar();
        cout << "Salario: " << salario << endl;
        cout << "cantidad vendida en el mes (en dólares)" << canVendida << endl;
        cout << "porciento de ganancia: " << porGanancia << endl;
        cout << "A Pagar: " << aPagar() << endl;
    }
    float getcanVendida()
    {
        return canVendida;
    }
};

TraDestajo::TraDestajo(/* args */)
{
    settipo(3);
}

TraDestajo::~TraDestajo()
{
}
class Empresa
{
private:
    string nom, dir;
    Trabajador *pTra[100];
    int n;

public:
    Empresa(/* args */);
    ~Empresa();
    // Ingresa los datos
    int menu()
    {
        int opc;
        cout << "Ingresa el literal\n 1)Tra Contratado 2) Tra Nombramiento 3) Tra Destajo" << endl;
        cin >> opc;
        while ((opc < 1) && (opc > 3)) // verificar
        {
            cout << "ingresa de nuevo la opc" << endl;
            cin >> opc;
        }
        return opc;
    }

    void leer()
    {
        cout << "Ingresa los siguientes datos de la empresa" << endl;
        cout << "Nombre: " << endl;
        cin >> nom;
        cout << "Direccion: " << endl;
        cin >> dir;
        cout << "Numero de Trabajadores a ingresasr" << endl;
        cin >> n;

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                switch (menu())
                {
                case 1:
                    cout << "(Tra Nombramineto)" << endl;
                    pTra[i] = new TraNombramiento;
                    pTra[i]->leer();
                    break;
                case 2:
                    cout << "(Tra Contratado)" << endl;
                    pTra[i] = new TraContratado;
                    pTra[i]->leer();
                case 3:
                    cout << "(Tra Destajo)" << endl;
                    pTra[i] = new TraContratado;
                    pTra[i]->leer();

                default:
                    cout << "Nose ingreso una opcion correcta" << endl;

                    break;
                }
            }
        }
    }

    // Mostrar la información de la empresa y los trabajadores que ganan más que un valor ingresado por el usuario del programa.
    void mostrar_valor()
    {
        cout << "Nombre de la empresa" << nom << endl;
        cout << "Direccion" << dir << endl;
        float v;
        cout << "Ingresa el valor" << endl;
        
        if (n > 0)
        {
            // tycast con validacion a los tres

            for (int i = 0; i < n; i++)
            { 
                cout<<"_____________________________________________________"<<endl;


                switch (pTra[i]->gettipo())
                {
                case 1:
                    TraContratado *pAux;
                    pAux = (TraContratado *)pTra[i];
                    if (pAux->aPagar() > v)
                    {
                        pAux->mostrar();
                    }
                    break;
                
                case 2:
                    TraNombramiento *pAux2;
                    pAux2 = (TraNombramiento *)pTra[i];
                    if (pAux->aPagar() > v)
                    {
                        pAux->mostrar();
                    }
                    break;
                    
                case 3:
                    TraDestajo *pAux3 = (TraDestajo *)pTra[i];
                    if (pAux3->aPagar() > v)
                    {
                        pAux3->mostrar();
                    }
                    
                break;

            default:
                break;
            }
            
        }
    }
}
    //Mostrar el total a pagar del mes por los trabajadores contratados cuyo valor de la hora trabajada sea mayor a un valor ingresado por el usuario del programa.
    void mostrar_contratados()
    {
        float v;
        cout<<"_____________________________________________________"<<endl;
        cout<<"Ingresa el valor de la hora a comparar"<<endl;
        cin>>v;
        if (n > 0)
        {
            // tycast
            for (int i = 0; i < n; i++)
            {
                if (pTra[i]->gettipo() == 1)
                {
                    TraContratado *pAux = (TraContratado *)pTra[i];
                if (pAux->getvalHora() > v)
                {
                    pAux->mostrar();
                }
                }
            }
        }


    }
    //Mostrar los trabajadores con nombramiento que NO tienen descuentos en el mes.
    void mostrar_nombramiento_nodes()
    {
        float v=0.0;
        cout<<"_____________________________________________________"<<endl;
        if (n > 0)
        {
            // tycast
            for (int i = 0; i < n; i++)
            {
                if (pTra[i]->gettipo() == 2)
                {
                    TraNombramiento *pAux = (TraNombramiento *)pTra[i];
                if (pAux->getdes()> v)
                {
                    pAux->mostrar();
                }
                }
            }
        }
    }

    //Mostrar los trabajadores a destajo que no vendieron en el mes
    void mostrar_destajo_noven()
    {
        float v=0.0;
        cout<<"_____________________________________________________"<<endl;
        if (n > 0)
        {
            // tycast
            for (int i = 0; i < n; i++)
            {
                if (pTra[i]->gettipo() == 3)
                {
                    TraDestajo *pAux = (TraDestajo *)pTra[i];
                if (pAux->getcanVendida()> v)
                {
                    pAux->mostrar();
                }
                }
            }
        }
    }

};
Empresa::~Empresa()
{
    for (int i = 0; i < n; i++)
    {
        delete pTra[i];
    }
}

int main()
{
    Empresa *pCentral = new Empresa;
    pCentral->leer();
    pCentral->mostrar_valor();
    pCentral->mostrar_contratados();
    pCentral->mostrar_nombramiento_nodes();
    pCentral->mostrar_destajo_noven();
    delete pCentral;
}
