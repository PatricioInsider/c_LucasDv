#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct estudiante
{
    string nombre,campo;
    int nota1,nota2,nota3;
    int sum;

}estudiantes[20];


int menu(){
    cout << "_______________" << endl;
    cout << "1.- Mostrar la lista de todos los alumnos en formato tipo tabla"<< endl;
    cout << "2.- Mostrar la lista de los alumnos con el detalle de EXONERADO o EXAMEN FINAL"<< endl;
    cout << "3.- Mostrar el promedio del curso de la Nota final" << endl;
    cout << "0.- Salir del programa" << endl;
}

int main () {
    int n=0,x,opc;

    //Ingreso de datos y notas
    for (int i = 0; i < 100; i++)
    {
        fflush(stdin);
        cout<<"Ingresa el nombre del estudiante "<<i+1<<endl;
        getline(cin,estudiantes[i].nombre,'\n');

        if (estudiantes[i].nombre=="")
        {
            break;
        }else{
            n++;
            //Primera nota
            do{
                x=0;
                cout << "ingresa nota 1 :(no pude ser menor mayor de 8)";
                cin >> estudiantes[i].nota1;
                if ((estudiantes[i].nota1>=0) && (estudiantes[i].nota1<9))
                {
                x=1;
                }
            }while(x==0);

            //Segunda nota
            do{
                x=0;
                cout << "ingresa nota 3: (no pude ser menor mayor de 10) ";
                cin >> estudiantes[i].nota2;
                if ((estudiantes[i].nota2>=0) && (estudiantes[i].nota2<11))
                {
                x=1;
                }
            }while(x==0);

            //Tercera nota
            do{
                x=0;
                cout << "ingresa nota 3 : (no pude ser menor mayor de 10)";
                cin >> estudiantes[i].nota3;
                if ((estudiantes[i].nota3>=0) && (estudiantes[i].nota3<11))
                {
                x=1;
                }
            }while(x==0);

            estudiantes[i].sum=estudiantes[i].nota1+estudiantes[i].nota2+estudiantes[i].nota3;
            if (estudiantes[i].sum>=25)
            {
                estudiantes[i].campo="EXONERADO";
            }else{
                estudiantes[i].campo="DAR PRINCIPAL";
            }
            cout<<"____________"<<endl;
        }
    }
        estudiantes[n].nombre= "Prom";
        for (int i = 0; i < n; i++)
        {
            estudiantes[n].nota1+=estudiantes[i].nota1;
        }
        for (int i = 0; i < n; i++)
        {
            estudiantes[n].nota2+=estudiantes[i].nota2;
        }
        for (int i = 0; i < n; i++)
        {
            estudiantes[n].nota3+=estudiantes[i].nota3;
        }
        for (int i = 0; i < n; i++)
        {
            estudiantes[n].sum+=estudiantes[i].sum;
        }
        //Promedio
        int promedio=0;
        for (int i = 0; i < n; i++)
        {
            promedio+= estudiantes[i].sum;
        }
        promedio =promedio/n;

        do
        {
            //Menu
        menu();
        cin >> opc;
        //Creacion de archivo por menu
        ofstream archivo;
        archivo.open("Tabla de Notas.txt",ios::out);
        switch (opc)
        {
        case 1:

            if (archivo.fail())
            {
                cout<<"No se pudo abrir el archivo "<<endl;
                exit(1);
            }

            archivo<<"Sistema de Notas\n Motivo: Impresion tipo tabla de los datos recolectados"<<endl;
            archivo<<"___________________"<<endl;
            archivo<<"Nombre .\tnota1\tnota2\tnota3\t"<<endl;
            for (int i = 0; i < n; i++)
            {
                archivo<<estudiantes[i].nombre<<"\t"<<estudiantes[i].nota1<<"\t"<<estudiantes[i].nota2<<"\t"<<estudiantes[i].nota3<<endl;
            }

            archivo.close();
            system("pause");
        break;
        case 2:
            if (archivo.fail())
            {
                cout<<"No se pudo abrir el archivo "<<endl;
                exit(1);
            }

            archivo<<"Sistema de Notas\n Motivo: Lista de los alumnos con el detalle de EXONERADO o EXAMEN FINAL"<<endl;
            archivo<<"___________________"<<endl;
            archivo<<"Nombre .\tnota1\tnota2\tnota3\tsuma\tFin"<<endl;
            for (int i = 0; i < n; i++)
            {
                archivo<<estudiantes[i].nombre<<"\t"<<estudiantes[i].nota1<<"\t"<<estudiantes[i].nota2<<"\t"<<estudiantes[i].nota3<<"\t"<<estudiantes[i].sum<<"\t"<<estudiantes[i].campo<<"\t"<<endl;
            }

            archivo.close();
            system("pause");

        case 3:
            if (archivo.fail())
            {
                cout<<"No se pudo abrir el archivo "<<endl;
                exit(1);
            }

            archivo<<"Sistema de Notas\n Motivo: Lista del promedio del curso de la Nota final"<<endl;
            archivo<<"___________________"<<endl;
            archivo<<"Nombre .\tnota1\tnota2\tnota3\tsuma\tFin"<<endl;
            for (int i = 0; i < n; i++)
            {
                archivo<<estudiantes[i].nombre<<"\t"<<estudiantes[i].nota1<<"\t"<<estudiantes[i].nota2<<"\t"<<estudiantes[i].nota3<<"\t"<<estudiantes[i].sum<<"\t"<<estudiantes[i].campo<<"\t"<<endl;
            }
            archivo<<"Promedio de Curso: "<<promedio<<endl;
            archivo.close();
            system("pause");
        default:
        cout<<"Muchas gracias por visitarnos"<<endl;
        break;
        }
        } while (opc!=0);
        
    return 0;

}


    