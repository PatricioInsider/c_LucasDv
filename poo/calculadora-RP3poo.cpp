#include <iostream>
//Programa orientado a objetos,ingreso a y b,calculadora
using namespace std;
//Comenzar de nuevo
class Calculadora
{
private:
    /* data */
public:
    float a,b;
    void menu(){
		cout<<"(1) Suma"<<endl;
		cout<<"(2) resta"<<endl;
		cout<<"(3) Multiplicar"<<endl;
		cout<<"(4) Divider"<<endl;	
		cout<<"(5) Ingresar nuevos datos"<<endl;
		cout<<"(6) Cerrar el programa"<<endl;	
	};
	void pedirDatos (){
		cout <<"Ingresa el num 1: ";
		cin>>a;
		cout <<"Ingresa el num 2: ";
		cin>>b;
		
		
	};
			
	float suma(){
		return(a+b);	
	};

    float resta(){
		return(a-b);	
	};
			
	float dividir(){
		return (a/b);
	};
			
	float multiplicar(){
		return(a*b);	
	};

    void leer()
    {
        int opc;
		int o=1;
		do{
		cout <<"Bienvenido al programa"<< endl;
		pedirDatos();
		int p = 1;
		do{			
			menu();
			cin>>opc;
			switch(opc){
				case 1:
					cout<< "La suma es: "<<suma()<<endl;
					break;
				case 2:
					cout<<"La resta es: "<<resta()<<endl;
					break;
			
				case 3:
					cout<<"La multiplicar es: "<<multiplicar()<<endl;
					break;
				case 4:
                    cout<<"La dividir es: "<<dividir()<<endl;
                    break;
				case 5:
					p=0;
					break;
				case 6:
					p=0;
					o=0;
					break;
					
				default:
					cout<<"No se ingreso una respuesta adecuada"<<endl;
			}
			cout<<"_______________"<<endl;
			}while(p==1);
			
			system("pause");
				
		}while(o==1);
	}

};




int main ()
{
    Calculadora Casio;
    Casio.leer();

}