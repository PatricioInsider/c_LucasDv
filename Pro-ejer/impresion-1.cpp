#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    // Pedir al usuario la expresión lógica
    string expresion;
    cout << "Ingrese una expresión lógica usando p, q, r: ";
    getline(cin, expresion);

    // Crear un arreglo con las variables p, q y r
    char variables[] = {'p', 'q', 'r'};

    // Calcular el número de filas en la tabla de verdad
    int filas = pow(2, 3);

    // Imprimir la primera fila de la tabla de verdad
    for (char variable : variables)
    {
        cout << variable << '\t';
    }
    cout << expresion << endl;

    // Imprimir el separador de la primera fila
    for (int i = 0; i < sizeof(variables); i++)
    {
        cout << "-\t";
    }
    cout << "-" << endl;

    // Generar y imprimir el resto de la tabla de verdad
    for (int i = 0; i < filas; i++)
    {
        // Convertir el número de fila a una cadena binaria
        string fila_binaria = bitset<3>(i).to_string();

        // Crear un mapa con las variables y sus valores para esta fila
        map<char, int> valores;
        for (int j = 0; j < sizeof(variables); j++)
        {
            valores[variables[j]] = fila_binaria[j] - '0';
        }

        // Evaluar la expresión lógica para esta fila
        int resultado = stoi(expresion, nullptr, 2);

        // Imprimir los valores de las variables y el resultado
        for (char variable : variables)
        {
            cout << valores[variable] << '\t';
        }
        cout << resultado << endl;
    }

    return 0;
}
