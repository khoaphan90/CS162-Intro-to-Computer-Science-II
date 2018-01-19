/*********************************************************************
** Program name: game.cpp for Project 3
** Author: Khoa Phan
** Date: May 10, 2017
** Description: This class holds the functions for game.cpp and is
** used to allow the game to function.
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "game.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "blue_men.hpp"
#include "medusa.hpp"
#include "harry_potter.hpp"
#include "menu.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** Game::setPlayer
** Function that sets the player's creature choices and determines
** fighting order.
*********************************************************************/
void Game::setPlayer()
{
	// call Menu to display creature types
	Menu a;
	for (int i = 0; i < 2; i++)
	{
			switch (a.typeMenu())
			{
			case VAMPIRE:
			{
				Creature* vamp = new Vampire;
				c.push_back(vamp);
				c[i]->setType("Vampire");
				break;
			}
			case BARBARIAN:
			{
				Creature* barb = new Barbarian;
				c.push_back(barb);
				c[i]->setType("Barbarian");
				break;
			}
			case BLUE_MEN:
			{
				Creature* bmen = new Blue_Men;
				c.push_back(bmen);
				c[i]->setType("Blue Men");
				break;
			}
			case MEDUSA:
			{
				Creature* med = new Medusa;
				c.push_back(med);
				c[i]->setType("Medusa");
				break;
			}
			case HARRY_POTTER:
			{
				Creature* hp = new Harry_Potter;
				c.push_back(hp);
				c[i]->setType("Harry Potter");
				break;
			}
			default:
				break;
		}
	}

	// randomly choose starting order
	int i = rand() % 2;
	if (i == 0)
	{
		c[0]->setPosition(ATTACK);
		c[1]->setPosition(DEFEND);
	}
	else
	{
		c[1]->setPosition(ATTACK);
		c[0]->setPosition(DEFEND);
	}
}

/*********************************************************************
** Game::playGame
** Function that starts and ends the game.
*********************************************************************/
bool Game::playGame()
{
	// variables initilization
	srand(time(NULL));
	char again = 'Y';

	// loop to determine if play again
	while (toupper(again) == 'Y')
	{
		// sets player creatures
		setPlayer();

		// loop until strPt = 0
		do
		{
			displayUI();
			playRound();
			cin.ignore();
			round++;

		} while (win == false);
		winner();

		// deallocate Creature vector
		for (int i = 0, s = c.size(); i < s; i++)
			delete c[i];
		c.clear();

		cin.clear();

		// prompt if playing again
		cout << "Would you like to play again? Y/N " << endl;
		again = checkChar(); // char validation
		cin.ignore();
	}
	return false;
}

/*********************************************************************
** Game::displayUI
** Function that prints out the UI with creature strength points
** round number and player ID.
*********************************************************************/
void Game::displayUI()
{
	cout << "+-----------------------------------------+\n";
	cout << "                 Round: " << round << endl;
	cout << "+-----------------------------------------+\n";
	cout << "Player 1:          --   Player 2:  " << endl
		<< "[" << c[0]->getType() << "][" << c[0]->getSP()
		<< "]   vs   [" << c[1]->getType() << "]["
		<< c[1]->getSP() << "]" << endl;
	cout << "+-----------------------------------------+\n";
}

/*********************************************************************
** Game::playRound
** Function that initiates a fight between the two creatures.
*********************************************************************/
void Game::playRound() 
{
	// determines which player is attacking or defending
	if (c[0]->getPosition() == ATTACK)
	{
		cout << "Player 1 " << endl;
		c[1]->defend(c[0]->attack());
		c[1]->setPosition(ATTACK);
		c[0]->setPosition(DEFEND);
	}

	else
	{
		cout << "Player 2 " << endl;
		c[0]->defend(c[1]->attack());
		c[0]->setPosition(ATTACK);
		c[1]->setPosition(DEFEND);
	}

	// check to see if any Creature strPt = 0
	win = gameStatus();
}


/*********************************************************************
** Game::gameStatus
** Function that determines if the game has ended or continues.
*********************************************************************/
bool Game::gameStatus()
{
	// check to see if any Creature strPt = 0
		if (c[0]->getSP() <= 0)
		{
			pWin = 2;
			return true;
		}
		if (c[1]->getSP() <= 0)
		{
			pWin = 1;
			return true;
		}
		else
			return false;
}

/*********************************************************************
** Game::winner
** Function that prints out the winner along with the type of
** creature they were using.
*********************************************************************/
void Game::winner()
{
	for (int i = 0; i < 2; i++)
		if (c[i]->getSP() >= 0)
		{
			cout << "\n\nThe winner is Player "
				<< pWin << " using "
				<< c[i]->getType()
				<< endl << endl;
			break;
		}
}