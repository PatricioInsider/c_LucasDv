#include <iostream>
//Programa de comparacion en Poo
using namespace std;

class Balanza
{
    public:
        int num1;
        int num2;

        void num_mayor () 
        {
            if (num1 == num2)
            {
                cout<<" Los numeros son iguales"<<endl;
            }else if (num1>num2){
                cout<<num1<<" es mas grande"<<endl;
            }else if (num2>num1){
                cout<<num2<<" es mas grande"<<endl;
            }
        }

        void leer ()
        {
            int p =1;
            int opc =0;
            do
            {
                cout<<"Ingresa el numero 1 :";
                cin>>num1;
                cout<<"Ingresa el numero 2 :";
                cin>>num2;
                num_mayor();

                cout<<"Deseas seguir comparando \n(1)si \n(2)no"<<endl;
                cin>>opc;
                if (opc==2)
                {
                    p=0;
                }
            } while (p==1);
            
            
        }
};



int main ()
{
    Balanza bal1;
    bal1.leer();   
    return 0;
}