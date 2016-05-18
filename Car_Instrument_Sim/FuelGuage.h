#ifndef FUEL_GUAGE_H
#define FUEL_GUAGE_H

class FuelGuage
{
private:
	int fuel;
	void init();
public:
	FuelGuage();
	FuelGuage(int fuel);
	FuelGuage(const FuelGuage& copy);
	int getFuel();
	void addFuel();
	void burnFuel();
};
#endif