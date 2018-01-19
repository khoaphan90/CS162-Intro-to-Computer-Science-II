/*********************************************************************
** Program name: game.hpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: Header file for game.cpp
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "die.hpp"

class Game
{
private:
	static const int nPlay = 2;
	int rounds;
	int score[2] = { 0,0 };
	int player[nPlay];
	int sizeDie[nPlay];;
	int rollResult[nPlay];
	Die* dice[2];
public:
	Game();
	void setDie();
	void setRounds();
	void start();
	int getScore(int);
	void displayScore();
	void clearScreen();
};
#endif // !GAME_HPP
