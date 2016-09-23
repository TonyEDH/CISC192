#include "CruiseShip.h"
#include <iostream>
#include <string>

using namespace std;

CruiseShip::CruiseShip(string name, string year, int passengers) : Ship(name, year)
{
	this->passengers = passengers;
}
CruiseShip::~CruiseShip()
{

}

string CruiseShip::getName()
{
	return name;
}

string CruiseShip::getYear()
{
	return year;
}

int CruiseShip::getPassengers()
{
	return passengers;
}

void CruiseShip::setName(string name)
{
	this->name = name;
}

void CruiseShip::setYear(string year)
{
	this->year = year;
}

void CruiseShip::setPassengers(int passengers)
{
	this->passengers = passengers;
}

void CruiseShip::print()
{
	cout << "\nShip name: " << name << endl;
	cout << "Max Passengers: " << passengers << " people" << endl;
}