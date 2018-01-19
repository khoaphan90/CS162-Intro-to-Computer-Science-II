/*********************************************************************
** Program name: zombieRoom.hpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: Header file for zombieRoom.cpp
*********************************************************************/
#ifndef ZOMBIEROOM_HPP
#define ZOMBIEROOM_HPP

#include <vector>
#include "room.hpp"
#include "zombie.hpp"

class ZombieRoom : public Room
{
private:
	struct Switch
	{
		bool isOn = false;
		char sIcon = 's';
	};
	std::vector<Switch*> sList;
	std::vector<Zombie*> zList;

	int switches = 0; 

	char zNorth;
	char zEast;
	char zSouth;
	char zWest;

public:
	ZombieRoom(Player*);
	~ZombieRoom();
	void printMessage();
	void action();
	void interact();
	void setComponents();
	void createDoors();
	void setConnectedRooms(Room*, Room*, Room*, Room*);
	void moveZombie();
};
#endif // !ARROWROOM_HPP
