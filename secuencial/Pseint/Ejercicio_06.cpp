#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n1,n2, producto, cociente;
    int resto;


    cout<< "Ingresa dos numeros para obtener el el producto, cociente entero, y resto entero"<< endl;

    cout<< "Numero 1";
    cin >> n1;
    cout<< "Numero 2";
    cin >> n2 ;

    producto = n1*n2;
	cociente = n1/n2;
	resto = n1%n2;

    cout<< "Procesando___"<<endl;
    cout<< "Producto:  "<< producto  <<endl;
    cout<< "Cociente entero:  "<< cociente  <<endl;
    cout<< "Resto: "<< resto  <<endl;
    return 0;
}