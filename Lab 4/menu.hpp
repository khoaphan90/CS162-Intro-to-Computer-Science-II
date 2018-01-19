/*********************************************************************
** Program name: menu.hpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Header file for the Menu class.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "university.hpp"

using namespace std;

class Menu
{
private:
public:
	bool mainMenu();
	void bldgMenu();
	void personMenu();
	void studentMenu();
	void instMenu();
	void workMenu();
protected:
};

#endif // !MENU_HPP
