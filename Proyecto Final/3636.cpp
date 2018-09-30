#include <iostream>
#include <string>
#include <conio.h>
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
	float cal[3];
	float PF;
};

//Variables globales
char selec;
alumno a[20];
int i;

//Funciones
void manual();
void editarLista();
void agregar();
void eliminar();
void agregarCalif();
void buscarYMostrar();
void buscarYModificar();
void buscarYEliminar();

//MENU PRINCIPAL
int main() {
	locale::global(locale("spanish"));
	system("cls");
	cout << "----Men� Principal---- " << endl;
	cout << endl;
	cout << "Introduzca el n�mero de la opci�n que desea seleccionar. " << endl;
	cout << "1. Manual de Uso. \n2. Lista de alumnos. \n3. Salir.  " << endl;
	cin >> selec;

	switch (selec) {
	case '1': manual();
		break;
	case '2': editarLista();
		break;
	case '3': cout << "Estas saliendo del programa. " << endl;
		system("pause");
		break;
	default: cout << "Seleccione una opci�n valida. " << endl;
		system("pause");
		main();
		break;
	}
}

//EDITAR LISTA
void editarLista() {
	system("cls");
	cout << "----Lista de Alumnos---- " << endl;
	cout << endl;

	for (int i = 0; i < 20; i++) {
		if (a[i].oc == true) {
			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". "<< " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;
		}
		else {
			cout << i + 1 << " --- VAC�O --- " << endl;
			cout << endl;
		}
	}

	cout << "Opciones de edici�n de lista. " << endl;
	cout << "1. Registrar. \n2. Eliminar. \n3. A�adir una calificaci�n. \n4. Buscar y Mostrar.";
	cout << "\n5. Buscar y Modificar. \n6. Buscar y Eliminar. \n7. Salir al menu.";
	cin >> selec;

	switch (selec) {
	case '1': agregar();
		break;
	case '2': eliminar();
		break;
	case '3': agregarCalif();
		break;
	case '4': buscarYMostrar();
		break;
	case '5': buscarYModificar();
		break;
	case'6':buscarYEliminar();
		break;
	case '7': main();
		break;
	default: cout << "Seleccione una opci�n valida. " << endl;
		system("pause");
		editarLista();
		break;
	}
}

//REGISTRO ALUMNO;
void agregar() {
	system("cls");
	cout << "----Registro---- " << endl;
	cout << endl;
	cout << "Escoja el n�mero donde desea registrar el alumno. (1 a 20)" << endl;
	cout << "Ingrese cero para salir a la lista. " << endl;
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
			cout << "Tel�fono: ";
			cin >> a[i].tel;
			cout << "-Direcci�n-" << endl;
			cout << "Colonia: ";
			cin.ignore();
			getline(cin, a[i].col);
			cout << "Calle: " ;
			getline(cin, a[i].calle);
			cout << "N�mero Residencia: ";
			cin >> a[i].num;
			a[i].oc = true;
			cout << "REGISTRO TERMINADO. " << endl;
			cout << endl;

			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;

			cout << "1. Registrar otro alumno. \n2. Volver a la lista. " << endl;
			cin >> selec;

			switch (selec) {
			case '1': agregar();
				break;
			case '2': editarLista();
				break;
			default: cout << "Seleccione una opci�n valida. " << endl;
				system("pause");
				editarLista();
				break;
			}

		}
		else {
			cout << "Este espacio est� ya ocupado, escoja otro.";
			system("pause");
			agregar();
		}
	}
	else if (i == 0) {
		editarLista();
	}
	else {
		cout << "N�mero de posicion invalida. Escoja un n�mero del 1 al 20." << endl;
		system("pause");
		agregar();
	}
}

//ELIMINAR ALUMNO
void eliminar() {
	system("cls");
	cout << "----Eliminar Alumno----" << endl;
	cout << endl;

	for (int i = 0; i < 20; i++) {
		if (a[i].oc == true) {
			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;
		}
		else {
			cout << i + 1 << " --- VAC�O --- " << endl;
			cout << endl;
		}
	}

	cout << "Seleccione el alumno que desea dar de baja (1 a 20). " << endl;
	cout << "Ingrese cero para salir a la lista. " << endl;
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
			default: cout << "Seleccione una opci�n valida. " << endl;
				system("pause");
				editarLista();
				break;
			}
		}
		else {
			cout << "Este espacio ya esta vac�o, escoja uno que contenga ya datos guardados. " << endl;
			system("pause");
			eliminar();
		}
	}
	else if (i == 0) {
		editarLista();
	}
	else{
		cout << "N�mero de posici�n inv�lida. Escoga un n�mero del 1 al 20." << endl;
		system("pause");
		eliminar();
	}
	
}

void agregarCalif(){
	system("cls");
	cout << "----Agregar Calificaci�n----" << endl;
	cout << endl;

	int nCal;
	float cal;
	int rep = 1;

	while (rep == 1) {
		cout << "Introduzca el n�mero de alumno para agregar calificaci�n (1 a 20). " << endl;
		cin >> i;

		if (i >= 1 && i <= 20) {
			i--;

			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correoE << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones.-  C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;

			cout << "Seleccione qu� calificaci�n registrar� (1, 2 o 3)." << endl;
			cin >> nCal;
			if (nCal >= 1 && nCal <= 3) {
				nCal--;
				cout << "Registre calificaci�n (entre 0 y 100). " << endl;
				cin >> cal;
				if (cal >= 0 && cal <= 100) {
					a[i].cal[nCal] = cal;
				}
				else {
					cout << "Introduzca una opcion valida. " << endl;
					system("pause");
				}
			}
			else {
				cout << "Introduzca una opcion valida. " << endl;
				system("pause");
			}
			cout << "�Desea registrar otra calificacion?";
			cin >> rep;
		}
		else {
			cout << "Introduza una opcion valida. " << endl;
			system("pause");
		}
	}
}

void  buscarYMostrar() {
	
	string matLook;
	bool encontrado = false;
	int rep = 1;

	while (rep == 1) {
		system("cls");
		cout << "----Buscar y Mostrar----" << endl;
		cout << endl;

		cout << "Introduzca la matricula del alumno que quiere buscar." << endl;
		cin >> matLook;

		for (int i = 0; i < 20; i++) {
			if (matLook == a[i].matr) {
				cout << "Encontrado." << endl;
				cout << endl;

				cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
				cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
				cout << "    Correo Electronico: " << a[i].correoE << ". Tel�fono: " << a[i].tel << ". " << endl;
				cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
				cout << "    Calificaciones.-  C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
				cout << endl;

				encontrado = true;

				break;
			}
		}

		if (!encontrado) {
			cout << "Registro no encontrado." << endl;
		}

		cout << "Desea buscar otro registro (1. Si  -- 0.No)." << endl;
		cin >> rep;
		if (rep <= 0) {
			rep = 0;
		}
		else {
			rep = 1;
		}
	}

	system("pause");
	editarLista();
}

void buscarYModificar() {

}

void buscarYEliminar() {

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