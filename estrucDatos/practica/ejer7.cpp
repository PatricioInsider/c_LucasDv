#include <iostream>

using namespace std;

const int MAX_ELEMENTOS = 100;
int main() {
    void ingresarArreglo(int arreglo[], int &n);
    void imprimirArreglo(const int arreglo[], int n);
    void eliminarRepetidos(int arreglo[], int &n) ;
    int arreglo[MAX_ELEMENTOS];
    int n;

    ingresarArreglo(arreglo, n);
    eliminarRepetidos(arreglo, n);
    imprimirArreglo(arreglo, n);

    return 0;
}

// Función para ingresar valores en un arreglo uno por uno
void ingresarArreglo(int arreglo[], int &n) {
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    cout << "Ingrese los elementos del arreglo uno por uno:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];
    }
}

// Función para eliminar valores repetidos en un arreglo
void eliminarRepetidos(int arreglo[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arreglo[i] == arreglo[j]) {
                for (int k = j; k < n - 1; k++) {
                    arreglo[k] = arreglo[k + 1];
                }
                n--;
                j--;
            }
        }
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(const int arreglo[], int n) {
    cout << "El arreglo resultante es: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
