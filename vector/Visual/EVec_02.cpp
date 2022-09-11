#include <iostream>

using namespace std;
int main (){
   
    float suma,pro, bajo,num,sumaBajo,multi,multiBajo,proBajo;
    suma =0;
	num =0;
	multi=1;
	sumaBajo=0;
	multiBajo =1;

    //Ingreso de datos
    int n;
    cout<<"Ingrese la magnitud de su vector: ";
    cin>> n;
    int v1[n];

    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = ";
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;

    for (int i = 1; i<=n; i++)
    {
        suma = suma + v1[i];
		multi = multi * v1[i];

    }

    pro = suma/n;
    cout<<"Suma de todos los elementos: "<< suma<<endl;
    cout<<"Producto de todos los elementos: "<< multi<<endl;
    cout<<"Promedio de los elementos: "<< pro<<endl;
    cout<<"_____________ "<<endl;
    
    cout<<"Numeros debajo del promedio: ";

    for (int i = 1; i<=n; i++)
    {
        if (v1[i]<pro)
        {
            num = num +1;
			sumaBajo = sumaBajo + v1[i];
			multiBajo = multiBajo * v1[i];
            cout<< v1[i]<< " ";
        }
        
    }
    cout<<" "<<endl;
    proBajo = sumaBajo/num;
    cout << "Elementos bajo el promedio: "<< num<< endl;
    cout << "Suma Elementos bajo el promedio: "<< sumaBajo<< endl;
    cout << "Producto Elementos bajo el promedio: "<< multiBajo<< endl;
    cout << "Promedio Elementos bajo el promedio: "<< proBajo<< endl;



}