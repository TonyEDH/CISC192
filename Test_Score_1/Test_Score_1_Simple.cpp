#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function prototypes
void sortArray(int array[], int inCount);
double avgArray(int array[], int inCount);
void printArray(int array[], int inCount, string header);

int main()
{
	char response;

	do
	{
		int *testScores;
		int count;
		double average;

		//Create Array
		cout << "Please enter the number of test scores to be entered: ";
		cin >> count;

		testScores = new int[count];
		//Fill Array
		for (int i = 0; i < count; i++)
		{
			int score;
			cout << "Test score " << (i + 1) << ": ";
			cin >> score;

			testScores[i] = score;
		}
		//Sort Array
		sortArray(testScores, count);
		//Average Array
		average = avgArray(testScores, count);
		//Print Sorted Array
		cout << "====================";
		printArray(testScores, count, "\nSorted Test Scores");
		//Print Avg
		cout << fixed << showpoint << setprecision(2);
		cout << "Average Score: " << average << endl;
		cout << "====================";

		cout << "\nWould you like to process another test(Y/N)? ";
		cin >> response;
	} while (toupper(response) != 'N');

	return 0;
}

/*Sorting function*/
void sortArray(int inArray[], int inCount)
{
	//Find number of elements in the function
	int startScan;
	int minIndex;
	int minVal;
	//Check Values for each element
	for (startScan = 0; startScan < (inCount - 1); startScan++)
	{
		minIndex = startScan;
		minVal = inArray[startScan];
		//Test values from other elements to current element value
		for (int i = startScan + 1; i < inCount; i++)
		{
			if (inArray[i] < minVal)
			{
				minVal = inArray[i];
				minIndex = i;
			}
		}
		inArray[minIndex] = inArray[startScan];
		inArray[startScan] = minVal;
	}

}

/*Find Average Score Function*/
double avgArray(int inArray[], int inCount)
{
	int total = 0;
	for (int i = 0; i < inCount; i++)
	{
		total += inArray[i];
	}
	
	return (total / static_cast<double>(inCount));
}


/*Print Array Function*/
void printArray(int inArray[], int inCount, string header)
{
	cout << header << endl;
	cout << "--------------------\n";
	for (int i = 0; i < inCount; i++)
	{
		cout << "Score " << (i + 1) << ": " << inArray[i] << endl;
	}
}