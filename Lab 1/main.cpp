/*********************************************************************
** Program name: main.cpp for Lab 1
** Author: Khoa Phan
** Date: April 4, 2017
** Description: This program is written to prompt user to choose the
size of matrix they would like to use which will then ask for input
and return a determinant for that matrix.
*********************************************************************/

#include <iostream>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int **mat, row, col, input;
	bool validInput = false;

	//prompt user to choose a matrix of 2x2 or 3x3
	do
	{
		cout << "Please enter which matrix you would like to use: " << endl;
		cout << "1.  2x2" << endl;
		cout << "2.  3x3" << endl;
		cin >> input;

		if (input == 1 || input == 2)
		{
			//determine which board to make based off input
			switch (input)
			{
				//create matrix 2x2
			case 1:
				row = col = 2;
				mat = new int*[row];
				for (int rows = 0; rows < 2; rows++)
					mat[rows] = new int[col];
				readMatrix(mat, row, col);

				//deallocate 
				for (int i = 0; i < 2; i++)
					delete[] mat[i];
				delete[] mat;
				mat = NULL;
				
				validInput = true;
				break;

				//create matrix 3x3
			case 2:
				row = col = 3;
				mat = new int*[row];
				for (int rows = 0; rows < 3; rows++)
					mat[rows] = new int[col];
				readMatrix(mat, row, col);

				//deallocate 
				for (int i = 0; i < 3; i++)
					delete[] mat[i];
				delete[] mat;
				mat = NULL;

				validInput = true;
				break;
			}
		}
		else
			cout << "Please select a valid option." << endl << endl;
	} while (validInput == false);

	return 0;
}