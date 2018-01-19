/*********************************************************************
** Program name: program2.cpp for Lab8
** Author: Khoa Phan
** Date: May 26, 2017
** Description: The main file that executes the sort the input files
** in ascending order.
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::string;
using std::cin;

void sortArray(int[], int);
void processArray(string, fstream &, int*, const int&);
void writeArray(fstream&, int*);
void displayArray(int*, const int);


int main()
{
	// BUBBLE SORT BOOK EXAMPLE:
	// Program 9-4, page 616

	// Set array variable and size
	const int ARRAYSIZE = 10;
	int numArr[ARRAYSIZE];

	// Open files
	fstream f1, f2, f3, f4;
	f1.open("early.txt"), f2.open("middle.txt"),
		f3.open("end.txt"), f4.open("original.txt");

	// process file, write out
	processArray("Early", f1, numArr, ARRAYSIZE);
	processArray("Middle", f2, numArr, ARRAYSIZE);
	processArray("End", f3, numArr, ARRAYSIZE);

	f1.close(), f2.close(), f3.close(), f4.close();

	return 0;
}

/*********************************************************************
** processArray
** Function that sorts, displays then writes the array information
** into a new file.
*********************************************************************/
void processArray(string desc, fstream &file, int *arr, const int &size)
{
	// User entered file name variables
	ofstream f;
	string filename;

	// process the file and array
	writeArray(file, arr);
	cout << desc << ":" << "\nSorted:   ";
	sortArray(arr, size);
	displayArray(arr, size);

	// Prompt user to enter name, export file as txt
	cout << "\nEnter the name of the output file: ";
	getline(cin, filename);
	filename += ".txt";
	f.open(filename);
	
	// Write data to new file and close
	for (int i = 0; i < 10; i++)
		f << arr[i] << " \n" << endl;
	f.close();
	cout << endl;
}


/*********************************************************************
** sortArray
** Function that sorts the integers in the array in ascending order.
*********************************************************************/
void sortArray(int array[], int size)
{
	int temp;
	bool madeAswap;

	do
	{
		madeAswap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				madeAswap = true;
			}
		}
	} while (madeAswap);
}

/*********************************************************************
** writeArray
** Function that writes the information from the file into the
** array in the program.
*********************************************************************/
void writeArray(fstream &file, int *arr)
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
	}
	else
		cout << "Error opening file." << endl;
}

void displayArray(int *arr, const int ARRAYSIZE)
{
	for (int i = 0; i < ARRAYSIZE; i++)
		cout << arr[i] << " ";
}