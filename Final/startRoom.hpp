/********************************************************************
** Program name : startRoom.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for startRoom.cpp
*********************************************************************/
#ifndef STARTROOM_HPP
#define STARTROOM_HPP

#include "room.hpp"
#include "items.hpp"

class StartRoom : public Room
{
private:
	char components;
public:
	StartRoom(Player*);
	~StartRoom();
	void printMessage();
	void action();
	void setConnectedRooms(Room*, Room*, Room*, Room*);
	void createDoors();
	void interact();
};
#endif // !STARTROOM_HPP
