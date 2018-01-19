/*********************************************************************
** Program name: binarySearch.cpp for Lab8
** Author: Khoa Phan
** Date: May 26, 2017
** Description: The main file that executes the search using a
** binary search function.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "validation.hpp"

using namespace std;

int binarySearch(int*,const int, const int, int, int);
bool writeArray(fstream&, int*);
void displayArray(int*, const int);


int main()
{
	bool openFile;
	char input;

	// Set array variable and size
	const int ARRAYSIZE = 10;
	int numArr[ARRAYSIZE];

	// Open files
	fstream f1;
	string filename;

	// enter and search first file
	do
	{
		cout << "Enter the name of the file: ";
		cin >> filename;
		f1.open(filename);

		//check valid file opening and
		//using binary search
		if (f1)
		{
			openFile = writeArray(f1, numArr);
			if (openFile == true)
			{
				cout << "Enter an integer to search: ";
				cin.ignore();
				int input = checkInt();
				binarySearch(numArr, input, ARRAYSIZE, 0, (ARRAYSIZE - 1));
			}
		}
		else
			cout << "Error opening file." << endl;

		cin.ignore();
		cout << "Again? (Y/N): " << endl << endl;
		input = checkChar();
		f1.close();

	} while (toupper(input) != 'N');

	return 0;
}

/*********************************************************************
** binarySearch
** Function that uses a binary search to search the array.
** Source:
**		Example: www.algolist.net/Algorithms/Binary_search
*********************************************************************/
int binarySearch(int *arr, const int input, const int size, int low, int high)
{
	int mid;

	// Checks the input for value and changes search area
	while (low <= high)
	{
		mid = low + ((high-low) / 2);
		// check if input is first in array
		//if (input == low)
			//return 0;
		if (arr[mid] == input)
		{
			cout << "Integer found!" << endl;
			return mid;
		}
		else if (arr[mid] < input)
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << "Integer not found." << endl;
	return -1;
}


/*********************************************************************
** writeArray
** Function that writes the information from the file into the
** array in the program.
*********************************************************************/
bool writeArray(fstream &file, int* arr)
{
	int values;

	// if file exist, open and write files into array. Search array
	// for value 0
	if (file)
	{
		for (int i = 0; i < 10; i++)
		{
			file >> values;
			arr[i] = values;
		}
		return true;
	}
	else
		return false;
}

void displayArray(int *arr, const int ARRAYSIZE)
{
	for (int i = 0; i < ARRAYSIZE; i++)
		cout << arr[i] << " ";
}

//int main()
//{
//	fstream file;
//	string filename;
//
//	const int ARRAYSIZE = 10;
//	int numArr[ARRAYSIZE];
//
//	file.open("sortedEarly.txt");
//	
//	int values;
//
//	for (int i = 0; i < ARRAYSIZE; i++)
//	{
//		file >> values;
//		numArr[i] = values;
//		cout << numArr[i] << " ";
//	}
//
//	int number, low, mid, high;
//	low = 1;
//	high = (ARRAYSIZE - 1);
//
//	cout << "enter number: ";
//	cin >> number;
//
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		cout << "LOW: " << low << " ";
//		cout << "MID: " << mid << " ";
//		cout << "HIGH: " << high << endl;
//		cout << "NUMBER: " << number << endl;
//
//		if (numArr[mid] == number)
//			cout << "FOUND IT!" << endl;
//		else if (numArr[mid] > number)
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//
//	return 0;
//}