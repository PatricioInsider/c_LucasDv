//Pogramacion orientado a objetos con ejecucion en el main
#include <iostream>

using namespace std;

class calculadora {
		
		private:
			float num1,num2,num3;
		public:
			
			void menu(){
				cout<<"(1) Suma"<<endl;
				cout<<"(2) Promedio"<<endl;
				cout<<"(3) Producto"<<endl;
				cout<<"(4) Mayor"<<endl;	
				cout<<"(5) Menor"<<endl;
				cout<<"(6) Ingresar nuevos datos"<<endl;
				cout<< "(7) Cerrar el programa"<<endl;	
			};
			void pedirDatos (){
				cout <<"Ingresa el num 1: ";
				cin>>num1;
				cout <<"Ingresa el num 2: ";
				cin>>num2;
				cout <<"Ingresa el num 3: ";
				cin>>num3;
				
			};
			
			float suma(){
				return(num1+num2+num3);	
			};
			
			float promedio(){
				return ((num1+num2+num3)/3);
			};
			
			float producto(){
				return(num1*num2*num3);	
			};
			
			float mayor(){
				if (num1 >=num2){
					if (num1>=num3){
						return num1;
					} else{
						return num3;
					}
				}else{
					if (num2>=num3){
						return num2;
					} else{
						return num3;
					}
				}
			};
			float menor (){
				if (num1 <=num2){
					if (num1<=num3){
						return num1;
					} else{
						return num3;
					}
				}else{
					if (num2<=num3){
						return num2;
					} else{
						return num3;
					}
				}
			};

			void leer(){
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
							cout<<"La Promedio es: "<<promedio()<<endl;
							break;
					
						case 3:
							cout<<"La Producto es: "<<producto()<<endl;
							break;
						case 4:
							cout<<"La mayor es: "<<mayor()<<endl;
							break;
						case 5:
							cout<<"La menor es: "<<menor()<<endl;
							break;
							
						case 6:
							p=0;
							break;
						case 7:
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
	
	
int main() {
	calculadora casio;
	casio.leer();
	return 0;
}
	
