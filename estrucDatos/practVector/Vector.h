/*TDA que iimplementa las operaciones basicas de gestion
de un arreglo unidimensional (vectores)*/
// Ejercicio 1: TDA que implementa las operaciones basicas de gestion de un arreglo unidimensional (vector)
// Nombe: Patricio Quishpe		Fecha:08 de noviembre de 2023

#include <iostream>
#define EXT 50

using namespace std;

class Vector
{				// Definicion del TDA
				// Definir atributos
private:		// Visibilidad de los elementos
	int ne;		// numero de elementos
	int v[EXT]; // Contenedor de valores

	
public: 
	
	Vector();
	// Ingresarelementos
	void ingresarE();
	void imprimirE();	   // imprimir
	void ordenarE();	   // ordenar
	void calcularMenMay(); // calcular-menor-mayor
	void insertarE();	   // insertar
	void eliminarE();	   // eliminar
	bool metodoBusqueda(int val);
	void buscarE(); // buscar- retorna posicion

	void setNe(int val);		 // Metodo que modifica estado del atributo
	void setV(int val, int pos); // Metodo que modifica estado de un elemento del atributo
	int getNe();				 // Metodo que devuelve el valor del atributo
	int getV(int pos);			 // Metodo devuelve estado independiente de un elemento del vector
};
// Implementacion de los metodos
Vector::Vector()
{
	// Inicializa los atributos
	setNe(0); // inicializador atributo ne
}
void Vector::setNe(int val)
{
	ne = val; // Almacena val en el atributo ne
}
void Vector::setV(int val, int pos)
{
	v[pos] = val; // val se almacena en posicion pos del vector v
}
int Vector::getNe()
{
	return ne; // devuelve el valor del atributo ne
}
int Vector::getV(int pos)
{
	return v[pos]; // devuelve el valor del elemento x del vector
}

// Ingresarelementos
void Vector::ingresarE()
{
	int n, val;
	cout << "IMGRESAR DE VALORES" << endl;
	cout << "cantidad de elementos a ingresar(max " << EXT << " ): " << endl;
	cin >> n;
	while ((n < 0) || (n > 50))
	{
		cout << "error, cantidad no valida:" << endl
			 << "Ingresa de nuevo el valor(max " << EXT << " ): " << endl;
		cin >> n;
	}
	setNe(n);
	for (int i = 0; i < getNe(); i++)
	{

		cout << "valor (" << i + 1 << ") :" << endl;
		cin >> val;
		/* En caso que se requiera ingresar valores positivos
		while (val<0)
		{
			cout<<"Ingresa un valor positivo"<<endl;
			cin>>val;
		}
		*/
		setV(val, i);
	}
}
// imprimir
void Vector::imprimirE()
{

	if (getNe() != 0)
	{
		for (int i = 0; i < getNe(); i++)
		{
			cout << "valor (" << i + 1 << ") : " << getV(i) << endl;
		}
	}
	else
	{
		cout << "El vector esta vacio" << endl;
	}
}

// ordenar
void Vector::ordenarE()
{
	int aux;

	for (int i = 0; i < getNe() - 1; i++)
	{
		aux = i;
		for (int j = i + 1; j < getNe(); j++)
		{
			if (getV(j) < getV(aux))
			{
				aux = j;
			}
		}
		int aux2 = getV(aux);
		setV(getV(i), aux);
		setV(aux2, i);
	}
	// mostrar
}
// calcular-menor-mayor
void Vector::calcularMenMay()
{

	ordenarE();
	if (getNe() != 0)
	{
		cout << "Valor menor" << v[0] << endl;
		cout << "Valor mayor" << v[(getNe() - 1)] << endl;
	}
	else
	{
		cout << "El vector esta vacio" << endl;
	}
}

// insertar
void Vector::insertarE()
{

	int n, val;
	cout << "Valores maximo que puedes ingresar " << EXT - getNe() << " : " << endl;
	cin >> n;
	while ((n < 0) || (n > (EXT - getNe())))
	{
		cout << "error, cantidad no valida:" << endl;
		cout << "Ingresa de nuevo el valor(max " << EXT - getNe() << " ): " << endl;
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Ingrese el valor que deceas agregar : ";
		cin >> val;
		// validamos en el ingreso de n que no debe sobrepasar la capacidad
		if (getNe() < EXT)
		{
			setV(val, getNe());
			setNe(getNe() + 1);
		}
		else
		{
			cout << "Se ha alcanzado el límite máximo de valores." << endl;
			break;
		}
	}
	ordenarE();
	imprimirE();
}
// eliminar
void Vector::eliminarE()
{

	if (getNe() == 0)
	{
		cout << "El arreglo está vacío." << endl;
	}
	else
	{
		

		int valor, i, j;
		bool en = false;
		cout << "Ingrese el valor que desea eliminar: ";
		cin >> valor;

		for (i = 0; i < getNe(); i++)
		{
			if (getV(i) == valor)
			{
				en = true;
				for (j = i; j < getNe() - 1; j++)
				{
					setV(getV(j + 1), j);
				}
				setNe(getNe() - 1);
				i--;
			}
		}
	}
	ordenarE();
	imprimirE();
}
// buscar
void Vector::buscarE()
{
	int val2;
	cout << "Ingresa el valor a buscar" << endl;
	cin >> val2;
	if (metodoBusqueda(val2))
	{
		cout << "Elemento encontrado :" << val2 << endl;
	}
	else
	{
		cout << "No se encontro el elemento " << endl;
	}
}
bool Vector::metodoBusqueda(int val)
{
	// retorna la posicion
	int i;
	bool b = false;

	for (i = 0; i < ne; i++)
	{ // Recorrido del vector ordenado
		if (val == v[i])
		{ // Se encuentra el valor
			return b = true;
		}
	}
	return b;
}