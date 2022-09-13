#include<iostream>
using namespace std;

//separarar un numero en su cifras
int main() {

	int cifras[10],dato,i=0;
	do
	{
		i=0;
		cout << "Ingresa un dato de 3 digitos" << endl;
		cin >> dato;
		while (dato>0)
		{
		cifras[i]=dato%10;
		dato=dato/10;
		i++;
		}
		//verifica las 3 cifras
	} while (i!=3);

	for (int j = 0; j <i ; j++)
	{
		if ((cifras[j]%2)==0) {
			cout << "El digito " << cifras[j] << " es numero par" << endl;
		} else {
			cout << "El digito " << cifras[j] << " es impar" << endl;
		}
	}
}

