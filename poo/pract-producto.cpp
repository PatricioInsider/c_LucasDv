#include <iostream>
#include <string.h>

using namespace std;

class Producto
{
private:
    string nombre,fecha,lote;
public:
    Producto(/* args */);
    ~Producto();
    void leer()
    {
        cout<<"Nombre del producto:"<<endl;
        cin>>nombre;
        cout<<"Fecha de caducidad formato (AAAAMMDD): "<<endl;
        cin>>fecha;
        cout<<"Ingresa el numero de lote: "<<endl;
        cin>>lote;
        
    }

    void mostrar()
    {
        cout<<nombre<<"\t"<<fecha<<"\t"<<lote<<"\t";
    }
    
};

Producto::Producto(/* args */)
{
}

Producto::~Producto()
{
}

class ProductoFresco: public Producto
{
private:
	string id;
public:
    ProductoFresco(/* args */);
    ~ProductoFresco();
    void leer()
    {
        leer();
        cout<<"Identificador: "<<endl;
        cin>>id;
        cout<<"***"<<endl;
    }

    int mostrar()
    {
        mostrar();
        cout<<id<<"\t"<<endl;
    }
    string getid()
    {
    	return id;
	}
};

ProductoFresco::ProductoFresco(/* args */)
{
}

ProductoFresco::~ProductoFresco()
{
}

class ProductoCongelado: public Producto
{
private:
    float temperatura;
public:
    ProductoCongelado(/* args */);
    ~ProductoCongelado();
    void leer_proCongelado()
    {
        leer();
        cout<<"Temperatura de congelacion recomendada(grados Ccelsius): "<<endl;
        cin>>temperatura;
        cout<<"***"<<endl;
    }

    void mostrar()
    {
        mostrar();
        cout<<temperatura<<"\t"<<endl;
        
    }
    float gettemperatura()
    {
        return temperatura;
    }
};

ProductoCongelado::ProductoCongelado(/* args */)
{
}

ProductoCongelado::~ProductoCongelado()
{
}

class Empresa
{
private:
    string nombre,direccion; 
    ProductoCongelado oCongelado[100];
    ProductoFresco oFresco[100];
    int nCongelado,nFresco;
public:
    Empresa(/* args */);
    ~Empresa();
    
    void ing_congelado()
    {
    	for (int i = 0; i < nCongelado; i++)
        {
        	cout<<"Ingresa Datos Del Producto Congelado "<<i+1<<endl;
            oCongelado[i].leer_proCongelado();
        }
	}
	void ing_fresco()
	{
		for (int i = 0; i < nFresco; i++)
        {
        	cout<<"Ingresa Datos Del Producto Frescos "<<i+1<<endl;
            oFresco[i].leer();
        }
	}
    void leer_empresa()
    {
    	cout<<"____________________________________________"<<endl;
        cout<<"Empresa Agroalimentaria"<<endl;
		cout<<"Ingreso de Datos totales"<<endl;
        cout<<"Nombre de la empresa: "<<endl;
        cin>>nombre;
        cout<<"Direccion:"<<endl;
        cin>>direccion;
        cout<<"Cantidad de productos congelados"<<endl;
        cin>>nCongelado;
        while (nCongelado<0)
        {
        	cout<<"Ingresa un valor positivo"<<endl;
        	cin>>nCongelado;
		}
        ing_congelado();
        system("pause");
        system("cls");
        cout<<"Cantidad de productos frescos"<<endl;
        cin>>nFresco;
        while (nFresco<0)
        {
        	cout<<"Ingresa un valor positivo"<<endl;
        	cin>>nFresco;
		}
        ing_fresco();
        system("pause");
        system("cls");
        
    }
    int ubi(string bus)
	{
    	int pos= -1;
        int i=0;
        if (nFresco>0)
        cout<<"Buscando..."<<endl;
        {
        	while ((pos==-1)&&(i<nFresco))
        	{
            if (oFresco[i].getid()==bus)
            {
                pos=i;
            }
            i++;
        	}
        	return pos;
				
		}
	}
    void bus_fresco()
    {
    	cout<<"____________________________________________"<<endl;
    	cout<<"Buscar un producto Fresco por Identificador"<<endl;
        string bus;
        cout<<"id del Producto Fresco a Buscar"<<endl;
        cin>>bus;
        //encabezado y verificar si hay o no hay elementos en la lista
        cout<<"Nombre\t"<<"F Cadu\t"<<"Iden \t"<<endl;
		int aux=ubi(bus);
		if (aux==-1)
		{
			cout<<"No se encontro el producto"<<endl;
		}else{
			oFresco[aux].mostrar();
		}
		
        

    }
    //Temperaturas <=-4

    void tem_congelado()
    {
        cout<<"____________________________________________"<<endl;
		cout<<"Todos los productos menores o iguales a -4 de temperatura"<<endl;
        //Impresion de productos congelados -4 
        cout<<"Nombre\t F Cad\t Lote\t Temp\t"<<endl;
        for (int i = 0; i <nCongelado ; i++)
        {
            if (oCongelado[i].gettemperatura()<=-4)
            {
                oCongelado[i].mostrar();
            }
            
        }
        

    }
};

Empresa::Empresa()
{
}

Empresa::~Empresa()
{
}



int main ()
{
    Empresa SanJuan; 
    SanJuan.leer_empresa();
    SanJuan.bus_fresco();
    SanJuan.tem_congelado();
}
