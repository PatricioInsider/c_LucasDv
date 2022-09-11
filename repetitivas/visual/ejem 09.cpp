#include <iostream>

using namespace std; 
int main (){
    float n,x;
    cout<< "Hasta que numero deceas realizar la tabla"<<endl;
    cin>>n;

    cout<<"x, 2, 3, 4, 5, 6, 7, 8, 9, 10"<<endl;

    for (int i=1;i<11;i+=1){
        for (int j=1;j<11;j+=1){
        x=i+j;
        cout<<x<<", ";
        }
        cout<<" "<<endl;
    }
    cout<<"Fin de la tabla "<<endl;

}