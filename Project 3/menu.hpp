/*********************************************************************
** Program name : menu.hpp for Project 3
** Author : Khoa Phan
** Date : May 10, 2017
** Description : Header file for menu.cpp
********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "validation.hpp"
#include "game.hpp"
#include "creature.hpp"

using std::cout;
using std::endl;
using std::cin;

class Menu
{
private:
public:
	bool mainMenu();
	TYPE typeMenu();
protected:
};

#endif // !MENU