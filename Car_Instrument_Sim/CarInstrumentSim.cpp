#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Odometer.h"
#include "FuelGuage.h"

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

		Odometer* car = new Odometer(myFuel, 1000);

		cout << "Car gas level: " << car->getFuelGuage()->getFuel() << endl;
		cout << "Car is off!" << endl;
		cout << "--------------------------" << endl;

		while(car->getFuelGuage()->getFuel() > 0)
		{
			car->addMile();

			int miles = car->getMileage();
			cout << "Mileage: " << miles << " , Fuel (gal left): " << car->getFuelGuage()->getFuel() << endl;
		}

		delete myFuel;
		delete car;

		cout << "Would you like to run the car again(Y/N)? ";
		cin >> response;

		system("cls||clear");

	} while(toupper(response) != 'N');

	return 0;
}





//public class CarInstrumentSim
//{
//	public static void main(String[] agrs)
//	{
//		//Car 1
//		//FuelGuage Obj
//		FuelGuage myFuel = new FuelGuage(6);
//
//		//Get and output fuel level
//		int fuelLevel = myFuel.getFuel();
//		System.out.println("Car1 gas level: " + fuelLevel);
//
//		//Fill up the FuelGuage to 15
//		System.out.println("Car1 is filling up");
//		while (myFuel.getFuel() < 15)
//		{
//			myFuel.addFuel();
//		}
//
//		//Create Odomoeter Obj and pass it the full FuelGuage and mileage
//		Odometer car1 = new Odometer(myFuel, 1000);
//		System.out.println("Car1 gas level: " + car1.getFuelGuage().getFuel());
//
//		//Run the car(Odometer)
//		System.out.println("Car1 is off!");
//		System.out.println("-----------------------------------");
//		while (car1.getFuelGuage().getFuel() > 0)
//		{
//			//Add mile to mileage 
//			car1.addMile();
//			//Display updated mileage and fuel level
//			int miles = car1.getMileage();
//			System.out.println("Mileage: " + miles + " ,Fuel(Gal left): " + car1.getFuelGuage().getFuel());
//
//		}
//		System.out.println("Out of gas!" +
//			"\n===================================");
//
//		//Car 2
//		//FuelGuage Obj
//		myFuel = new FuelGuage(8);
//
//		//Get and output fuel level
//		fuelLevel = myFuel.getFuel();
//		System.out.println("Car2 gas level: " + fuelLevel);
//
//		//Fill up the FuelGuage to 15
//		System.out.println("Car2 is filling up");
//		while (myFuel.getFuel() < 15)
//		{
//			myFuel.addFuel();
//		}
//
//		//Create Odomoeter Obj and pass it the full FuelGuage and mileage
//		Odometer car2 = new Odometer(myFuel, 999850);
//		System.out.println("Car2 gas level: " + car2.getFuelGuage().getFuel());
//
//		//Run the car(Odometer)
//		System.out.println("Car2 is off!");
//		System.out.println("-----------------------------------");
//		while (car2.getFuelGuage().getFuel() > 0)
//		{
//			//Add mile to mileage
//			car2.addMile();
//			//Display updated mileage and fuel level
//			int miles = car2.getMileage();
//			System.out.println("Mileage: " + miles + " ,Fuel(Gal left): " + car2.getFuelGuage().getFuel());
//
//		}
//		System.out.println("Out of gas!" +
//			"\n===================================");
//
//	}
//}