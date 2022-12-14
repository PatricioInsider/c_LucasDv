#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class Cliente
{
	private:
		string ci,nombres,apellidos;
		float cantidadFrutas;
	public:
		void leer()
		{
			cout<<"Ingresa los datos"<<endl;
			cout<<"CI:"<<endl;
			cin>>ci;
			cout<<"Nombres"<<endl;
			cin>>nombres;
			cout<<"Apellidos"<<endl;
			cin>>apellidos;
			cout<<"Cantidad de frutas "<<endl;
			cin>>cantidadFrutas;
			cout<<"_____________________________"<<endl;
				
		}
		
		float precio_cli()
		{
			return (cantidadFrutas*2.45);
		}
		void mostrar()
		{
			cout<<ci<<"\t"<<nombres<<"\t"<<apellidos<<"\t"<<cantidadFrutas<<"\t"<<precio_cli()<<"\t";
		}
		
		string getc(){
			return ci;
		}
		string getn(){
			return nombres;
		}
		string geta(){
			return apellidos;
		}
		float getcF(){
			return cantidadFrutas;
		}
				
};

class Afiliado: public Cliente
{
	private: 
		string codigoAfiliado;
	public:
		void leer_afiliado()
		{
			leer();
			cout<<"Codigo de afiliado: ";
			cin>>codigoAfiliado;
		}
		float precio_afi()
		{
			return (getcF()*2.15);
		}
		void mostrar_afiliado()
		{
			cout<<getc()<<"\t"<<getn()<<"\t"<<geta()<<"\t"<<getcF()<<"\t"<<precio_afi()<<"\t";
			cout<< codigoAfiliado<<endl;
		}
		
};

class Fruteria
{
	private:
		string nombre,direccion;
		int nCli,nAfi;
		Cliente oCliente[100];
		Afiliado oAfiliado[100];
	public:
		
		//a. Ingresar la información de la frutería y sus clientes y afiliados
		void leer_fruteria()
		{
			cout<<"Ingresa los datos "<<endl;
			cout<<"Nombre de la fruteria: ";
			cin>>nombre;
			cout<<"Direccion de la fruteria:";
			cin>>direccion;
			cout<<"Cantidad de clientes: ";
			cin>>nCli;
			cout<<"Cantidad de Afiliados:";
			cin>>nAfi;
			ing_cli();
			ing_afi();
			system("pause");
			
		}
		
		void ing_afi()
		{
			for (int i=0;i<nAfi;i++)
			{
				cout<<"Afiliado "<<i+1<<endl;
				oAfiliado[i].leer_afiliado();
			}
		}
		
		void ing_cli()
		{
			for (int i=0;i<nCli;i++)
			{
				cout<<"Cliente "<<i+1<<endl;
				oCliente[i].leer();
			}
		}
		
		void mos_cliente()
		{
			cout<<"Id\t"<<"Nombres\t"<<"Apellidos\t"<<"Cant F\t"<<"Precio F\t"<<endl;
			for (int i=0;i<nCli;i++)
			{
				oCliente[i].mostrar();
			}
		}
		
		void mos_afiliado()
		{
			cout<<"Id\t"<<"Nombres\t"<<"Apellidos\t"<<"Cant F\t"<<"Precio F\t"<<"Cd Afi\t"<<endl;
			for (int i=0;i<nAfi;i++)
			{
				oAfiliado[i].mostrar_afiliado();
				cout<<endl;
			}
		}
		//b.Mostrar la información de la frutería y sus clientes y afiliados
		void mostrar_fruteria()
		{
			cout<<"Datos generales de la Fruteria: "<<endl;
			cout<<"Nombre:"<<nombre<<endl;
			cout<<"Direccion: "<<direccion<<endl;
			mos_afiliado();
			mos_cliente();
			system("pause");
		}
		
		float me_cli()
		{
			if(nCli>0)
			{
				int menos=oCliente[0].precio_cli();
				for(int i;i<nCli;i++)
				{
					if (oCliente[i].precio_cli()<menos)
					{
						menos=oCliente[i].precio_cli();
					}
				}
				return menos;
			}
		}
		//c.Mostrar el cliente que menos ha comprado (en $)
		void menos_cliente()
		{
			cout<<"Cliente menos "<<endl;
			cout<<"Id\t"<<"Nombres\t"<<"Apellidos\t"<<"Cant F\t"<<"Precio \t"<<endl;
			for (int i=0;i<nCli;i++)
			{
				if (oCliente[i].precio_cli()==me_cli())
				{
					oCliente[i].mostrar();
				}
			}
			system("pause");
		};
		
		float may_afi()
		{
			if(nAfi>0)
			{
				int may=oAfiliado[0].precio_afi();
				for(int i;i<nAfi;i++)
				{
					if (oAfiliado[i].precio_afi()<may)
					{
						may=oAfiliado[i].precio_afi();
					}
				}
				return may;
			}
		}
		//d.Mostrar el afiliado que mas ha comprado (en $)
		void mas_afiliado()
		{
			cout<<"Afiliado mas "<<endl;
			cout<<"Id\t"<<"Nombres\t"<<"Apellidos\t"<<"Cant F\t"<<"Precio F\t"<<"Cd Afi\t"<<endl;
			for (int i=0;i<nAfi;i++)
			{
				if (oAfiliado[i].precio_afi()==may_afi())
				{
					oAfiliado[i].mostrar_afiliado();
				}
			}
			system("pause");
		};
		
		
		void cinco_afi()
		{
			for (int i=0;i<nAfi;i++)
			{
				if (oAfiliado[i].precio_afi()>=100)
				{
					oAfiliado[i].mostrar_afiliado();
				}
			}
		}
		void cinco_cli()
		{
			for (int i=0;i<nCli;i++)
			{
				if (oCliente[i].precio_cli()>=100)
				{
					oCliente[i].mostrar();
				}
			}
		}
		
		//e.Mostrar todos los clientes y afiliados que han comprado más de $100.00
		void mas_cli_afi()
		{
			cout<<"________________________"<<endl;
			cout<<"Mayor a 100"<<endl;
			cout<<"Afiliado mas "<<endl;
			cout<<"Id\t"<<"Nombres\t"<<"Apellidos\t"<<"Cant F\t"<<"Precio F\t"<<"Cd Afi\t"<<endl;
			cinco_afi();
			cout<<"Id\t"<<"Nombres\t"<<"Apellidos\t"<<"Cant F\t"<<"Precio \t"<<endl;
			cinco_cli();
			system("pause");
		}
		
};


int main() {
	Fruteria DoniaPetrona;
	DoniaPetrona.leer_fruteria();//a
	DoniaPetrona.mostrar_fruteria();//b
	DoniaPetrona.menos_cliente();//c
	DoniaPetrona.mas_afiliado();//4
	DoniaPetrona.mas_cli_afi();//5
	return 0;
}
