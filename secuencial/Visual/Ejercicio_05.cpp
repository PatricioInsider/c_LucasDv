#include <iostream>
using namespace std;
int main()
{
    float hm, dam, m,dm;
    cout<< "Ingresa la longitud del perímetro de un terreno, expresada con enteros." << endl;
    cin >> hm ;
    cout<< "Ingresa en enteros los decametros" << endl;
    cin >> dam ;
    cout<< "Ingresa en enteros los metros" << endl;
    cin >> m ;

    dm = (m*10)+(dam*100)+(hm*1000);

    cout<< "Procesando___"<<endl;
    cout<< "La longitud en decímetros es:  "<< dm<< " dm"<<endl;
}