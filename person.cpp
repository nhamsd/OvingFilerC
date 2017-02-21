#include "person.h"


Person::Person(string name, string email)
{
	this->name = name;
	this->email = email;
	this->car = nullptr;
}

Person::Person(string name, string email, Car* car)
{
	this->name = name;
	this->email = email;
	this->car = car;

}

string Person::getName() const
{
	return this->name;
}

string Person::getEmail() const
{
	return this->email;
}

Car Person::getCar() const
{
	return Car();
}

void Person::setEmail(string email)
{
	this->email = email;
}

bool Person::hasAvailableSeats() const
{
	if (car->hasFreeSeats() && car != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//Person Person::operator<(Person a)
//{
//	int SIZE;
//	if (getName().size() == a.getName().size()) {
//		SIZE = getName().size();
//	}
//	else if (getName().size() < a.getName().size()) {
//		SIZE = getName().size();
//	}
//	else {
//		SIZE = a.getName().size();
//	}
//	for (int i = 0; i < SIZE; i++) {
//		if (this->name[i] < a.getName[i]) {
//			return a;
//		}
//		else if (this->name[i] > a.getName[i]) {
//			return *this;
//		}
//	}
//} 

//bool Person::operator==(Person a)
//{
//	if (getName() == a.getName()) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

bool Person::hasCar()
{
	if (this->car != nullptr) {
		return true;
	}
	else {
		return false;
	}
}



//void Person::print(ostream & os) const
//{
//	cout << "Name: " << name << endl << "Email: " << email << endl;
//	if (hasAvailableSeats()) {
//		cout << "Car: " << "Has available seats." << endl;
//	}
//	else {
//		cout << "No available seats." << endl;
//	}
//}
//2e) Hvorfor const argumentet Person&? Fordi vi peker til en verdi i en klasse
//mens funksjonen ligger utenfor klassen. Vi vil helst ikke endre denne verdien
//med denne funksjonen.

std::ostream & operator<<(std::ostream & os, const Person & p)
{
	os << "Name: " << p.getName() << "\tEmail: " << p.getEmail();
	return os;
}

bool operator<(const Person  &a, const Person  &b)
{
	string a1 = a.getName(); string b1 = b.getName();
	return a1 < b1;
}

bool operator==(const Person &a, const Person &b)
{
	return a.getName() == b.getName();
}

//void print(ostream & os, const Person &p)
//{
//	cout << "Name: " << p.getName() << endl << "Email: " << p.getEmail() << endl;
//	if (p.hasAvailableSeats()) {
//		cout << "Car: " << "Has available seats." << endl;
//	}
//	else {
//		cout << "No available seats." << endl;
//	}
//}
