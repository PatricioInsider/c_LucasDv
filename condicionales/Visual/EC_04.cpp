#include  <iostream>
#include <string>
#include <cmath>
//Quishpe Patricio
//Realice un algoritmo que lea una determinada cantidad de bits y lo transforme a bytes, KB, MB, GB y TB.
using namespace std;

int main () {
    int x,opc;
    float res;

    cout << "Escribe la cantidad de bits"<<endl;
    cin >> x;
    cout << "A que unidad decesas transformar" <<endl;
    cout << "1_ a Bytes"<<endl;
    cout << "2_ a KB"<<endl;
    cout << "3_ a MB"<<endl;
    cin >> opc;

    switch (opc){
        case 1:cout << "1_ a Bytes"<<endl;
        res = x/8;
        cout << res << " bytes"<<endl; 
        break;

        case 2:cout << "2_ a KB"<<endl;
        res = (x/8)/ pow(2,10) ;
        cout << res << " Kb"<<endl; 
        break;

        case 3:cout << "3_ a MB"<<endl;
        res = (x/8)/ pow(2,20) ;
        cout << res << " Mb"<<endl; 
        break;
        default : cout <<"No se ha seleccionado una opcion"<< endl;
    }
    return 0;
}