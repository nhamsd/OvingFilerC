#pragma once

class Car {
private:
	int freeSeats;

public:
	Car();
	Car(int freeSeats);
	bool hasFreeSeats() const;
	void reserveFreeSeat();
};