#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a,b,aux  ;
    cout << "Ingresa el valor a: ";
    cin >> a;
    cout << "Ingresa el valor b: ";
    cin >> b;
    aux = a;
    a =b;
    b =aux;
    cout << "Valores antiguos" <<endl;
    cout << "a = "<<a<<endl;
    cout << "b = "<<b<<endl<<"Conversion"<<endl;
    cout << "Valores actuales" <<endl;
    cout << "a = "<<a<<endl;
    cout << "b = "<<b<<endl;
    return 0;
}
