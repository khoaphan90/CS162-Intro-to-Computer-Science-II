/********************************************************************
** Program name : room.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for room.cpp
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP

enum DIRECTION { NORTH, EAST, SOUTH, WEST, NA };

#include "player.hpp"
#include "stdlib.h"

class Room
{
protected:
	struct Door
	{
		Room *roomPtr;
		bool locked = true;
	};
	bool powerStatus = false;
	bool spikeLock = true;
	bool zombieLock = true;
	bool escape = false;

	Door dNorth;
	Door dSouth;
	Door dEast;
	Door dWest;

	Room *currentRoom;

	Player *p;

	Items *key;

	char pNorth = 0;
	char pEast = 0;
	char pSouth = 0;
	char pWest = 0;

	int rows;
	int cols;
	char **map;
public:
	Room();
	virtual ~Room();
	Room(Player*);
	void setPlayer(Player*);
	Player* getPlayer();

	void setPNorth();
	void setPEast();
	void setPSouth();
	void setPWest();

	void control();
	virtual void interact();
	int getRows();
	int getCols();
	void printRoom();
	void setRoom(Room*);
	Room* getRoom() const;
	int traverseRoom();
	void setPowerStatus(bool);
	void setSpikeLock(bool);
	void setZombieLock(bool);
	virtual void printMessage();
	virtual void action() = 0;
	virtual void createDoors() = 0;
	virtual void setConnectedRooms(Room*, Room*, Room*, Room*) = 0;
};
#endif