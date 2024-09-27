#include <iostream>
#include <locale.h>
#include <string>

using namespace std;


// Definiciones de cantidad máxima para arrays azafatas
const int MAX_IDIOMAS = 10;
const int MAX_AZAFATAS = 10;
const int MAX_VIP = 50;
const int MAX_TURISTA = 200;

// Clase cEmpleado y subclases
class cEmpleado {
protected:
    string idEmpleado;
    string nombre;
    string cargo;

public:
    
    cEmpleado(string id, string nombre, string cargo)
        : idEmpleado(id), nombre(nombre), cargo(cargo) {}
    virtual void leerDatos() {
        cout << "ID Empleado: "; cin>>idEmpleado;
        cout << "Nombre: " ; cin>>nombre ;
        cout << "Cargo Detallado: " ; cin>>cargo ;
    }
    virtual void mostrarDatos() {
        cout << "ID Empleado: " << idEmpleado << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Cargo Detallado: " << cargo << endl;
    }

    string getidEmpleado(){
        return idEmpleado;
    }

    string getIdEmpleado() {
    return idEmpleado;
    }
    void setIdEmpleado(string id) {
        idEmpleado = id;
    }

    string getNombre() {
        return nombre;
    }
    void setNombre(string nombre) {
        nombre = nombre;
    }

    string getCargo() {
        return cargo;
    }
    void setCargo(string cargo) {
        cargo = cargo;
    }

};

class cPiloto : public cEmpleado {
private:
    string licencia;
    int horasVuelo;

public:
    cPiloto(string id, string nombre, string cargo, string licencia, int horasVuelo) 
  : cEmpleado(id, nombre, cargo), licencia(licencia), horasVuelo(horasVuelo) {}

    void leerDatos() {
        cEmpleado::leerDatos();
        cout << "Licencia: ";cin >>licencia;
        cout << "Horas de Vuelo: " ;cin>>horasVuelo;
    }
    void mostrarDatos() {
        cEmpleado::mostrarDatos();
        cout << "Licencia: "<< licencia<<endl;
        cout << "Horas de Vuelo: " << horasVuelo<<endl;
    }
    //... otros métodos ...
    string getLicencia() {
    return licencia;
    }
    void setLicencia(string licencia) {
        licencia = licencia;
    }

    int getHorasVuelo() {
        return horasVuelo;
    }
    void setHorasVuelo(int horasVuelo) {
        horasVuelo = horasVuelo;
    }
    

};

class cAzafata : public cEmpleado {
private:
    string idiomas[MAX_IDIOMAS];
    int cantidadIdiomas;

public:
    cAzafata(string id = "default_id", string nombre = "default_nombre", string cargo = "default_cargo") 
        : cEmpleado(id, nombre, cargo) {
        cantidadIdiomas = 0;
        // Inicializar otros atributos si es necesario
    }
    void agregarIdioma(string idioma) {
        if (cantidadIdiomas < MAX_IDIOMAS) {
            idiomas[cantidadIdiomas++] = idioma;
        }
    }

    void leerDatos() {
        cEmpleado::leerDatos();
        string idioma;
        cout << "Cantidad de idiomas: ";cin>>cantidadIdiomas;
        for (int i = 0; i < cantidadIdiomas; i++) {
            cout<<"Ingresa el idioma "<< i+1<<" : ";cin>> idioma;
            idiomas[i] = idioma;
        }
        cout << endl;
    }
    void mostrarDatos() {
        cEmpleado::mostrarDatos();
        cout << "Cantidad de Idiomas: "<< cantidadIdiomas <<endl;
        for (int i = 0; i < cantidadIdiomas; i++) {
            cout<<"Idioma "<< i+1<< " : " << idiomas[i] <<endl;
        }
    }
    
    string getIdioma(int index) {
        if (index >= 0 && index < cantidadIdiomas) {
            return idiomas[index];
        }
        return ""; // Valor por defecto si el índice no es válido
    }
    int getcantidadIdiomas(){
        return cantidadIdiomas;
    }
};


// Clase base que representa un avion
class cAvion{
    private:

        string Marca, Modelo, ID;
        int Tipo;
        cPiloto Piloto;

    public:

        // Constructor por defecto
       cAvion(string marca, string modelo, string id, int tipo, cPiloto piloto)
        : Marca(marca), Modelo(modelo), ID(id), Tipo(tipo), Piloto(piloto) {}
        // su constructor debería manejar también la inicialización de la parte cEmpleado del objeto
        // Método virtual para ingresar informacion del avion
        virtual void leer(){

            cout << "\nIngrese la Identificacion: ";
            cin >> ID;

            cout << "Ingrese la Marca: ";
            cin >> Marca;

            cout << "Ingrese la Modelo: ";
            cin >> Modelo;

            cout << "Ingrese los datos del piloto: ";
            Piloto.leerDatos();
        }
        virtual ~cAvion() {
        // Limpieza si es necesario
    }

        // Método virtual para mostrar informacion detallada del avion
        virtual void mostrar(){

            cout << "Identificacion del avion: " << ID << endl;
            cout << "Marca: " << Marca << endl;
            cout << "Modelo: " << Modelo << endl;
            cout<<"Piloto a cargo: --------"<<endl;
            Piloto.mostrarDatos();

        }

        // Métodos de obtencion y modificacion del tipo del avion
        string getID(){
            return ID;
        }

        string getMarca()
        {
            return Marca;
        }

        int getTipo()
        {
            return Tipo;
        }

        void setTipo(int t)
        {
            Tipo = t;
        }
};

// Clase derivada que representa un avion de carga
class cCarga : public cAvion {
    private:
        int Cap_C;

    public:
        // Constructor por defecto, inicializa el tipo y la capacidad de carga
        cCarga(string marca, string modelo, string id, int tipo, cPiloto piloto, int cap_c)
            : cAvion(marca, modelo, id, tipo, piloto), Cap_C(cap_c)
        {}

        // Sobrescribe el método de lectura para incluir la capacidad de carga
        void leer()
        {
            cAvion::leer();
            cout << "Ingrese la Capacidad de Carga: ";
            cin >> Cap_C;
        }

        // Sobrescribe el método de mostrar para incluir la capacidad de carga
        void mostrar()
        {
            cAvion::mostrar();
            cout << "Capacidad de Carga: " << Cap_C << endl;
        }

        // Método de obtencion de la capacidad de carga
        int getCap_C()
        {
            return Cap_C;
        }
    };
class cViajero {
private:
    string id;
    string nombre;
    string apellido;

public:
    // Constructor
    cViajero(string id = "", string nombre = "", string apellido = "")
        : id(id), nombre(nombre), apellido(apellido) {}

    // Destructor
    ~cViajero() {
        // Realizar limpieza si es necesario
    }

    // Métodos get y set para 'id'
    string getId() const {
        return id;
    }

    void setId(string id) {
        id = id;
    }

    // Métodos get y set para 'nombre'
    string getNombre() const {
        return nombre;
    }

    void setNombre(string nombre) {
        nombre = nombre;
    }

    // Métodos get y set para 'apellido'
    string getApellido() const {
        return apellido;
    }

    void setApellido(string apellido) {
        apellido = apellido;
    }

    // Método para leer los datos del viajero desde la entrada estándar
    void leerDatos() {
        cout << "Ingrese ID del viajero: ";
        cin >> id;
        cout << "Ingrese nombre del viajero: ";
        cin >> nombre;
        cout << "Ingrese apellido del viajero: ";
        cin >> apellido;
        cout<<"------------------------"<<endl;
        
    }

    // Método para mostrar la información del viajero
    void mostrarDatos() const {
        cout << "ID del viajero: " << id << endl;
        cout << "Nombre del viajero: " << nombre << endl;
        cout << "Apellido del viajero: " << apellido << endl;
    }
};



    // Clase derivada que representa un avion de pasajeros
class cPasajero : public cAvion {
private:
    cAzafata azafatas[MAX_AZAFATAS];
    cViajero VipViajero[MAX_VIP];
    cViajero TurViajero[MAX_TURISTA];
    int cantidadTripulacion;
    int cantidadVip;
    int cantidadTurista;

public:
    // Constructor
    cPasajero(string marca, string modelo, string id, int tipo, cPiloto piloto)
    : cAvion(marca, modelo, id, tipo, piloto),
      cantidadTripulacion(0),
      cantidadVip(0),
      cantidadTurista(0) {
          for (int i = 0; i < MAX_AZAFATAS; i++) {
              // Aquí suponemos que cada azafata se inicializa con valores predeterminados.
              // Debes ajustar esto según la lógica de tu aplicación.
              azafatas[i] = cAzafata("default_id", "default_nombre", "default_cargo");
          }
          // Initialize or setup other members if needed
      }

    // Destructor
    ~cPasajero() {
    }

    // Métodos get y set
    int getCantidadTripulacion() {
        return cantidadTripulacion;
    }

    void setCantidadTripulacion(int cantidad) {
        cantidadTripulacion = cantidad;
    }

int validar(){
    int aux;
    cin>>aux;
    while ((aux<0) || (aux>MAX_AZAFATAS))
    {
        cout << "Ingresa el numero de nuevo: ";
        cin>>aux;
    }
    return aux;
}
void leer() {
    cAvion::leer(); // Llamada al método mostrar de cAvion
    cout << "------------------------------INGRESO DE TRIPULACION-----------------------" << endl;
    // leer información de cada azafata
    cout << "--Ingresa el numero de Azafatas: ";
    int aux;
    aux=validar();
    for (int i = 0; i < aux; i++) {
        cout <<"Azafata N "<< i+1<<endl;
        azafatas[i].leerDatos();
    }
    cin.ignore();
    
    cout << "--Cantidad de Pasajeros VIP: " ;
    cantidadVip=validar();
    // Mostrar información de cada viajero VIP
    for (int i = 0; i < cantidadVip; i++) {
        cout <<"PasajeroVIP #"<< i+1<<endl;
        VipViajero[i].leerDatos();
    }
    cin.ignore();
    
    cout << "--Cantidad de Pasajeros Turistas: " ;
    cantidadTurista=validar();
    // Mostrar información de cada viajero Turista
    for (int i = 0; i < cantidadTurista; i++) {
        cout <<"PasajeroTUR #"<< i+1<<endl;
        TurViajero[i].leerDatos();
    }
    cin.ignore();
    cantidadTripulacion = cantidadTurista + cantidadVip + aux;
}
    // Método para calcular la cantidad de la tripulación
    

    // Método para agregar azafatas
    void agregarAzafata(cAzafata azafata) {
        if (cantidadTripulacion < MAX_AZAFATAS) {
            azafatas[cantidadTripulacion++] = azafata;
        }
    }

    // Método para agregar VipViajero y TurViajero
    void agregarVipViajero(cViajero viajero) {
        if (cantidadVip < MAX_VIP) {
            VipViajero[cantidadVip++] = viajero;
        }
    }

    void agregarTurViajero(cViajero viajero) {
        if (cantidadTurista < MAX_TURISTA) {
            TurViajero[cantidadTurista++] = viajero;
        }
    }

    // Método para mostrar
void mostrar() {
    cAvion::mostrar(); // Llamada al método mostrar de cAvion
    cout << "Cantidad de Tripulación: " << getCantidadTripulacion() << endl;
    
    // Mostrar información de cada azafata
    cout << "Azafatas:" << endl;
    for (int i = 0; i < cantidadTripulacion; i++) {
        azafatas[i].mostrarDatos();
    }
    
    cout << "Cantidad de Pasajeros VIP: " << cantidadVip << endl;
    // Mostrar información de cada viajero VIP
    for (int i = 0; i < cantidadVip; i++) {
        VipViajero[i].mostrarDatos();
    }
    
    cout << "Cantidad de Pasajeros Turistas: " << cantidadTurista << endl;
    // Mostrar información de cada viajero Turista
    for (int i = 0; i < cantidadTurista; i++) {
        TurViajero[i].mostrarDatos();
    }
}


    // ... otros métodos ...
};


    // Clase que representa un aeropuerto y gestiona aviones
class cAeropuerto{
    private:
        string Nombre, Direccion;
        int Cant_Aviones;
        cAvion* pA[100];

    public:
        // Constructor por defecto
        cAeropuerto()
        {
            Nombre = Direccion = "";
            Cant_Aviones = 0;
        }

        // Método para ingresar informacion del aeropuerto y agregar aviones
         void Leer() {
        cout << "Nombre del Aeropuerto: ";
        // Utilizamos getline para leer la entrada con espacios en blanco
        getline(cin, Nombre);

        cout << "Direccion: ";
        getline(cin, Direccion);

        nuevoAvion();
        }

        // Método para agregar un nuevo avion al aeropuerto
        void nuevoAvion()
{
    if (Cant_Aviones < 100)
    {
        bool b = true;
        do
        {
            int tipo = menu();
            switch (tipo)
            {
            case 1:
                {
                    // Proporciona valores predeterminados o solicita al usuario los valores necesarios
                    string marca, modelo, id;
                    int tipoAvion = 1; // Suponiendo que 1 representa un avión de pasajeros
                    cPiloto piloto("piloto_id", "piloto_nombre", "piloto_cargo", "licencia", 100);
                    pA[Cant_Aviones] = new cPasajero(marca, modelo, id, tipoAvion, piloto);
                    cout << Cant_Aviones + 1 << " Avion de pasajeros: " << endl;
                    pA[Cant_Aviones++]->leer();
                    break;
                }
            case 2:
                {
                    string marca, modelo, id;
                    int tipoAvion = 2; // Suponiendo que 2 representa un avión de carga
                    int cap_c=10; // Variable para almacenar la capacidad de carga
                    // Solicitar al usuario que ingrese la capacidad de carga
                    cin.ignore();
                    cPiloto piloto("piloto_id", "piloto_nombre", "piloto_cargo", "licencia", 100);
                    pA[Cant_Aviones] = new cCarga(marca, modelo, id, tipoAvion, piloto, cap_c);
                    cout << Cant_Aviones + 1 << " Avion de carga: " << endl;
                    pA[Cant_Aviones++]->leer();
                    break;
                }
            case 3:
                b = false;
                cout << "Saliendo del programa....." << endl;
                break;
            }
        } while (Cant_Aviones < 100 && b == true);
    }
}


        // Método para mostrar un menú y obtener la opcion del usuario
        int menu()
        {
            int n;
            cout << "\n\t---<< MENU>>---" << endl;
            cout << " [1] Avion de Pasajeros:" << endl;
            cout << " [2] Avion de Carga:" << endl;
            cout << " [3] Salir:" << endl;
            do
            {
                cout << "\n---------------------"<<endl;
                cout << " Ingrese la Opcion: ";
                cin >> n;
                cout << "\n---------------------"<<endl;
            } while (n < 1 || n > 3);
            return n;
        }

        // Método para mostrar informacion detallada de aviones de pasajeros con capacidad mayor o igual a un valor ingresado
        void MostrarCapPas()
        {
            cout << "\n\tNombre" << Nombre << endl;
            cout << "Direccion: " << Direccion << endl;
            cout << "\n\t---AVIONES CON CANTIDAD DE PASAJEROS MAYOR IGUAL AL VALOR INGRESADO---" << endl;
            int Valor = LeerValor();
            for (int i = 0; i < Cant_Aviones; i++)
            {
                if (pA[i]->getTipo() == 1)
                {
                    cPasajero* pAp = (cPasajero*)pA[i];
                    if (pAp->getCantidadTripulacion() >= Valor)
                    {
                        cout << endl;
                        pA[i]->mostrar();
                    }
                }
            }
        }

        // Método para obtener un valor ingresado por el usuario
        int LeerValor()
        {
            int Valor;
            cout << "\nIngrese un valor_ Usuario: ";
            cin >> Valor;
            return Valor;
        }

        // Método para eliminar un avion
        void EliminarAvion()
        {
            int pos = buscar();
            if (pos == -1)
            {
                cout << "Avion no eliminado" << endl;
            }
            else
            {
                delete pA[pos];
                pA[pos] = pA[--Cant_Aviones];
                cout << "Avion eliminado" << endl;
            }
        }

        // Método para leer la identificacion de un avion
        string leerID()
        {
            string id;
            cout << "\nIngrese la Identificacion del Avion Accidentado: ";
            cin >> id;
            return id;
        }

        // Método para buscar la posicion de un avion por su identificacion
        int buscar()
        {
            string id = leerID();
            int pos = -1, i = 0;
            while (i < Cant_Aviones && pos == -1)
            {
                if (pA[i]->getID() == id)
                {
                    pos = i;
                }
                i++;
            }
            return pos;
        }

        // Destructor que libera la memoria de los aviones
        ~cAeropuerto()
        {
            for (int i = 0; i < Cant_Aviones; i++)
            {
                delete pA[i];
            }
        }
};

// Funcion principal
int main(){
    setlocale(LC_ALL, "");
    cAeropuerto* pAe = new cAeropuerto();

    // Operaciones principales
    pAe->Leer();
    pAe->MostrarCapPas();
    pAe->EliminarAvion();
    pAe->nuevoAvion();

    // Liberar memoria al finalizar
    delete pAe;

    return 0;
}