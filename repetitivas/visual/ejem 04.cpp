#include<iostream>
using namespace std;
int main(){
    int conta,n,num,opc;
    cout<<"De cuantos numeros deceas sacar la factorial? "<<endl;
    cin>>n;
    conta =0;
    num=0;
    opc=0;
    do{
        cout<<"_________________"<<endl;
        conta=conta+1;
        cout<<"Escribe el numero que deceas sacar el factorial"<<endl;
        do{
            cout<<"Escribe un numero positivo"<<endl;
            cin>>num;
        }while(num<0);
        cout<<"El dato numero "<<conta<< "_ El factorial de "<<num<< " es: ";
        while (num !=0) {
            cout<< num<<", ";
            num =num-1;
        }

        cout<<" "<<endl;
        if (conta ==n) {
            opc=1;
        }

    } while(not (opc ==1));
}