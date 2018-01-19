/*********************************************************************
** Program name: main.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Main file for university information systems program.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "university.hpp"
#include "building.hpp"

#include "student.hpp"

using namespace std;

int main()
{
	Menu start;

	bool menuActive = true;
	while (menuActive == true)
	{
		menuActive = start.mainMenu();
	}	
	return 0;
}