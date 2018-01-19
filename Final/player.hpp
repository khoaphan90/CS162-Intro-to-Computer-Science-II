/********************************************************************
** Program name : player.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for player.cpp
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "inventory.hpp"
#include "items.hpp"

class Player
{
protected:
	char icon = '0';
	int y;
	int x;
	int energy = 1500;
	bool hasEscaped = false;
	Inventory inv;
public:
	void addInventory(Items*);
	Inventory getInventory() const;
	void setEscape(bool);
	bool getEscape() const;
	void setY(int);
	void setX(int);
	int getY() const;
	int getX() const;
	void setStepCount(int);
	int getStepCount() const;
	char getIcon();
	void fatigue();
};
#endif
