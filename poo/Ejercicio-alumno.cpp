/*
Realizar un programa que conste de una clase llamada alumno que tenga como atributos el nombre y la nota del alumno.
Definir los metodos para inicializar sus atributos, imprimirlos y mostrar un mensake con el resultado de la nota y si ha aprobado o no
*/
#include <iostream>
#include <string.h>

using namespace std;

class Persona
{
private:
    string nombre, dni;
    int edad;

public:
    Persona();
    ~Persona();

    void mostrar(void)
    {
        cout << "Nombre: " << this->nombre << endl;
        cout << "Dni: " << this->dni << endl;
        cout << "Edad: " << this->edad << endl;
    }
    void datos_persona()
    {
        cout<<"iNGRESO DE DATOS"<<endl;
        cout<<"Nombre: "<<endl;
        cin>>nombre;
        cout<<"Dni: "<<endl;
        cin>>dni;
        cout<<"Edad: "<<endl;
        cin>>edad;
    }
    bool es_mayor_edad()
    {
        if (edad >= 18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void setnombre(string a)
    {
        nombre = a;
    }

    void setedad(float a)
    {
        edad = a;
    }
    string getnombre()
    {
        return nombre;
    }
    
    string getdni()
    {
        return dni;
    }
    int getedad()
    {
        return edad;
    }
    void setdni(string a)
    {
        dni=a;
    }
};

Persona::Persona(/* args */)
{
    nombre = dni = "";
    edad = 0;
}

Persona::~Persona()
{
}

class Cuenta
{
private:
    Persona titular;
    float cantidad;

public:
    Cuenta(/* args */);
    ~Cuenta();

    void mostrar_cuenta()
    {
        cout << "Titular: " << endl;
        titular.mostrar();
        cout << "Cantidad: " << cantidad << endl;
    }
    /*
    void datos_cuenta()
    {
        cout<<"Titular: "<<endl;
        cin>>titular;
        cout<<"Cantidad: "<<endl;
        cin>>cantidad;
    }*/

    void ingresar()
    {
        float aux;
        cout<<"Ingresa la cantidad a ingresar"<<endl;
        cin>>aux;
        while (aux <= 0)
        {
            cout << "No se puede ingresar una cantidad negativa: " << endl;
            cout << "Valor:" << endl;
            cin >> aux;
        }
        cantidad += aux;
    }
    void retirar()
    {
        float aux;
        cout<<"cantidad= "<<cantidad<<endl;
        cout<<"Ingresa la cantidad a retirar"<<endl;
        cin>>aux;       cantidad -= aux;
    }
    float getcantidad()
    {
        return cantidad;
    }

    void setcantidad(float a)
    {
        cantidad =a;
    }
    float gettitular_nombre()
    {
        return titular.getedad();
    }
    bool gettitular_es_mayor()
    {
        return titular.es_mayor_edad();
    }
    void settitular_edad(int a)
    {
        titular.setedad(a);
    }
    void settitular_nombre(string a)
    {
        titular.setnombre(a);
    }

    void mostrar_persona()
    {
        titular.mostrar();
    }
    void settitular_dni(string a)
    {
        titular.setdni(a);
    }
};

Cuenta::Cuenta(/* args */)
{
    cantidad = 0;
}

Cuenta::~Cuenta()
{
}

class CuentaJoven: public Cuenta
{
private:
    string bonificacion;
public:
    CuentaJoven(/* args */);
    CuentaJoven(string a, float c, float d, string e);
    ~CuentaJoven();

    bool titular_valido()
    {
        if (gettitular_es_mayor() && (gettitular_nombre()<25))
        {
            return true;
        }else{
            return false;
        }
        
    }

    void retirar_cuenta()
    {
        if (titular_valido())
            {
                retirar();
            }
    }
    
    void ingresar_cuenta()
    {
        if (titular_valido())
            {
                ingresar();
            }
    }

    void mostrar_cuenta_joven()
    {
        cout<<"Cuenta Joven"<<endl;
        cout<<"Titular: "<<endl;
        mostrar_persona();
        cout<<"Cantidad: "<<getcantidad()<<endl;
        cout<<"Bonificacion: "<<bonificacion<<endl;
        
    };
};

CuentaJoven::CuentaJoven(string a, float c, float d, string e)
{
    settitular_nombre(a);
    settitular_edad(c);
    setcantidad(d);
    bonificacion=e;
    
}

CuentaJoven::~CuentaJoven()
{
}

int main()
{
    CuentaJoven persona1("Pedro",20,300,"20%");//Nombre,id,edad,cantidad,bonificacion
    persona1.retirar_cuenta();
    persona1.ingresar_cuenta();
    persona1.mostrar_cuenta_joven();
    
}