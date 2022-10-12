
#include<iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main() {
	int cont,n,z;
	float k;
	float m;
	cout << "Ingresa el numero mayor de la serie" << endl;
	scanf("%d",&n);
	cin >> n;
	cout << "serie: ";
	z = 1;
	m = 2;
	while (k<n) {
		cont = 0;
		while (cont<3) {
			if (z<=n) {
				printf(", %d",z);
			}
			cont = cont+1;
			z = z+2;
			k = k+1;
		}
		cont = 0;
		while (cont<3) {
			if (m<=n) {
				printf(", %d",m);
			}
			cont = cont+1;
			m = m+2;
			k = k+1;
		}
	}
	return 0;
}
