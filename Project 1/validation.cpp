/*********************************************************************
** Program name: validation.cpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: These are the validation functions used to validate
** the input values of the user. They are restricted to integers only
** and will either return an error message or integer that may be
** converted.
*********************************************************************/

#include <iostream>	
#include <string>

using std::cout;
using std::cin;
using std::endl;

// input validation to accept ints only.
// source: http://www.cplusplus.com/forum/beginner/147249/


/**********************************************************
//				Validation::getNum
// Function that prompt for input and checks to see if
// input is at least a double. If anything else, it makes
// it invalid.
**********************************************************/
double getNum()
{
	double input;

	while (!(cin >> input))
	{
		//clears and ignores input if not double
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Invalid input. Try again." << endl;
	}
	cin.ignore(80, '\n');
	return input;
}


/**********************************************************
//				Validation::validOption
// Function that recieves input from getNum and checks
// input. If input is a number, it is then converted to
// and integer.
**********************************************************/
int validOption()
{
	double number = getNum();
	while (number != static_cast<int>(number) || number < 0)
	{
		cout << "Invalid input. Try again." << endl;
		number = getNum();
	}
	return static_cast<int>(number);
}

/**********************************************************
//				Validation::validRange
// Function checks the range of the number input against
// the GameBoard's board array to make sure it does not
// exceed the boundaries of the array.
**********************************************************/
int validRange(int row, int col)
{
	int number = validOption();
	while (number > row || number > col || number < 0)
	{
		cout << "Please enter a within the game board size. "
			<< "Please try again." << endl;
		number = validOption();
	}
	return number;
}