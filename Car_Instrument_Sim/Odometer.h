#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGuage.h"

class Odometer
{
private:
	void init();
	int mileage;
	int milesSinceAddingFuel;
	FuelGuage* fuel;
public:
	Odometer();
	Odometer(FuelGuage* inFuel, int inMileage);
	FuelGuage* getFuelGuage();
	int getMileage();
	void addMile();
	void resetMiles();
	~Odometer();
};

#endif