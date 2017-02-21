#include <iostream>
#include "cannonball.h"
#include "utilities.h"
#include<cmath>
using namespace std;

double acclY(){
	return -9.81;
}

double velY(double initVelocityY, double time) {
	double aY = acclY();
	return (initVelocityY + aY*time);
}

double posY(double initPosition, double initVelocity, double time) {
	return (initPosition + initVelocity*time + (acclY()*std::pow(time, 2) / 2));
}

double posX(double initPosition, double initVelocity, double time) {
	return (initPosition + initVelocity*time);
}

void printTime(int time) {
	double seconds = time % 60; // rest, total seconds
	int minutes = time / 60; // # whole minutes with the given seconds
	int hours = minutes / 60; // whole hours given minutes, total hours
	double hourminutes = minutes % 60; // rest, total minutes
	std::cout << hours << " hours, " << hourminutes << " minutes and " << seconds << " seconds" << std::endl;
}

double  flightTime(double initVelocityY) {
	return (-2 * initVelocityY / acclY());
}


void getUserInput(double *theta, double *absVelocity) {
	cout << "Input angle (degrees): ";
	cin >> *theta; cout << endl;
	cout << "input absolute start velocity in m/s: ";
	cin >> *absVelocity; cout << endl;
}

double degToRad(double deg) {
	double pi = 3.141592;
	return deg*(pi / 180);
}

// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity

double getVelocityX(double theta, double absVelocity) {
	// theta i radianer
	return absVelocity*cos(theta);
}

double getVelocityY(double theta, double absVelocity) {
	return absVelocity*sin(theta);
}

// Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
// gitt vinkelen theta. Disse komponentene lagres i minnet.

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	return flightTime(velocityY)*velocityX;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	//cout << "Cannonball travels " << getDistanceTraveled(velocityX, velocityY) << " m" << endl;
	return (distanceToTarget - getDistanceTraveled(velocityX, velocityY));
}

// Oppgave 6

void playTargetPractice() {
	double theta; double absVelocity; double velocityX; double velocityY;
	int chances = 1; 
	int i = 0;
	int win = 0;

	while(chances == 1) {
		int distanceToTarget = randomWithLimits(100, 1000);
		cout << "distance to target: " << distanceToTarget << endl<< endl;
		getUserInput(&theta, &absVelocity);
		theta = degToRad(theta);
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);

		double temp = targetPractice(distanceToTarget, velocityX, velocityY);
		cout << "distance travelled: " << getDistanceTraveled(velocityX, velocityY) << endl;

		if (temp >= (- 5) && temp <= (5)) {
			cout << "Target hit" << endl << endl << endl;
			win = 1;
			chances = 0;
		}
		else if (temp < (- 5)) {
			cout << "Shot too long." << endl << endl << endl;
		}
		else if (temp > (5)) {
			cout << "Shot too short." << endl << endl << endl;
		}

		i++;
		if (i == 9) {
			chances = 0;
		}
	
	}

	if (win == 1) {
		cout << " Congratulations, you have won!" << endl;
	}
	else {
		cout << "You have lost!" << endl;
	}
	
}
