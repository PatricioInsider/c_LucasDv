#include <iostream>
#include <string>

using namespace std;

class Facturas{
public:
    string numMedidor,ci;
    int lecAnterior,lecActual,lectotal;

    Facturas(){
        numMedidor=ci="";
        lecActual=lecAnterior=0;
    }
    void mostrar(){
        cout<<numMedidor<<"\t"<<ci<<"\t"<<lecActual<<"\t"<<lecAnterior<<"\t";
    }
    void leer(){
        cout<<"Numero del Medidor: ";
        cin>>numMedidor;
        cout<<"Cedula de identidad del due�o del medidor";
        cin>>ci;
        cout<<"Lectura Anterior: ";
        cin>>lecAnterior;
        cout<<"Lectura Actual: ";
        cin>>lecActual;

        while (lecActual<lecAnterior)
        {
            cout<<"Te recuerdo que la lectura actual no puede ser menor de la actual"<<endl;
            cout<<"Lectura Actual: ";
            cin>>lecActual;
        }

        lectotal = lecAnterior-lecAnterior;
    }

};
class Empresa{
public:

    string nombre,ciudad;
    int buscar;
    Facturas fact[130];
    int n;

    void mayor(int n)
    {
        int a=0;
        cout <<"_________________________________"<<endl;
        cout<<"Busqueda de facturas con valor mayor al ingresado"<<endl;
        cout<<"Ingrese el valor base: ";
        cin>>buscar;

        cout <<"_________________________________"<<endl;
        cout<<"Resultado de Busqueda"<<endl;
         cout<<"Nombre de la empresa: "<<nombre<<endl;
        cout<<"Direccion de la empresa: "<<ciudad<<endl;
        cout<<"N.medidor \t CI \t LecAnterior \t LecActual"<<endl;

        for (int i =0;i<n;i++)
        {

            if (fact[i].lectotal>=buscar) {
                fact[i].mostrar();
                a=1;
            }
        }
        if (a==0)
        {
            cout<<"No se encontro ninguna fatura mayor al valor establecido"<<endl;
        }
    }


    void leer(){
        cout<<"Ingresa el nombre de la empresa"<<endl;
        cin>>nombre;
        cout<<"Ingresa la ciudad de direccion de la empresa"<<endl;
        cin>>ciudad;
        cout<<"Ingrese el numero de facturas"<<endl;
        cin>>n;
        while(n>130){
            cout<<"EL numero de facturas no puede ser mayor a 130"<<endl;
            cout<<", Ingresa nuevamente el numero de facturas"<<endl;
            cin>>n;
        }

        //Ingreso de datos de las facturas
        for (int i=0; i<n;i++)
        {
            cout<<"Factura ingresada numero: "<<i+1<<endl;
            fact[i].leer();
        }

        mayor(n);




    };


};



int main()
{
    Empresa EmpreElectrica;
    EmpreElectrica.leer();
}

