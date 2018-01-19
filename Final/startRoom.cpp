/*********************************************************************
** Program name: startRoom.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived
** class startRoom.
*********************************************************************/
#include <iostream>
#include "startRoom.hpp"

/*********************************************************************
** StartRoom::StartRoom
** Default constructor class that generates walls and creates items.
*********************************************************************/
StartRoom::StartRoom(Player* player)
{
	p = player;
	map[7][15] = p->getIcon();
	p->setX(15);
	p->setY(7);

	//// horizontal walls
	//for (int i = 8; i < 22; i++)
	//	map[11][i] = '#';
	//for (int i = 8; i < 22; i++)
	//	map[4][i] = '#';

	//// vertical walls
	//for (int i = 4; i < 7; i++)
	//	map[i][7] = '#';
	//for (int i = 9; i < 12; i++)
	//	map[i][7] = '#';
}

/*********************************************************************
** StartRoom::~StartRoom
** Destructor that deallocates created items
*********************************************************************/
StartRoom::~StartRoom()
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;
}

/*********************************************************************
** StartRoom::printMessage
** Function that prints out information for user about the room.
*********************************************************************/
void StartRoom::printMessage()
{
	std::cout << "\n  It's dimly lit, but we should\n"
		<< "     explore this room.\n\n";
}

/*********************************************************************
** StartRoom::interact
** Function that allows user to interact with objects
*********************************************************************/
void StartRoom::interact()
{
	if ((pEast == '|') || (pWest == '|'))
		std::cout << "This door is locked.\n" << std::endl;
	if (pNorth == '-')
		if (zombieLock == false)
		{
			std::cout << "You opened the door using the ["
				"KEY]!\n\n";
		}
		else
			std::cout << "This door is locked.\n" << std::endl;
}

/*********************************************************************
** StartRoom::createDoors
** Function that creates the set of doors for the room.
*********************************************************************/
void StartRoom::createDoors()
{
	// set starting user location
	map[p->getY()][p->getX()] = p->getIcon();

	// north doors
	dNorth.locked = true;
	if (zombieLock == false)
	{
		map[0][(cols / 2)] = 0;
		map[0][(cols / 2) - 1] = 0;
	}
	else
	{
		map[0][(cols / 2) - 1] = '-';
		map[0][(cols / 2)] = '-';
	}
	map[0][(cols / 2) + 1] = '+';
	map[0][(cols / 2) - 2] = '+';

	// west doors
	map[(rows / 2) + 1][0] = '+';
	map[(rows / 2) - 1][0] = '+';
	if (spikeLock == false)
 		map[(rows / 2)][0] = 0;
 	else
 		map[(rows / 2)][0] = '|';

	// south doors
	dSouth.locked = true;
	map[rows - 1][(cols / 2) + 1] = '+';
	map[rows - 1][(cols / 2) - 2] = '+';

	// east doors
	map[(rows / 2) + 1][cols - 1] = '+';
	map[(rows / 2) - 1][cols - 1] = '+';
	if (powerStatus == true)
		map[(rows / 2)][cols - 1] = 0;
	else
		map[(rows / 2)][cols - 1] = '|';
}

/*********************************************************************
** StartRoom::setConnectedRooms
** Function that sets the connecting rooms to this room.
*********************************************************************/
void StartRoom::setConnectedRooms(Room *n, Room *e, Room *s, Room *w)
{
	dNorth.roomPtr = n;
	dEast.roomPtr = e;
	dSouth.roomPtr = s;
	dWest.roomPtr = w;
}

/*********************************************************************
** StartRoom::action
** Function that calls any actions that the room has.
*********************************************************************/
void StartRoom::action()
{

}