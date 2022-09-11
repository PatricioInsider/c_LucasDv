#include  <iostream>
//Quishpe Patricio
//Determinar si un número leído es par o impar; determinar además si este número es positivo o negativo.
using namespace std;

int main () {
    int n;
    cout << "Escribe un numero"<< endl;
    cin>> n;
    if ((n%2) == 0) {
        cout << "Este numero es par" <<endl;
    } else {
        cout << "Este numero no es par" <<endl;
    }  
    return 0;
}