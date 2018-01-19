/*********************************************************************
** Program name: determinant.cpp for Lab 1
** Author: Khoa Phan
** Date: April 4, 2017
** Description: This program returns the determinant using the
mathematical formula that calculates it. It recieves information from
a 2D array that holds values stored by user input.
*********************************************************************/

#include <iostream>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::endl;

/*********************************************************
			Determinant::determinant
This function receives the 2D array that has been passed 
to it and calculates the determinant usings its math
forumula. It then displays the result and the matrix.
*********************************************************/
void determinant(int** m, int row, int col)
{
	int result = 0;
	//determinant for 2x2
	if (row == 2)
	{
		int ad, bc;
		ad = m[0][0] * m[1][1];
		bc = m[0][1] * m[1][0];
		result = ad - bc;
	}

	//determinant for 3x3
	if (row == 3)
	{
		//3x3 a(ei-fh) - b(di-fg) + c(dh-eg)
		int a, b, c;
		a = m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1]));
		b = m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]));
		c = m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0]));
		result = a - b - c;
	}

	//display original array
	cout << "Here is the matrix:" << endl;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
			cout << m[r][c] << " ";
		cout << endl;
	}

	//display results
	cout << "\nDeterminant is: " << result << endl;
}