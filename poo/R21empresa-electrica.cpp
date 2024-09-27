#include <iostream>
#include <string>

using namespace std;

class Facturas
{
private:
    string numFactura, numMedidor, ci;
    float lecAnterior, lecActual;
    float valork;
    int tipo;

public:
    Facturas(/* args */);
    ~Facturas();
    virtual void leer()
    {
        cout << "Numero de Factura: ";
        cin >> numFactura;
        cout << "Numero del Medidor: ";
        cin >> numMedidor;
        cout << "Cedula de identidad del due�o del medidor:";
        cin >> ci;
        cout << "ingresa el valor de Kwh" << endl;
        cin >> valork;
        cout << "Lectura Anterior: ";
        cin >> lecAnterior;
        cout << "Lectura Actual: ";
        cin >> lecActual;
        while (lecActual <= lecAnterior)
        {
            cout << "Te recuerdo que la lectura actual no puede ser menor de la anterior" << endl;
            cout << "Lectura Actual: ";
            cin >> lecActual;
        }
    }

    virtual void mostrar()
    {
        cout << "Numero de Factura: " << numFactura << endl;
        cout << "Numero del Medidor: " << numMedidor << endl;
        cout << "Cedula de identidad del due�o del medidor:" << ci << endl;
        cout << "Lectura Anterior: " << lecAnterior << endl;
        cout << "Lectura Actual: " << lecActual << endl;
    }
    string getnumFactura()
    {
        return numFactura;
    }
    float getlecActual()
    {
        return lecActual;
    }
    float getlecAnterior()
    {
        return lecAnterior;
    }
    float getvalork()
    {
        return valork;
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

Facturas::Facturas(/* args */)
{
    numFactura=numMedidor=ci="";
    tipo = 0;
    lecActual=lecAnterior=valork=0;
}

Facturas::~Facturas()
{
}

class FacResidencial : public Facturas
{
private:
    float des;
public:
    FacResidencial(/* args */);
    ~FacResidencial();
    void leer()
    {
        Facturas::leer();
        cout << "Ingresa el descuento: ";
        cin >> des;
        while(des<0)
        {
            cout << "De no tener descuento ingresa 0, pero no se puede ingresar un valor negativo"<<endl;
            cout << "descuentos: " << endl;
        cin >> des;
        }
    }

    float total_pagar()
    {
        float totalAPagar;
        totalAPagar = ((getlecActual() - getlecAnterior()) * getvalork()) - (des);
    }
    void mostrar()
    {
        Facturas::mostrar();
        cout << "Total a pagar: " << total_pagar()<<endl;
    }
    
};

FacResidencial::FacResidencial(/* args */)
{
    des=0;
    settipo(1);
}

FacResidencial::~FacResidencial()
{
}

class FacIndustrial : public Facturas
{
private:
    float facMulti;

public:
    FacIndustrial(/* args */);
    ~FacIndustrial();
    void leer()
    {
        Facturas::leer();
        cout << "Factor multiplicar: " << endl;
        cin >> facMulti;
        while (facMulti<0)
        {
            cout << "De no tener descuento ingresa 0, pero no se puede ingresar un valor negativo"<<endl;
            cout << "facmultiplicar: " << endl;
        cin >> facMulti;
        }
        
    }
    float total_pagar()
    {
        float totalAPagar;
        totalAPagar = (getlecActual() - getlecAnterior()) * facMulti * getvalork();
    }
    void mostrar()
    {
        Facturas::mostrar();
        cout<<"Fact multiplicar:"<<facMulti<<endl;
        cout << "Total a pagar: " << total_pagar()<<endl;
    }
    float getfacMulti()
    {
        return facMulti;
    }
    
};

FacIndustrial::FacIndustrial(/* args */)
{
    facMulti=0;
    settipo(2);
}

FacIndustrial::~FacIndustrial()
{
}

class EmpresaElectrica
{
private:
    string nom, ciu;
    Facturas *pFac[100];
    int n;

public:
    EmpresaElectrica(/* args */);
    ~EmpresaElectrica();

    // a ingreso de datos
    int menu()
    {
        int opc;
        cout << "Ingresa el literal\n 1)Fac Residencial 2) Fac Industrial" << endl;
        cin >> opc;
        while ((opc < 1) && (opc > 2)) // verificar
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
        cout << "Ciudad: " << endl;
        cin >> ciu;
        cout << "Numero de facturas a ingresasr" << endl;
        cin >> n;

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                switch (menu())
                {
                case 1:
                    cout << "(Factura Residencial)" << endl;
                    pFac[i] = new FacResidencial;
                    pFac[i]->leer();
                    break;
                case 2:
                    cout << "(Factura Industrial)" << endl;
                    pFac[i] = new FacIndustrial;
                    pFac[i]->leer();

                default:
                    break;
                }
            }
        }
    }

    // imprimir todos los datos de una factura dado su numero
    int busqueda(string bus)
    {
        int pos = -1;
        int i = 0;
        if (n > 0)
        {
            cout << "Buscando..." << endl;
            while ((pos == -1) && (i < n))
            {

                if (pFac[i]->getnumFactura() == bus)
                {
                    pos = i;
                }
                i++;
            }
            return pos;
        }
    }
    void mostrar_nfactura()
    {
        cout<<"______________Literal de busqueda Num Factura_______________"<<endl;
        string v;
        int pos;
        cout << "Ingresa el numero de la factura: " << endl;
        cin >> v;
        pos = busqueda(v);
        if (pos == -1)
        {
           
            cout << "no se encontro la factura" << endl;
        }
        else
        {
            pFac[pos]->mostrar();
            
        }
        cout<<"______"<<endl;
    }
    // Mostrar la informacion de todas las figuras industriales
    void mostrar_findutriales()
    {
                cout<<"______________Literal de busqueda Facmulti_______________"<<endl;
        int con=0;
        float v;
        cout << "Ingresa el valor de factor de multiplicacion" << endl;
        cin >> v;
        if (n > 0)
        {
            // tycast
            for (int i = 0; i < n; i++)
            {
                if (pFac[i]->gettipo() == 2)
                {
                    FacIndustrial *pAux = (FacIndustrial *)pFac[i];
                if (pAux->getfacMulti() > v)
                {
                    pAux->mostrar();
                    cout<<endl;
                    cout<<"__________"<<endl;
                    con+=1;
                }
                }

                
            }
            if (con==0)
            {
                cout<<"No se encontro ninguna factura con la caracteristica"<<endl;
            }
            
        }
    }
};

EmpresaElectrica::EmpresaElectrica(/* args */)
{
    
}

EmpresaElectrica::~EmpresaElectrica()
{
    for (int i = 0; i < n; i++)
    {
        delete pFac[i];
    }
    
} 

int main()
{
    EmpresaElectrica *pCentral = new EmpresaElectrica;
    pCentral->leer();
    pCentral->mostrar_nfactura();
    pCentral->mostrar_findutriales();
    delete pCentral;
};