#ifndef FUEL_GUAGE_H
#define FUEL_GUAGE_H

class Odometer;

class FuelGuage
{
	friend class Odometer;
private:
	int fuel;
	void init();
public:
	FuelGuage();
	FuelGuage(int fuel);
	FuelGuage(const FuelGuage* copy);
	int getFuel();
	void addFuel();
	void burnFuel();
	~FuelGuage();
};
#endif