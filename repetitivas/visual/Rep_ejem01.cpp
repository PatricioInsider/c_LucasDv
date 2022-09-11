#include <iostream>

using namespace std;
int main(){
    int n,m;
    cout << "De que numero deceas que se impriman los numeros n = ";
    cin>> n;
    cout << "De que numero deceas que se impriman los numeros m = ";
    cin>> m;
    for (int i=1;i< 101;i+=1){
        if ((i%n == 0)&&(i%m ==0)){
            cout<<i<<endl;
        }
    }

}