/*********************************************************************
** Program name: loadedDie.cpp for Lab 3
** Author: Khoa Phan
** Date: April 18, 2017
** Description:
*********************************************************************/

#include <iostream>
#include "die.hpp"
#include "loadedDie.hpp"

using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** LoadedDie::LoadedDie
** Function that creates a die that is biased towards larger half the
** the die.
*********************************************************************/
LoadedDie::LoadedDie(int s) : Die(s)
{
	//writes values into array
	for (int i = 0; i < sides; i++)
	{
		value[i] = (i + 1);
		// modify middle values to output higher
		for (int j = 0; j < (sides / 4); j++)
			value[(sides / 2) - 1] = ((sides / 2) + 1);
	}
}