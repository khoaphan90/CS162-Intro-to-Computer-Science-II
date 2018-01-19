/********************************************************************
** Program name : battery.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for battery.cpp
*********************************************************************/
#ifndef BATTERY_HPP
#define BATTERY_HPP

#include "items.hpp"

class Battery : public Items
{
protected:
	bool have = false;
public:
	Battery();
	void setIcon() { item = 'B'; }
	char getItem();
	int use();
};
#endif