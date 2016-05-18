#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Odometer.h"

using namespace std;

int main()
{
	char response;

	do 
	{
		FuelGuage* myFuel = new FuelGuage(6);

		int fuelLevel = myFuel->getFuel();

		cout << "Car gas level: " << fuelLevel << endl;
		cout << "Car is filling up" << endl;

		while(myFuel->getFuel() < 15)
		{
			myFuel->addFuel();
		}

		Odometer* car = new Odometer(myFuel, 999990);

		cout << "Car gas level: " << car->getFuelGuage()->getFuel() << endl;
		cout << "Car is off!" << endl;
		cout << "--------------------------" << endl;

		while(car->getFuelGuage()->getFuel() > 0)
		{
			car->addMile();

			int miles = car->getMileage();
			cout << "Mileage: " << setw(6) << miles << ", Fuel (gal left): " << car->getFuelGuage()->getFuel() << endl;
		}

		delete myFuel;
		delete car;

		cout << "Would you like to run the car again(Y/N)? ";
		cin >> response;

		system("cls||clear");

	} while(toupper(response) != 'N');

	return 0;
}