// ColaCircular.h
// Implementa el TDA cola circular

typedef int tipo; // Definición del tipo de datos que contendrá la cola
#define EXT 4    // Dimensión máxima del TDA

class ColaCircular {
private:
    tipo elementos[EXT]; // Definición del arreglo contenedor de datos
    int frente;          // Apuntador a posición de extracción de la cola
    int final;           // Apuntador a posición de inserción de la cola
public:
    ColaCircular();       // Constructor
    void agregar(tipo val); // Insertar un elemento en la cola
    tipo quitar();          // Eliminar un elemento de la cola
    tipo frenteCola();      // Obtener el frente de la cola sin eliminarlo
    bool colaVacia();       // Verificar si la cola está vacía
    bool colaLlena();       // Verificar si la cola está llena
    int tamanoCola();       // Obtener el tamaño actual de la cola
    void reiniciarCola();   // Reiniciar el estado de la cola
};

ColaCircular::ColaCircular() {
    frente = -1;  // Inicializar el apuntador de extracción a -1
    final = -1;   // Inicializar el apuntador de inserción a -1
}

void ColaCircular::agregar(tipo val) {
    if (colaLlena()) {
        reiniciarCola();
    }

    if (colaVacia()) {
        frente = final = 0;
    } else {
        final = (final + 1) % EXT;
    }

    elementos[final] = val;
}


tipo ColaCircular::quitar() {
    tipo aux = -1; // Valor por defecto si la cola está vacía
    if (!colaVacia()) {
        aux = elementos[frente];
        if (frente == final) {
            frente = final = -1;
        } else {
            frente = (frente + 1) % EXT;
        }
    }
    return aux;
}

tipo ColaCircular::frenteCola() {
    tipo aux = -1; // Valor por defecto si la cola está vacía
    if (!colaVacia()) {
        aux = elementos[frente];
    }
    return aux;
}

bool ColaCircular::colaVacia() {
    return frente == -1;
}

bool ColaCircular::colaLlena() {
    return (frente == (final + 1) % EXT);
}

int ColaCircular::tamanoCola() {
    if (colaVacia()) {
        return 0;
    }
    return (final - frente + EXT) % EXT + 1;
}

void ColaCircular::reiniciarCola() {
    frente = -1;
    //final = -1;
}
