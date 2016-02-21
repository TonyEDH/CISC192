#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int minVal = 1;
	int maxVal = 100;

	unsigned seed = time(0);//you may need to explicitly cast (ex. static_cast<unsigned>(time(0)))
	srand(seed);
	char c = ' ';

	cout << "Lets play a game! \n\nYou are trapped in a room, and the only way to get out is to enter the correct number!";
	cout << "\nI will be nice and tell you if you're too high or too low.";

	do
	{
		int randNum = minVal + (rand() % (maxVal - minVal + 1));
		int guess = 0;

		cout << "\nGuess the correct number from " << minVal << "-" << maxVal << " and press <ENTER> to escape. \n\nGood Luck!\n";
		do
		{
			cout << "\n\nCode: ";
			cin >> guess;
			if (guess > randNum)
			{
				cout << "Ha ha ha! Too high, try again.\n";
			}
			else if (guess < randNum)
			{
				cout << "He he he! Too low, try again.\n";
			}
			else
			{
				cout << "\nCorrect!\n";
				cout << "You got the right code! You can stay if you wish... ";
				cout << "Do you wish to leave the room (Y/N)? ";
				cin >> c;
				cout << "--------------------------------------------------------------------------------\n";
			}
		} while (guess != randNum);
	} while (toupper(c) != 'Y');
	return 0;
}
