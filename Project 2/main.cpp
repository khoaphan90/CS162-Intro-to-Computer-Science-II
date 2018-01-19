/*********************************************************************
** Program name: main.cpp for Project 2
** Author: Khoa Phan
** Date: April 28, 2017
** Description: These is the code written to start the operating
** program.
*********************************************************************/

#include <iostream>
#include "list.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// call class variables to start
	Menu start;
	List a;

	bool active = true;

	cout << "Welcome to the Grocery Shopping List."
		<< endl << endl;

	// run menu until exit
	while (active == true)
		active = start.mainMenu(a);

	return 0;
}