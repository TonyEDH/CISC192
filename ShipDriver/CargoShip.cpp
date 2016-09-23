#include "CargoShip.h"
#include <iostream>
#include <string>

using namespace std;

CargoShip::CargoShip(string name, string year, int capacity) : Ship(name, year)
{
	this->capacity = capacity;
}

CargoShip::~CargoShip() 
{

}

string CargoShip::getName()
{
	return name;
}

string CargoShip::getYear()
{
	return year;
}

int CargoShip::getCapacity()
{
	return capacity;
}

void CargoShip::setName(string name)
{
	this->name = name;
}

void CargoShip::setYear(string year)
{
	this->year = year;
}

void CargoShip::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void CargoShip::print()
{
	cout << "\nShip Name: " << name << endl;
	cout << "Ship Capacity: " << capacity << " tons" << endl;
}
	