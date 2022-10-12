#include<iostream>
#include <string>
using namespace std;

int main() {
	int c,d,i,m,x;
	string denegar,e,mes,s;
	string l="lunes";
	float dias;
	x = 0;
	cout << "Ingrese el dia(numero)" << endl;
	cin >> d;
	cout << "Ingrese el mes(numero)" << endl;
	cin >> m;
	cout << "Primer dia del mes (lunes, martes, mi�rcoles, etc)" << endl;
	cin>>s;
	denegar = "Dia del mes fuera del rango ";
	if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
		dias = 31;
		if (d<=dias) {
			x = d;
		} else {
			cout << denegar << endl;
		}
	}
	if (m==4 || m==6 || m==9 || m==11) {
		dias = 30;
		if (d<=dias) {
			x = d;
		} else {
			cout << denegar << endl;
		}
	}
	if (m==2) {
		dias = 28;
		if (d<=dias) {
			x = d;
		} else {
			cout << denegar << endl;
		}
	}
	if (x==d) {
		switch (m) {
		case 1:
			mes = "Enero";
			break;
		case 2:
			mes = "Febrero";
			break;
		case 3:
			mes = "Marzo";
			break;
		case 4:
			mes = "Abril";
			break;
		case 5:
			mes = "Mayo";
			break;
		case 6:
			mes = "Junio";
			break;
		case 7:
			mes = "Julio";
			break;
		case 8:
			mes = "Agosto";
			break;
		case 9:
			mes = "Septiembre";
			break;
		case 10:
			mes = "Octubre";
			break;
		case 11:
			mes = "Noviembre";
			break;
		case 12:
			mes = "Diciembre";
			break;
		default:
			cout << "Mes fuera de rango" << endl;
		}
		
		if (s=="lunes") {
			c = 0;
		}
		if (s=="martes") {
			c = 1;
		}
		if (s=="miercoles") {
			c = 2;
		}
		if (s=="jueves") {
			c = 3;
		}
		if (s=="viernes") {
			c = 4;
		}
		if (s=="sabado") {
			c = 5;
		}
		if (s=="domingo") {
			c = 6;
		}
		c = c+d;
		do {
			if (c<8) {
				i = 1;
				switch (c) {
				case 1:
					e = "lunes";
					break;
				case 2:
					e = "martes";
					break;
				case 3:
					e = "miercoles";
					break;
				case 4:
					e = "jueves";
					break;
				case 5:
					e = "viernes";
					break;
				case 6:
					e = "sabado";
					break;
				case 7:
					e = "domingo";
					break;
				default:
					cout << "Ingresa correctamente el dia" << endl;
				}
			}
			c = c-7;
		} while (i!=1);
		cout << "El " << d << " de " << mes << " es " << e << endl;
	}
	return 0;
}

