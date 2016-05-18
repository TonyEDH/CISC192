#include "FuelGuage.h"

FuelGuage::FuelGuage()
{
	init();
}

FuelGuage::FuelGuage(int fuel)
{
	init();
	this->fuel = fuel;
}

FuelGuage::FuelGuage(const FuelGuage& copy)
{
	this->fuel = copy.fuel;
}

void FuelGuage::init()
{
	this->fuel = 0;
}

int FuelGuage::getFuel()
{
	return fuel;
}

void FuelGuage::addFuel() 
{
	fuel++;
}

void FuelGuage::burnFuel() 
{
	fuel--;
}