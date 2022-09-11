#include  <iostream>
#include <string>
//Quishpe Patricio
//Escribir un algoritmo que dado el orden de un día de la semana, escribir el  día correspondiente.
using namespace std;

int main () {
    int dia;
    const string orden = "El dia con orden "; 
    cout << "Ingrese el orden de un dia de la semana. Ejemplo: 5" << endl;
    cin >> dia;

    if (dia == 1) {
        cout << orden <<dia<< " es Lunes"<<endl;
    }
    if (dia == 2) {
        cout << orden <<dia<< " es Martes"<<endl;
    }
    if (dia == 3) {
        cout << orden <<dia<< " es Miercoles"<<endl;
    }
    if (dia == 4) {
        cout << orden <<dia<< " es Jueves"<<endl;
    }
    if (dia == 5) {
        cout << orden <<dia<< " es Viernes"<<endl;
    }
    if (dia == 6) {
        cout << orden <<dia<< " es Sabado"<<endl;
    }
    if (dia == 7) {
        cout << orden <<dia<< " es Domingo"<<endl;
    }

    return 0;
}