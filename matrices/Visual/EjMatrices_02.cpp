#include <iostream>

using namespace std;
int main (){

    //Ingreso de datos
    int m1[3][3];

    for (int i=1 ; i<=3 ; i++) 
    {
        for (int j=1; j <=3; j++) 
        {
            cout << "Dato ("<< i<< ","<<j<<"): ";
            cin>>m1[i][j];
        }
    }

    int suma=0;
    int res=0;
    for (int i=1 ; i<=3 ; i++) 
    {
        for (int j=1; j <=3; j++) 
        {
            if (m1[i][j]>=0)
            {
                suma= suma+ m1[i][j];
            } else{
                res = res +m1[i][j];
            }
            
        }
    }

    cout<<"Suma de los elementos positivos: "<< suma<<endl;
    cout<<"Suma de los elementos negativos: "<< res<<endl; 
}