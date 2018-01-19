/*********************************************************************
** Program name: program1.cpp for Lab8
** Author: Khoa Phan
** Date: May 26, 2017
** Description: The main file that executes the search for 0 in the
** external .txt files
*********************************************************************/

#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::fstream;

void findZero(fstream&);

int main()
{
	fstream f1, f2, f3, f4;
	f1.open("early.txt");
	f2.open("middle.txt");
	f3.open("end.txt");
	f4.open("original.txt");

	
	findZero(f1);
	findZero(f2);
	findZero(f3);
	findZero(f4);

	return 0;
}


/*********************************************************************
** findZero
** Function that searches input file for 0 and displays if it exist
** within that file.
*********************************************************************/
void findZero(fstream &file)
{
	int numList[10];
	int values;
	bool found = false;

	// if file exist, open and write files into array. Search array
	// for value 0
	if (file)
	{
		for (int i = 0; i < 10; i++)
		{
			file >> values;
			numList[i] = values;
		}

		for (int i = 0; i < 10; i++)
			if (numList[i] == 0)
				found = true;

		if (found)
			cout << "File target value '0' found." << endl;
		else
			cout << "File target value '0' not found." << endl;
	}
	else
		cout << "Error opening file." << endl;
}
