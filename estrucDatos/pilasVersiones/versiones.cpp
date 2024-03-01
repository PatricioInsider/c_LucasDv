#include <iostream>
#include <string.h>
#include "Pila.h"

using namespace std;

class ControlVersiones {
private:
    Pila historial;  

public:
    void realizarCommit(const string& nuevaVersion);
    void revertirVersion();
    void mostrarVersionActual();
    void mostrarHistorialVersiones();
};

void ControlVersiones::realizarCommit(const string& nuevaVersion) {
    historial.push(nuevaVersion);
    cout << "Commit realizado. Version actual: " << nuevaVersion << "\n";
}

void ControlVersiones::revertirVersion() {
    if (!historial.PilaVacia()) {
        historial.pop();
        cout << "Revertir cambios a la version anterior.\n";
        mostrarVersionActual();
    } else {
        cout << "No hay versiones anteriores para revertir.\n";
    }
}

void ControlVersiones::mostrarVersionActual() {
    cout << "Version actual: " << historial.CimaPila().c_str() << "\n";
}

void ControlVersiones::mostrarHistorialVersiones() {
    cout << "Historial de versiones committ:\n";
    Pila auxiliar = historial; 
    while (!auxiliar.PilaVacia()) {
        cout << auxiliar.pop() << " ";
    }
    cout << "\n";
}

int main() {
    ControlVersiones control;

    control.mostrarVersionActual(); 

    control.realizarCommit("v1.0");
    control.realizarCommit("v1.1");
    control.realizarCommit("v2.0");

 
    control.mostrarHistorialVersiones();
    control.mostrarVersionActual();


    control.revertirVersion(); 
    control.revertirVersion(); 

    return 0;
}
