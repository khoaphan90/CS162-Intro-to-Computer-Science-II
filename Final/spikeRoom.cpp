/*********************************************************************
** Program name: room.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived class 
** spikeRoom.
*********************************************************************/
#include <iostream>
#include "spikeRoom.hpp"
#include "crowbar.hpp"
#include "key.hpp"

/*********************************************************************
** SpikeRoom::SpikeRoom
** Default constructor class that generates walls and creates items.
*********************************************************************/
SpikeRoom::SpikeRoom(Player* player)
{
	// create new crowbar and key
	crowbar = new Crowbar;
	key = new Key;

	// set player 
	p = player;

	// vertical walls
	for (int i = 3; i < 12; i++) map[i][4] = '#';
	for (int i = 8; i < 12; i++) map[i][8] = '#';
	for (int i = 0; i < 6; i++) map[i][12] = '#';
	for (int i = 0; i < 6; i++) map[i][13] = '#';
	for (int i = 0; i < 6; i++) map[i][14] = '#';
	for (int i = 5; i < 6; i++) map[i][15] = '#';
	for (int i = 5; i < 6; i++) map[i][16] = '#';
	for (int i = 5; i < 6; i++) map[i][20] = '#';
	for (int i = 5; i < 6; i++) map[i][21] = '#';
	for (int i = 3; i < 12; i++) map[i][22] = '#';
	for (int i = 3; i < 12; i++) map[i][23] = '#';
	
	// horizontal walls
	for (int i = 4; i < 12; i++) map[2][i] = '#';
	for (int i = 4; i < 12; i++) map[3][i] = '#';
	for (int i = 8; i < 30; i++) map[10][i] = '#';
	for (int i = 15; i < 25; i++) map[13][i] = '#';
	for (int i = 28; i < 30; i++) map[14][i] = '#';
	setComponents();
}

/*********************************************************************
** SpikeRoom::~SpikeRoom
** Function that deallocates the created items.
*********************************************************************/
SpikeRoom::~SpikeRoom()
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;

	delete crowbar;
	delete key;
}

/*********************************************************************
** SpikeRoom::printMessage
** Function that prints out information for user about the room.
*********************************************************************/
void SpikeRoom::printMessage()
{
	std::cout << " It looks like those spikes are\n"
		<< "   dangerous. Better not go\n"
		<< "     anywhere near them.\n";
}

/*********************************************************************
** SpikeRoom::interact
** Function that allows user to interact with objects
*********************************************************************/
void SpikeRoom::interact()
{
	// interact with the map
	if (map != 0)
	{
		// check if there is a crowbar next to user
		if ((pNorth == '7') || (pEast == '7') || (pSouth == '7') || (pWest == '7'))
		{
			std::cout << "   You picked up a [" << crowbar->getName() << "].\n\n";
			{
				crowbar->setHave(true);
				p->addInventory(crowbar);
				std::cout << " A small clink is heard in the\n"
					<< " distance. Should go investigate\n"
					<< "        what that was.\n\n" << std::endl;
				map[13][28] = key->getItem();
			}
			// remove crowbar from ground
			map[1][10] = 0;
		}
		// check if there is a key next to user
		if ((pNorth == 'K') || (pEast == 'K') || (pSouth == 'K') || (pWest == 'K'))
		{
			std::cout << "    You picked up a [" << key->getName()
				<< "]!\n Lets see if it works on a door.\n\n";
			{
				key->setHave(true);
				p->addInventory(key);
				dEast.roomPtr->setZombieLock(false);
			}
			// remove key from ground
			map[13][28] = 0;
		}
	}
}

/*********************************************************************
** SpikeRoom::setComponents
** Function that sets any objects needed to complete room puzzle.
*********************************************************************/
void SpikeRoom::setComponents()
{
	// crowbar location
	map[1][10] = crowbar->getItem();
	
	//set spikes to alternate
	spike2.spikeRaise = true;
}

/*********************************************************************
** SpikeRoom::createDoors
** Function that creates the set of doors for the room.
*********************************************************************/
void SpikeRoom::createDoors()
{
	map[(rows / 2) + 1][cols - 1] = '+';
	map[(rows / 2) - 1][cols - 1] = '+';
}

/*********************************************************************
** SpikeRoom::setConnectedRooms
** Function that sets the connecting rooms to this room.
*********************************************************************/
void SpikeRoom::setConnectedRooms(Room *n, Room *e, Room *s, Room *w)
{
	dNorth.roomPtr = 0;
	dEast.roomPtr = e;
	dSouth.roomPtr = 0;
	dWest.roomPtr = 0;
}

/*********************************************************************
** SpikeRoom::action
** Function that calls any actions that the room has.
*********************************************************************/
void SpikeRoom::action()
{
	raiseSpikes();
	takeDamage();

	if ((spike1.spikeRaise == false) && (spike1.spikeDelay == 4))
	{
		spike1.spikeRaise = true;
		spike1.spikeDelay = 0;
	}
	else
	{
		spike1.spikeRaise = false;
		spike1.spikeDelay++;
	}

	if ((spike2.spikeRaise == false) && (spike2.spikeDelay == 5))
	{
		spike2.spikeRaise = true;
		spike2.spikeDelay = 0;
	}
	else
	{
		spike2.spikeRaise = false;
		spike2.spikeDelay++;
	}
}

/*********************************************************************
** SpikeRoom::raiseSpikes
** Function that controls the spikes up or down.
*********************************************************************/
void SpikeRoom::raiseSpikes()
{
	if (spike1.spikeRaise == true)
	{
		for (int i = 15; i <= 21; i++)
			map[4][i] = spike1.sIcon;
		for (int i = 0; i <= 3; i++)
			map[2][i] = spike1.sIcon;
		for (int i = 0; i <= 3; i++)
			map[10][i] = spike1.sIcon;
	}
	else // drop spikes
	{
		for (int i = 15; i <= 21; i++)
			map[4][i] = 0;
		for (int i = 0; i <= 3; i++)
			map[2][i] = 0;	
		for (int i = 0; i <= 3; i++)
			map[10][i] = 0;	
	}

	if (spike2.spikeRaise == true)
	{
		for (int i = 6; i <= 9; i++)
			map[i][14] = spike1.sIcon;
		for (int i = 4; i <= 7; i++)
			map[i][8] = spike1.sIcon;
		for (int i = 11; i <= 14; i++)
			map[i][12] = spike1.sIcon;	
	}
	else // drop spikes
	{
		for (int i = 6; i <= 9; i++)
			map[i][14] = 0;
		for (int i = 4; i <= 7; i++)
			map[i][8] = 0;	
		for (int i = 11; i <= 14; i++)
			map[i][12] = 0;	
	}
}

/*********************************************************************
** SpikeRoom::takeDamage
** Function that reduces user energy if a spike is near them.
*********************************************************************/
void SpikeRoom::takeDamage()
{
	// check if step on spikes
	if ((pNorth == '^') || (pEast == '^') || (pSouth == '^') || (pWest == '^'))
		if (((pNorth == '^') && (pEast != '^')) || ((pNorth == '^') && (pWest != '^')) ||
			((pSouth == '^') && (pEast != '^')) || ((pSouth == '^') && (pWest != '^')) ||
			((pEast == '^') && (pNorth != '^')) || ((pEast == '^') && (pSouth != '^')) ||
			((pWest == '^') && (pNorth != '^')) || ((pWest == '^') && (pSouth != '^')))
		{
			std::cout << "    You stepped on a spike...\n"
				<< "  Your energy has been reduced.\n\n";

			p->setStepCount((p->getStepCount() - 10));
		}
}