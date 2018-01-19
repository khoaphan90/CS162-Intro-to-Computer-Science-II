/*********************************************************************
** Program name: ant.hpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: Header file for the ant.cpp, Ant class.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "gameBoard.hpp"

enum Direction { NORTH, SOUTH, EAST, WEST };

class Ant
{
private:
	enum Direction antDir;
	char square, temp;
public:
	void ant(char**, int,int);
	enum Direction antDirection(char**, int, int, enum Direction);
	void playAnt(char**, int, int);
};

#endif // !ANT_HPP
