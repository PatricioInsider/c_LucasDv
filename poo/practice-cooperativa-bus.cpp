//Declaracion variables: Marca-brand modelo-model placa-plate kilometraje-kilometer year-año
#include <iostream>
#include <string.h>

using namespace std;

class ClBus
{
private:
    string brand,model,plate;
    int year,kilometer;
public:
    ClBus();
    ~ClBus();

    void mostrar(void)
    {
        cout<<brand<<"\t"<<model<<"\t"<<year<<"\t"<<plate<<endl;
    }
    void leer(void)
    {
        cout<<"Ingresa los siguientes datos del Bus"<<endl;
        cout<<"Modelo: ";
        getline(cin,model);
        cout<<"Marca: ";
        getline(cin,brand);
        cout<<"Placa";
        getline(cin,plate);
    }

    void set_year (int aux)
    {
        this->year = aux;
    }
    void set_model (string aux)
    {
        this->model = aux;
    }
    void set_plate(string aux)
    {
        this->plate;
    }
    void set_brand(string aux)
    {
        this->brand=aux;
    }
    void set_kilometer(int aux)
    {
        this->kilometer=aux;
    };
    
    string get_plate(void)
    {
        return plate;
    }
    string get_model(void)
    {
        return model;
    }
    string get_brand(void)
    {
        return brand;
    }
    int get_kilometer(void)
    {
        return kilometer;
    }
    int get_year(void)
    {
        return year;
    }
};

ClBus::ClBus()
{
    brand=model=plate="";
    year=kilometer=0;
}

ClBus::~ClBus()
{
}


class ClCooperative
{
private:
    ClBus obBus[30];
    string name;
    int n;
public:
    ClCooperative(/* args */);
    ~ClCooperative();

//A-Obtener los datos del bus con la cooperativa
    void leer(){
        cout<<"Ingrese nombre de la coperativa"<<endl;
		getline(cin,name);
		cout<<"Con cuantas unidas dispone la cooperativa"<<endl;
		cin>>n;
		for (int i=0;i<n;i++){
			obBus[i].leer();
		}
    }
//B-Mostrar la informacion de la cooperativa
    void mosCop(){
		cout<<"Cooperativa de buses: "<<name<<endl;
		cout<<"marca"<<"\t"<<"modelo"<<"\t"<<"a�o"<<"\t"<<"placa"<<endl;
		cout<<"-----------------------------------------------------------------------------------"<<endl<<endl;
		for (int i=0;i<n;i++){
			obBus[i].mostrar();
		}
	}
//C-Buscar placa
//D-Mostrar buses que tienen mas de 5 años
//E- Encontrar marca


};


ClCooperative::ClCooperative(/* args */)
{
}

ClCooperative::~ClCooperative()
{
}

    

int main ()
{
    ClCooperative ObValle;
    ObValle.leer();
    ObValle.mosCop();

}
