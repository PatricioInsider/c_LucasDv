/*POO encapsulamiento.
Se desea elaborar un programa orientado a objetos en el lenguaje de programación C++ que permita gestionar la información de los estudiantes de un curso.
De cada estudiante se conoce su código, nombre, apellido, 3 notas parciales y el porciento de asistencia a clases (un valor entre 0 y 100).
Del curso se conoce el nombre de la asignatura, el nivel y paralelo
El programa debe permitir:
a. Ingresar los datos del curso
b. Ingresar los datos de los estudiantes
c. Mostrar los datos del curso y sus estudiantes clasificándolo en función de su nota acumulada y el porciento de asistencia a clases, como EXONERADO, REPROBADO o SUSPENSO
d. Mostrar los datos de los estudiantes que en el segundo parcial obtuvieron una nota igual o superior a 7 puntos.
*/

#include <iostream>
#include <locale.h>
#include <cmath>
#include <string>
using namespace std;

class Estudiante
{
private:
    // Declaracion de los datos que caracterizan a nuestro objeto
    int nota1, nota2, nota3, pruebaPrincipal, pruebaSuspension;
    int total;
    float asis;
    string nombre, apellido, codigo, cidentidad, clasificacion;

public:
    // Creacion del Constructor y destructor con mensaje por consola al actuar
    Estudiante();
    ~Estudiante()
    {
    }

    int acumulacion() // Imptimr todos los datos resultantes
    {
        cout << nombre << "\t" << apellido << "\t" << codigo << "\t" << nota1 << "\t" << nota2 << "\t" << nota3 << "\t" << total << "\t" << asis << "\t" << clasificacion << "\t" << endl;
    }

    int validacion(int b, int a) // Recibimos dos parametros y los comparamos para que la nota sea aceptada
    {
        int v;
        int x = 1;
        do
        {
            cin >> v;
            if (v >= b && v <= a)
            {
                cout << "Nota aceptada" << endl;
                x = 0;
            }
            else
            {
                cout << "Ingresa de nuevo la nota" << endl;
            }
        } while (x == 1);
        cout << "-------------------------" << endl;
        return v;
    }

    void datos(void)
    {
        cout << "Nombre del estudiante(un solo nombre): ";
        cin >> nombre;
        cout << "Apellido  del estudiante*(un solo apellido): ";
        cin >> apellido;
        cout << "Codigo del estudiante: ";
        cin >> codigo;
        cout << "Ingresa la cedula de estudiante: ";
        cin >> cidentidad;

        cout << "Ingresa la nota del primer parcial: ";
        nota1 = validacion(0, 8);
        cout << "Ingresa la nota del segundo parcial: ";
        nota2 = validacion(0, 10);
        cout << "Ingresa la nota del tercer parcial: ";
        nota3 = validacion(0, 10);
        cout << "Ingresa el porcentaje de asistencia: ";
        asis = validacion(0, 100);

        total = nota1 + nota2 + nota3;
    }

    void estado(int a) // Imprime el estado final del objeto
    {
        cout << "-------------------------" << endl;
        cout << "Fin del semestre" << endl;
        cout << "Nombre :\t" << this->nombre << " " << this->apellido << endl;
        cout << "Codigo :\t" << this->codigo << endl;
        cout << "Cedula Identidad :\t" << this->cidentidad << endl;
        cout << "Clasificacion: " << clasificacion << endl;
        cout << "Nota final: \t" << this->total << endl;
    }

    void read() // Realiza el ingreso de datos llamando a la funcion validacion que recibe 2 parametros
    {

        int aux = 0;
        datos();
        if (total >= 25 && total <= 28)
        {
            cout << "Estudiante Exonerado" << endl;
            total = total + 12;
            aux = 1;
        }
        else if (total >= 4)
        {
            cout << "Ingresa la nota del examen principal: ";
            pruebaPrincipal = validacion(0, 12);
            total = total + pruebaPrincipal;
            if (total >= 28)
            {

                cout << "Estudiante Aprobado" << endl;
                aux = 1;
            }
            else if (total >= 16)
            {
                cout << "Ingrese la nota del examen de recuperacion: ";
                pruebaSuspension = validacion(0, 20);
                total = round(total / 2) + pruebaSuspension;
                if (total >= 28)
                {
                    cout << "Estudiante Aprobado" << endl;
                    aux = 1;
                }
                else
                {
                    cout << "Estudiante Reprobado" << endl;
                }
            }
            else
            {
                cout << "Estudiante Reprobado" << endl;
            }
        }
        else if (total < 4)
        {
            cout << "Estudiante Reprobado" << endl;
        }
        if (asis >= 75)
        {
            cout << "Asistencia Aprobada" << endl;
        }
        else
        {
            cout << "Asistencia Reprobada" << endl;
            aux = 0;
        }

        if (aux == 1 && asis >= 75)
        {
            clasificacion = "APROBADO";
        }
        else
        {
            clasificacion = "REPROBADO";
        }
        // Impresion del estado actual del objeto perteneciente a la clase Estudiante
        
    }
   

    int getnota2(void)
    {
        return nota2;
    }

};

class Curso
{

private:
    // Declaracion de los datos que caracterizan a nuestro objeto
    string nivel, paralelo, asignatura;
    int n;
    Estudiante est[50];

public:
    Curso();

    void mostrarAna() // Impresion de tabla llamando al metodo acumulado de la class Estudiante
    {
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "\tCurso: " << nivel << "\tParalelo: " << paralelo << "\tAsignatura: " << asignatura << endl;

        cout << "NOM\t"<< "APELL\t"<< "COD\t"<< "P1\t"<< "P2\t"<< "P3\t"<< "NA\t"<< "ASIST\t"<< "CLASIF\t" << endl;
        for (int i = 0; i <= n; i++)
        {
            // impresion de cada una de los objetos de la clase estudiante
            est[i].acumulacion();
        }
    };

    void leer() // Reliza el ingreso de datos
    {

        cout << "ACTA DE NOTAS ACUMULADAS" << endl;
        cout << "Ingresa el Curso" << endl;
        cin >> nivel;
        cout << "Ingresa el paralelo" << endl;
        cin >> paralelo;
        cout << "Ingresa la asignatura" << endl;
        cin >> asignatura;

        cout << "Ingresa la cantidad de estudiantes" << endl;
        cin >> n;
        for (int i = 0; i < n; i++) // Creamos la cantidad de elementos del vector est llamando a su read
        {
            est[i].read();
        }
    }

    void nota_acumulada(){

        cout<<"Impresion de los estudiantes parcial 2 mayor = 7"<<endl;
        cout<<"-------------------------------"<<endl;
        cout << "NOM\t"<< "APELL\t"<< "COD\t"<< "P1\t"<< "P2\t"<< "P3\t"<< "NA\t"<< "ASIST\t"<< "CLASIF\t" << endl;
        for (int i = 0; i < n; i++)
        {
            if (est[i].getnota2()>=7)
            {
                est[i].acumulacion();
            }
            
        }
        
    }

};

// Creacion del Constructor y destructor con mensaje por consola al actuar

Curso ::Curso()
{
    nivel = paralelo = asignatura = "";
    n = 0;
}

Estudiante ::Estudiante()
{
    nota1 = nota2 = nota3 = total = pruebaPrincipal = pruebaSuspension = asis = 0;
    nombre = apellido = codigo = cidentidad = "";
}

int main()
{
    // Creamos el objeto curso y le ordenamos traer el metodo leer
    Curso poo;
    poo.leer();
    poo.mostrarAna();
    return 0;
}
