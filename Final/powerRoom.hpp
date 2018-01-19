/********************************************************************
** Program name : powerRoom.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for powerRoom.cpp
*********************************************************************/
#ifndef POWERROOM_HPP
#define POWERROOM_HPP

#include <vector>
#include "room.hpp"
#include "battery.hpp"

class PowerRoom : public Room
{
private:
	char power = 'S';
	bool powerOn = false;
	std::vector<Battery*> bList;
public:
	PowerRoom(Player*);
	~PowerRoom();
	void printMessage();
	void interact();
	void action();
	void setComponents();
	void createDoors();
	void setConnectedRooms(Room*, Room*, Room*, Room*);
};
#endif // !POWERROOM_HPP
