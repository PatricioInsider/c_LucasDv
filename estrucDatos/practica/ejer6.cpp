#include <iostream>

using namespace std;

const int MAX_ELEMENTOS = 100;


int main() {
    void ingresarArreglo(int arreglo[], int &n);
    void ordenarArreglo(int arreglo[], int n);
    void imprimirArreglo(const int arreglo[], int n);
    bool buscarValor(int arreglo[], int n, int valor);
    int arreglo[MAX_ELEMENTOS];
    int n;

    ingresarArreglo(arreglo, n);
    ordenarArreglo(arreglo, n);

    int valorBuscado;
    cout << "Ingrese el valor que desea buscar en el arreglo: ";
    cin >> valorBuscado;

    if (buscarValor(arreglo, n, valorBuscado)) {
        cout << "El valor " << valorBuscado << " se encuentra en el arreglo." << endl;
    } else {
        cout << "El valor " << valorBuscado << " no se encuentra en el arreglo." << endl;
    }

    imprimirArreglo(arreglo, n);

    return 0;
}
// Función para ingresar valores en un arreglo con repeticiones
void ingresarArreglo(int arreglo[], int &n) {
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    cout << "Ingrese los elementos del arreglo y el número máximo de repeticiones, separados por espacios:" << endl;
    for (int i = 0; i < n; i++) {
        int elemento, repeticiones;
        cin >> elemento >> repeticiones;

        for (int j = 0; j < repeticiones; j++) {
            arreglo[i] = elemento;
            i++;
        }
        i--;
    }
}

// Función para ordenar un arreglo usando un algoritmo de ordenamiento
void ordenarArreglo(int arreglo[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
    }
}

// Función para buscar un valor en un arreglo utilizando búsqueda binaria
bool buscarValor(int arreglo[], int n, int valor) {
    int izquierda = 0, derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arreglo[medio] == valor) {
            return true;
        }
        if (arreglo[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return false;
}

// Función para imprimir un arreglo
void imprimirArreglo(const int arreglo[], int n) {
    cout << "El arreglo resultante es: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}