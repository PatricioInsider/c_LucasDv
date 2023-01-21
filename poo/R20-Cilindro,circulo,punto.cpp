#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

class Punto
{
private:
  int x, y, tipo;
  string id;

public:
  Punto(/* args */);
  ~Punto();

  virtual void leer()
  {
    cout << "Ingresa los valores" << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "id=";
    cin >> id;
  }

  virtual void mostrar(void)
  {
    cout << "Posicion" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
  }
  float modulo()
  {
    float mod = sqrt((x * x) + (y * y));
    return mod;
  }
  float getmodulo()
  {
    return modulo();
  }

  string getid()
  {
    return id;
  }
  int gettipo()
  {
    return tipo;
  }
  void settipo(int newtipo)
  {
    tipo = newtipo;
  }
};

class Circulo : public Punto
{
private:
  int r;

public:
  Circulo(/* args */);
  ~Circulo();
  void leer()
  {
    Punto::leer();
    cout << "r = ";
    cin >> r;
  }
  float area()
  {
    float a;
    a = 3.1416 * (r * r);
    return a;
  }
  void mostrar()
  {
    Punto::mostrar();
    cout << "r = " << r << endl;
    cout << "Area = " << area() << endl;
  }
};

Circulo::Circulo(/* args */)
{
  r = 0;
  settipo(2);
}

Circulo::~Circulo()
{
}

class Cilindro : public Circulo
{
private:
  int h;

public:
  Cilindro(/* args */);
  ~Cilindro();
  void leer()
  {
    Circulo::leer();
    cout << "h= ";
    cin >> h;
  }
  float vol()
  {
    float vol;
    vol = area() * h;
    return vol;
  }
  void mostrar()
  {
    Circulo::mostrar();
    cout << "Volumen = " << vol() << endl;
  }
};

Cilindro::Cilindro(/* args */)
{
  h = 0;
  settipo(3);
}

Cilindro::~Cilindro()
{
}

Punto::Punto(/* args */)
{
  x = y = 0;
  tipo = 1;
}

Punto::~Punto()
{
}

class Figura
{
private:
  Punto *pVecFigura[100];
  int n;

public:

  Figura();
  ~Figura();
  
  int menu()
  {
    int opc;
    cout << "Ingresa el literal\n 1)Punto 2)Circulo 3)Cilindro" << endl;
    cin >> opc;
    while (opc < 0 && opc > 4) // verificar
    {
      cout << "ingresa de nuevo la opc" << endl;
      cin >> opc;
    }
    return opc;
  }
  // a ingreso de datos
  // listo
  void leer()
  {
    cout << "Ingresa la cantidad de figuras";
    cin >> n;
    if (n > 0)
    {
      for (int i = 0; i < n; i++)
      {
        switch (menu())
        {
        case 1:
          cout << "(punto)Ingresa los datos de la figura" << i + 1 << endl;
          pVecFigura[i] = new Punto;
          pVecFigura[i]->leer();
          break;
        case 2:
          cout << "(Circulo)Ingresa los datos de la figura" << i + 1 << endl;
          pVecFigura[i] = new Circulo;
          pVecFigura[i]->leer();
          break;
        case 3:
          cout << "(Circulo)Ingresa los datos de la figura" << i + 1 << endl;
          pVecFigura[i] = new Cilindro;
          pVecFigura[i]->leer();
          break;
        default:
          cout << "No se ingreso un dato valido" << endl;
          break;
        }
      }
    }
  }

  // b. Mostrar los datos de los figuras, agregando el área y volumen de aquellas figuras que lo permitan
  void mostrar()

  {

    for (int i = 0; i < n; i++)
    {
      pVecFigura[i]->mostrar();
    }
  }

  // c. Mostrar el punto, círculo o cilindro que se encuentre más cerca del origen de coordenadas
  // Listo
  int busca()
  {
    int pos = -1, max = 999;
    for (int i = 0; i < n; i++)
    {
      if (pVecFigura[i]->getmodulo() < max)
      {
        max = pVecFigura[i]->getmodulo();
        pos = i;
      }
    }
    return pos;
  }
  void mostrar_cercano_origen()
  {
    int pos = busca();
    cout << " La figura mas cercana al origen es: " << endl;
    pVecFigura[pos]->mostrar();
    // Comprar
  }
  // d. Agregar un nuevo elemento a la Figura.
  // Listo
  void agregar()
  {
    n += 1;
    switch (menu())
    {
    case 1:
      cout << "(punto)Ingresa los datos de la figura" << n << endl;
      pVecFigura[n] = new Punto;
      pVecFigura[n]->leer();
      break;
    case 2:
      cout << "(Circulo)Ingresa los datos de la figura" << n << endl;
      pVecFigura[n] = new Circulo;
      pVecFigura[n]->leer();
      break;
    case 3:
      cout << "(Circulo)Ingresa los datos de la figura" << n << endl;
      pVecFigura[n] = new Cilindro;
      pVecFigura[n]->leer();
      break;
    default:
      cout << "No se ingreso un dato valido" << endl;
      break;
    }
  }

  // e. Eliminar un elemento de la figura, dado su identificador.
  // Listo
  int ubi(string bus)
  {
    int pos = -1;
    int i = 0;
    cout << "Buscando..." << endl;
    while ((pos == -1) && (i < n))
    {

      if (pVecFigura[i]->getid() == bus)
      {
        pos = i;
      }
      i++;
    }
    return pos;
  }
  void eliminar()
  {
    string elemento;
    cout << "Ingresa  el identificador: " << endl;
    cin >> elemento;
    if (n > 0)
    {
      int aux = ubi(elemento);
      delete pVecFigura[aux];
    }
  }

  // f. Actualizar la información de un elemento de la Figura, dado su identificador.
  // listo
  void actualizador()
  {
    string iden;
    cout << "ingrese identificador de la figura: ";
    cin >> iden;
    int pos = ubi(iden);
    pVecFigura[pos]->leer();
  }

  // g. Intercambiar dos elementos de la Figura, dados sus identificadores.
  void intercambiar()
  {
    int val1, val2;
    cout << "Ingresa la ubicacion del valor que deceas intercambiar:" << endl;
    cout << "Ingresa valor 1: ";
    cin >> val1;
    if (val1 < n)
    {
    }
    while ((val1 < 0) || (val1 > n))
    {
      cout << "Ingressa una ubicacion valida \n";
      cout << "Ingresa valor 1: ";
      cin >> val1;
    }
    cout << "Ingresa valor 2: ";
    cin >> val2;
    while ((val1 < 0) || (val1 > n))
    {
      cout << "Ingresa una ubicacion valida \n";
      cout << "Ingresa valor 2: ";
      cin >> val2;
    }
    Punto *pAux;
    pAux = pVecFigura[val1];
    pVecFigura[val1] = pVecFigura[val2];
    pVecFigura[val2] = pAux;
  }

  // h, Mostrar los círculos cuya área sea mayor a una ingresada por el usuario.
  void areaUsuario()
  {
    float area;
    cout << "ingrese un area a comparar: ";
    cin >> area;
    for (int i = 0; i < n; i++)
    {
      if (pVecFigura[i]->gettipo() == 2)
      {
        Circulo *pC;
        pC = (Circulo *)pVecFigura[i];
        if (pC->area() > area)
        {
          pVecFigura[i]->mostrar();
        }
      }
    }
  }

  // i. Mostrar todos los cilindros cuyo volumen sea inferior a uno ingresado por el usuario, incluyendo el volumen promedio de éstos.
  void volumen_inferior()
  {
    float volumen;
    cout << "Ingresa el volumen de referencia: ";
    cin >> volumen;
    float aux = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
      if (pVecFigura[i]->gettipo() == 3)
      {
        Cilindro *pAux = (Cilindro *)pVecFigura[i];
        if (pAux->vol() < volumen)
        {
          pVecFigura[i]->mostrar();
          aux += pAux->vol();
          pos++;
        }
      }
    }

    cout << "El promedio del volumen inferior al ingresado es :" << aux / pos << endl;
  }
};

Figura::Figura()
{
  n=0;
}
Figura::~Figura()
{
  for (int i = 0; i < n; i++)
  {
    delete pVecFigura[i];
  }
  
}

int main()
{
  Figura *pCentral = new Figura;
  pCentral->leer();
  pCentral->mostrar();
  pCentral->mostrar_cercano_origen();
  pCentral->agregar();
  pCentral->eliminar();
  pCentral->actualizador();
  pCentral->intercambiar();
  pCentral->areaUsuario();
  pCentral->volumen_inferior();
}