#include "cannonball.h"
#include "utilities.h"
#include<iostream>
#include <ctime>
using namespace std;

void main() {

	int task;
	int running = 1;

	while (running) {

		cout << "\nVelg en oppgave:" << endl;
		cout << "\t0) Avslutt" << endl;
		cout << "\t1) Oppgave 3a og b" << endl;
		cout << "\t2) Oppgave 4" << endl;
		cout << "\t3) Oppgave 5b og c" << endl;
		cout << "\t4) Oppgave 6" << endl;

		cout << "Angi valg: ";
		cin >> task;
		switch (task) {
		case 0:
			running = 0;
			break;

		case 1:
			// 3 a og b

		{cout << "acceleration in Y: " << acclY() << endl;
		double result = posX(0, 50.0, 5.0); /* initPosition, initVelocity, time */
		cout << "posX: " << result << endl;
		double expected = 250.0;
		cout << "posX expected: " << expected << endl;
		/* sjekk om resultatet er nøyaktig nok */
		double result2 = posY(0, 25, 5.0); /* initPosition, initVelocity, time */
		cout << "posY: " << result2 << endl;

		double expected2 = 2.375;
		cout << "posY expected: " << expected2 << endl;
		/* sjekk om resultatet er nøyaktig nok */

		cout << "Velocity in Y: " << velY(25, 5) << endl;
		cout << "expected: -24.05" << endl << endl;


		cout << "flighttime 5 sec test: ";
		printTime(5); cout << endl << endl;

		cout << "test flighttime: " << flightTime(25) << endl << "expected value: 5.09684" << endl; }
		break;

		case 2:

			// 4
		{double theta; double absVelocity; double velocityX; double velocityY;
		getUserInput(&theta, &absVelocity);

		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);

		double distanceToTarget = 100; // blink 100 m unna

		cout << "Kanonkulen lander " << targetPractice(distanceToTarget, velocityX, velocityY) << "m unna blinken" << endl; }
		break;
		case 3:
			//5 b & c

		{std::srand(std::time(nullptr)); // 5c

		for (int i = 0; i < 10; i++) {
			cout << randomWithLimits(0, 100) << endl;
		}
		}

		break;
		case 4:
			playTargetPractice();
			break;

		default:
			cout << "Feil input" << endl;
			break;
		}
	}
}