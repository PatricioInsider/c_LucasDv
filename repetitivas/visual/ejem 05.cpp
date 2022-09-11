#include <iostream>
#include <cmath>
using namespace std;
int main (){
    float a,res;
    a=0;
    for(int i =-15;i<11;i+=1){
        a = a +0.5;
        res =  pow(i,2)-a;
        cout<<"El resultado de x = "<< i<< " y en a = "<< a<<endl;
        cout<<"Resultado = "<< res<<endl;
        cout<<"__________________"<<endl;
        
    }
}