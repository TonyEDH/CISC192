#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship
{
private:
	int capacity;
public:
	CargoShip(string name, string year, int capacity);
	~CargoShip();

	string getName();
	string getYear();
	int getCapacity();
	void setName(string name);
	void setYear(string year);
	void setCapacity(int capacity);

	void print();

};

#endif