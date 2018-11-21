#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

//ESTRUCTURA DE DATOS DE ALUMNO
struct alumno {
	bool oc = false;
string nombre;
string apellidoP;
string apellidoM;
string correo;
string tel;
string matr;
string num;
string calle;
string col;
float cal[3] = {0, 0, 0};
float PF = 0;

};

//VARIABLES GLOBALES
char selec;
alumno a[20];
int i;
string iC;

//FUNCIONES EN MENU
void salida();
void manual();
void editarLista(); //
void agregar(); //
void eliminar(); //  
void agregarCalif(); //
void buscarYMostrar(); //
void buscarYModificar();
void buscarYEliminar(); //

//OTROS PROCESOS
void escritura();
void lectura();
bool validadorSelec(char s);
float calculaPromedio(float P1, float P2, float P3);

//Escritura de Datos
void escritura() {
	ofstream fichero;
	fichero.open("datos.txt");
	for (int i = 0; i < 20; i++) {
		fichero << a[i].nombre << endl;
		fichero << a[i].apellidoP << endl;
		fichero << a[i].apellidoM << endl;
		fichero << a[i].matr << endl;
		fichero << a[i].correo << endl;
		fichero << a[i].tel << endl;
		fichero << a[i].col << endl;
		fichero << a[i].calle << endl;
		fichero << a[i].num << endl;
		fichero << a[i].oc << endl;
		fichero << a[i].cal[0] << endl;
		fichero << a[i].cal[1] << endl;
		fichero << a[i].cal[2] << endl;
		fichero << a[i].PF;
	}
	fichero.close();

	editarLista();
}

void lectura() {
	ifstream fichero("datos.txt");
	for (int i = 0; i < 20; i++) {
		getline(fichero, a[i].nombre);
		getline(fichero, a[i].apellidoP);
		getline(fichero, a[i].apellidoM);
		getline(fichero, a[i].matr);
		getline(fichero, a[i].correo);
		getline(fichero, a[i].tel);
		getline(fichero, a[i].col);
		getline(fichero, a[i].calle);
		getline(fichero, a[i].num);
		fichero >> a[i].oc;
		fichero >> a[i].cal[0];
		fichero >> a[i].cal[1];
		fichero >> a[i].cal[2];
		fichero >> a[i].PF;
	}
	fichero.close();
}

//Validador para Selec
bool validadorSelec(char s) {
	bool r;
	if (s >= 48 && s <= 57) {
		r = true;
	}
	else {
		r = false;
	}
	return r;
}


bool validadorTelefono(string n) {
	bool r = false;
	int size = n.size();

	if (size < 12) {
		r = true;
	}
	else {
		cout << "Numero telefonico invalido. Vuelva a introducirlo" << endl;
		system("pause");
	}

	return r;
}

bool validadorCorreo(string c) {
	bool r = false;
	int valArroC = 0;
	int valPuntC = 0;
	int size = c.size();

	for (int i = 0; i < size; i++) {
		if (c[i] == '@') {
			valArroC++;
		}
		if (c[i] == '.') {
			valPuntC++;
		}
	}

	if (c[size - 1] != 'm' &&  c[size - 2] != 'o' && c[size - 3] != 'c'  && c[size - 4] != '.'){
		cout << "Correo Electronico invalido. Coloque .com al final." << endl;
		system("pause");
    }
	else if (valArroC == 0) {
		cout << "Correo Electronico invalido. Su correo debe contener un arroba." << endl;
		system("pause");
	}
	else if (valArroC > 1) {
		cout << "Correo Electronico invalido. Solo puede ingresar un arroba." << endl;
		system("pause");
	}
	else {
		r = true;
	}

	return r;
}

//Calcula promedio final
float calculaPromedio(float P1, float P2, float P3) {
	float sumaTotal;
	P1 = P1 * .30;
	P2 = P2 * .45;
	P3 = P3 * .25;
	sumaTotal = P1 + P2 + P3;
	return sumaTotal;
}

//CUERPO DEL PROGRAMA

//MENU PRINCIPAL
int main() {
	locale::global(locale("spanish"));

	lectura();

	system("cls");
	cout << "----Men� Principal---- " << endl;
	cout << endl;
	cout << "Introduzca el n�mero de la opci�n que desea seleccionar. " << endl;
	cout << "1. Manual de Uso. \n2. Lista de alumnos. \n3. Salir.  " << endl;

	selec = _getch();
	while (!validadorSelec(selec)) {
		selec = _getch();
	}
	

	switch (selec) {
	case '1': manual();
		break;
	case '2': editarLista();
		break;
	case '3': cout << "Estas saliendo del programa. " << endl;
		salida();
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
			    cout << i + 1 << ".-   Matricula: " << a[i].matr << ". " << endl;
			    cout << "      Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			    cout << "      Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
			    cout << "      Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			    cout << "      Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			    a[i].PF = calculaPromedio(a[i].cal[0], a[i].cal[1], a[i].cal[2]);
			    cout << "      Promedio Final: " << a[i].PF << " ." << endl;
			    cout << endl;
		    }
			else {
				cout << i + 1 << " --- VAC�O --- " << endl;
				cout << endl;
			}
	}

	cout << "Opciones de edici�n de lista. " << endl;
	cout << "1. Registrar. \n2. Eliminar. \n3. A�adir una calificaci�n. \n4. Buscar y Mostrar.";
	cout << "\n5. Buscar y Modificar. \n6. Buscar y Eliminar. \n7. Guardar cambios. \n8. Salir al Menu.\n";
	
	selec = _getch();
	while (!validadorSelec(selec)) {
		selec = _getch();
	}

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
	case '7': escritura();
		break;
	case '8': main();
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
	cout << "Ingrese cero o cualquier caracter para salir a la lista. " << endl;
	getline(cin, iC);
	i = atoi(iC.c_str());

	if (i >= 1 && i <= 20) {
		i--;

		if (a[i].oc == false) {
			cout << "REGISTRE LOS SIGUIENTES DATOS. " << endl;
			cout << "Nombre: ";
			getline(cin, a[i].nombre);
			cout << "Apellido Paterno: ";
			getline(cin, a[i].apellidoP);
			cout << "Apellido Materno: ";
			getline(cin, a[i].apellidoM);

			cout << "Matricula: ";
			getline(cin, a[i].matr);

			cout << "Correo Electronico: ";
			getline(cin, a[i].correo);
			while (!validadorCorreo(a[i].correo)) {
				getline(cin, a[i].correo);
			}

			cout << "Tel�fono: ";
			getline(cin, a[i].tel);
			while (!validadorTelefono(a[i].tel)) {
				getline(cin, a[i].tel);
			}

			cout << "-Direcci�n-" << endl;
			cout << "Colonia: ";
			getline(cin, a[i].col);
			cout << "Calle: " ;
			getline(cin, a[i].calle);
			cout << "N�mero Residencia: ";
			getline(cin, a[i].num);

			a[i].oc = true;

			cout << "REGISTRO TERMINADO. " << endl;
			cout << endl;

			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;

			cout << "1. Registrar otro alumno. \n2. Volver a la lista. " << endl;
			
			selec = _getch();
			while (!validadorSelec(selec)) {
				selec = _getch();
			}

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
				cout << i + 1 << ".-   Matricula: " << a[i].matr << ". " << endl;
				cout << "      Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
				cout << "      Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
				cout << "      Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
				cout << "      Calificaciones: C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
				a[i].PF = calculaPromedio(a[i].cal[0], a[i].cal[1], a[i].cal[2]);
				cout << "      Promedio Final: " << a[i].PF << " ." << endl;
				cout << endl;
			}
			else {
				cout << i + 1 << " --- VAC�O --- " << endl;
				cout << endl;
			}
	}

	cout << "Seleccione el alumno que desea dar de baja (1 a 20). " << endl;
	cout << "Ingrese cero o cualquier caracter para salir a la lista. " << endl;
	getline(cin, iC);
	i = atoi(iC.c_str());

	if (i >= 1 && i <= 20) {
		i--;
		if (a[i].oc == true) {
			a[i].oc = false;
			cout << "ALUMNO DADO DE BAJA. " << endl;

			cout << "1. Eliminar otro alumno. \n2. Volver a la lista. " << endl;
			
			selec = _getch();
			while (!validadorSelec(selec)) {
				selec = _getch();
			}

			switch (selec) {
			case '1': eliminar();
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

//REGISTRA CALIFICACION
void agregarCalif(){
	int nCal;
	float cal;
	char rep = '1';
	string nCalS;
	string repC;
	string calS;


	system("cls");
	cout << "----Agregar Calificaci�n----" << endl;
	cout << endl;

	cout << "Introduzca el n�mero de alumno para agregar calificaci�n (1 a 20). " << endl;
	getline(cin, iC);
	i = atoi(iC.c_str());

	if (i >= 1 && i <= 20) {
		i--;
		if (a[i].oc == true) {
			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones.-  C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;

			while (rep == '1') {
				cout << "Seleccione qu� calificaci�n registrar� (1, 2 o 3)." << endl;
				getline(cin, nCalS);
				nCal = atoi(nCalS.c_str());

				if (nCal >= 1 && nCal <= 3) {
					nCal--;
					cout << "Registre calificaci�n. (entre 0 y 100). Separe las decimales con , " << endl;
					getline(cin, calS);
					cal = atof(calS.c_str());

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
				cout << "�Desea registrar otra calificacion para este alumno? " << endl;
				cout << "1. Si. 0. No. \n";

				selec = _getch();
				while (!validadorSelec(selec)) {
					selec = _getch();
				}

				switch (selec) {
				case '1': rep = '1';
					break;
				default: rep = '0';
					break;
				}
			}
			cout << "�Desea registrar otra calificacion para otro registro? " << endl;
			cout << "1. Si. 0. No. \n";
			selec = _getch();
			while (!validadorSelec(selec)) {
				selec = _getch();
			}
			
			switch (selec) {
			case '1': agregarCalif();
				break;
			default: editarLista();
				break;
			}
		}
		else {
			cout << "No hay alumno ocupando este espacio." << endl;

			system("pause");
			editarLista();
		}
	}
	else {
	    cout << "Introduza una opcion valida. " << endl;
		system("pause");
		agregarCalif();
	}
}

//BUSCAR MOSTRAR
void  buscarYMostrar() {
	string matLook;
	bool encontrado = false;

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
				cout << "    Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
				cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
				cout << "    Calificaciones.-  C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
				cout << endl;

				encontrado = true;

				break;
			}
		}

		if (!encontrado) {
			cout << "Registro no encontrado." << endl;
			cout << "�Desea intentar de nuevo? (1. Si -- 0. No)" ;

			selec = _getch();
			while (!validadorSelec(selec)) {
				selec = _getch();
			}

			switch (selec) {
			case '1': buscarYMostrar();
				break;
			default: editarLista();
				break;
			}
		}
		else {
			cout << "Desea buscar otro registro (1. Si  -- 0.No)." << endl;
			selec = _getch();
			while (!validadorSelec(selec)) {
				selec = _getch();
			}

			switch (selec) {
			case '1': buscarYMostrar();
				break;
			default: editarLista();
				break;
			}
		}
}

//BUSCAR MODIFICAR
void buscarYModificar() {
	string matLook;
	bool encontrado = false;
	char rep = '1';

	system("cls");
	cout << "----Buscar y Modificar----" << endl;
	cout << endl;

	cout << "Introduzca la matricula del alumno que quiere modificar." << endl;
	cin >> matLook;

	for (int i = 0; i < 20; i++) {
		if (matLook == a[i].matr) {
			while (rep == '1') {
				system("cls");
				cout << "----Buscar y Modificar----" << endl;
				cout << "Encontrado.\n" << endl;

				cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
				cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
				cout << "    Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
				cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
				cout << "    Calificaciones.-  C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
				cout << endl;

				cout << "Vuelva a ingresar los datos del alumno: " << endl;

				cout << "Nombre: ";
				cin.ignore();
				getline(cin, a[i].nombre);
				cout << "Apellido Paterno: ";
				getline(cin, a[i].apellidoP);
				cout << "Apellido Materno: ";
				getline(cin, a[i].apellidoM);

				cout << "Matricula: ";
				getline(cin, a[i].matr);

				cout << "Correo Electronico: ";
				getline(cin, a[i].correo);
				while (!validadorCorreo(a[i].correo)) {
					getline(cin, a[i].correo);
				}

				cout << "Tel�fono: ";
				getline(cin, a[i].tel);
				while (!validadorTelefono(a[i].tel)) {
					getline(cin, a[i].tel);
				}

				cout << "-Direcci�n-" << endl;
				cout << "Colonia: ";
				getline(cin, a[i].col);
				cout << "Calle: ";
				getline(cin, a[i].calle);
				cout << "N�mero Residencia: ";
				getline(cin, a[i].num);

				cout << "Modificacion completa." << endl;
				cout << "Desea repetir el proceso  (1.Si - 0.No)" << endl;
				
				selec = _getch();
				while (!validadorSelec(selec)) {
					selec = _getch();
				}

				switch (selec) {
				case '0': rep = '0';
					break;
				default: break;
				}
			}

			encontrado = true;
			break;
		}
	}


	if (!encontrado) {
		cout << "Registro no encontrado." << endl;
		cout << "�Desea intentar de nuevo? (1. Si -- 0. No)";

		selec = _getch();
		while (!validadorSelec(selec)) {
			selec = _getch();
		}

		switch (selec) {
		case '1': buscarYModificar();
			break;
		default: editarLista();
			break;
		}
	}
	else {
		cout << "Desea buscar otro registro (1. Si  -- 0.No)." << endl;
		selec = _getch();
		while (!validadorSelec(selec)) {
			selec = _getch();
		}

		switch (selec) {
		case '1': buscarYModificar();
			break;
		default: editarLista();
			break;
		}
	}
}

//BUSCAR ELIMINAR
void buscarYEliminar() {
	string matLook;
	bool encontrado = false;

	system("cls");
	cout << "----Buscar y Eliminar----" << endl;
	cout << endl;

	cout << "Introduzca la matricula del alumno que quiere eliminar." << endl;
	cin >> matLook;

	for (int i = 0; i < 20; i++) {
		if (matLook == a[i].matr) {
			cout << "Encontrado." << endl;
			cout << endl;

			cout << i + 1 << ".- Matricula: " << a[i].matr << ". " << endl;
			cout << "    Apellido y Nombre: " << a[i].apellidoP << " " << a[i].apellidoM << " " << a[i].nombre << ". " << endl;
			cout << "    Correo Electronico: " << a[i].correo << ". Tel�fono: " << a[i].tel << ". " << endl;
			cout << "    Direcci�n: " << a[i].calle << " " << a[i].num << ", " << a[i].col << endl;
			cout << "    Calificaciones.-  C1: " << a[i].cal[0] << ". " << " C2: " << a[i].cal[1] << ". " << " C3: " << a[i].cal[2] << ". " << endl;
			cout << endl;

			cout << "�Seguro que desea elimiarlo? (1. Si -- 0. No) " << endl;
			selec = _getch();
			while (!validadorSelec(selec)) {
				selec = _getch();
			}

			switch (selec) {
			case '1': a[i].oc = false;
				break;
			default: cout << "�Desea buscar otro registro para eliminar? (1. Si -- 0.No)" << endl;
				selec = _getch();
				while (!validadorSelec(selec)) {
					selec = _getch();
				}

				switch (selec) {
				case '1': buscarYEliminar();
					break;
				default: editarLista();
					break;
				}
				break;
			}

			encontrado = true;
            break;
		}
	}

	if (!encontrado) {
		cout << "Registro no encontrado." << endl;
		cout << "�Desea intentar de nuevo? (1. Si -- 0. No)";

		selec = _getch();
		while (!validadorSelec(selec)) {
			selec = _getch();
		}

		switch (selec) {
		case '1': buscarYEliminar();
			break;
		default: editarLista();
			break;
		}
	}
	else {
		cout << "Desea buscar otro registro (1. Si  -- 0.No)." << endl;
		selec = _getch();
		while (!validadorSelec(selec)) {
			selec = _getch();
		}

		switch (selec) {
		case '1': buscarYEliminar();
			break;
		default: editarLista();
			break;
		}
	}
}

void salida() {
	ofstream fichero;
	fichero.open("datos.txt");
	for (int i = 0; i < 20; i++) {
		fichero << a[i].nombre << endl;
		fichero << a[i].apellidoP << endl;
		fichero << a[i].apellidoM << endl;
		fichero << a[i].matr << endl;
		fichero << a[i].correo << endl;
		fichero << a[i].tel << endl;
		fichero << a[i].col << endl;
		fichero << a[i].calle << endl;
		fichero << a[i].num << endl;
		fichero << a[i].oc << endl;
		fichero << a[i].cal[0] << endl;
		fichero << a[i].cal[1] << endl;
		fichero << a[i].cal[2] << endl;
		fichero << a[i].PF;
	}
	fichero.close();
}


//MANUAL DE USO
void manual() {
	system("cls");
	cout << "MANUAL DE USO. " << endl;
	cout << "Bienvenido al manual de usuario. Antes de usar el programa, lea atentamente\neste manual de uso y siga cada instrucci�n para manejar datos.\nEste programa le facilitar� el registro y la administraci�n de sus alumnos.\n" << endl;
	cout << "Navegaci�n.\n";
	cout << "Para navegar a trav�s del men�, se desplegar� en pantalla una lista de opciones,\npara seleccionar solo presiona la tecla del n�mero indicado para cada opci�n.\n" << endl;
	cout << "Lista de alumnos.\n";
	cout << "Para ingresar a la lista de alumnos, al iniciar el programa presione la tecla 2.\nAl ingresar, se mostrar� la lista de alumnos:\nLa lista tiene capacidad para almacenar 20 espacios de alumnos.\nSi existe un espacio ocupado, los datos del alumno se mostrar�n en el\nsiguiente formato:" << endl;
	cout << "-# Espacio-   -MATR�CULA\n";
	cout << "              -APELLIDO Y NOMBRE\n";
	cout << "              -CORREO ELECTR�NICO -TEL�FONO\n";
	cout << "              -DIRECCI�N\n";
	cout << "              -CALIFICACIONES\n";
	cout << "              -PROMEDIO FINAL\n";
	cout << "Si existe un espacio desocupado o vac�o, solo se mostrar� el n�mero de espacio\njunto a la palabra --VAC�O--.\n";
	cout << "Debajo de la lista de alumnos, se desplegar� las opciones de edici�n de lista.\nPara seleccionar una opci�n, presione la tecla del n�mero indicado para cada opci�n.\n" << endl;
	cout << "Registro alumno\n" << endl;
	cout << "Para registrar un alumno, selecciona la opci�n Registrar en la lista de alumno.\nUna vez dentro, ingrese el n�mero de espacio donde desea registrar al alumno e ingrese\nlos siguientes datos:\n";
	cout << "-Nombre : Si posee m�s de un nombre, ingrese los dos en orden habitual y separados por un espacio.\n-Apellido Paterno.\n-Apellido Materno.\n-Matr�cula.\n-Correo Electr�nico: Este debe cumplir con ciertos car�cteres para ser validado.\n     Debe contener un arroba, y terminar con .com\n-Tel�fono: No debe pasar de los 12 caracteres.\n-Direcci�n:\n        -Colonia\n	-Calle\n	-N�mero.\n" << endl;
	cout << "Eliminar alumno\n";
	cout << "Pare eliminar un alumno del registro, ingrese a la opci�n Eliminar alumno debajo de la lista\nde alumnos. Se desplegar� la lista de alumnos para que pueda observar el n�mero de espacio\nde cada alumno. Para eliminar del registro, ingrese el n�mero de espacio del alumno que\ndesea eliminar.\n" << endl;
	cout << "Agregar calificacion\n";
	cout << "El programa tiene espacio para guardar 3 calificaciones para cada uno de los alumnos registrados.\nPara agregar una calificacion, ingrese a la opci�n Agregar calificaci�n debajo de la lista de\nalumnos. A continuaci�n ingrese el n�mero de espacio del alumno. Especifique el espacio\nde calificac�n ingresando un n�mero del 1 al 3 e ingrese la calificaci�n. Recuerda que solo se admiten\nvalores de 0 a 100 para las calificaciones.\nSe le preguntar� si desea agregar otra calificaci�n para el mismo alumno, si as� lo desea presione 1.\nRepita el proceso.\nSe le preguntar� si desea agregar calificaci�n para otro alumno, si as� lo desea presione 1.\nRepita el proceso.\n" << endl;
	cout << "Buscar y Mostrar\n";
	cout << "Esta funci�n permine buscar un registro en base a la matr�cula del alumno y mostrarlo en pantalla.\nPara acceder a esta funci�n, ingrese a la opci�n Buscar y Mostrar debajo de la lista de alumnos.\nPara buscar un registro, ingrese la matr�cula del alumno que quiere buscar.\nSi el registro existe, se mostrara su informaci�n en pantalla.\n" << endl;
	cout << "Buscar y Modificar\n";
	cout << "Esta funci�n permine buscar un registro en base a la matr�cula del alumno y modificar los datos de este.\nPara acceder a esta funci�n, ingrese a la opci�n Buscar y Modificar debajo de la lista de alumnos.\nPara buscar un registro, ingrese la matr�cula del alumno que quiere buscar.\nSi el registro existe, se mostrar� su informaci�n actual en pantalla y le permitir� ingresar de nuevo\nlos datos del alumno. Modifique el campo que desea.\n" << endl;
	cout << "Buscar y Eliminar\n";
	cout << "Esta funci�n permine buscar un registro en base a la matr�cula del alumno y eliminarlo.\nPara acceder a esta funci�n, ingrese a la opci�n Buscar y Eliminar debajo de la lista de alumnos.\nPara buscar un registro, ingrese la matr�cula del alumno que quiere buscar.\nSi el registro existe, se mostrara su informaci�n en pantalla y se le preguntar� si desea eliminar\nese registro. Si est� seguro de eliminarlo presione 1.\n" << endl;
	cout << "Guardar cambios\n";
	cout << "Si desea guardar los cambios ya hechos, ingrese a la opci�n Guardar cambios debajo de la lista de alumnos.\nSe guardar�n los datos en el disco.\n" << endl;
	cout << "Salir del programa\n";
	cout << "Para salir del programa solo seleccione la opci�n Salir en el men� principal.\nAl salir, se ejecutara la funci�n de guardar cambios para asegurar sus cambios.\n" << endl;
	cout << "..." << endl;
	system("pause");
	main();
}