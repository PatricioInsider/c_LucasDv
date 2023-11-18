#include <iostream>

const int MAX_ELEMENTOS = 100;
using namespace std;

int main() {
    void ingresarNumeros(int arreglo[], int n);
    void modificarOrden(int arreglo[], int n, int l);
    void imprimirArreglo(int arreglo[], int n);
    int arreglo[MAX_ELEMENTOS];
    int n, l;

    cout << "Ingrese la cantidad de números a ingresar: ";
    cin >> n;

    if (n <= MAX_ELEMENTOS) {
        ingresarNumeros(arreglo, n);

        cout << "Arreglo original: ";
        imprimirArreglo(arreglo, n);

        cout << "Ingrese el valor de l para mover los últimos l valores al principio: ";
        cin >> l;

        if (l > n) {
            cout << "El valor de l no puede ser mayor que la cantidad de elementos en el arreglo." << endl;
        } else {
            modificarOrden(arreglo, n, l);

            cout << "Arreglo modificado: ";
            imprimirArreglo(arreglo, n);
        }
    } else {
        cout << "La cantidad de números ingresada supera el límite permitido." << endl;
    }

    return 0;
      }
void ingresarNumeros(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

// Función para modificar
void modificarOrden(int arreglo[], int n, int l) {
    if (l > n) {
        cout << "El valor de l no puede ser mayor que la cantidad de elementos en el arreglo." << endl;
        return;
    }

    int temp[MAX_ELEMENTOS];
    for (int i = 0; i < n; i++) {
        temp[i] = arreglo[i];
    }

    for (int i = 0; i < l; i++) {
        arreglo[i] = arreglo[n - l + i];
    }

    for (int i = l; i < n; i++) {
        arreglo[i] = temp[i - l];
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}