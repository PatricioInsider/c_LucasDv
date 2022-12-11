/*
*/
#include <iostream>
#include <string.h>

using namespace std;

class Point
{
private:
    float x,y;
    string id;
public:
    Point(float a,float b);
    Point()
    {
        
    }

    void data_point(void)
    {
        cout<<"x = ";
        cin>>x;
        cout<<"y = ";
        cin>>y;
        cout<<"id = ";
        cin>>id;
    }

    void read_point(void)
    {
        cout<<"----------------"<<endl;
        cout<<"Elemento Punto"<<endl;
        cout<<"Ingresa los valores"<<endl;
        data_point();
        system("pause");
    }
    void show_point(void)
    {
        cout<<"Posicion"<<endl;
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }

    int getx(void)
    {
        return x;
    }
    int gety(void)
    {
        return y;
    }
    void setx(int a)
    {
        x=a;
    }
    void sety(int a)
    {
        y=a;
    }
    string getid(void)
    {
        return id;
    }
};

class Circle: public Point{
private:
    float r;
public:

	Circle(float a, float b, float c): Point(a, b)
    {
        r=c;
    };
    Circle()
    {
    };

    void data_circle(void)
    {
        data_point();
        cout<<"r = ";
        cin>>r;
    }
    void read_circle(void)
    {
        cout<<"----------------"<<endl;
        cout<<"Figura Circulo "<<endl;
        cout<<"Ingresa los valores"<<endl;
        data_circle();
        system("pause");
    }

    float area_cir()
    {
        float a;
        a= 3.1416*(r*r);
        return a;
    }
    void show_circle()
    {
        cout<<"Posicion: "<<endl;
        cout<<"x = "<<getx()<<endl;
        cout<<"x = "<<gety()<<endl;
        cout<<"r = "<<r<<endl;
        cout<<"Area = "<<area_cir()<<endl;
    }
    float getr(void)
    {
        return r;
    }
    void setr(int a)
    {
        r=a;
    }
};

class Cylinder: public Circle{

private:
    float h;
public:
    Cylinder(float a,float b,float c,float d):Circle(a,b,c)
    {
        h=d;
    }
    Cylinder():Circle(){
			h=0;
	}
    void data_cylinder()
    {
        data_circle();
        cout<<"h= ";
        cin>>h;
    }
    void read_cylinder()
    {
        cout<<"----------------"<<endl;
        cout<<"Figura Cilindro"<<endl;
        cout<<"Ingresa los valores"<<endl;
        data_cylinder();
        system("pause");
    }

    float area_cyl()
    {
        float area;
        area= 2*3.1416*(getr()*(getr()+h));
        return area;
    }

    float vol_cyl()
    {
        float vol;
        vol= area_cir()*h;
        return vol;
    }

    void show_cylinder()
    {
        cout<<"Posicion: "<<endl;
        cout<<"x = "<<getx()<<endl;
        cout<<"y = "<<gety()<<endl;
        cout<<"r = "<<getr()<<endl;
        cout<<"Area= "<<area_cyl()<<endl;
        cout<<"Volumen = "<<vol_cyl()<<endl;
    }
    void up_cyl()
	{
	    int a,b,c,d;
	    cout<<"Nuevo x: "<<endl;
	    cin>>a;setx(a);
	    cout<<"Nuevo y: "<<endl;
	    cin>>b;sety(b);
	    cout<<"Nuevo r: "<<endl;
	    cin>>c;setr(c);
	    cout<<"Nuevo h: "<<endl;
	    cin>>h;
	}

};

class Figures{ //figures es de mu�eco
	private:
		int n;
		Cylinder oBody[100];
	public:

	void read_figures()
	{
		cout<<"Ingresa el numero de extremidades"<<endl;
		cin>>n;
		cout<<"Diagrama de cuerpo____"<<endl;
		for (int i;i<n;i++)
		{
            cout<<"Cilindro numero :"<<i+1<<endl;
			oBody[i].data_cylinder();
		}
	}

	void show_figures(void)
	{
		cout<<"Datos del Mu�eco"<<endl;
		for (int i;i<0;i++)
		{
			oBody[i].show_cylinder();
		}
	}


	//Mostrar todos los cilindros que sehan mayor o igual al promedio de volumen
    float promedi_all_cyl()
    {
        int a=0,aux=0,aux2;
        for(int i=0;i<n;i++)
        {
            a= oBody[i].vol_cyl();
            aux+=a;
        }
        if (aux!=0)
        {
            aux2=aux/n;
        }
        return(aux2);
    }

	void may_figures(void)
	{
	    cout<<"Impresion de cilindros menores al promedio"<<endl;
	    for (int i=0;i<n;i++)
        {
            if(oBody[i].vol_cyl()>=promedi_all_cyl())
            {
                cout<<"Cilindro n="<<i+1<<endl;
                cout<< oBody[i].vol_cyl();
            }
        }

	}
	//B)Actualizar los datos del mu�eco a traves de un identificador;


	void update_figures()
	{
	    string searchId;
	    cout<<"Actualizar los datos de un cilindro"<<endl;
	    cout<<"Ingresa el identificador a buscar"<<endl;
	    cin>>searchId;
	    int i=0;
	    int aux=-1;
	    while(aux==-1&&i<n)
        {
            if(oBody[i].getid()==searchId)
            {
                cout<<"Cilindro n="<<i+1<<endl;
                oBody[i].up_cyl();
                aux=i;
            }
            i++;
        }


	}

};

Point::Point(float a,float b)
{
	x=a;
	y=b;
}

int main (void)
{
    /*
	Point oPoint;
    oPoint.read_point();
    oPoint.show_point();
    Circle oCircle;
    oCircle.read_circle();
    oCircle.show_circle();
    Cylinder oCylinder;
    oCylinder.read_cylinder();
    oCylinder.show_cylinder();
    */
    Figures oPinocho;
    oPinocho.read_figures();
    oPinocho.show_figures();
    //oPinocho.may_figures();
	oPinocho.update_figures();
    oPinocho.show_figures();
	return 0;
}
