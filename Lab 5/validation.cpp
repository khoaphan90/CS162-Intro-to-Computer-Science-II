/*********************************************************************
** Program name: validation.cpp for Lab 5
** Author: Khoa Phan
** Date: May 2, 2017
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
		cout << "*Invalid input. Please try again.*\n"; //if you get here, it's an error
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
** Validation::checkRange1
** Function that checks if the input is an integer and is odd
*********************************************************************/

// *Modified from above source to check only odds
double checkRange1()
{
	string input;
	double out;

	while (true) {
		getline(cin, input);
		stringstream ss(input);

		if (ss >> out && !(ss >> input))
		{
			if (out >= 0 && out <= 5)
				return out;
			else
				cout << "Please choose a rating between 0-5. Try again." << endl;
		}

		cin.clear();
	}
}


/*********************************************************************
** Validation::checkRange2
** Function that checks if the input for range
*********************************************************************/

double checkRange2()
{
	string input;
	double out;

	while (true) {
		getline(cin, input);
		stringstream ss(input);

		if (ss >> out && !(ss >> input))
		{
			if (out >= 0 && out <= 4)
				return out;
			else
				cout << "Please choose a GPA within 0.0-4.0. Try again." << endl;
		}
		cin.clear();
	}
}
