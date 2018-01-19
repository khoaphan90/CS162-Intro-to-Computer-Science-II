/*********************************************************************
** Program name: ant.cpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: This is the Ant class used to create the ant and 
** determine its location. The class also has the ant's sequence of
** of moves.
*********************************************************************/

#include <iostream>
#include "ant.hpp"
#include "validation.hpp"
#include "gameBoard.hpp"
#include "validation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**********************************************************
//				Ant::ant
// Function that establishes the ant's starting location
// and default direction. Data validation used for 
// staring point.
**********************************************************/
void Ant::ant(char **bArray, int r, int c)
{
	//default values of ant
	antDir = NORTH;
	square = ' ';
	temp = ' ';

	char ant;
	int xCoord, yCoord;

	//prompt user for start location
	do
	{
		cout << "Please choose a starting location. " << endl;
		xCoord = validRange(r, c) -1;
		yCoord = validRange(r, c) -1;

	} while (!(xCoord < c) && (yCoord < r));

	//set location from input
	ant = bArray[xCoord][yCoord] = '@';
}

/**********************************************************
//				Ant::playAnt
// This function passes information from the ant's
// location and direction as well as the board array
**********************************************************/
void Ant::playAnt(char** game, int r, int c)
{
	//pushes info from board
	antDirection(game, r, c, antDir);
}

/**********************************************************
//				Ant::antDirection
// This function takes the enum parameter of the ant
// and determines the ant's next move on the board.
**********************************************************/
enum Direction Ant::antDirection(char** board, int row, int col, 
	enum Direction direction)
{
	switch (direction)
	{
	case NORTH:
		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				if (board[r][c] == '@')
				{
					if (square == ' ')
					{
						board[r][c] = '#';
						if (c + 1 >= col)
						{
							c = 0;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r][c + 1];
							board[r][c + 1] = '@';
						}
						return antDir = EAST;
					}
					if (square == '#')
					{
						board[r][c] = ' ';
						if (c == 0)
						{
							c = col - 1;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r][c - 1];
							board[r][c] = ' ';
							board[r][c - 1] = '@';
						}
						return antDir = WEST;
					}
				}
		break;
	case SOUTH:
		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				if (board[r][c] == '@')
				{
					if (square == ' ')
					{
						board[r][c] = '#';
						if (c == 0)
						{
							c = col - 1;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r][c - 1];
							board[r][c - 1] = '@';
						}
						return antDir = WEST;
					}
					if (square == '#')
					{
						board[r][c] = ' ';
						if (c + 1 >= col)
						{
							c = 0;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r][c + 1];
							board[r][c + 1] = '@';
						}
						return antDir = EAST;
					}
				}
		break;
	case EAST:
		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				if (board[r][c] == '@')
				{
					if (square == ' ')
					{
						board[r][c] = '#';
						if (r + 1 >= row)
						{
							r = 0;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r + 1][c];
							board[r + 1][c] = '@';
						}
						return antDir = SOUTH;
					}
					if (square == '#')
					{
						board[r][c] = ' ';
						if (r == 0)
						{
							r = row - 1;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
						square = board[r - 1][c];
						board[r - 1][c] = '@';
						}
						return antDir = NORTH;
					}
				}
		break;
	case WEST:
		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				if (board[r][c] == '@')
				{
					if (square == ' ')
					{
						board[r][c] = '#';
						if (r == 0)
						{
							r = row - 1;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r - 1][c];
							board[r - 1][c] = '@';
						}
						return antDir = NORTH;
					}
					if (square == '#')
					{
						board[r][c] = ' ';
						if (r + 1 >= row)
						{
							r = 0;
							square = board[r][c];
							board[r][c] = '@';
						}
						else
						{
							square = board[r + 1][c];
							board[r + 1][c] = '@';
						}
						return antDir = SOUTH;
					}
				}
		break;
	}
}
