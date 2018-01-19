/********************************************************************
** Program name : wrench.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for wrench.cpp
*********************************************************************/
#ifndef WRENCH_HPP
#define WRENCH_HPP

#include "items.hpp"

class Wrench : public Items
{
protected:
	bool have = false;
public:
	Wrench();
	void setIcon() { item = 'W'; }
	char getItem();
	int use();
};
#endif
