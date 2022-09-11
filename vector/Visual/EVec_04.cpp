#include <iostream>

using namespace std;
int main (){
   int n,m;
    cout<<"Ingrese la magnitud de su vector v1: ";
    cin>> n;
    cout<<"Ingrese la magnitud de su vector v2: ";
    cin>> m;
    int v1[n];
    int v2[m];
    int v3[m+n];
    cout<<"Ingresa todos los datos array 1 : ____________"<<endl;
    for (int i = 1; i<=n; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = " << endl;
        cin>>v1[i];
    }
    cout<< "_____________ "<<endl;
    cout<<"Ingresa todos los datos array 2 : ____________"<<endl;
    for (int i = 1; i<=m; i++)
    {
        cout<<"Ingresa el dato: ("<<i<< ") = " << endl;
        cin>>v2[i];
    }
    cout<< "_____________ "<<endl;

    int j=1;
    for (int i = 1; i<=(n+m); i++) {
        if (i<= n) {
            v3[i] = v1[i];

        } else{
            v3[i] = v2[j];
			j = j + 1;
        }
    }

    cout<< "Primer: " ;

    for (int i = 1; i<=(n); i++) {
        cout<< v1[i]<< ", ";
    }
    cout<< " "<<endl;
    cout<< "Segundo: " ;

    for (int i = 1; i<=(m); i++) {
        cout<< v2[i]<< ", ";
    }
    cout<< " "<<endl;

    cout<< "Resul: " ;

    for (int i = 1; i<=(n+m); i++) {
        cout<< v3[i]<< ", ";
    }

}