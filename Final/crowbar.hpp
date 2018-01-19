/********************************************************************
** Program name : crowbar.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for crowbar.cpp
*********************************************************************/
#ifndef CROWBAR_HPP
#define CROWBAR_HPP

#include "items.hpp"

class Crowbar : public Items
{
protected:
	bool have = false;
public:
	Crowbar();
	void setIcon() { item = '7'; }
	char getItem();
	int use();
};
#endif // !CROWBAR_HPP
