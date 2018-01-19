/********************************************************************* 
** Program name: readMatrix.cpp for Lab 1
** Author: Khoa Phan
** Date: April 4, 2017
** Description: This program is written to prompt user to input values
to be stored into the matrix which will then use the determinant
function.
*********************************************************************/

#include <iostream>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::endl;

/*********************************************************
			ReadMatrix::readMatrix
This function receives the array board of 2x2 or 3x3 from
the main function and prompts user to store integer values
into the array. It then calls the determinant function.
*********************************************************/

void readMatrix(int** matrix, int row, int col)
{

	for (int r = 0; r < row; r++)
	{
		cout << "Please enter " << col << " numbers for row " 
			<< r + 1 << "." << endl;;
		//store user inputted values
		for (int c = 0; c < col; c++)
			cin >> matrix[r][c];
		cout << endl;
	}
	//call determinant function
	determinant(matrix, row, col);
}