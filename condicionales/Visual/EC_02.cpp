#include  <iostream>
#include <cmath>
//Quishpe Patricio
//Realizar un algoritmo que lea la fecha de nacimiento y determine su signo zodiacal.
using namespace std;

int main () {
    int a,m,d;

    cout << "Escribe tu año de nacimiento"<< endl;
    cin >> a;
    cout << "Escribe tu mes de nacimiento/ ej:4"<< endl;
    cin >> m;
    cout << "Escribe tu dia de nacimiento"<< endl;
    cin >> d;

    //Enero

    if (m==1){
        if (d <= 19) {
            cout << "Signo: Capricornio"<<endl;
        } else {
            cout << "Signo: Acuario" <<endl;
        }  
    }

    
    //Febrero
    if (m==2){
        if (d <= 18) {
            cout << "Signo: Acuario"<<endl;
        } else {
            cout << "Signo: Piscis" <<endl;
        }  
    }

    //Marzo
    if (m==3){
        if (d <= 20) {
            cout << "Signo: Piscis"<<endl;
        } else {
            cout <<"Signo: Aries" <<endl;
        }  
    }
    //Abril
    if (m ==4){
        if (d <= 19) {
        cout << "Signo: Aries"<<endl;
        } else {
            cout << "Signo: Tauro" <<endl;
        } 
    }

    //Mayo
    if (m==5){
        if (d <= 20) {
            cout << "Signo: Tauro"<<endl;
        } else {
            cout << "Signo: Geminis" <<endl;
        }  
    }
    
    //Junio
    if (m==6){
        if (d <= 20) {
            cout << "Signo: Piscis"<<endl;
        } else {
            cout <<"Signo: Aries" <<endl;
        }  
    }

    //Julio
    if (m==7){
        if (d <= 22) {
            cout << "Signo: Cancer"<<endl;
        } else {
            cout <<"Signo: Leo" <<endl;
        }  
    }
    //Agosto
    if (m==8){
        if (d <= 22) {
            cout << "Signo: Leo"<<endl;
        } else {
            cout <<"Signo: Virgo" <<endl;
        }  
    }
    
    //Septiembre
    if (m==9){
        if (d <= 22) {
            cout <<  "Signo: Virgo"<<endl;
        } else {
            cout << "Signo: Libra" <<endl;
        }  
    }
    
    //Octubre
    if (m==10){
        if (d <= 22) {
            cout << "Signo: Libra"<<endl;
        } else {
            cout <<"Signo: Escorpio" <<endl;
        }  
    }
    
    //Noviembre
   if (m==11){
        if (d <= 21) {
            cout << "Signo: Escorpio"<<endl;
        } else {
            cout <<"Signo: Sagitario" <<endl;
        }  
    }
    
    //Diciembre
    if (m==12){
        if (d <= 21) {
            cout << "Signo: Sagitario"<<endl;
        } else {
            cout <<"Signo: Capricornio"<<endl;
        }  
    }
    return 0;
}