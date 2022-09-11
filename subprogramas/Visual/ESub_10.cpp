#include <iostream>
#include <string.h>
//Realizar un algoritmo que dado el ordinal de un día del año, se determine mediante una función a que mes pertenece. No olvide que febrero tiene 28 dias.
using namespace std;


int mes(int x){
    string meses[]={"Enero","Febrero","Marzo","Abril", "Mayo","Junio","Julio","Agosto","Septiembre","Octubre", "Noviembre","Diciembre"};
    int dias[]={31,28,31,30,31,30,31,31,30,31,30,31};

    int suma=0;
    int j=0;
    for (int i = 0; i < 12; i++)
    {
        suma = suma + dias[i];
        dias[j] = suma;
        j +=1;
    }
    
    
    for (int i = 1; i <= 11; i++)
    {
        if ((x>=dias[i-1]) && (x<= dias[i]))
        {
            cout<<"El dia: "<<x<< " pertenece al mes de "<<meses[i]<<endl;
        }
        
    }

}


int main()
{
    int dia,opc=0;

    do
    {
        cout<<"Ingresa el dia del año: "<<endl;
        cin>>dia;
        if (dia<366)
        {
            mes(dia);
            //Menu salida
            cout<<"Intentar nuevamente(1)  salir(0)"<<endl;
            cin>>opc;
        }else{
            cout<<"Error de consola al no ingresar un dia valido"<<endl;
        }
        
    } while (opc!=0);
        
}