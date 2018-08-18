#include <iostream>
#include <math.h>
using namespace std;

/* Programa que calcula el radio r y �ngulo
sexagecimal alfa dadas las coordenadas (x, y)
de un punto.*/

int main(){
	

	float x, y, r, alpha;

	cout << "Escribe las coordenadas de un punto (x, y). ";
	cin >>x>>y;

	r = sqrt(pow(x, 2) + pow(y, 2));
	alpha = asin(y / r);
	alpha = round( alpha * 180.0 / 3.1416);
	
	cout << "El radio es: " << r << ", y el �ngulo es : " << alpha << "." << endl;

	system("pause");
	return 0;
}
