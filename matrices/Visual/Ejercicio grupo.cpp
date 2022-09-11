#include <iostream>
#include<conio.h>

using namespace std;

int main(){
    //camara de apuestas
    int num;
    cout <<"Ingresa el numero de apuestas"<<endl;
    cin>>num;
	int participantes[num];
	int aux,min;
    //Ingreso de la cantidad apostada por los participantes
    for(int i=1;i<=num;i++){
		cout<<"Ingresa La apuesta del participante "<<i<<" : "<<endl;
        cin>>participantes[i];
	}

    int i,j;
	//Algoritmo del Ordenamiento por Selecci�n
	for(int i=0;i<5;i++){
		min = i;
		for(j=i+1;j<5;j++){
			if(participantes[j] < participantes[min]){
				min = j;
			}
		}
		aux = participantes[i];
		participantes[i] = participantes[min];
		participantes[min]= aux;
	}

    cout<<"Existe recompensa para los 2 primeros puestos "<<endl;
    cout<<"El primer lugar gano el 110 porciento de su inversion"<<endl;
    cout<<"El segundo lugar gano el 50 porciento de su inversion"<<endl;
	
	cout<<"\nPremios"<<endl;
	for(i=4;i>=2;i--){

        if (i ==1)
        {
            int sum;
            sum =participantes[i]* 1.1;
            cout<<"Apuesta: "<<participantes[i]<< " / gano "<<sum<<"dolares"<<endl;
            cout<<(participantes[i]+sum)<< " = Total"<<endl;
        } else {
            
            int sum=0;
            sum =participantes[i]* 1.1;
            cout<<"Apuesta: "<<participantes[i]<< " / gano "<<sum<<"dolares"<<endl;
            cout<<(participantes[i]+sum)<< " = Total"<<endl;
        }
        
	}

	getch();
	return 0;
}
