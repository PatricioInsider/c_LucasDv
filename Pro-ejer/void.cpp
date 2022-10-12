#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
//Menu del sistema


void menu(){
  cout<<"menu"<<endl;
  cout<<"1. Imprimir la cantidad de dígitos que se compone el número entero N"<<endl;
  cout<<"2.Imprimir el dígito mayor y el dígito menor"<<endl;
  cout<<"3. Imprimir la suma y el promedio de los dígitos"<<endl;
  cout<<"4.Imprimir los dígitos en orden descendente (de mayor a menor)"<<endl;
  cout<<"5. Salir"<<endl;
}
int cantidad(int vec[],int);
void orden(int cifras[],int);
void menmay(int cifras[],int);
void sumpro(int cifras[],int);


int main() {
    
    int cifras[20];
    int num,opc=0;
    cout << "Ingrese un numero entero \n";
    cout<<"(Recuerda ingresar un numero entero sino el programa se cerrara automaticamente)\n";
    cin>>num;

    //Numero de cifras
    int n=0;
    
    n=cantidad(cifras,num);

    int x=0;
    do
    {
        cout<<"___________\n";
        menu();
        cin>>opc;
        fflush(stdin);
        system("Pause");
        switch(opc){
        case 1:
            cout<<"Hay "<<n<<" digitos en este numero"<<endl;
        break;
        case 2:
            
            menmay(cifras,num);
        break;

        case 3:
            sumpro(cifras,num);
        
        break;

        case 4:
            
            cout<<endl;
            orden(cifras,num);
        break;

        case 5:
            cout<<"Gracias por usar el sistema"<<endl;
            x=10;
        break;
        default:
            cout<<"No se reconocio la orden del sistema"<<endl;
        break;
    }
    } while (x!=10);
    
}

int cantidad(int vec[],int num){
    int n=0;
    while (num>0)
	{
	    vec[n]=num%10;
		num=num/10;
		n++;
	}
    
    return n;
}

void orden(int cifras[],int num){
    int n=0;
    while (num>0)
	{
	    cifras[n]=num%10;
		num=num/10;
		n++;
	}
    int aux=0;
    for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    if (cifras[j]<cifras[j+1])
                    {
                        aux = cifras[j];
                        cifras[j]=cifras[j+1];
                        cifras[j+1]=aux;
                    }
                }
            }

            cout<<"Numeros descerndentes: ";
            for (int i = 0; i < n; i++)
            {
                cout<<cifras[i]<<", ";
            }
}

void menmay(int cifras[],int num){
    int n=0,men=0,may=0;
    while (num>0)
	{
	    cifras[n]=num%10;
		num=num/10;
		n++;
	}
    int aux=0;
    for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    if (cifras[j]<cifras[j+1])
                    {
                        aux = cifras[j];
                        cifras[j]=cifras[j+1];
                        cifras[j+1]=aux;
                    }
                }
            }
    may = cifras[0];
    men = cifras[n-1];
    cout<<"Digito mayor: "<<may<<endl;
    cout<<"Digito menor: "<<men<<endl;
    
}

void sumpro(int cifras[],int num){
    int n=0,sum=0,pro=0;
    while (num>0)
	{
	    cifras[n]=num%10;
		num=num/10;
		n++;
	}
    for (int i = 0; i < n; i++)
    {
        sum +=cifras[i];
    }
    pro=sum/n;
    cout<<"La suma de las cifras es: "<<sum<<endl;
    cout<<"Eñ promedio de los dijitos es: "<<pro<<endl;
}