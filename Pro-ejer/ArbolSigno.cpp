#include <iostream>

using namespace std;
int main() {
  //Teclado numero de filas
  //Arbol y tronco con la mitad
  //numero de filas >5
  int filas=0;
  do{
    cout<<"Ingresa el numero de filas del arbol (este debe ser mayor que 5): "<<endl;
    cin>>filas;
  }while(filas<6);
  
  //Cuerpo del arbol
 int k = 1;
  for (int i=filas;i>0;i--){
   //Espacios
  for (int j=i;j>0;j--){
   cout<<" ";
  }
  //cuerpo
   
  for(int l=0;l<k;l++){
      cout<<"*"<<" ";
    }
    k+=1;
  cout<<endl;
    
  }

  //Tronco del arbol
  
  int v=filas-1;
  filas=filas/2;
  int m = 1;
  for (int i=filas;i>0;i--){
   //Espacios
  for (int j=1;j<=v;j++){
   cout<<" ";
  }
  //cuerpo
   
  for(int m=0;m<2;m++){
      cout<<"*"<<" ";
    }
    k+=1;
  cout<<endl;
    
  }
}