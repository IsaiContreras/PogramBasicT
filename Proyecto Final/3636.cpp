#include <iostream>
#include <string>
using namespace std;

//Estructura de alumno
struct alumno {
	bool oc = false;
	string nombre;
	string apellidoP;
	string apellidoM;
	string correoE;
	string tel;
	string matr;
	string num;
	string calle;
	string col;
	int cal[3];
};

//Variables globales
int selec;
alumno a[20];
int i;

//Funciones
void manual();
void editarLista();
void agregar();
void eliminar();

//MENU PRINCIPAL
int main() {
	locale::global(locale("spanish"));
	system("cls");
	cout << "Menú Principal. " << endl;
	cout << "Introduzca el número de la opción que desea seleccionar. " << endl;
	cout << "1. Manual de Uso. \n2. Lista de alumnos. \n3. Salir.  " << endl;
		cin >> selec;

	switch (selec) {
	case 1: manual();
		break;
	case 2: editarLista();
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

//EDITAR LISTA
void editarLista() {
	system("cls");
	cout << "Lista de Alumnos. " << endl;
	cout << endl;

	for (int i = 0; i < 20; i++) {
		if (a[i].oc == true) {
			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Telefono: " << a[i].tel << ". " << endl;
			cout << "    Direccion: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". "<< " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;
		}
		else {
			cout << i + 1 << " --- VACIO --- " << endl;
			cout << endl;
		}
	}

	cout << "Opciones de edicion de lista. " << endl;
	cout << "1. Registrar. \n2. Eliminar. \n3. Volver al menu." << endl;
	cin >> selec;

	switch (selec) {
	case 1: agregar();
		break;
	case 2: eliminar();
		break;
	case 3: main();
		break;
	default: cout << "Seleccione una opción valida. " << endl;
		system("pause");
		editarLista();
		break;
	}
}

//REGISTRO ALUMNO;
void agregar() {
	system("cls");
	cout << "Registro. " << endl;
	cout << "Escoja el numero donde desea registrar el alumno. (1 a 20)" << endl;
	cin >> i;
	if (i >= 1 && i <= 20) {
		i--;

		if (a[i].oc == false) {
			cout << "REGISTRE LOS SIGUIENTES DATOS. " << endl;
			cout << "Nombre: ";
			cin.ignore();
			getline(cin, a[i].nombre);
			cout << "Apellido Paterno: ";
			cin>>a[i].apellidoP;
			cout << "Apellido Materno: ";
			cin >> a[i].apellidoM;
			cout << "Matricula: ";
			cin >> a[i].matr;
			cout << "Correo Electronico: ";
			cin >> a[i].correoE;
			cout << "Telefono: ";
			cin >> a[i].tel;
			cout << "-Direccion-" << endl;
			cout << "Colonia: ";
			cin.ignore();
			getline(cin, a[i].col);
			cout << "Calle: " ;
			getline(cin, a[i].calle);
			cout << "Numero Residencia: ";
			cin >> a[i].num;
			a[i].oc = true;
			cout << "REGISTRO TERMINADO. " << endl;
			cout << endl;

			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Telefono: " << a[i].tel << ". " << endl;
			cout << "    Direccion: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;

			cout << "1. Registrar otro alumno. \n2. Volver a la lista. " << endl;
			cin >> selec;

			switch (selec) {
			case 1: agregar();
				break;
			case 2: editarLista();
				break;
			default: cout << "Seleccione una opción valida. " << endl;
				system("pause");
				editarLista();
				break;
			}

		}
		else {
			cout << "Este espacio esta ya ocupado, escoja otro.";
			system("pause");
			agregar();
		}
	}
	else {
		cout << "Numero de posicion invalida. Escoga un numero del 1 al 20." << endl;
		system("pause");
		agregar();
	}
}

//ELIMINAR ALUMNO
void eliminar() {
	system("cls");
	cout << "Eliminar Alumno. " << endl;

	for (int i = 0; i < 20; i++) {
		if (a[i].oc == true) {
			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Telefono: " << a[i].tel << ". " << endl;
			cout << "    Direccion: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;
		}
		else {
			cout << i + 1 << " --- VACIO --- " << endl;
			cout << endl;
		}
	}

	cout << "Seleccione el alumno que desea dar de baja (1 a 20). " << endl;
	cin >> i;
	if (i >= 1 && i <= 20) {
		i--;
		if (a[i].oc == true) {
			a[i].oc = false;
			cout << "ALUMNO DADO DE BAJA. " << endl;

			cout << "1. Eliminar otro alumno. \n2. Volver a la lista. " << endl;
			cin >> selec;

			switch (selec) {
			case 1: eliminar();
				break;
			case 2: editarLista();
				break;
			default: cout << "Seleccione una opción valida. " << endl;
				system("pause");
				editarLista();
				break;
			}
		}
		else {
			cout << "Este espacio ya esta vacio, escoja uno que contenga ya datos guardados. " << endl;
			system("pause");
			eliminar();
		}
	}
	else {
		cout << "Numero de posicion invalida. Escoga un numero del 1 al 20." << endl;
		system("pause");
		eliminar();
	}
}

//MANUAL DE USO
void manual() {
	system("cls");
	cout << "Manual de Uso. " << endl;
	cout << "Bienvenido al manual de uso. \n" << endl;
	cout << "AUN NO ESCRIBO EL MANUAL XD."<<endl;
	system("pause");
	main();
}