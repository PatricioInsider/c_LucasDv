#include <iostream>
#include <string>

using namespace std;
struct estudiante
{
    string nombre,campo;
    int par1,par2,par3;
    int sum;

}estudiantes[20];

int main () {
    int n=0;
    //Ingreso de numero de estudiantes
    cout<<"Ingresa el numero de estudiantes que deseas ingresar"<<endl;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"Ingresa el nombre del estudiante "<<i+1<<endl;
        getline(cin,estudiantes[i].nombre,'\n');
        //cin>>estudiantes[i].nombre;

        cout<<"Parcial 1 de "<<estudiantes[i].nombre<<endl;
        cin>>estudiantes[i].par1;

        cout<<"Parcial 2 de"<<estudiantes[i].nombre<<endl;
        cin>>estudiantes[i].par2;

        cout<<"Parcial 3 de "<<estudiantes[i].nombre<<endl;
        cin>>estudiantes[i].par3;

        estudiantes[i].sum=estudiantes[i].par1+estudiantes[i].par2+estudiantes[i].par3;
        if (estudiantes[i].sum>=25)
        {
            estudiantes[i].campo="EXONERADO";
        }else{
            estudiantes[i].campo="DAR PRINCIPAL";
        }
        
    }

    //escritura de manea secuencial
    cout<<"Escritura de manera secuencial"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<i<<estudiantes[i].par1<<estudiantes[i].par2<<estudiantes[i].par3<<endl;
    }

    
    estudiantes[n].nombre= "Promedio";
    for (int i = 0; i < n; i++)
    {
        estudiantes[n].par1+=estudiantes[i].par1;
    }
    for (int i = 0; i < n; i++)
    {
        estudiantes[n].par2+=estudiantes[i].par2;
    }
    for (int i = 0; i < n; i++)
    {
        estudiantes[n].par3+=estudiantes[i].par3;
    }
    for (int i = 0; i < n; i++)
    {
        estudiantes[n].sum+=estudiantes[i].sum;
    }

    //escritura de manea total
    cout<<"_____________"<<endl;
    cout<<"RESULTADO"<<endl;
    int i = 0;
    for (i=0; i < n; i++)
    {
        cout<<estudiantes[i].nombre<<"\t"<<estudiantes[i].par1<<"\t"<<estudiantes[i].par2<<"\t"<<estudiantes[i].par3<<"\t"<<estudiantes[i].sum<<"\t"<<estudiantes[i].campo<<endl;
    }
    cout<<estudiantes[n].nombre<<"\t"<<estudiantes[n].par1<<"\t"<<estudiantes[n].par2<<"\t"<<estudiantes[n].par3<<"\t"<<estudiantes[n].sum<<"\t"<<endl;
}
    