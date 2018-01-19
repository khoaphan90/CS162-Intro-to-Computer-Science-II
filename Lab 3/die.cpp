/*********************************************************************
** Program name: die.cpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description: This program is written to create a unique die that
** can contain as many sides as wanted.
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "die.hpp"

using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Die::Die
** Function that recieves a number of sides and creates values based
** off that number.
*********************************************************************/
Die::Die(int s)
{
	sides = s;
	value = new int[sides];

	// write value to array based on # of sides
	for (int i = 0; i < sides; i++)
		value[i] = (i + 1);
}

/*********************************************************************
** Die::roll
** Function that randomly chooses a value from the array and takes
** modulus based on number of sides to select a random number that 
** will then return a value at that location.
*********************************************************************/
int Die::roll()
{
	// choose random #, return at array location
	int i = rand() % sides;
	return value[i];
}

/*********************************************************************
** Die::~Die
** Destructor that deallocates memory from die creation
*********************************************************************/
Die::~Die()
{
	delete[] value;
	value = NULL;
}