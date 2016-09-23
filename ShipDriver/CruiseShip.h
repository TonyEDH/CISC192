#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"
#include <iostream>
#include <string>

using namespace std;

class CruiseShip : public Ship
{
private:
	int passengers;

public:
	CruiseShip(string name, string year, int passengers);
	~CruiseShip();

	string getName();
	string getYear();
	int getPassengers();
	void setName(string name);
	void setYear(string year);
	void setPassengers(int passengers);

	void print();

};

#endif