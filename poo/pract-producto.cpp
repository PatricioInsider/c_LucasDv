#include <iostream>
#include <string.h>

using namespace std;

class Producto
{
private:
    string nombre, fecha, lote;
    int tipo;

public:
    Producto(/* args */);
    ~Producto();
    virtual void leer()
    {
        cout << "Nombre del producto:" << endl;
        cin >> nombre;
        cout << "Fecha de caducidad formato (AAAAMMDD): " << endl;
        cin >> fecha;
        cout << "Ingresa el numero de lote: " << endl;
        cin >> lote;
    }

    virtual void mostrar()
    {
        cout << nombre << "\t" << fecha << "\t" << lote << "\t";
    }
    int gettipo()
    {
        return tipo;
    }
};

Producto::Producto(/* args */)
{
    nombre = fecha = lote = "";
    tipo = 0;
}

Producto::~Producto()
{
}

class ProductoFresco : public Producto
{
private:
    string id,origen;
    int tipo;

public:
    ProductoFresco(/* args */);
    ~ProductoFresco();
    void leer()
    {
        Producto::leer();
        cout << "Identificador: " << endl;
        cin >> id;
        
        cout << "Pais de origen: " << endl;
        cin >> origen;
        cout << "***" << endl;
    }

    void mostrar()
    {
        Producto::mostrar();
        cout << id << "\t" << endl;
    }
    string getid()
    {
        return id;
    }
    int gettipo()
    {
        return tipo;
    }
    string getorigen()
    {
        return origen;
    }
};

ProductoFresco::ProductoFresco(/* args */)
{
    tipo = 2;
}

ProductoFresco::~ProductoFresco()
{
}

class ProductoCongelado : public Producto
{
private:
    float temperatura;
    int tipo;

public:
    ProductoCongelado(/* args */);
    ~ProductoCongelado();
    void leer()
    {
        Producto::leer();
        cout << "Temperatura de congelacion recomendada(grados Ccelsius): " << endl;
        cin >> temperatura;
        cout << "***" << endl;
    }

    void mostrar()
    {
        Producto::mostrar();
        cout << temperatura << "\t" << endl;
    }
    float gettemperatura()
    {
        return temperatura;
    }
    int gettipo()
    {
        return tipo;
    }
};

ProductoCongelado::ProductoCongelado(/* args */)
{
    tipo = 2;
}
// Retorna un atributo declarado en el constructor

/*
int Producto::gettipo()
{
    return tipo;

}
*/
ProductoCongelado::~ProductoCongelado()
{
}

class Empresa
{
private:
    string nombre, direccion;
    Producto *vPs[100];
    // ProductoCongelado *oCongelado[100];
    // ProductoFresco *oFresco[100];
    int nTotal;

public:
    Empresa(/* args */);
    ~Empresa();

    void ing_congelado(int n1)
    {
        for (int i = 0; i < n1; i++)
        {
            cout << "Ingresa Datos Del Producto Congelado " << i + 1 << endl;
            vPs[i] = new ProductoCongelado;
            vPs[i]->leer();
        }
    }
    void ing_fresco(int n2)
    {
        for (int i = 0; i < n2; i++)
        {
            cout << "Ingresa Datos Del Producto Frescos " << i + 1 << endl;
            vPs[i] = new ProductoFresco;
            vPs[i]->leer();
        }
    }
    void leer()
    {
        int n1, n2;
        cout << "____________________________________________" << endl;
        cout << "Empresa Agroalimentaria" << endl;
        cout << "Ingreso de Datos totales" << endl;
        cout << "Nombre de la empresa: " << endl;
        cin >> nombre;
        cout << "Direccion:" << endl;
        cin >> direccion;
        cout << "Cantidad de productos congelados" << endl;
        cin >> n1;
        while (n1 < 0)
        {
            cout << "Ingresa un valor positivo" << endl;
            cin >> n1;
        }
        ing_congelado(n1);
        system("pause");
        system("cls");
        cout << "Cantidad de productos frescos" << endl;
        cin >> n2;
        while (n2 < 0)
        {
            cout << "Ingresa un valor positivo" << endl;
            cin >> n2;
        }
        ing_fresco(n2);
        nTotal = n1 + n2;
        system("pause");
        system("cls");
    }
    int ubi(string bus)
    {
        int pos = -1;
        int i = 0;
        if (nTotal > 0)
            cout << "Buscando..." << endl;
        {
            while ((pos == -1) && (i < nTotal))
            {
                if (vPs[i]->gettipo() == 2)
                {
                    ProductoFresco *pAux = (ProductoFresco *)vPs[i];
                    if (pAux->getid() == bus)
                    {
                        pos = i;
                    }
                }
                i++;
            }
            return pos;
        }
    }
    void bus_fresco()
    {
        cout << "____________________________________________" << endl;
        cout << "Buscar un producto Fresco por Identificador" << endl;
        string bus;
        cout << "id del Producto Fresco a Buscar" << endl;
        cin >> bus;
        // encabezado y verificar si hay o no hay elementos en la lista
        cout << "Nombre\t"
             << "F Cadu\t"
             << "Iden \t" << endl;
        int aux = ubi(bus);
        if (aux == -1)
        {
            cout << "No se encontro el producto" << endl;
        }
        else
        {
            vPs[aux]->mostrar();
        }
    }
    // Temperaturas <=-4

    void tem_congelado()
    {
        cout << "____________________________________________" << endl;
        cout << "Todos los productos menores o iguales a -4 de temperatura" << endl;
        // Impresion de productos congelados -4
        cout << "Nombre\t F Cad\t Lote\t Temp\t" << endl;
        if (nTotal > 0)
        {
            for (int i = 0; i < nTotal; i++)
            {
                if (vPs[i]->gettipo() == 2)
                {
                    ProductoCongelado *pAux = (ProductoCongelado *)vPs[i];
                    if (pAux->gettemperatura() <= -4)
                    {
                        vPs[i]->mostrar();
                    }
                }
            }
        }
    }
};

Empresa::Empresa()
{
}

Empresa::~Empresa()
{
    for (int i = 0; i < nTotal; i++)
    {
        delete vPs[i];
    }
}

int main()
{
    Empresa *ptr;
    ptr = new Empresa;
    ptr->leer();
    ptr->bus_fresco();
    ptr->tem_congelado();

    delete ptr;
    return 0;
}
