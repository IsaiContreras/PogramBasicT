#include <iostream>
#include <math.h>
using namespace std;

void main() {
	float r, alpha, x, y;

	locale::global(locale("spanish"));

	cout << "Introduzca un vector de radio r y ángulo alpha. ";
	cin >> r >> alpha;

	alpha = alpha * (3.1416 / 180);

	x = r * cos(alpha) ;
	y = r * sin(alpha) ;

	cout << "Las coordenadas de el vector son:" << endl;
	//Para que se vea más elegante.
	cout << "Abscisa (x) = " << x << ". Ordenada (y) = " << y <<". "<<endl;
	

	system("pause");
}