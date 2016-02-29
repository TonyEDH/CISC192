#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//Game loop variable
	char response;

	do
	{
		//Declare variables
		const int ARRAY_SIZE = 5;
		int numbers[ARRAY_SIZE];
		int low;
		int high;
		int total = 0;
		double average;
		string fileName;
		ifstream inFile;

		//Get file name/path from user
		cout << "Please enter file path/name:";
		cin >> fileName;

		//Open file and read file to store numbers into array
		inFile.open(fileName);

		//Check for file existance
		if (inFile)
		{
			//Store number values in array and close file
			int num;
			cout << "\nAccessing file: " << fileName << endl << endl;
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				cout << "Processing...\n";
				inFile >> num;
				numbers[i] = num;
				inFile.ignore();
			}

			inFile.close();
			cout << "\nClosing file...\n\n";
		}
		//Give error message if file does not exist
		else
		{
			cout << "\nERROR: Cannot open file:" << fileName << endl;
		}
		
		//Set starting high and low values to test against
		high = numbers[0];
		low = numbers[0];

		//Used Enhanced/Range Based FOR loops to process array data
		for (int val : numbers)
		{
			if (val > high)
			{
				high = val;
			}
			else if (val < low)
			{
				low = val;
			}
		}

		for (int val : numbers)
		{
			total += val;
		}

		//Calculate average
		average = total / static_cast<double>(ARRAY_SIZE);

		//Output processed data
		cout << "Total:" << total << endl;
		cout << "High:" << high << endl;
		cout << "Low:" << low << endl;
		cout << "Average:" << average << endl;
		cout << endl;

		//Ask user if they want to repeat
		cout << "Would you like to process another file (Y/N)? ";
		cin >> response;
		cout << "\n===================================================\n";
	} while (toupper(response) != 'N');

	return 0;
}