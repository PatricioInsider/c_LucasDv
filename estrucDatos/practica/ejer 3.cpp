#include <iostream>

using namespace std;


int main() {
    int m1;
    void generarFibonacci(int m1, int fibonacci[]);
    void invertirArreglo(int arreglo[], int m1);
    void imprimirArreglo(int arreglo[], int m1);

    do {
        cout << "Ingrese la cantidad de términos de la serie de Fibonacci a generar (debe ser un número positivo): ";
        cin >> m1;
    } while (m1 <= 0);

    int fibonacci[m1];
    generarFibonacci(m1, fibonacci);

    cout << "Los primeros " << m1 << " términos de la serie de Fibonacci son:" << endl;
    imprimirArreglo(fibonacci, m1);

    invertirArreglo(fibonacci, m1);

    cout << "Los términos invertidos son:" << endl;
    imprimirArreglo(fibonacci, m1);

    return 0;
}
// Función para generar los m1 primeros términos de la serie de Fibonacci
void generarFibonacci(int m1, int fibonacci[]) {
    for (int i = 0; i < m1; i++) {
        if (i == 0) {
            fibonacci[i] = 0;
        } else if (i == 1) {
            fibonacci[i] = 1;
        } else {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }
}

// Función para invertir un arreglo
void invertirArreglo(int arreglo[], int m1) {
    int inicio = 0;
    int fin = m1 - 1;
    while (inicio < fin) {
        // Intercambiar los elementos en las posiciones inicio y fin
        int temp = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temp;
        inicio++;
        fin--;
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int arreglo[], int m1) {
    for (int i = 0; i < m1; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}