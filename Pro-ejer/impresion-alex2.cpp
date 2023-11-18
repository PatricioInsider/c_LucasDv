#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Pedir al usuario las dos expresiones lógicas en p y q
    string expresion_p, expresion_q;
    cout << "Ingrese la expresión lógica en p: ";
    getline(cin, expresion_p);
    cout << "Ingrese la expresión lógica en q: ";
    getline(cin, expresion_q);

    // Crear un mapa con las variables p y q
    map<char, int> valores;

    // Evaluar ambas expresiones para todas las combinaciones de valores de p y q
    bool equivalentes = true;
    for (int p = 0; p <= 1; p++)
    {
        for (int q = 0; q <= 1; q++)
        {
            // Asignar los valores de p y q al mapa
            valores['p'] = p;
            valores['q'] = q;

            // Evaluar las expresiones lógicas para esta combinación de valores
            bool resultado_p = static_cast<bool>(stoi(expresion_p, nullptr, 2));
            bool resultado_q = static_cast<bool>(stoi(expresion_q, nullptr, 2));

            // Determinar si las expresiones son lógicamente equivalentes
            if (resultado_p != resultado_q)
            {
                equivalentes = false;
                break;
            }
        }
        if (!equivalentes)
        {
            break;
        }
    }

    // Imprimir el resultado
    if (equivalentes)
    {
        cout << "Las expresiones son lógicamente equivalentes." << endl;
    }
    else
    {
        cout << "Las expresiones no son lógicamente equivalentes." << endl;
    }

    return 0;
}
