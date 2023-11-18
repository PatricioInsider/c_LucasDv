#include <iostream>
using namespace std;

int main() {

    void ordenarAscendenteSeleccion(int arreglo[], int n);
    void ordenarDescendenteInsercion(int arreglo[], int n); 
    void intercalarArreglos(int arreglo1[], int arreglo2[], int resultado[], int n);
    int n;
    cout << "Ingrese el tamaño de los arreglos: ";
    cin >> n;

    int arreglo1[n];
    int arreglo2[n];

    cout << "Ingrese el primer arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arreglo1[i];
    }

    cout << "Ingrese el segundo arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arreglo2[i];
    }

    ordenarAscendenteSeleccion(arreglo1, n);

    ordenarDescendenteInsercion(arreglo2, n);

    // Imprimir los arreglos ordenados
    cout << "Arreglo 1 ordenado ascendentemente: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo1[i] << " ";
    }
    cout << endl;

    cout << "Arreglo 2 ordenado descendentemente: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo2[i] << " ";
    }
    cout << endl;

    // Crear un arreglo para almacenar el resultado de la intercalación
    int resultado[2 * n];

    intercalarArreglos(arreglo1, arreglo2, resultado, n);

    // Imprimir el arreglo intercalado
    cout << "Arreglo intercalado: ";
    for (int i = 0; i < 2 * n; i++) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    return 0;
        }

void ordenarAscendenteSeleccion(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[minIndex]) {
                minIndex = j;
            }
        }
        swap(arreglo[i], arreglo[minIndex]);
    }
}


void ordenarDescendenteInsercion(int arreglo[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] < key) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = key;
    }
}

void intercalarArreglos(int arreglo1[], int arreglo2[], int resultado[], int n) {
    int i = 0, j = 0;
    for (int k = 0; k < n * 2; k++) {
        if (k % 2 == 0) {
            resultado[k] = arreglo1[i++];
        } else {
            resultado[k] = arreglo2[j++];
        }
    }
}