/*********************************************************************
** Program name: instructor.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Function for the Instructor class that derived from
** the People class that inherits the functions from people
** and having a unique attribute and do_work function.
*********************************************************************/

#include <iostream>
#include <string>
#include "instructor.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** Instructor::Instructor
** Default constructor for Instructor
*********************************************************************/
Instructor::Instructor()
{
}

/*********************************************************************
** Instructor::~Instructor
** Destructor for Instructor
*********************************************************************/
Instructor::~Instructor()
{
}

/*********************************************************************
** Instructor::do_work
** Function that displays the Instructor's do_work information
*********************************************************************/
void Instructor::do_work(int x)
{
	int hours = x;
	cout << "Instructor " << getName()
		<< " graded papers for " << hours
		<< " hours." << endl;
}

/*********************************************************************
** Instructor::setRating
** Function sets the rating for the instructor's rating variable
*********************************************************************/
void Instructor::setRating()
{ 
	cin.clear();
	double r;
	cout << "Enter rating: ";
	r = checkRange1();
	rating = r; 
}

/*********************************************************************
** Instructor::getAttribute
** Function that retrieves instructor's rating variable
*********************************************************************/
double Instructor::getAttribute()
{ return rating; }

/*********************************************************************
** Instructor::printInfo
** Function that prints the information for Instructor
*********************************************************************/
void Instructor::printInfo(int s)
{
	for (int i = 0; i < 3; i++)
		if ((s) == i)
			cout << "Name: " << name << endl
			<< "Age: " << age <<  endl
			<< "Rating: " << rating << endl;
}

/*********************************************************************
** Instructor::returnType
** Function that returns the type of the instructor
*********************************************************************/
Person Instructor::returnType()
{
	return INSTRUCTOR;
}