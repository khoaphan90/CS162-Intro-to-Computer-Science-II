/*********************************************************************
** Program name: powerRoom.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds a derived class powerRoom.
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include "powerRoom.hpp"
#include "battery.hpp"

/*********************************************************************
** PowerRoom::PowerRoom
** Default constructor that generates walls and creates items.
*********************************************************************/
PowerRoom::PowerRoom(Player* player)
{
	// create new batteries
	for (int i = 0; i < 4; i++)
		bList.push_back(new Battery);
	bList[3]->setName("BATTERY");

	// set player and items
	p = player;
	setComponents();

	// create horizontal walls
	for (int i = 11; i < 22; i++) map[5][i] = '#';
	for (int i = 8; i < 22; i++) map[6][i] = '#';
	for (int i = 8; i < 22; i++) map[7][i] = '#';
	for (int i = 8; i < 22; i++) map[9][i] = '#';
	for (int i = 8; i < 22; i++) map[10][i] = '#';
	for (int i = 8; i < 22; i++) map[11][i] = '#';

	// vertical walls
	//for (int i = 4; i < 14; i++)
		//map[i][7] = '#';
}

/*********************************************************************
** PowerRoom::~PowerRoom
** Function that deallocates the created items.
*********************************************************************/
PowerRoom::~PowerRoom()
{
	for (int i = 0; i < 4; i++)
		delete bList[i];

	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;
}

/*********************************************************************
** PowerRoom::printMessage
** Function that prints out information for user about the room.
*********************************************************************/
void PowerRoom::printMessage()
{
	std::cout << " This looks like a power room.\n"
		<< " Lets see if we can find a way\n "
		<< " to turn on the power.\n";
}

/*********************************************************************
** PowerRoom::setComponents
** Function that sets any objects needed to complete room puzzle.
*********************************************************************/
void PowerRoom::setComponents()
{
	// set battery insert locations
	map[5][8] = '[';
	map[5][9] = '-';
	map[5][10] = ']';

	// insert batteries
	map[0][0] = bList[0]->getItem();
	map[0][29] = bList[1]->getItem();
	map[14][0] = bList[2]->getItem();
	map[14][29] = bList[3]->getItem();

	// create walls for batteries
	map[13][0] = '#';
	map[1][29] = '#';
	map[14][28] = '#';
	map[0][1] = '#';

	// set power location
	map[8][15] = power;
}

/*********************************************************************
** PowerRoom::createDoors
** Function that creates the set of doors for the room.
*********************************************************************/
void PowerRoom::createDoors()
{
	map[8][8] = '|';
	map[8][21] = '|';
	map[0][(cols / 2) + 1] = '+';
	map[0][(cols / 2) - 2] = '+';
}

/*********************************************************************
** PowerRoom::setConnectedRooms
** Function that sets the connecting rooms to this room.
*********************************************************************/
void PowerRoom::setConnectedRooms(Room *n, Room *e, Room *w, Room *s)
{
	dNorth.roomPtr = n;
	dEast.roomPtr = 0;
	dSouth.roomPtr = 0;
	dWest.roomPtr = 0;
}

/*********************************************************************
** PowerRoom::interact
** Function that allows user to interact with objects
*********************************************************************/
void PowerRoom::interact()
{
	// check if for power switch
	if (map != 0)
	{
		if (pNorth == power || pEast == power ||
			pSouth == power || pWest == power)
		{
			if (powerStatus == false)
			{
				powerStatus = true;
				dNorth.roomPtr->setPowerStatus(true);
				std::cout << "The light flickers and a loud click"
					<< "\nis heard in the other room..." << std::endl;
			}
			else
				std::cout << "The switch has already been flipped..." << std::endl;
		}
		// check for batteries
		if (pNorth == 'B' || pEast == 'B' || pSouth == 'B' || pWest == 'B')
		{
			if (pNorth == 'B')
			{
				std::cout << "You picked up a [" << bList[0]->getName() << "].\n\n";
				p->addInventory(bList[0]);
				map[0][0] = 0;
			}
			if (pEast == 'B')
			{
				std::cout << "You picked up a [" << bList[1]->getName() << "].\n\n";
				p->addInventory(bList[1]);
				map[0][29] = 0;
			}
			if (pSouth == 'B')
			{
				std::cout << "You picked up a [" << bList[3]->getName() << "].\n\n";
				p->addInventory(bList[3]);
				map[14][29] = 0;
			}
			if (pWest == 'B')
			{
				std::cout << "You picked up a [" << bList[2]->getName() << "].\n\n";
				p->addInventory(bList[2]);
				map[14][0] = 0;
			}
		}
		// check for battery location
		if (pNorth == '-' || pEast == '-' || pSouth == '-' || pWest == '-')
		{
			if (p->getInventory().searchInventory(bList[3]) == true)
			{
				bList[3]->use();
				std::cout << "  A loud clang is heard!\n";
				map[8][8] = 0;
				map[8][21] = 0;
			}
			else if (p->getInventory().searchInventory(bList[0]) == true)
				std::cout << "[" << bList[0]->getName() << "] has no charge...\n\n";
			else if (p->getInventory().searchInventory(bList[1]) == true)
				std::cout << "[" << bList[1]->getName() << "] has no charge...\n\n";
			else if (p->getInventory().searchInventory(bList[2]) == true)
				std::cout << "[" << bList[2]->getName() << "] has no charge...\n\n";
			else
				std::cout << "Looks like a spot for a battery.\n\n";
		}
	}
}

/*********************************************************************
** PowerRoom::action
** Function that calls any actions that the room has.
*********************************************************************/
void PowerRoom::action()
{

}