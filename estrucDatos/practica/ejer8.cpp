#include <iostream>

using namespace std;

int main() {
    int A, B;
    bool esPalindromo(int numero);
    void generarPalindromos(int A, int B);
    cout << "Ingrese el valor de A: ";
    cin >> A;

    cout << "Ingrese el valor de B: ";
    cin >> B;

    generarPalindromos(A, B);

    return 0;
}
// Función para verificar si un número es palíndromo
bool esPalindromo(int numero) {
    int original = numero;
    int reverso = 0;

    while (numero > 0) {
        int digito = numero % 10;
        reverso = reverso * 10 + digito;
        numero = numero / 10;
    }

    return original == reverso;
}

// Función para generar y mostrar los números palíndromos entre A y B
void generarPalindromos(int A, int B) {
    cout << "Los números palíndromos entre " << A << " y " << B << " son:" << endl;

    for (int numero = A; numero <= B; numero++) {
        if (esPalindromo(numero)) {
            cout << numero << " ";
        }
    }

    cout << endl;
}