#pragma once
#include <iostream>
#include <string>
#include "car.h"

using namespace std;

class Person {
private:
	string name;
	string email;
	Car* car;
public:
	Person(string name, string email);
	Person(string name, string email, Car* car);
	string getName() const;
	string getEmail() const;
	Car getCar() const;
	void setEmail(string email);
	bool hasAvailableSeats() const;	bool hasCar();

};

std::ostream& operator<<(std::ostream& os, const Person& p);

bool operator < (const Person &a, const Person &b);bool operator == (const Person &a, const Person &b);