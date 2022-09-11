#include <iostream>

using namespace std;
int main (){
    int opc,gra;
    float c,f,k;
    cout<<"Que tipo de conversion deceas escribir? "<<endl;
    cout<< "1. TRANSFORMAR GRADOS FAHRENHEIT A GRADOS CELSIUS"<<endl;
    cout<<"2. TRANSFORMAR GRADOS CELSIUS A GRADOS FAHRENHEIT" <<endl;
    cout<< "3. TRANSFORMAR GRADOS CENTIGRADOS A GRADOS KELVIN"<<endl;
    cout<<"4. TRANSFORMAR GRADOS KELVIN A GRADOS CENTIGRADOS" <<endl;
    cout<<"5. TRANSFORMAR GRADOS KELVIN A GRADOS FAHRENHEIT"<<endl;
    cout<< "6. SALIR"<<endl;
    cout<< "Escribe el numero"<<endl;
    cin>>opc;
    c=0;
    f=0;
    k=0;
    if (opc!= 6){
        switch (opc){
        case 1:
            cout<<"___________" <<endl;
            cout<<"GRADOS FAHRENHEIT A GRADOS CELSIUS" <<endl;
            cout<<"Escribe los grados para la conversion" <<endl;
            cin>>gra;
            c = (gra-32)/1.8;
            cout<<gra<< " GRADOS FAHRENHEIT = "<<c<< " GRADOS CELSIUS" <<endl;
            break;
        case 2:
            cout<<"___________" <<endl;
            cout<<"GRADOS CELSIUS A GRADOS FAHRENHEIT" <<endl;
            cout<<"Escribe los grados para la conversion" <<endl;
            cin>>gra;
            f = (gra*1.8)+32;
            cout<<gra<<  " GRADOS CELSIUS = "<<f<< " GRADOS FAHRENHEIT" <<endl;
            break;
        case 3:
            cout<<"___________" <<endl;
            cout<<"GRADOS CENTIGRADOS A GRADOS KELVIN"<<endl;
            cout<<"Escribe los grados para la conversion" <<endl;
            cin>>gra;
            k = gra + 273.15;
            cout<<gra<< " GRADOS CENTIGRADOS = "<<k<<  " GRADOS KELVIN"<<endl;
        case 4:
            cout<<"___________" <<endl;
            cout<<"GRADOS KELVIN A GRADOS CENTIGRADOS"<<endl;
            cout<<"Escribe los grados para la conversion" <<endl;
            cin>>gra;
            c = gra - 273.15;
            cout<<gra<< " GRADOS KELVIN = "<<c<< " GRADOS CENTIGRADOS"<<endl;
        case 5:
            cout<<"___________" <<endl;
            cout<<"GRADOS KELVIN A GRADOS FAHRENHEIT"<<endl;
            cout<<"Escribe los grados para la conversion" <<endl;
            cin>>gra;
            f = ((gra-273.15)*(9/5))+32;
            cout<<gra<< " GRADOS KELVIN = "<<f<< " GRADOS FAHRENHEIT"<<endl;

         
        default:
            cout<<"Error, No se encontro una opcion dentro del menu"<<endl;
            break;
        }
    }
    cout <<"saliendo";

}