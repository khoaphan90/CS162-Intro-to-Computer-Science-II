/*********************************************************************
** Program name : menu.hpp for Project2
* * Author : Khoa Phan
** Date : April 28, 2017
** Description : Header file for menu.cpp
********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "validation.hpp"
#include "list.hpp"

using std::cout;
using std::endl;
using std::cin;

class Menu
{
private:
public:
	bool mainMenu(List&);
	void displayMenu(List&);
	void modifyMenu(List&);
	void displayItem(List&, int);
	void modifyItem(int);
protected:
};

#endif // !MENU