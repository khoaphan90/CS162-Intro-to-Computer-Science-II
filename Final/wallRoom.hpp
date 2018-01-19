/********************************************************************
** Program name : wallRoom.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for wallRoom.cpp
*********************************************************************/
#ifndef WALLROOM_HPP
#define WALLROOM_HPP

#include "room.hpp"

class WallRoom : public Room
{
private:
	char wall = '|';
	int moveRight = 0;
	int moveLeft = 29;
public:
	WallRoom(Player*);
	~WallRoom();
	void printMessage();
	void interact();
	void action();
	void setComponents();
	void createDoors();
	void setConnectedRooms(Room*, Room*, Room*, Room*);
};
#endif // !POWERROOM_HPP