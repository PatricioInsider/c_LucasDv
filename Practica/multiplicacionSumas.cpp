#include <iostream>
using namespace std;

int main() {
    int dividendo, divisor, cociente = 0;

    // Solicita al usuario los números a dividir
    cout << "Introduce el dividendo: ";
    cin >> dividendo;
    cout << "Introduce el divisor: ";
    cin >> divisor;

    // Verifica que el divisor no sea cero
    if (divisor == 0) {
        cout << "Error: División por cero no está permitida." << endl;
        return 1; // Termina el programa con un código de error
    }

    // Realiza la división usando restas sucesivas
    while (dividendo >= divisor) {
        dividendo -= divisor; // Resta 'divisor' de 'dividendo'
        cociente++; // Incrementa el cociente
    }

    // Muestra el resultado
    cout << "El cociente es: " << cociente << endl;
    cout << "El residuo es: " << dividendo << endl;

    return 0;
}
