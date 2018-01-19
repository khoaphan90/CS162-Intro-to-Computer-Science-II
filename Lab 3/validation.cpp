/*********************************************************************
** Program name: validation.cpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: These are the validation functions used to validate
** the input values of the user. They are restricted to integers only
** and will either return an error message or integer that may be
** converted.
*********************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "validation.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stringstream;


// Source http://www.cplusplus.com/forum/beginner/76374/
// by MetalMilitia
// Integer input validation
// *expand later to suite other input types


/*********************************************************************
** Validation::checkInput
** Function checks for values that are not integers
*********************************************************************/
int checkInput()
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
** Validation::checkOdd
** Function that checks if the input is an integer and is odd
*********************************************************************/

// *Modified from above source to check only odds
int checkOdd()
{
	string input;
	int out;

	while (true) {
		getline(cin, input);
		stringstream ss(input);

		if (ss >> out && !(ss >> input))
		{
			if (out % 2 != 0 && out > 0)
				return out;
		}
		cin.clear();
		cout << "Please enter a positive odd number. Try again." << endl;
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
			if (out == 1 || out == 2)
				return out;
			else
				cout << "Please choose a valid option. Try again." << endl;
		}

		cin.clear();
	}
}
