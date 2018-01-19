/*********************************************************************
** Program name: validation.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: These are the validation functions used to validate
** the input values of the user. They are restricted to integers only
** and will either return an error message or integer that may be
** converted.
*********************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "validation.hpp"

using namespace std;


// Source http://www.cplusplus.com/forum/beginner/76374/
// by MetalMilitia
// input validation
// *expand later to suite other input types


/*********************************************************************
** Validation::checkInt
** Function checks for values that are not integers
*********************************************************************/
int checkInt()
{
	string input;
	int out;

	while (true) {
		getline(cin, input);
		stringstream ss(input); //covert input to a stream for conversion to int

		if (ss >> out && !(ss >> input))
		{
			if (out > 0)
				return out;
		}
		cin.clear(); //in case of a cin error, like eof() -- prevent infinite loop
		cout << "\nInvalid input. Please try again.\n"; //if you get here, it's an error
	}
}

/*********************************************************************
** Validation::checkDouble
** Function checks for values that are not integers
*********************************************************************/
double checkDouble()
{
	string input;
	double out;

	while (true) {
		getline(cin, input);
		stringstream ss(input); //covert input to a stream for conversion to double

		if (ss >> out && !(ss >> input))
		{
			if (out > 0)
				return out;
		}
		cin.clear(); //in case of a cin error, like eof() -- prevent infinite loop
		cout << "\nInvalid input. Please try again.\n"; //if you get here, it's an error
	}
}


/*********************************************************************
** Validation::checkRange
** Function that checks if the input is an integer and is odd
*********************************************************************/

// *Modified from above source to check only odds
int checkRange()
{
	string input;
	int out;

	while (true) {
		getline(cin, input);
		stringstream ss(input);

		if (ss >> out && !(ss >> input))
		{
			if (out > 0 && out < 6)
				return out;
		}

		cin.clear();
		cout << "Invalid input. Try again." << endl;
	}
}

/*********************************************************************
** Validation::checkChar
** Function that checks for Y or N inputs
*********************************************************************/
char checkChar()
{
	string input;
	char out;

	while (true) {
		getline(cin, input);
		stringstream ss(input);

		if (ss >> out && !(ss >> input))
		{
			if (toupper(out) == 'W' || toupper(out) == 'S' 
				|| toupper(out) == 'A' || toupper(out) == 'D')
				return out;
		}

		cin.clear();
		//cout << "Invalid input. Try again." << endl;
	}
}
