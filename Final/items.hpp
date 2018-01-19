/********************************************************************
** Program name : items.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for items.cpp
*********************************************************************/
#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>

class Items
{
protected:
	std::string name;
	char item;
	bool have = false;
public:
	virtual ~Items();
	void setName(std::string);
	std::string getName();
	virtual void setHave(bool);
	virtual bool getHave() const;
	virtual char getItem() = 0;
	virtual int use() = 0;
};
#endif