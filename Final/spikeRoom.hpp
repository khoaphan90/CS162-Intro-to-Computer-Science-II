/********************************************************************
** Program name : spikeRoom.hpp for Final Project
** Author : Khoa Phan
** Date : June 10, 2017
* * Description : Header file for spikeRoom.cpp
*********************************************************************/
#ifndef SPIKEROOM_HPP
#define SPIKEROOM_HPP

#include "room.hpp"

class SpikeRoom : public Room
{
private:
	struct Spike
	{
		char sIcon = '^';
		bool spikeRaise = false;
		int spikeDelay = 0;
	};
	Spike spike1;
	Spike spike2;
	Items *crowbar;
public:
	SpikeRoom(Player*);
	~SpikeRoom();
	void printMessage();
	void raiseSpikes();
	void takeDamage();
	void interact();
	void action();
	void setComponents();
	void createDoors();
	void setConnectedRooms(Room*, Room*, Room*, Room*);
};
#endif // !ARROWROOM_HPP
