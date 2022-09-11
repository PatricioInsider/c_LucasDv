#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float radio, lon, are ;
    const float pi = 3.1416;
    cout << " Escribe el radio:  ";
    cin >> radio;
    lon = 2*pi*radio;
    are = pi * pow(radio,2);
    cout << "La longitud de la circunferencia es:" << lon<<endl;
    cout << "El Area del circulo es:" << are;

}