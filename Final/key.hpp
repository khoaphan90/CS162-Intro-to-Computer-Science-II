/********************************************************************
** Program name : key.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for key.cpp
*********************************************************************/
#ifndef KEY_HPP
#define KEY_HPP

#include "items.hpp"

class Key : public Items
{
protected:
	bool have = false;
public:
	Key();
	void setIcon() { item = 'K'; }
	char getItem();
	int use();
};
#endif
