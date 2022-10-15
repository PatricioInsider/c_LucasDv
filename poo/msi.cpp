#include <iostream>

using namespace std;

class Humano{
	
	public:
		float peso,altura;
		
		float msi(){
			return (peso/(altura*altura));
		}
		
		void estado(){
			if (msi()<18.5){
				cout <<"Bajo peso"<<endl;
			}else if(msi()<24.9){
				cout <<"Peso Normal"<<endl;
			}else if(msi()<29.9){
				cout <<"Sobrepeso"<<endl;
			}else if(msi()>=29.9){
				cout <<"Obeso"<<endl;
			}
			
		}
		
		float leer(){
			cout<<"Ingresa el peso en kg: "<<endl;
			cin>>peso;
			
			cout<<"<ingresa la altura en mtrs: "<<endl;
			cin>>altura;
			
			cout<<"Su masa corporal es de :"<<msi()<<"\n Asi que se encuentra en estado: ";
			estado();
		}
		
		
};

int main() 
{
	Humano jairo;
	jairo.leer();
	return 0;
}
