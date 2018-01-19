/*********************************************************************
** Program name: building.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Function for the Building class that stores information
** of building objects
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "building.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** Building::Building
** Default constructor for Building
*********************************************************************/
Building::Building()
{
}

/*********************************************************************
** Building::Building
** Function that takes parameters and sets the class variables of object
*********************************************************************/
Building::Building(string n, double s, string a)
{
	name = n;
	bSize = s;
	address = a;
}

/*********************************************************************
** Building::setName
**Function that prompts user to set the name 
*********************************************************************/
void Building::setName()
{ 
	cin.clear();
	string n;
	cout << "Enter name: ";
	getline(cin, n);
	name = n; 
}

/*********************************************************************
** Building::setSize
** Function that prompts user to set the size  
*********************************************************************/
void Building::setSize()
{ 
	cin.clear();
	double s;
	cout << "Enter size: ";
	s = checkDouble();
	bSize = s; 
}

/*********************************************************************
** Building::setAddress
** Function that prompts user to set the address 
*********************************************************************/
void Building::setAddress()
{ 
	cin.clear();
	string a;
	cout << "Enter address: ";
	getline(cin, a);
	address = a; 
}

/*********************************************************************
** Building::getName
** Function that retrieves name of a building object
*********************************************************************/
string Building::getName() const
{ return name; }

/*********************************************************************
** Building::getSize
**  Function that retrieves size of a building object
*********************************************************************/
double Building::getSize() const
{ return bSize; }

/*********************************************************************
** Building::getAddress
** Function that retrieves address of a building object
*********************************************************************/
string Building::getAddress() const
{ return address; }