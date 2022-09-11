#include  <iostream>
#include <string>
#include <cmath>
//Quishpe Patricio
//Realice un algoritmo que a través de un menú calcule el área de cinco figuras geométricas
using namespace std;

int main () {
    int opc;
    float res,b,a,r,l,dmay,dmen;

    cout << "Figura Gewometrica que deseas sacar el area"<<endl;
    cout << "A que unidad decesas transformar" <<endl;
    cout << "1_ Cuadrado"<<endl;
    
    cout << "2_ Circulo"<<endl;
    cout << "3_ Triangulo"<<endl;
    cout << "4_ Rectangulo"<<endl;
    cout << "5_ Rombo"<<endl;
    cin >> opc;

    switch (opc){
        case 1:cout << "1_ Cuadrado"<<endl;
        cout<< "Lado: ";
        cin>> l;
        res = l*4;
        cout << "Area de la figura seleccionada: "<<res;
        break;

        case 2:cout << "2_ a KB"<<endl;
        cout << "Radio: ";
        cin>> r;
        res = 3.1416 * pow(r,2);
        cout << "Area de la figura seleccionada: "<<res;
        break;

        case 3:cout <<  "3_ Triangulo"<<endl;
        cout << "Base: ";
        cin>> b;
        cout << "Altura: ";
        cin >>a;
        res = (b*a)/2;
        cout << "Area de la figura seleccionada: "<<res;
        break;

        case 4: cout << "4_ Rectangulo"<<endl;
        cout << "Base: ";
        cin>> b;
        cout << "Altura: ";
        cin >>a;
        res = b*a;
        cout << "Area de la figura seleccionada: "<<res;
        break;

        case 5 :cout << "5_ Rombo"<<endl;
        cout << "Diametro mayor: ";
        cin >> dmay;
        cout << "Diametro menor: ";
        cin >> dmen;
        res= (dmay *dmen)/2;
        cout << "Area de la figura seleccionada: "<<res;
        break;
        

        default : cout <<"No se ha seleccionado una opcion"<< endl;
    }
    return 0;
}