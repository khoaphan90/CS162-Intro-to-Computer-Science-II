/*********************************************************************
** Program name: recursion.cpp for Lab 5
** Author: Khoa Phan
** Date: May 2, 2017
** Description: This file holds the functions to be used to 
** demonstrate the use of recursive functions.
*********************************************************************/

#include <iostream>
#include <array>
#include "recursion.hpp"

using namespace std;

/*********************************************************************
** stringReverse
** Function that reverses a user input string
*********************************************************************/
string stringReverse(string in, int i)
{
	string temp;

	// writes char at i location
	if (i >= 0)
	{
		temp = in.at(i);
		return temp + (stringReverse(in, i - 1));
	}
	else
		return temp; // return reversed string
}


/*********************************************************************
** sumArray
** Function that takes a pointer to an array and adds all values.
*********************************************************************/
int sumArray(int *arr, int aNum)
{
	// initialize sum
	int sum = 0;
	int i = aNum - 1;

	// conditional to break recursion
	if (i < 0)
		return sum; // return sum of all elements
	else
	{
		sum += arr[i];
		return (arr[i] + sumArray(arr, (aNum - 1)));
	}
}

/*********************************************************************
** triangular
** Function that calculates the triangular number from user input 
** amount of rows.
*********************************************************************/
int triangular(int rows, int i)
{
	// initialize count
	int temp = 0;

	// conditional to break recursion
	if (i <= rows )
	{
		temp += i;
		return temp + triangular(rows, i + 1);
	}
	else
		return temp;
}