/*
Se desea elaborar un programa orientado a objetos en el lenguaje de programación C++ que permita gestionar la información de los trabajadores de una empresa de la que se conoce su nombre y dirección.

De los trabajadores contratados se conoce su CI, nombres, apellidos, cantidad de horas trabajadas y valor de la hora trabajada del mes. El total a pagar en el mes se calcula como cantidad de horas trabajadas multiplicado por el valor de la hora trabajada.

De los trabajadores con nombramiento se conoce su CI, nombres, apellidos, salario y descuentos del mes. El total a pagar en el mes se calcula como salario menos los descuentos. 

Ingresar la información de la empresa y sus trabajadores
Mostrar la información de la empresa y los trabajadores que ganan más que un valor ingresado por el usuario del programa.
Mostrar el total a pagar del mes por la empresa.
Mostrar de los trabajadores contratados el que MENOS y el MÁS gana 
Mostrar TODOS los trabajadores contratados que ganan igual que el trabajador contratado que MENOS gana.
*/
#include <iostream>
#include <string.h>

using namespace std;

class Trabajador
{
private:
    string id, nom,apell;
    float total;
public:
    Trabajador(/* args */);
    ~Trabajador();

    void leer_trabajador()
    {
        cout<<"Id: "<<endl;
        cin>>id;
        cout<<"Nombre; "<<endl;
        cin>>nom;
        cout<<"Apellido:"<<endl;
        cin>>apell;
    }
    void mostrar_trabajadores()
    {
        cout<<id<<"\t"<<nom<<"\t"<<apell<<"\t"<<total<<"\t"<<endl;
    }

    string getid ()
    {
        return id;
    }
    string getnom ()
    {
        return nom;
    }
    string getapell ()
    {
        return apell;
    }
    void settotal(float a )
    {
        total=a;
    }
    float gettotal()
    {
        return total;
    }
};

Trabajador::Trabajador(/* args */)
{
}

Trabajador::~Trabajador()
{
}


// Clase que representa a un trabajador contratado
class TrabajadorContratado {

  Trabajador persona;
  int horaTrabajadas;
  float valorHoras;
 public:
    void leer_contra()
    {
        persona.leer_trabajador();
        cout<<"Horas Trabajadas: "<<endl;
        cin>>horaTrabajadas;
        cout<<"Valor de la Hora: "<<endl;
        cin>>valorHoras;
    }

    float v_pagar()
    {
        persona.settotal(horaTrabajadas*valorHoras);
        return(horaTrabajadas*valorHoras);
    }
    void mostrar_contra()
    {
        persona.mostrar_trabajadores();
    }
  
};

class TrabajadorNombramiento
{
private:
    Trabajador Persona;
    float salario,desc;
public:
    TrabajadorNombramiento(/* args */);
    ~TrabajadorNombramiento();

    void leer_nombra()
    {
        Persona.leer_trabajador();
        cout<<"Salario: "<<endl;
        cin>>salario;
        cout<<"Descuentos: "<<endl;
        cin>>desc;
    }

    float v_pagar()
    {
        return salario -desc;
        Persona.settotal(salario -desc);
    }
    void mostrar_nombra()
    {
        Persona.mostrar_trabajadores();
    }
};

TrabajadorNombramiento::TrabajadorNombramiento(/* args */)
{
}

TrabajadorNombramiento::~TrabajadorNombramiento()
{
}



class Empresa
{
private:
    TrabajadorContratado oContra[100];
    TrabajadorNombramiento oNombra[100];
    string nombre_empresa,direccion_empresa;
    int nContra,nNombra;
    float totalPagar;
public:
    Empresa(/* args */);
    ~Empresa();
    

    void pedir_contra()
    {
        for (int i=0;i<nContra;i++)
			{
				cout<<"Trabajador Contratado "<<i+1<<endl;
				oContra[i].leer_contra();
			}
    }
    void pedir_nombra()
    {
        for (int i=0;i<nNombra;i++)
			{
				cout<<"Cliente "<<i+1<<endl;
				oNombra[i].leer_nombra();
			}
    }
    //informacion de la empresa y sus trabajadores
    void leer_empresa()
    {
        cout<<"Nombre de la empresa: "<<endl;
        cin>>nombre_empresa;
        cout<<"Direccion: "<<endl;
        cin>> direccion_empresa;
        cout<<"Cantidad de Trabajadores Contratados: "<<endl;
        cin>>nContra;
        pedir_contra();

        cout<<"___________________________________________"<<endl;
        cout<<"CAntidad de Trabajadores Nombrados: "<<endl;
        cin>>nNombra;
        pedir_nombra();
    }

    //Mostrar la informacion de la empresa

    void mos_contra()
    {
        cout<<"Trabajadores Contratados"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl;
        for(int i = 0; i<nContra;i++)
        {
            oContra[i].mostrar_contra();
        }

    }

    void mos_nombra()
    {
        cout<<"Trabajadores Nombramiento"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl;
        for(int i = 0; i<nNombra;i++)
        {
            oNombra[i].mostrar_nombra();
        }

    }
    void info_empresa()
    {
        cout<<"______________________________________"<<endl;
        
        cout<<"Informacion de la empresa"<<endl;
        cout<<"Nombre: "<<nombre_empresa<<endl;
        cout<<"Direccion: "<<direccion_empresa<<endl;
        cout<<"Trabajadores Contratados"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl;
        mos_contra();      
        cout<<"Trabajadores Nombrados"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl;  
        mos_nombra();
    }
    //muestra el total apagar
    void total_pagar()
    {
        cout<<"______________________________________"<<endl;
        
        float aux=0;
        cout<<"La empresa sebera pagar: "<<endl;
        for (int i = 0; i < nContra; i++)
        {
            aux+=oContra[i].v_pagar();
        }
        for (int i = 0; i < nNombra; i++)
        {
            aux+=oNombra[i].v_pagar();
        }
        cout<<"Total a pagar es: "<<aux<<endl;
        
    }
    //Mostat de los trabajadores contratados el que menos y mas a ganado
    int me_contra()
    {
        int pos=0;
        if(nContra>0)
			{
				int menos=oContra[0].v_pagar();
				for(int i;i<nContra;i++)
				{
					if (oContra[i].v_pagar()<menos)
					{
                        pos=i;
					}
				}
				return pos;
			}
    }
    void menos_contra()
    {
        for (int i=0;i<nContra;i++)
			{
				if (oContra[i].v_pagar()==me_contra())
				{
					oContra[i].mostrar_contra();
				}
			}
			system("pause");

    };

    int ma_contra()
    {
        int pos=0;
         if(nContra>0)
			{
				int menos=oContra[0].v_pagar();
				for(int i;i<nContra;i++)
				{
					if (oContra[i].v_pagar()>menos)
					{
						menos=oContra[i].v_pagar();
                        pos=i;
					}
				}
				return pos;
			}
    }
    void mas_contra()
    {
        for (int i=0;i<nContra;i++)
			{
				if (oContra[i].v_pagar()==ma_contra())
				{
					oContra[i].mostrar_contra();
				}
			}
			system("pause");
    };


    void men_mas_contra()
    {
        cout<<"______________________________________"<<endl;
        
        cout<<"Judor con menos ganado es:"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl; 
        menos_contra();
        oContra[me_contra()].mostrar_contra();  
        cout<<"Jugador con mas ganado es:"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl; 
        oContra[ma_contra()].mostrar_contra();        
    }

    //mostrar todos igual al menos contratado
    void all_menos_contratados()
    {
        cout<<"______________________________________"<<endl;
        
        cout<<"Judores con menos ganado es:"<<endl;
        cout<<"id\t"<<"nomb\t"<<"Apell\t"<<"Valor\t"<<endl;
        for (int i=0;i<nContra;i++)
			{
				if (oContra[i].v_pagar()==oContra[me_contra()].v_pagar())
				{
					oContra[i].mostrar_contra();
				}
			}
			system("pause");

    }
};

Empresa::Empresa(/* args */)
{
}

Empresa::~Empresa()
{
}


int main()
{
    Empresa oValles;
    oValles.leer_empresa();
    oValles.info_empresa();
    oValles.total_pagar();
    oValles.men_mas_contra();
    oValles.all_menos_contratados();
}
