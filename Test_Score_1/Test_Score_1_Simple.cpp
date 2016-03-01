#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function Prototypes
int getNumScores();
void getScores(int inArray[], int inCount);
void sortArray(int inArray[], int inCount);
double avgArray(int inArray[], int inCount);
void printArray(int inArray[], int inCount, string header);

int main()
{
	//Game loop variable
	char response;

	do
	{
		//Variables
		int *testScores;
		int count;
		double average;

		//Get number of scores
		count = getNumScores();
		//Create Array with num of scores 
		testScores = new int[count];
		//Fill Array with scores input from user
		getScores(testScores, count);
		//Sort Array in ascending order
		sortArray(testScores, count);
		//Average Array scores
		average = avgArray(testScores, count);
		//Print Sorted Array
		cout << "====================";
		printArray(testScores, count, "\nSorted Test Scores");
		//Print Average score
		cout << fixed << showpoint << setprecision(2);
		cout << "Average Score: " << average << endl;
		cout << "====================";

		//Ask to run again
		cout << "\nWould you like to process another test(Y/N)? ";
		cin >> response;
	} while (toupper(response) != 'N');

	return 0;
}

/*Get number of test scores from user*/
int getNumScores()
{
	int count;
	cout << "Please enter the number of test scores to be entered: ";
	cin >> count;
	return count;
}

/*Get test scores from user*/
void getScores(int inArray[], int inCount)
{
	int score;
	for (int i = 0; i < inCount; i++)
	{
		do
		{
			cout << "Test score " << (i + 1) << ": ";
			cin >> score;

		} while (score < 0);
		inArray[i] = score;
	}
}

/*Sorting array of test scores in ascending order*/
void sortArray(int inArray[], int inCount)
{
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