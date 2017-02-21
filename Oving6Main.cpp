#include "car.h"
#include "person.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main() {

	int task;
	int running = 1;

	while (running) {

		cout << "\nVelg en oppgave:" << endl;
		cout << "\t0) Avslutt" << endl;
		cout << "\t1) Test av Person, 2f" << endl;
		cout << "\t2) Oppgave 4" << endl;
		cout << "\t3) " << endl;
		cout << "\t4) " << endl;

		cout << "Angi valg: ";
		cin >> task;

		switch (task) {

		case 0:
			running = 0;
			break;

		case 1: {
			Car arnesBil(2); Car henkesBil(1); Car arneBil2(2);

			Person arne("arne aalberg", "arneaalberg@gmail.com", &arnesBil);
			Person jennifer("jennifer jensen", "jen@gmail.com");
			Person henke("henke larsson", "henke@hotmail.com", &henkesBil);
			Person arne2("arne malboro", "sigarkongen@msn.no", &arneBil2);

			vector <Person> personer = { arne, jennifer, henke, arne2 };

			cout << "Personer med bil: " << endl;

			for (int i = 0; i < personer.size(); i++) {

				if (personer[i].hasCar()) {
					cout << personer[i].getName() << " har bil." << endl;
				}
			}

			cout << " arne, henke, arne2" << endl;
			break;
		}
		case 2:
			break;
		case 3:
			break;

		default:
			cout << "Feil input" << endl;
			break;
		}
	}
}