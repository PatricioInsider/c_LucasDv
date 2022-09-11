#include <iostream>
//Realizar un algoritmo mediante sub-programas que lea la fecha de nacimiento y determine su signo zodiacal.
using namespace std;
void signo(int a,int b);
int main()
{
    int d,m,y;
    cout<<"Ingresa tu fecha de nacimiento en numeros"<<endl;
    cout<<"Dia: ";cin>>d;
    cout<<"Mes: ";cin>>m;
    cout<<"Año: ";cin>>y;

    signo(d,m);
}

void signo (int a,int b)//Encontrar su signo zodiacal
{
    string ora ="Segun tu fecha de nacimiento, tu signo zodiacal es:";
    switch (b)
    {
    case 1:
        if (a <= 20)
        {
            cout<<ora<<"Capricornio"<<endl;
        }else
        {
            cout<<ora<<"Acuario"<<endl;
        }
        break;
    case 2:
        if (a  <= 18)
        {
            cout<<ora<<"Acuario"<<endl;
        }
        else
        {
            cout<<ora<<"Piscis"<<endl;
        }
        break;
    case 3:
        if (a  <= 20)
        {
            cout<<ora<<"Piscis"<<endl;
        }
        else
        {
            cout<<ora<<"Aries"<<endl;
        }
        break;
    case 4:
        if (a  <= 20)
        {
            cout<<ora<< "Aries"<<endl;
        }
        else
        {
            cout<<ora<<"Tauro"<<endl;
        }
        break;
    case 5:
        if (a  <= 21)
        {
            cout<<ora<< "Tauro"<<endl;
        }
        else
        {
            cout<<ora<< "Geminis"<<endl;
        }
        break;
    case 6:
        if (a  <= 21)
        {
            cout<<ora<<"Geminis"<<endl;
        }
        else
        {
            cout<<ora<<"Cancer"<<endl;
        }
        break;
    case 7:
        if (a  <= 22)
        {
            cout<<ora<<"Cancer"<<endl;
        }
        else
        {
            cout<<ora<<"Leo"<<endl;
        }
        break;
    case 8:
        if (a <= 23)
        {
            cout<<ora<<"Leo"<<endl;
        }
        else
        {
            cout<<ora<<"Virgo"<<endl;
        }
        break;
    case 9:
        if (a  <= 23)
        {
            cout<<ora<<"Virgo"<<endl;
        }
        else
        {
            cout<<ora<< "Libra"<<endl;
        }
        break;
    case 10:
        if (a  <= 23)
        {
            cout<<ora<<"Libra"<<endl;
        }
        else
        {
            cout<<ora<<"Escorpio"<<endl;
        }
        break;
    case 11:
        if (a  <= 22)
        {
            cout<<ora<<"Escorpio"<<endl;
        }
        else
        {
            cout<<ora<<"Sagitario"<<endl;
        }
        break;
    case 12:
        if (a <= 21)
        {
            cout<<ora<<"Sagitario"<<endl;
        }
        else
        {
            cout<<ora<<"Capricornio"<<endl;
        }
        break;
    default:
        cout<<"Los datos no son correctos "<<endl;
    
    }
}
