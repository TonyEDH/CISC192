#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Prototypes
string getFileName();
bool isFileValid(string inFileName);
int countData(string inFileName);
void getData(string inFileName, int inArray[], int inCount);
int getHigh(int inArray[], int inCount);
int getLow(int inArray[], int inCount);
double getAverage(int inArray[], int inCount);
void printData(int inHigh, int inLow, double inAverage);

int main()
{
	char response;
	do
	{
		//Variables
		int count;
		int high;
		int low;
		int *data;
		double average;
		string fileName;
		ifstream inFile;

		fileName = getFileName();
		count = countData(fileName);
		data = new int[count];
		getData(fileName, data, count);
		high = getHigh(data, count);
		low = getLow(data, count);
		average = getAverage(data, count);
		printData(high, low, average);


		cout << "Do you want to process another file (Y/N)? ";
		cin >> response;
	} while (toupper(response) != 'N');
	return 0;
}


/*Get file name/path from user*/
string getFileName()
{
	string filename;
	bool isValid = false;
	do
	{
		system("cls||clear");
		cout << "Enter name/path of file to be processed:";
		cin >> filename;

		isValid = isFileValid(filename);

	} while (!isValid);

	return filename;
}

/*Checks File Validity*/
bool isFileValid(string inFileName)
{
	ifstream inFile;
	inFile.open(inFileName);
	if (inFile)
	{
		inFile.close();
		return true;
	}
	else
	{
		inFile.close();
		return false;
	}
}

/*Count number of data for array decalaration*/
int countData(string inFileName)
{
	int num;
	int count = 0;
	ifstream inFile;
	inFile.open(inFileName);

	while (inFile >> num)
	{
		count++;
	}
	inFile.close();
	return count;
}

/*Get data from file and store in array*/
void getData(string inFileName, int inArray[], int inCount)
{
	int num;
	ifstream inFile;
	inFile.open(inFileName);
	cout << "\nAccessing file..." << endl << endl;

	for (int i = 0; i < inCount; i++)
	{
		cout << "Processing...\n";
		inFile >> num;
		inArray[i] = num;
		inFile.ignore();
	}
	inFile.close();
}

/*Get highest number from data*/
int getHigh(int inArray[], int inCount)
{
	int high = inArray[0];

	for (int i = 0; i < inCount; i++)
	{
		if (inArray[i] > high)
		{
			high = inArray[i];
		}
	}
	return high;
}

/*Get lowest number from data*/
int getLow(int inArray[], int inCount)
{
	int low = inArray[0];

	for (int i = 0; i < inCount; i++)
	{
		if (inArray[i] < low)
		{
			low = inArray[i];
		}
	}
	return low;
}

/*Get average of numbers in data*/
double getAverage(int inArray[], int inCount)
{
	int total = 0;
	double average;

	for (int i = 0; i < inCount; i++)
	{
		total += inArray[i];
	}
	average = total / static_cast<double>(inCount);
	return average;
}

/*Print out processed data*/
void printData(int inHigh, int inLow, double inAverage)
{
	cout << "-----------------\n";
	cout << "High: " << inHigh << endl;
	cout << "Low: " << inLow << endl;
	cout << "Average: " << inAverage << endl;
	cout << "-----------------\n";
}