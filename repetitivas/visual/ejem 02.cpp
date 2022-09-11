#include <iostream>

using namespace std; 
int main (){
    int suma;
    int x;
    suma = 0;
    do{
        cout<< "Escriba un numero positivo"<<endl;
        cin>>x;
        if (x>0) {
            cout<<"Los divisores de "<< x <<" son: ";
            for(int i=1;i<(x+1);i+=1){
                if ((x%i) ==0) {
                    cout<< i<<", ";
                    suma =suma+i;
                }
            }
            x=1;
            cout <<"Y la suma de los divisores es: "<<suma<<endl;
        }
    } while (x<0);

}