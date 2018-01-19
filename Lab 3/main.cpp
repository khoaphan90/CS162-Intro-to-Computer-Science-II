/*********************************************************************
** Program name: main.cpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description:
*********************************************************************/

#include <iostream>
#include "validation.hpp"
#include "menu.hpp"
#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int input;
	// welcome prompt, options
	cout << "Welcome to the Dice Game." << endl << endl;
	cout << "Please choose an option." << endl;
	cout << "1. Start" << endl;
	cout << "2. Quit" << endl;
	input = checkInput();

	mainMenu(input);

	return 0;
}