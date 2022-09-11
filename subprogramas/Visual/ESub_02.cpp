#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

void opcc(int& opc);


float cuadrado()
{
    float l,res;
    cout<< "Lado: ";
    cin>> l;
    res = l*4;
    cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}

float circulo()
{
    float r,res;
    cout << "Radio: ";
        cin>> r;
        res = 3.1416 * pow(r,2);
        cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}

float triangulo()
{
    float res,b,a;
    cout << "Base: ";
    cin>> b;
    cout << "Altura: ";
    cin >>a;
    res = (b*a)/2;
    cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}

float rectangulo()
{
    float a,b,res;
    
    cout << "Base: ";
    cin>> b;
    cout << "Altura: ";
    cin >>a;
    res = b*a;
    cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}


float rombo()
{
    
    float dmay,dmen,res; 
    cout << "Diametro mayor: ";
    cin >> dmay;
    cout << "Diametro menor: ";
    cin >> dmen;
    res= (dmay *dmen)/2;
    cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}

float cubo()
{
    
    float res,a; 
    cout << "EScrible la longitud de la arista:  ";
    cin >> a;
    res= 6*pow(a,2);
    cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}

float cilindro()
{
    
    float res,a,r; 
    cout << "Radio: ";
    cin >> r;
    cout << "Altura: ";
    cin >> a;
    res= (2*3.14159*r)*a;
    cout << "Area de la figura seleccionada: "<<res<<endl;
    return 0;
}



//Escribir un programa que calcule áreas de figuras geométricas mediante subprogramas
int main (){
    int opc=0;

    do
    {
        cout<<"_________"<<endl;
        opcc(opc);
        if (opc != 0)
        {
            switch (opc){
                case 1:cout << "1_ Cuadrado"<<endl;
                cuadrado();
                break;

                case 2:cout << "2_ Ciculo"<<endl;
                circulo();
                break;

                case 3:cout <<  "3_ Triangulo"<<endl;
                triangulo();

                break;

                case 4: cout << "4_ Rectangulo"<<endl;
                rectangulo();

                break;

                case 5 :cout << "5_ Rombo"<<endl;
                rombo();
                break;

                case 6 :cout << "6_Cubo"<<endl;
                cubo();
                break;

                case 7 :cout << "7_Cilindro"<<endl;
                cilindro();
                break;
                

                default : cout <<"No se ha seleccionado una opcion"<< endl;
            }
            
        }
        system("pause");
    } while (opc != 0);
    
    
}

void opcc(int& opc )
{
    
    cout << "Figura Gewometrica que deseas sacar el area"<<endl;
    cout << "A que unidad decesas transformar" <<endl;
    cout << "1_ Cuadrado"<<endl;
    cout << "2_ Circulo"<<endl;
    cout << "3_ Triangulo"<<endl;
    cout << "4_ Rectangulo"<<endl;
    cout << "5_ Rombo"<<endl;
    cout << "6_ Cubo"<<endl;
    cout << "7_ Cilindro"<<endl;
    cout << "0 salir"<<endl;
    cin >>opc;
}