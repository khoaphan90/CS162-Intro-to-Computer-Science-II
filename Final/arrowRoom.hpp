/********************************************************************
** Program name : arrowRoom.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for arrowRoom.cpp
*********************************************************************/
#ifndef ARROWROOM_HPP
#define ARROWROOM_HPP

#include "room.hpp"
#include "items.hpp"
#include <vector>

class ArrowRoom : public Room
{
private:
	struct Arrow
	{
		bool exist = true;
		char block = 'A';
		char aBack = '|';
		int aX;
		int aY;
	};
	std::vector<Arrow*> aList;
	Items *wrench;
	int machines = 4;
public:
	ArrowRoom(Player*);
	~ArrowRoom();
	void printMessage();
	bool destroyMachine(Arrow*);
	void shootArrowsDown(int, int&, int);
	void shootArrowsUp(int, int&, int);
	void takeDamage(int, int&, int);
	void interact();
	void action();
	void setComponents();
	void createDoors();
	void setConnectedRooms(Room*, Room*, Room*, Room*);
};
#endif // !ARROWROOM_HPP
