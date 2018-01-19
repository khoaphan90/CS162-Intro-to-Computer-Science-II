/*********************************************************************
** Program name: zombieRoom.cpp for Final Project
** Author: Khoa Phan
** Date: June 10, 2017
** Description: This file holds the functions for the derived
** class zombieRoom.
*********************************************************************/
#include <iostream>
#include "zombieRoom.hpp"
#include "zombie.hpp"

Zombie::Zombie(){}

/*********************************************************************
** ZombieRoom::ZombieRoom
** Default constructor class that generates walls and creates items.
*********************************************************************/
ZombieRoom::ZombieRoom(Player* player)
{
	// create new zombies and switches
	for (int i = 0; i < 4; i++)
		zList.push_back(new Zombie);
	zList[3]->setArmor();

	for (int i = 0; i < 4; i++)
		sList.push_back(new Switch);

	// set player
	p = player;

	// create walls
	for (int i = 0; i <= 14; i++) map[i][0] = '#';
	for (int i = 0; i <= 14; i++) map[i][29] = '#';
	for (int i = 1; i <= 12; i++) map[0][i] = '#';
	for (int i = 17; i <= 28; i++) map[0][i] = '#';
	for (int i = 1; i <= 12; i++) map[14][i] = '#';
	for (int i = 17; i <= 28; i++) map[14][i] = '#';

	for (int i = 3; i <= 5; i++) map[i][6] = '#';
	for (int i = 9; i <= 11; i++) map[i][6] = '#';
	for (int i = 3; i <= 5; i++) map[i][7] = '#';
	for (int i = 9; i <= 11; i++) map[i][7] = '#';
	for (int i = 3; i <= 5; i++) map[i][8] = '#';
	for (int i = 9; i <= 11; i++) map[i][8] = '#';

	for (int i = 3; i <= 5; i++) map[i][21] = '#';
	for (int i = 9; i <= 11; i++) map[i][21] = '#';
	for (int i = 3; i <= 5; i++) map[i][22] = '#';
	for (int i = 9; i <= 11; i++) map[i][22] = '#';
	for (int i = 3; i <= 5; i++) map[i][23] = '#';
	for (int i = 9; i <= 11; i++) map[i][23] = '#';

	setComponents();
}

/*********************************************************************
** ZombieRoom::~ZombieRoom
** Function that deallocates the created items.
*********************************************************************/
ZombieRoom::~ZombieRoom()
{
	for (int i = 0; i < rows; i++)
		delete[] map[i];
	delete[] map;
	map = NULL;

	for (int i = 0; i < 4; i++)
		delete zList[i];

	for (int i = 0; i < 4; i++)
		delete sList[i];
}

/*********************************************************************
** ZombieRoom::printMessage
** Function that prints out information for user about the room.
*********************************************************************/
void ZombieRoom::printMessage()
{
	std::cout << "    Zombies wander the room!\n"
		<< "  We should need to avoid them!\n";
}

/*********************************************************************
** ZombieRoom::interact
** Function that allows user to interact with objects
*********************************************************************/
void ZombieRoom::interact()
{
	// check switch status
	if (map != 0)
	{
		if ((pNorth == 's') || (pEast == 's') ||
			(pSouth == 's') || (pWest == 's'))
		{
			if (sList[0]->isOn == false && 
				map[p->getY()][p->getX()] == map[4][5])
			{
				std::cout << "     A switch is turned on.\n" << std::endl;
				sList[0]->isOn = true;
				switches++;
			}
			else if (sList[1]->isOn == false &&
				map[p->getY()][p->getX()] == map[10][5])
			{
				std::cout << "     A switch is turned on.\n" << std::endl;
				sList[1]->isOn = true;
				switches++;
			}
			else if (sList[2]->isOn == false &&
				map[p->getY()][p->getX()] == map[4][24])
			{
				std::cout << "     A switch is turned on.\n" << std::endl;
				sList[2]->isOn = true;
				switches++;
			}
			else if (sList[3]->isOn == false &&
				map[p->getY()][p->getX()] == map[10][24])
			{
				std::cout << "     A switch is turned on.\n" << std::endl;
				sList[3]->isOn = true;
				switches++;
			}
			else
				std::cout << "Already flipped this switch...\n" << std::endl;
		}
		if (switches == 4)
		{
			std::cout << "       The doors unlocked!\n"
				<< "      Lets get out of here!\n" << std::endl;
			map[0][14] = 0;
			map[0][15] = 0;
		}
	}
}

/*********************************************************************
** ZombieRoom::setComponents
** Function that sets any objects needed to complete room puzzle.
*********************************************************************/
void ZombieRoom::setComponents()
{
	// set zombie starting locations
	zList[0]->setZY(6);
	zList[0]->setZX(5);

	zList[1]->setZY(4);
	zList[1]->setZX(27);

	zList[2]->setZY(12);
	zList[2]->setZX(5);

	zList[3]->setZY(10);
	zList[3]->setZX(25);
	
	// spawn zombies
	for (int i = 0; i < 4; i++)
		map[zList[i]->getZY()][zList[i]->getZX()]
		= zList[i]->getZombie();

	// spawn switches
	map[4][6] = sList[0]->sIcon;
	map[10][6] = sList[1]->sIcon;
	map[4][23] = sList[2]->sIcon;
	map[10][23] = sList[3]->sIcon;
}

/*********************************************************************
** ZombieRoom::createDoors
** Function that creates the set of doors for the room.
*********************************************************************/
void ZombieRoom::createDoors()
{
	// north doors
	map[0][(cols / 2) + 1] = '+';
	map[0][(cols / 2) - 2] = '+';

	// south doors
	map[rows - 1][(cols / 2) + 1] = '+';
	map[rows - 1][(cols / 2) - 2] = '+';

	// create locked door
	map[0][14] = '-';
	map[0][15] = '-';
}

/*********************************************************************
** ZombieRoom::setConnectedRooms
** Function that sets the connecting rooms to this room.
*********************************************************************/
void ZombieRoom::setConnectedRooms(Room *n, Room *e, Room *s, Room *w)
{
	dNorth.roomPtr = n;
	dEast.roomPtr = 0;
	dSouth.roomPtr = s;
	dWest.roomPtr = 0;
}

/*********************************************************************
** ZombieRoom::action
** Function that calls any actions that the room has.
*********************************************************************/
void ZombieRoom::action()
{
	moveZombie();
	if ((pNorth == 'Z') || (pEast == 'Z') || (pSouth == 'Z') || (pWest == 'Z'))
	{
		std::cout << "      The zombie hits you!\n"
			<< "   Your energy has depleted.\n\n";
		p->setStepCount(p->getStepCount() - 10);
	}
}

/*********************************************************************
** ZombieRoom::moveZombie
** Function that moves the zombies randomly around the room.
*********************************************************************/
void ZombieRoom::moveZombie()
{
	for (int i = 0; i < 4; i++)
	{
		// randomize zombie movement
		int random = rand() % 4;

		if (zList[i]->zombieExist())
		{
			// move zombie up
			if (random == 0)
			{
				if (map[zList[i]->getZY() - 1][zList[i]->getZX()] == 0)
				{
					map[zList[i]->getZY()][zList[i]->getZX()] = 0;
					map[zList[i]->getZY() - 1][zList[i]->getZX()]
						= zList[i]->getZombie();
					zList[i]->setZY(zList[i]->getZY() - 1);
				}
			}

			// move zombie right
			else if (random == 1)
			{
				if (map[zList[i]->getZY()][zList[i]->getZX() + 1] == 0)
				{
					map[zList[i]->getZY()][zList[i]->getZX()] = 0;
					map[zList[i]->getZY()][zList[i]->getZX() + 1]
						= zList[i]->getZombie();
					zList[i]->setZX(zList[i]->getZX() + 1);
				}
			}

			// move zombie down
			else if (random == 2)
			{
				if (map[zList[i]->getZY() + 1][zList[i]->getZX()] == 0)
				{
					map[zList[i]->getZY()][zList[i]->getZX()] = 0;
					map[zList[i]->getZY() + 1][zList[i]->getZX()]
						= zList[i]->getZombie();
					zList[i]->setZY(zList[i]->getZY() + 1);
				}
			}

			// move zombie left
			else if (random == 3)
			{
				if (map[zList[i]->getZY()][zList[i]->getZX() - 1] == 0)
				{
					map[zList[i]->getZY()][zList[i]->getZX()] = 0;
					map[zList[i]->getZY()][zList[i]->getZX() - 1]
						= zList[i]->getZombie();
					zList[i]->setZX(zList[i]->getZX() - 1);
				}
			}
		}
	}
}