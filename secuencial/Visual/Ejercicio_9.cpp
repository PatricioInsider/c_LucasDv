#include <iostream>

using namespace std;
int main()
{
    int billetes,b100,b20,b10,b5, b1,resb100,resb20,resb10,resb5 ;
    cout << "Cantidad de dolares en billetes:  ";
    cin >> billetes;

    b100 = billetes/100;
	resb100 = billetes%100;
	b20 = resb100/20;
	resb20 = resb100 % 20;
	b10 = resb20/10;
	resb10 = resb20 % 10;
	b5 = resb10/5;
	resb5 = resb10 % 5;

    cout << "Dados los resultados" <<endl;
    cout << "Billetes de 100:  "<< b100 <<endl;
    cout << "Billetes de 20: "<< b20 <<endl;
    cout << "Billetes de 10: "<< b10 <<endl;
    cout <<  "Billetes de 5: "<< b5 <<endl;
    cout <<  "Billetes de 1: "<< resb5 <<endl;
   
    return 0;
}
