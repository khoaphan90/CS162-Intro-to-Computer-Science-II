/*********************************************************************
** Program name: gameBoard.cpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: This class is written to provide a board for the ant
** to make its moves. It consists of creation, displaying and calling
** the ant class.
*********************************************************************/

#include <iostream>
#include "gameBoard.hpp"
#include "menu.hpp"
#include "ant.hpp"
#include "validation.hpp"

using std::cout;
using std::cin;
using std::endl;

/**********************************************************
//				GameBoard::gameBoard
// Default function that calls the user to enter 
// information and start the game.
**********************************************************/
void GameBoard::gameBoard()
{
	//prompt user to enter information
	cout << "Please enter the number of rows." << endl;
	row = validOption();
	cout << "Please enter the number of columns." << endl;
	col = validOption();
	cout << "Please enter the number of steps (suggested 52)." << endl;
	numSteps = validOption();

	//start game
	playGame();
}

/**********************************************************
//				GameBoard::playGame
// Function to start the game by creating the ant and 
// game board for it to work on.
**********************************************************/
void GameBoard::playGame()
{
	//create and and board
	Ant a;
	createBoard();
	displayBoard();

	//ant start location
	a.ant(gBoard, row, col);

	//display board, steps
	for (int i = 0; i < numSteps; i++)
	{
		a.playAnt(gBoard, row, col);
		cout << "Step " << i + 1 << endl;
		displayBoard();
	}
	//deallocate array
	deallocate();
}

/**********************************************************
//				GameBoard::drawBorder
// Function that creates the border of the board to 
// establish the boundaries of it.
**********************************************************/
void GameBoard::drawBorder()
{
	//creates top and bottom border
	cout << "+-";
	for (int i = 0; i < row; i++)
		cout << "--";
	cout << "+" << endl;
}

/**********************************************************
//				GameBoard::createBoard
// Function that creates the new board dynamically in which
// prints out empty spaces for the ant to move on. Array
// is prompty deallocated.
**********************************************************/
void GameBoard::createBoard()
{
	//fill array with empty space
	char wSpace = ' ';
	gBoard = new char*[row];

	for (int i = 0; i < row; i++)
		gBoard[i] = new char[col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
				gBoard[r][c] = wSpace;
}


/**********************************************************
//				GameBoard::deallocte
// Function that deallocates the board array
**********************************************************/
void GameBoard::deallocate()
{
	for (int i = 0; i < row; i++)
		delete[] gBoard[i];
	delete[] gBoard;
	gBoard = NULL;
}

/**********************************************************
//				GameBoard::displayBoard
// Function that displays the board array in its current
// state. This will update as the ant makes its move 
// throughout the board.
**********************************************************/
void GameBoard::displayBoard()
{
	//create top border, middle, bottom
	drawBorder();
	for (int r = 0; r < row; r++)
	{
		cout << "| ";
		for (int c = 0; c < col; c++)
		{
			cout << gBoard[r][c] << ' ';
		}
		cout << "|\n";
	}
	drawBorder();
	cout << endl;
}
