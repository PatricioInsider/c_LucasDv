#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

//Registro
struct datosPersona
{
    string nombre;
    float nota1, nota2, nota3, promedio;    
} ; 

int main () {

    int num;
    float pro;
    cout<<"Ingrese el numero de estudiantes a ingresar: ";
    cin >> num;
    pro = 0;

    
    
    datosPersona*persona = new datosPersona[num];
    //Ingreso de datos para el registro
    for (int i = 1; i <= num; i++)
    {
        cout<< "______________"<<endl;
        cout<< "Estudiante "<<i<< ": "<<endl;
        cout<<"Nombre : ";
        cin >> persona[i].nombre;
        fflush(stdin);
        cout<<"Nota 1 : ";
        cin >> persona[i].nota1;
        fflush(stdin);
        cout<<"Nota 2 : ";
        cin >> persona[i].nota2;
        fflush(stdin);
        cout<<"Nota 3 : ";
        cin >> persona[i].nota3;
        fflush(stdin);

        persona[i].promedio = (persona[i].nota1+persona[i].nota2+persona[i].nota3)/3; 
        pro += persona[i].promedio;
        cout<<"Promedio: "<<persona[i].promedio<<endl;

    }

    //Impresion de datos en consola
    cout<< "°°______________"<<endl;
    for (int i = 1; i <= num; i++)
    {
        cout<< "Estudiante "<< i << endl;
        cout<< "Estudiante: " << persona[i].nota1<<endl;
        cout<< "Nombre: "<< persona[i].nombre<< endl;
        cout<< "Nota 1 : "<< persona[i].nota1<<endl;
        cout<< "Nota 2 : "<< persona[i].nota2<<endl;
        cout<< "Nota 3 : "<< persona[i].nota3<<endl;
        cout<< "Promedio del estudiante: "<< persona[i].promedio<< endl;
        
    }

    //persona.nombre = "Juan";
    //cout << "La edad es " << persona.edad;
    getch();
    return 0;
}