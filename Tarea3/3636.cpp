#include <iostream>
using namespace std;

void main() {
	int SUMA, n;

	cout << "Introduzca un numero natural. ";
	cin >> n;

	SUMA = n * (n + 1) / 2;

	cout << "La suma de los primeros " << n << " numeros naturales es = " << SUMA<<endl;
	system("pause");
}