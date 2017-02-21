#include "car.h"

#include <iostream>

Car::Car() //temp
{
	this->freeSeats = 0; //temp!!!
}

///Oppgave 1
Car::Car(int freeSeats)
{
	this->freeSeats = freeSeats;
}

bool Car::hasFreeSeats() const
{
	if (freeSeats>0) {
		return true;
	}
	else {
		return false;
	}

}

void Car::reserveFreeSeat()
{
	this->freeSeats--;
}


