/*********************************************************************
** Program name: inventory.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the class inventory.
*********************************************************************/
#include <iostream>
#include "inventory.hpp"
#include <algorithm>

/*********************************************************************
** Inventory::setItem
** Function that pushes an item into inventory.
*********************************************************************/
void Inventory::setItem(Items* item)
{
	list.push_back(item);
}

/*********************************************************************
** Inventory::getItem
** Function that retrieves item from inventory at a specific location.
*********************************************************************/
Items * Inventory::getItem(int i) const { return list[i]; }

/*********************************************************************
** Inventory::displayInv
** Function that displays inventory of the user.
*********************************************************************/
void Inventory::displayInv()
{

	std::cout << "	| Inventory |" << std::endl;
	if (list.size() == 0)
		std::cout << "Inventory is empty." << std::endl;
	for (int i = 0, s = list.size(); i < s; i++)
	{
		std::cout << "[" << list[i]->getName() << "]";
	}
	std::cout << std::endl << std::endl;
}

/*********************************************************************
** Inventory::displayInv
** Function that searches inventory of user to see if they have an
** item.
*********************************************************************/
bool Inventory::searchInventory(Items *item)
{
	// search string names
	std::string temp;

	for (int i = 0, s = list.size(); i < s; i++)
		if (list[i]->getName() == item->getName())
			temp = list[i]->getName();

	if (temp == item->getName())
		return true;

	else
		return false;
}
