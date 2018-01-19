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

Game::~Game()
{
	//// deallocate Player vector
	//for (int i = 0, s = p.size(); i < s; i++)
	//	delete p[i];
}

/*********************************************************************
** Game::setPlayer
** Function that sets the player's creature choices and determines
** fighting order.
*********************************************************************/
void Game::setPlayer()
{
	// add creature to a queue

	int cAmt;
	cout << "Enter the amount of creatures per team: ";
	cAmt = checkInt();

	// call Menu to display creature types
	Menu a;

	// create players, ID: 0 = 1, 1 = 2;
	Player *one = new Player;
	Player *two = new Player;
	p.push_back(one);
	p.push_back(two);


	for (int i = 0; i < 2; i++)
	{
		cout << "\nSelect Player " << i + 1
			<< " creatures." << endl;
		for (int j = 0; j < cAmt; j++)
		{
			switch (a.typeMenu())
			{
			case VAMPIRE:
			{
				Creature* vamp = new Vampire;
				vamp->setName();
				p[i]->a.addBack(vamp);
				break;
			}
			case BARBARIAN:
			{
				Creature* barb = new Barbarian;
				barb->setName();
				p[i]->a.addBack(barb);
				break;
			}
			case BLUE_MEN:
			{
				Creature* bmen = new Blue_Men;
				bmen->setName();
				p[i]->a.addBack(bmen);
				break;
			}
			case MEDUSA:
			{
				Creature* med = new Medusa;
				med->setName();
				p[i]->a.addBack(med);
				break;
			}
			case HARRY_POTTER:
			{
				Creature* hp = new Harry_Potter;
				hp->setName();
				p[i]->a.addBack(hp);
				break;
			}
			default:
				break;
			}
		}
	}


	// randomly choose starting order
	int i = rand() % 2;
	if (i == 0)
	{
		//switch position to player turn
		p[0]->setPosition(ATTACK);
		p[1]->setPosition(DEFEND);
	}
	else
	{
		p[1]->setPosition(ATTACK);
		p[0]->setPosition(DEFEND);
	}
}

/*********************************************************************
** Game::playGame
** Function that starts and ends the game.
*********************************************************************/
bool Game::playGame()
{
	// variables initialization
	srand(time(NULL));
	char again = 'Y', display = 'Y';

	// loop to determine if play again
	while (toupper(again) == 'Y')
	{
		setPlayer();
		do
		{
			do
			{
				displayUI();
				playRound();
				cin.ignore();
			} while (winRnd == false);
			round++;
			win = winner();
		} while (win == false);

		// display options to see stack
		cout << "Would you like to see the list of"
			<< " defeated creatures? Y/N" << endl;
		display = checkChar();
		if (toupper(display) == 'Y')
			defeated.displayList();

		// prompt if playing again
		cout << "Would you like to play again? Y/N " << endl;
		again = checkChar(); // char validation
		cin.ignore();
	}

	delete p[0];
	delete p[1];

	cout << "\nThank you for playing!!" << endl;

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
}

/*********************************************************************
** Game::displayRound
** Function that prints out the UI with creature strength points
** round number and player ID.
*********************************************************************/
void Game::displayRound()
{
	cout << "+-----------------------------------------+\n";
	cout << "                 Round: " << round << endl;
	cout << "+-----------------------------------------+\n";
	cout << "     Team 1: " << p[0]->a.getFront()->getName() <<
		"    ||    Team 2: " << p[1]->a.getFront()->getName() << endl;
	cout << "+-----------------------------------------+\n";
}

/*********************************************************************
** Game::playRound
** Function that initiates a fight between the two creatures.
*********************************************************************/
void Game::playRound() 
{
	 //determines which player is attacking or defending
	if (p[0]->getPosition() == ATTACK)
	{
		cout << "Player 1 " << endl;
		p[1]->a.getFront()->defend(p[0]->a.getFront()->attack());
		p[1]->setPosition(ATTACK);
		p[0]->setPosition(DEFEND);
	}

	else
	{
		cout << "Player 2 " << endl;
		p[0]->a.getFront()->defend(p[1]->a.getFront()->attack());
		p[0]->setPosition(ATTACK);
		p[1]->setPosition(DEFEND);
	}

	// check to see if any Creature strPt = 0
	winRnd = gameStatus();
}


/*********************************************************************
** Game::gameStatus
** Function that determines if the game has ended or continues.
*********************************************************************/
bool Game::gameStatus()
{
	//if statement that will check for score,
	// this will check # of creatures in players queue

	// check to see if any Creature strPt = 0
		if (p[0]->a.getFront()->getSP() <= 0)
		{
			displayRound();			
			
			cout << "The winner of this round is "
				<< p[1]->a.getFront()->getName()
				<< endl << endl;

			cout << p[1]->a.getFront()->getName() << " has"
				<< " been sent to the back of the queue on"
				<< " their team!" << endl;

			string defeat = p[0]->a.getName();
			sendDefeated(defeat);

			p[0]->a.removeFront();
			p[1]->a.moveFrontToBack();

			p[1]->score += 2;
			p[0]->score--;
			return true;
		}
		else if (p[1]->a.getFront()->getSP() <= 0)
		{
			displayRound(); 
			
			cout << "The winner of this round is "
				<< p[0]->a.getFront()->getName()
				<< endl << endl;

			cout << p[0]->a.getFront()->getName() << " has"
				<< " been sent to the back of the queue on"
				<< " their team!" << endl;

			string defeat = p[1]->a.getName();
			sendDefeated(defeat);

			p[1]->a.removeFront();
			p[0]->a.moveFrontToBack();

			p[0]->score += 2;
			p[1]->score--;
			return true;
		}
		else
			return false;
}

/*********************************************************************
** Game::sendDefeated
** Function that sends losing creature to the defeated pile.
*********************************************************************/
void Game::sendDefeated(string d)
{
	defeated.addTop(d);
}

/*********************************************************************
** Game::winner
** Function that prints out the winner along with the type of
** creature they were using.
*********************************************************************/
bool Game::winner()
{
	if (p[0]->a.isEmpty() == true)
	{
		cout << "Player 2 has won!!" << endl << endl;
		cout << "+-----------------------------------------+\n";
		cout << "Final Score" << endl;
		cout << "+-----------------------------------------+\n";
		cout << "Team 1: " << p[0]->score << "     ||     Team 2: "
			<< p[1]->score << endl << endl << endl;
		return true;
	}
	else if (p[1]->a.isEmpty() == true)
	{
		cout << "Player 1 has won!!" << endl << endl;
		cout << "+-----------------------------------------+\n";
		cout << "                Final Score" << endl;
		cout << "+-----------------------------------------+\n";
		cout << "Team 1: " << p[0]->score << "     ||     Team 2: "
			<< p[1]->score << endl << endl << endl;
		return true;
	}
	else
		return false;
}