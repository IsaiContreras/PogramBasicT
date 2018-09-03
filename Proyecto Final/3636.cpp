#include <iostream>
using namespace std;

int selec;
void manual();
void listaAlumnos();
void editarLista();
void agregar();
void eliminar();


void main() {
	locale::global(locale("spanish"));
	system("cls");
	cout << "Menú Principal. " << endl;
	cout << "Introduzca el número de la opción que desea seleccionar. " << endl;
	cout << "1. Manual de Uso. \n2. Lista de alumnos. \n3. Salir.  " << endl;
		cin >> selec;

	switch (selec) {
	case 1: manual();
		break;
	case 2: listaAlumnos();
		break;
	case 3: cout << "Estas saliendo del programa. " << endl;
		system("pause");
		break;
	default: cout << "Seleccione una opción valida. " << endl;
		system("pause");
		main();
		break;
	}
}

void manual() {
	system("cls");
	cout << "Manual de Uso. " << endl;
	cout << "Bienvenido al manual de uso. \n" << endl;
	system("pause");
	main();
}

void listaAlumnos(){
	system("cls");
	cout << "Lista de Alumnos. " << endl;



	cout << "1. Editar Lista. \n2. Salir al Menú. " << endl;
	cin >> selec;

	switch (selec) {
	case 1: editarLista();
		break;
	case 2: main();
		break;
	default: cout << "Seleccione una opción valida. " << endl;
		system("pause");
		listaAlumnos();
		break;
	}
}

void editarLista() {
	system("cls");
	cout << "Edición de Lista de Alumnos. " << endl;



	cout << "1. Registrar. \n2. Eliminar. \n3. Regresar a la Lista. " << endl;
	cin >> selec;

	switch (selec) {
	case 1: agregar();
		break;
	case 2: eliminar();
		break;
	case 3: listaAlumnos();
		break;
	default: cout << "Seleccione una opción valida. " << endl;
		system("pause");
		editarLista();
		break;
	}
}

void agregar() {
	system("cls");
	cout << "Registro. " << endl;
	cout << "Registre los datos del alumno. " << endl;

	cout << "1. Registrar otro alumno. \n2. Volver a edición de lista. " << endl;
	cin >> selec;

	switch (selec) {
	case 1: agregar();
		break;
	case 2: editarLista();
		break;
	default: cout << "Seleccione una opción valida. " << endl;
		system("pause");
		agregar();
		break;
	}
}

void eliminar() {
	system("cls");
	cout << "Eliminar Alumno. " << endl;
	cout << "Seleccione el alumno que desea eliminar. " << endl;

	cout << "1. Eliminar otro alumno. \n2. Volver a edición de lista. " << endl;
	cin >> selec;

	switch (selec) {
	case 1: eliminar();
		break;
	case 2: editarLista();
		break;
	default: cout << "Seleccione una opción valida. " << endl;
		system("pause");
		agregar();
		break;
	}
}
