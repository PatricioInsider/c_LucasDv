#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a,b,c,per,area;
    cout<< "Lado a: " << endl;
    cin >> a ;
    cout<< "Lado b: " << endl;
    cin >> b ;
    cout<< "Lado c: " << endl;
    cin >> c ;

    per = (a+b+c)/2;
    area = sqrt((per*(per - a)*(per - b)*(per - c)));

    cout<< "Perimetro del triangulo: " << per <<endl;
    cout<< "Area del triangulo: " << area <<endl;
}
