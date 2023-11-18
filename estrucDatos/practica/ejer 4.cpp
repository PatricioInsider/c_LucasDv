#include <iostream>

using namespace std;

const int MAX_ELEMENTOS = 100;

int main() {
    int arregloA[MAX_ELEMENTOS], arregloB[MAX_ELEMENTOS];
    int n, m;
    bool estaContenido(int arregloA[], int n, int arregloB[], int m);


    cout << "Ingrese el tamaño del arreglo A: ";
    cin >> n;
    cout << "Ingrese los elementos del arreglo A separados por espacios: ";
    for (int i = 0; i < n; i++) {
        cin >> arregloA[i];
    }

    cout << "Ingrese el tamaño del arreglo B: ";
    cin >> m;
    cout << "Ingrese los elementos del arreglo B separados por espacios: ";
    for (int i = 0; i < m; i++) {
        cin >> arregloB[i];
    }

    if (estaContenido(arregloA, n, arregloB, m) && estaContenido(arregloB, m, arregloA, n)) {
        cout << "Ambos arreglos están contenidos completamente en el otro." << endl;
    } else {
        cout << "Los arreglos no están completamente contenidos en el otro." << endl;
    }

    return 0;
}

bool estaContenido(int arregloA[], int n, int arregloB[], int m) {
    if (n > m) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        bool encontrado = false;
        for (int j = 0; j < m; j++) {
            if (arregloA[i] == arregloB[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            return false;
        }
    }

    return true;
}