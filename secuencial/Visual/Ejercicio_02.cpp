#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int segIngresados, hor, resHor,min,resMin  ;
    cout << "Cantidad de segundos: ";
    cin >> segIngresados;
    hor = segIngresados/3600;
	resHor = segIngresados % 3600;
	min = resHor/60;
	resMin = resHor % 60;

    cout << "Horas: "<< hor << endl;
    cout << "minutos: " << min << endl;
    cout << "Segundos: " <<  resMin << endl;

    return 0;
}