#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

using namespace std;

class Ship
{
protected:
	string name;
	string year;

public:
	Ship(string name, string year);
	virtual ~Ship();

	string getName();
	string getYear();
	void setName(string name);
	void setYear(string year);

	virtual void print();
};

#endif