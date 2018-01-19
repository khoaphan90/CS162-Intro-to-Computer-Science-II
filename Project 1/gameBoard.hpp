/*********************************************************************
** Program name: gameBoard.hpp for Project 1
** Author: Khoa Phan
** Date: April 12, 2017
** Description: Header file for the gameBoard.cpp, GameBoard class.
*********************************************************************/

#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

class GameBoard
{
private:
	int row;
	int col;
	int numSteps;
	char** gBoard;
public:
	void gameBoard();
	void createBoard();
	void displayBoard();
	int getRow() { return row; };
	int getCol() { return col; };
	char** getBoard() { return gBoard; };
	void playGame();
	void drawBorder();
	void deallocate();
};

#endif // !GAMEBOARD_HPP
