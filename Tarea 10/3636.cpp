#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;

int main() {
	locale::global(locale("spanish"));
	int x = 49;
	int contador = 0;

	
	srand(time(NULL));
	for (int i = 0; i<100; i++) {
		system("cls");
		int r = rand() % 2;
		if (r == 0) {
			x = x - 1;
		}
		else {
			x = x + 1;
		}

		if (x == 49) {
			contador = contador + 1;
		}

		if (x < 0) {
			x = 99;
		}
		if (x > 99) {
			x = 0;
		}

		cout << "|";
		for (int j = 0; j<100; j++) {
			if (j == x) {
				if (x == 49) {
					cout << "(A)";
				}
				else {
					cout << "A";
				}
			}
			else {
				if (j == 49) {
					cout << "(*)";
				}
				else {
					cout << "*";
				}
			}
		}
		cout << "|";
	}
	cout << endl << "Veces que pasó el inicio:  "<< contador << " ." << endl;
	system("pause");
	return 0;
}