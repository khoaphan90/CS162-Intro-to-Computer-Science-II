/*********************************************************************
** Program name: people.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Functions that establish the People class that is used
** by derived classes to inherit the features of this class.
*********************************************************************/

#include <iostream>
#include <string>
#include "people.hpp"
#include "student.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** People::People
** Default constructor for People class
*********************************************************************/
People::People()
{
}

/*********************************************************************
** People::setName
** Function that sets name 
*********************************************************************/
void People::setName()
{
	string n;
	cout << "Enter name: ";
	getline(cin, n); 
	name = n;
}

/*********************************************************************
** People::setAge
** Function that sets age
*********************************************************************/
void People::setAge()
{
	int a;
	cout << "Enter age: ";
	a = checkInt();
	age = a;
}

/*********************************************************************
** People::getName
** Function that retrieves name
*********************************************************************/
string People::getName() const
{
	return name;
}

/*********************************************************************
** People::getAge
** Function that retrieves age
*********************************************************************/
int People::getAge() const
{
	return age;
}