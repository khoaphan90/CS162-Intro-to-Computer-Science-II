/*********************************************************************
** Program name: menu.cpp for Lab5
** Author: Khoa Phan
** Date: May 2, 2017
** Description: Function program that is used to create a menu that
** will receive input from the user to choose options.
*********************************************************************/

#include <iostream>

#include "menu.hpp"
#include "recursion.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** Menu::mainMenu
** Menu that displays initial screen of options for user
*********************************************************************/
bool Menu::mainMenu()
{
	// intialize variables
	string line, reverse;
	int* arr;
	int sNum, aNum, tNum, result, rows;

	// main menu prompt
	int input;
	cout << "+---------------------------------+" << endl;
	cout << " Welcome to the Recursion Program." << endl;
	cout << "+---------------------------------+" << endl;
	cout << "\nPlease choose a following option:\n"
		<< "\n1. Reverse a String"
		<< "\n2. Sum of an Array"
		<< "\n3. Calculate Triangular Number"
		<< "\n4. Exit Program"
		<< endl;
	cout << "\nChoice: ";
	input = checkInt();

	switch (input)
	{
	case 1:
		// prompt user to enter a string to be reversed
		cout << "Please enter a string: ";
		cin.clear();
		getline(cin, line);
		sNum = line.length();

		// call function and display results
		reverse = stringReverse(line, sNum-1);
		cout << reverse << endl;

		return true;
		break;
	case 2: 
		// prompt user to enter # elements in array
		cout << "Please enter an array size: ";
		cin.clear();
		aNum = checkInt();

		//create new array
		arr = new int[aNum];

		// prompt user to enter integers to fill
		// array according to aNum 
		for (int i = 0; i < aNum; i++)
		{
			cout << "Enter a number: ";
			tNum = checkInt();
			arr[i] = tNum;
		}
		result = sumArray(arr, aNum);
		cout << "The total sum is: " <<
			result << endl;

		// deallocate ptr array
		delete[] arr;

		return true;
		break;
	case 3:
		// Prompt user to enter # of rows
		cout << "Please enter a number of rows: ";
		rows = checkInt();

		// call triangular and display result
		result = triangular(rows, 0);
		cout << "The result is: " << result << endl;

		return true;
		break;
	case 4:
		cout << "Thank you for using this program." << endl;
		return false;
		break;
	default:
		cout << "Please choose a valid option" << endl;
		return true;
	}
}