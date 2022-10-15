#include <iostream>

using namespace std;

class circulo {

    public:
    
	float r;

    float perimetro(){
        return ((r*3.1416)*2);
    }
    float diametro (){
        return (r*2);
    }
    float area(){
    	return (3.1416*(r*r));
	}
	void menu(){
		cout<<"(1) diametro"<<endl;
		cout<<"(2) circunferencia o perimetro"<<endl;
		cout<<"(3) area"<<endl;
		cout<<"(4) ingresar nuevos valores"<<endl;	
		cout<<"(5) cerrar el programa"<<endl;	
	};

	int leer (){
		int opc;
		int o=1;
		
		do{
			cout <<"Bienvenido al programa"<< endl;
			cout << "Ingresa el radio"<<endl;
			cin>>r;
			int p = 1;
			
			do{
				
				menu();
				cin>>opc;
				switch(opc){
					case 1:
						cout<< "El diametro es: "<<diametro()<<endl;
						break;
					case 2:
						cout<< "El perimetro es: "<<perimetro()<<endl;
						break;
				
					case 3:
						cout<< "El perimetro es: "<<area()<<endl;
						break;
					case 4:
						p=0;
						break;
					case 5:
						p=0;
						o=0;
						break;
						
					default:
						cout<<"No se ingreso una respuesta adecuada"<<endl;
				}
				
			}while(p==1);
			
			system("pause");
			
		}while(o==1);
		return 0;
	}


};



int main()
{
    circulo moneda;
	moneda.leer();
    
}