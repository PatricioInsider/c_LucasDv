#include <iostream>

using namespace std;

class Calculadora {
    public:
        int suma(){
            int num1,num2;
            cout << "Ingresa el primer numero: "<<endl;
            cin >> num1;
            cout << "Ingresa el segundo numero: "<<endl;
            cin >> num2;
            return (num1 +num2);
        }

};


int main (){
    int res;
    Calculadora maria;
    res = maria.suma();
    cout << "El resultado de la operacion es : "<<res<<endl;
    return 0;
}