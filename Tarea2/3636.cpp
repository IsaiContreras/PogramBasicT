#include <iostream>
using namespace std;

int main() {
	locale::global(locale("spanish"));

	int edad;
	char nombre[20], apellido[20], tel[20];
	cout << "Introduzca su nombre, porfavor: ";
	cin >> nombre;

	cout << "Indroduzca su apellido: ";
	cin >> apellido;

	cout << "Introduzca su edad: ";
	cin >> edad;

	cout << "Por �ltimo, introduzca su tel�fono: ";
	cin >> tel;

	cout << "Muchas gracias, aqu� su ficha de datos."<< endl;
	cout << endl;

	cout << "Nombre completo: " << apellido << ", " << nombre << "." << endl;
	cout << "---" << endl;
	cout << "Edad: " << edad << " a�os." << endl;
	cout << "Tel�fono: +52 " << tel << endl;


	system("pause");
	return 0;
}