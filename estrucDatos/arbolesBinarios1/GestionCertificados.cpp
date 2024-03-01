
using namespace std;
#include <iostream>
#include "ArbolBinario.h"  // Incluye tu archivo ArbolBinario.h con la definición de la clase

// Prototipos de funciones
void ingresoCertificados(ArbolBinario *a);
void verDatosCer(ArbolBinario a);
void buscarCertificadoEspecial(ArbolBinario a);
void certificadosExistentes(ArbolBinario a);

int main() {
    system("color f0");

    ArbolBinario a;  // Declaración del ABB

    cout << "INGRESO DE CERTIFICADOS";
    ingresoCertificados(&a);  // Llamado a funciones

    verDatosCer(a);

    certificadosExistentes(a);

    buscarCertificadoEspecial(a);

    cout << endl;
    system("pause");

    return 0;
}

// Implementación de las funciones

void ingresoCertificados(ArbolBinario *a) {
    Tipo aux;       // Variable de lectura
    Tipo fin = 99999;  // Marca de fin de lectura

    cout << endl;
    cout << "Número de certificado. Ingrese [" << fin << "] para terminar: ";
    cin >> aux;  // Lectura

    if (aux != fin) {  // No ingresa marcador de fin lectura
        a->insertarNodo(aux);
        ingresoCertificados(a);
    }
}

void verDatosCer(ArbolBinario a) {
    cout << "\nDatos de los Certificados:\n";
    cout << "Número total de certificados: " << a.contarNodos(a.getRaiz()) << endl;
    cout << "Altura del árbol de Certificados: " << a.calcularAltura(a.getRaiz()) << endl;
    cout << "Certificados existentes:\n";
    a.verHojas(a.getRaiz());
}

void certificadosExistentes(ArbolBinario a) {
    cout << "\nLista de Certificados Existentes:\n";
    a.recorrerEnInorden();
}

void buscarCertificadoEspecial(ArbolBinario a) {
    cout << "\nBuscar certificado especial:\n";
    Tipo valor;
    cout << "Ingrese el número de certificado a buscar: ";
    cin >> valor;

    NodoBinario *encontrado = a.buscarNodo(valor);

    if (encontrado) {
        cout << "El certificado con número " << valor << " ha sido encontrado.\n";
    } else {
        cout << "El certificado con número " << valor << " no ha sido encontrado.\n";
    }
}