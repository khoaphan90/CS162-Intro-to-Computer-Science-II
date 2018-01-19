/********************************************************************
** Program name : inventory.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for inventory.cpp
*********************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>
#include "items.hpp"

class Inventory
{
protected:
	std::vector<Items*> list;
public:
	void setItem(Items*);
	Items* getItem(int) const;
	void displayInv();
	bool searchInventory(Items*);
};
#endif
