#include <iostream>

using namespace std;

int main() {
    void ingresarValores(int arreglo[], int n);
    void ordenarPositivos(int arreglo[], int n);
    void ordenarNegativos(int arreglo[], int n);
    void imprimirArreglo(int arreglo[], int n);


    int n;

    cout << "Ingrese la cantidad de valores a ingresar: ";
    cin >> n;

    if (n > 0) {
        int arreglo[n];

        ingresarValores(arreglo, n);
        ordenarPositivos(arreglo, n);
        ordenarNegativos(arreglo, n);

        cout << "Arreglo con valores positivos ascendentes y valores negativos descendentes:" << endl;
        imprimirArreglo(arreglo, n);
    } else {
        cout << "La cantidad de valores debe ser mayor que cero." << endl;
    }

    return 0;
}
// Función para ingresar valores en un arreglo
void ingresarValores(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

// Función para ordenar los valores positivos en orden ascendente
void ordenarPositivos(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arreglo[i] >= 0 && arreglo[j] >= 0 && arreglo[i] > arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}

// Función para ordenar los valores negativos en orden descendente
void ordenarNegativos(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arreglo[i] < 0 && arreglo[j] < 0 && arreglo[i] < arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}