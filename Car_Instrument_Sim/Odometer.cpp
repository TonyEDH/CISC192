#include "Odometer.h"

Odometer::Odometer()
{
	init();
}

Odometer::Odometer(FuelGuage* inFuel, int inMileage)
{
	init();
	this->fuel = new FuelGuage(inFuel);
	this->mileage = inMileage;
	this->milesSinceAddingFuel = 0;
}

void Odometer::init()
{
	fuel = new FuelGuage();
	mileage = 0;
	milesSinceAddingFuel = 0;
}

FuelGuage* Odometer::getFuelGuage()
{
	return fuel;
}


int Odometer::getMileage()
{
	return mileage;
}

void Odometer::addMile()
{
	if(mileage < 999999)
	{
		mileage++;
		milesSinceAddingFuel++;
	}
	else
	{
		mileage = 0;
		milesSinceAddingFuel++;
	}

	if((milesSinceAddingFuel % 24) == 0)
	{
		fuel->burnFuel();
	}
}

void Odometer::resetMiles()
{
	milesSinceAddingFuel = 0;
}

Odometer::~Odometer()
{
	delete fuel;
}