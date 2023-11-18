#include <iostream>
#include <string>

using namespace std;

const int MAX_ESTUDIANTES = 100;

string nombres[MAX_ESTUDIANTES];
int calificaciones[MAX_ESTUDIANTES];

int main() {
    int n;
    void ingresarEstudiantes(int n);
    void mostrarMejoresCalificaciones(int n, int m);
    void ordenarEstudiantes(int n);

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    ingresarEstudiantes(n);
    ordenarEstudiantes(n);

    int m;
    cout << "Ingrese la cantidad de estudiantes con mejores calificaciones a mostrar: ";
    cin >> m;

    mostrarMejoresCalificaciones(n, m);

    return 0;
}
void ingresarEstudiantes(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> nombres[i];
        cout << "Ingrese la calificación del estudiante " << i + 1 << ": ";
        cin >> calificaciones[i];
    }
}

void ordenarEstudiantes(int n) {
    for (int i = 0; i < n - 1; i++) {
        int max= i;
        for (int j = i + 1; j < n; j++) {
            if (calificaciones[j] > calificaciones[max]) {
                max = j;
            }
        }
        if (max != i) {
            swap(nombres[i], nombres[max]);
            swap(calificaciones[i], calificaciones[max]);
        }
    }
}