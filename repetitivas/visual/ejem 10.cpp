#include <iostream>

using namespace std; 
int main (){
  int i,x;
  for(int i=1;i<106;i+=1){
    x = i*i;
    if ((x>999)&&(x<10000)){
        cout<<"C_perfecto _ "<< i<< " x "<< i<<  "= "<< x<< "  "<<endl;
    }
  }  

}