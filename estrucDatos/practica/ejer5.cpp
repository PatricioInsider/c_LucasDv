#include <iostream>

using namespace std;

const int MAX_ELEMENTOS = 100;


int main() {
    int arreglo[MAX_ELEMENTOS];
    int n;
    void imprimirArreglo(const int arreglo[], int n);
    void ingresarArregloUnico(int arreglo[], int &n);
    ingresarArregloUnico(arreglo, n);
    imprimirArreglo(arreglo, n);

    return 0;
}

// Función para ingresar un arreglo con valores únicos
void ingresarArregloUnico(int arreglo[], int &n) {
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    cout << "Ingrese los elementos del arreglo (valores únicos) separados por espacios:" << endl;
    for (int i = 0; i < n; i++) {
        int elemento;
        cin >> elemento;

        // Verificamos si el valor ya ha sido ingresado
        bool repetido = false;
        for (int j = 0; j < i; j++) {
            if (arreglo[j] == elemento) {
                repetido = true;
                break;
            }
        }

        if (repetido) {
            cout << "El valor " << elemento << " ya ha sido ingresado. Ingrese otro valor." << endl;
            i--; // Retrocedemos para ingresar un valor válido
        } else {
            arreglo[i] = elemento;
        }
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(const int arreglo[], int n) {
    cout << "El arreglo ingresado es: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
