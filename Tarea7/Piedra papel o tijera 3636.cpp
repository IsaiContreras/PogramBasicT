#include <iostream>
#include <time.h>
using namespace std;

void elegirModo();
void juegoConCPU();
void juegoConAmigo();

void main() {
	locale::global(locale("spanish"));
	cout << "Bienvenido a Piedra Papel Tijera."<< endl;

	system("pause");
	elegirModo();

	cout << "Gracias por jugar. Vuelve pronto :)" << endl;
	system("pause");
}

void elegirModo() {
	system("cls");
	int modo;
	cout << "Elija un modo de juego. " << endl;
	cout << "0. Contra un Amigo. \n1. Contra la Máquina. \n2. Salir del juego." << endl;
	cin >> modo;
	
	if (modo == 0) {
		juegoConAmigo();
	}
	else if (modo == 1) {
		juegoConCPU();
	}
}

void juegoConCPU() {
	system("cls");
	int player, CpU, restart;

	cout << "Elija la acción que desea jugar. " << endl;
	cout << "1.Piedra. \n2.Papel. \n3.Tijera." << endl;
	cin >> player;

	switch (player) {
	case 1: cout << "Eligiste Piedra. " << endl;
		break;
	case 2: cout << "Elegiste Papel. " << endl;
		break;
	case 3: cout << "Elegiste Tijeras. " << endl;
		break;
	}

	srand(time(NULL));
	CpU = rand() % 3 + 1;

	switch (CpU) {
	case 1: cout << "Rival eligió Piedra. " << endl;
		break;
	case 2: cout << "Rival eligió Papel. " << endl;
		break;
	case 3: cout << "Rival eligió Tijeras. " << endl;
		break;
	}

	if (CpU == player) {
		cout << "¡EMPATE!" << endl;
	}
	else {
	  if (CpU == 1 && player == 3) {
		cout << "Perdiste. :( " << endl;
	  }
	  else if (CpU == 2 && player == 1) {
		      cout << "Perdiste. :( " << endl;
	       }
	  else if (CpU == 3 && player == 2) {
		     cout << "Perdiste. :( " << endl;
	  }
	  else {
		cout << "¡GANASTE!. Felicidades :)" << endl;
	  }
    }

	cout << "¿Quieres volver a jugar?" << endl;
	cout << "1. Si. \n0. Volver a Elegir modo." << endl;
	cin >> restart;

	if (restart == 1) {
		juegoConCPU();
	}
	if (restart == 0) {
		elegirModo();
	}
}

void juegoConAmigo() {
	system("cls");
	int player1, player2, restart;
	cout<<"¡ESTO SE JUEGA SIN VER LA ACCIÓN DE TU RIVAL! XD Sin trampas. \n"<<endl;

	cout << "Elija la acción que desea jugar, Jugador 1. NO VEAS JUGADOR 2. " << endl;
	cout << "1.Piedra. \n2.Papel. \n3.Tijera." << endl;
	cin >> player1;
	system("cls");

	cout << "Elija la acción que desea jugar, Jugador 2. " << endl;
	cout << "1.Piedra. \n2.Papel. \n3.Tijera." << endl;
	cin >> player2;

	switch (player1) {
	case 1: cout << "Jugador 1 eligió Piedra. " << endl;
		break;
	case 2: cout << "Jugador 1 eligió Papel. " << endl;
		break;
	case 3: cout << "Jugador 1 eligió Tijeras. " << endl;
		break;
	}

	switch (player2) {
	case 1: cout << "Jugador 2 eligió Piedra. " << endl;
		break;
	case 2: cout << "Jugador 2 eligió Papel. " << endl;
		break;
	case 3: cout << "Jugador 2 eligió Tijeras. " << endl;
		break;
	}

	if (player2 == player1) {
		cout << "¡EMPATE!" << endl;
	}
	else {
		if (player2 == 1 && player1 == 3) {
			cout << "¡GANA JUGADOR 2!" << endl;
		}
		else if (player2 == 2 && player1 == 1) {
			cout << "¡GANA JUGADOR 2!" << endl;
		}
		else if (player2 == 3 && player1 == 2) {
			cout << "¡GANA JUGADOR 2! " << endl;
		}
		else {
			cout << "¡GANA JUGADOR 1!" << endl;
		}
	}

	cout << "¿Quieres volver a jugar?" << endl;
	cout << "1. Si. \n0. Volver a Elegir modo." << endl;
	cin >> restart;

	if (restart == 1) {
		juegoConAmigo();
	}
	if (restart == 0) {
		elegirModo();
	}
}