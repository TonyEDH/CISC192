#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Ship* ships[] = { new Ship("Big Blue", "1985"),
					  new CruiseShip("Oasis of the Seas", "2013", 2800),
					  new CargoShip("Olympia", "1998", 100000) };

	for (int i = 0; i < 3; i++)
	{
		ships[i]->print();
	}

	for (int i = 0; i < 3; i++)
	{
		delete ships[i];
	}

	char c;
	cout << "Press any key and <ENTER> to exit." << endl;
	cin >> c;

	return 0;
}