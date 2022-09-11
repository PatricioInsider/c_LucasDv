#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int a[10000];
	string b[10000];
	int comcas;
	int comprarcasa;
	int d,d1,z1,h,hl,h1,i,r1,r2,r4,rl1,ter,ter1,vas,r21,r2111,r2a,r2q,r211,r23;
	int num;
	int w[1000];
	string w1[1000];
	string x;
	int z;
	cout << "Bienvenido a la Inmobiliaria Don Cangrejo" << endl;
	cout << "Por favor ingresa tu nombre" << endl;
	cin >> x;
	cout << "Por favor ingresa tu numero de cedula" << endl;
	cin >> z;
	// Menu de presentaci�n
	do {
            int NumerodeFactura = 0;
            string aux;
		cout << "*****************************************" << endl;
		cout << "Bienvenido a la Inmoviliaria Don Cangrejo" << endl;
		cout << "*****************************************" << endl;
		cout << "Por favor elija un servicio que desee utilizar" << endl;
		cout << "1._Compra y venta " << endl;
		cout << "2._Arriendo" << endl;
		cout << "3._Salir" << endl;
        cin >> num;
		switch (num){
		case 1:
		     	             /// --------------------------->> COMPRAR Y VENTA <<----------------------------------------------------//

			cout << "**************************************************" << endl;
			cout << "1._Casa" << endl;
			cout << "2._Terreno" << endl;
			cout << "**************************************************" << endl;
			cin >> r1;
			cout << "Desea comprar(0) o vender(1)" << endl;
			cin >> rl1;
			                                // * COMPRA DE CASAS * //
			if (r1==1 && rl1==0) {
				cout << "1._Casa de 3 pisos con piscina,garage y patio trasero = $22500" << endl;
				cout << "2._Casa de 2 pisos con jardin y garage = $15000" << endl;
				cout << "3._Casa de 1 piso con garage = $7500" << endl;
				cout << "**************************************************" << endl;
				cin >> comcas;
				cout << "Cuantas casas deseas comprar" << endl;
				cin >> comprarcasa;
            fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE COMPRA DE CASA/S "<<endl;
                data << " NOMBRE DEL/A VENDEDOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data << " CASAS COMPRADAS: "<<comprarcasa<<endl;

                if (comcas==1) {
					d = comprarcasa*22500;
					data << "El total de la venta es de :" << d << endl;
                    } else if (comcas==2) {
						d1 = comprarcasa*15000;
						data << "El total de la venta es de :" << d1 << endl;
					} else if (comcas==3) {
							z1 = comprarcasa*7500;
							data << "El total de la venta es de :" << z1 << endl;
                    }
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();
                    }

                if (r1==1 && rl1==1) {

                                            // * VENTA DE CASAS * //
					cout << "Cuantas casas deseas vender" << endl;
					cin >> vas;
					if (r1==1) {
						for (i=1;i<=vas;i++) {
							cout << "Ingrese el valor de la casa " << i << endl;
							cin >> a[i];
							cout << "Ingrese la dimension de la casa " << i << endl;
							cin >> b[i];
						}
						cout << "**************************************************" << endl;
						for (i=1;i<=vas;i++) {
							cout << "Valor de la casa: " << a[i] <<" $  " << "Dimension: " << b[i] << endl;
						}
						cout << "**************************************************" << endl;

            fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE VENTA DE CASA/S "<<endl;
                data << " NOMBRE DEL/A VENDEDOR/RA: "<<x<<" CON CI: "<<z<<endl;
                for (i=1;i<=vas;i++) {
                data << "CASA No."<<i<<endl;
                data << "VALOR DE LA CASA: " << a[i] <<" $  " << "DIMENSION: " << b[i] << endl;
						}
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();

                  }

					}
                                            // * COMPRAR TERRENO/S * //
					if (r1==2 && rl1==0) {
						cout << "Cuantos terrenos deseas comprar?" << endl;
						cin >> h;
						cout << "**************************************************" << endl;
						cout << "1._Terrenos de 240000m�2   -->$750,000" << endl;
						cout << "2._Terrenos de 14789652m�2  -->$1,2 millones" << endl;
						cout << "**************************************************" << endl;
						cin >> hl;


							fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE COMPRA DE TERRENO/S "<<endl;
                data << " NOMBRE DEL/A VENDEDOR/RA: "<<x<<" CON CI: "<<z<<endl;
                if (hl==1) {
							ter = h*750000;
							data << "El total de la compra es de: " << ter << endl;
						} else if (hl==2) {
								ter1 = h*1200000;
                            data << "El valor total de la compra es de: " << ter1 << endl;
							}
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();

					}
							         // * VENDER TERRENO/S*

						if (r1==2 && rl1==1){
						cout << "Cuantos terrenos deseas vender?" << endl;
						cin >> h1;
						for (i=1;i<=h1;i++) {
							cout << "Ingrese el valor del terreno " << i << endl;
							cin >> w[i];
							cout << "Ingrese la dimension del terreno " << i << endl;
							cin >> w1[i];
						}


                                    fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE COMPRA DE TERRENO/S "<<endl;
                data << " NOMBRE DEL/A VENDEDOR/RA: "<<x<<" CON CI: "<<z<<endl;
                for (i=1;i<=h1;i++) {
							data << "El valor del terreno " << i << " y su dimension es:" << endl;
							data << "El valor del terreno es: " << w[i] << "  " << "Dimension: " << w1[i] << endl;
						}
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();
					}

			break;

		case 2:
		             ///----------------------->>  ARRIENDO  <<-----------------------------------------------------///
			cout << "**************************************************" << endl;
			cout << "1._Casa" << endl;
			cout << "2._Departamentos" << endl;
			cout << "**************************************************" << endl;
			cin >> r2;
			                                /// * ARRENDAR CASA/S *
			if(r2==1){
                cout<<"\n************************************************";
                cout<<"\n1._2 Pisos,3 Dormitorios y 2 Ba�os privados   --->   $225";
                cout<<"\n2._1 Piso,2 Dormitorios, y 1 Ba�o privado     --->   $120";
                cout<<"\n************************************************";
                cout<<endl;
                cin>>r21;
                if(r21==1){
                    cout<<"\nDesea que este amueblado?: (1)si  (0)no"<<endl;
                    cout<<endl;
                    cin>>r211;
                    if (r211==1){
                        cout<<"\nEl valor extra a pagar por el amueblado es $150"<<endl;
                        r2q=225+150;
                        cout<<"\nEl total a pagar por el arriendo es: "<<r2q<<" $"<<endl;
                        cout<<endl;

                                    fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE ARRIENDO DE CASA"<<endl;
                data << " NOMBRE DEL/A ARRENDADOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data <<"\nEl total a pagar por el arriendo es: "<<r2q<<" $"<<endl;
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();






                    }else{

                        if(r211==0){
                                                fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE ARRIENDO DE CASA"<<endl;
                data << " NOMBRE DEL/A ARRENDADOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data <<"\nEl total a pagar por el arriendo es: 225 $"<<endl;
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();



                        }

                        }

                }else{
                        if(r21==2){
                        cout<<"\nDesea que este amueblado?: (1)si,(0)no";
                        cout<<endl;
                        cin>>r2111;
                        if(r2111==1){
                            cout<<"\nEl valor extra a pgar por el amueblado es $105";
                            r2a=105+120;
                            cout<<"\nEl total a pagar por el arriendo es: $"<<r2a;
                            cout<<endl;



                            fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE ARRIENDO DE CASA"<<endl;
                data << " NOMBRE DEL/A ARRENDADOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data <<"\nEl total a pagar por el arriendo es: "<<r2a<<" $"<<endl;
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();


                        }else{
                        if(r2111==0){
                          fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE ARRIENDO DE CASA"<<endl;
                data << " NOMBRE DEL/A ARRENDADOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data <<"\nEl total a pagar por el arriendo es: 120 $"<<endl;
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();

                          }

                          }

                          }

                          }





                                              /// * ARRENDAR DEPARTAMENTO/S*

			} else if(r2==2){

                    cout<<"\n************************************************";
                    cout<<"\n1._Departamento: 3 dormitorios, 2 ba�os privados ---> $150";
                    cout<<"\n2._ Departamento: 2 dormitorio, 1 ba�o privado    ---> $80";
                    cout<<"\n************************************************";
                    cin>>r23;
                    cout<<"\nLos departamentos no poseen la opci�n de amueblar";
                    if(r23==1){

                                    fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE ARRIENDO DE DEPARTAMENTO"<<endl;
                data << " NOMBRE DEL/A ARRENDADOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data <<"\nEl total a pagar por el arriendo es: 150 $"<<endl;
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();

                    }else if(r23==2){

                            fstream  data("facturaCASA.txt",ios::out);
			if(!data.is_open()){
             data.open("facturaCASA.txt");
              }
                data << "||=========================================================||"<<endl;
                data << "||               INMOBILIARIA  DON CANGREJO                ||"<<endl;
                data << "||---------------------------------------------------------||"<<endl;
                data << "||  DIRECCION: Guayaquil y Espejo 1254                     ||"<<endl;
                data << "||  FACTURA No."<<NumerodeFactura+1<<"                    ||"<<endl;
                data << "||=========================================================||"<<endl<<endl;
                data << ">> FACTURA DE ARRIENDO DE DEPARTAMENTO"<<endl;
                data << " NOMBRE DEL/A ARRENDADOR/RA: "<<x<<" CON CI: "<<z<<endl;
                data <<"\nEl total a pagar por el arriendo es: 80 $"<<endl;
                cout<<endl;
                data.close();
              if (!data.is_open()) {
                   data.open("facturaCASA.txt",ios::in);
                    }
                  while (!data.eof()) {
                      getline(data, aux);
                   cout << aux << endl;
                   }
                    data.close();


                            }
                            }


			break;
			///--------------------------------------------------------- FACTURA -----------------------------------------///

		case 3:
		    break;
		}
		system("pause");
		system("cls");
	}while(num!=3);
	cout<<endl;

	cout<<"Gracias por utilizar nuestros servicios";

	}

