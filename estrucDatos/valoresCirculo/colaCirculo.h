#include <iostream>
using namespace std;
class ColaCircular {
private:
int capacidad;
int *cola;
int frente, final;
public:
ColaCircular(int tamano) {
capacidad = tamano;
cola = new int[capacidad];
frente = final = -1;
}
~ColaCircular() {
delete[] cola;
}
bool estaVacia() {
return frente == -1;
}
bool estaLlena() {
return (final + 1) % capacidad == frente;
void encolar(int elemento) {
if (estaLlena()) {
cout << "La cola esta llena. No se puede encolar." << endl;
} else {
if (estaVacia()) {
frente = 0;
}
final = (final + 1) % capacidad;
cola[final] = elemento;
cout << "Se encolo el elemento " << elemento << "." << endl;
}
}
void desencolar() {
if (estaVacia()) {
cout << "La cola esta vacia. No se puede desencolar." << endl;
} else {
int elementoDesencolado = cola[frente];
if (frente == final) {
frente = final = -1;
} else {
frente = (frente + 1) % capacidad;
}
cout << "Se desencolo el elemento " << elementoDesencolado << "." << endl;
}
}
};