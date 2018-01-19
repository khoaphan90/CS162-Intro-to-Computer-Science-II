/*********************************************************************
** Program name: student.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Function for the Student class that derived from
** the People class that inherits the functions from people
** and having a unique attribute and do_work function.
*********************************************************************/

#include <iostream>
#include <string>
#include "student.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** Student::Student
** Default constructor for Student
*********************************************************************/
Student::Student()
{
}

/*********************************************************************
** Validation::Student
** Function sets information from parameters that are passed into it
*********************************************************************/
Student::Student(string n, int a, double g)
{
	name = n;
	age = a;
	gpa = g;
}

/*********************************************************************
** Student::Student
** Destructor for Student
*********************************************************************/
Student::~Student()
{
}

/*********************************************************************
** Student::do_work
** Function that displays the Students's do_work information
*********************************************************************/
void Student::do_work(int x)
{
	int hours = x;
	cout << getName() << " did " << hours
		<< " hours of homework." << endl;
}

/*********************************************************************
** Student::setGPA
** Function that sets student's GPA variable
*********************************************************************/
void Student::setGPA()
{
	cin.clear();
	double g;
	cout << "Enter GPA: ";
	g = checkRange2();
	gpa = g;
}

/*********************************************************************
** Student::getAttribute
** Function that retrieves student's GPA variable
*********************************************************************/
double Student::getAttribute()
{ return gpa; }

/*********************************************************************
** Student::printInfo
** Function that prints the information for student
*********************************************************************/
void Student::printInfo(int s)
{
	for (int i = 0; i < 3; i++)
		if ((s) == i)
			cout << "Name: " << name << endl
			<< "Age: " << age << endl
			<< "GPA: " << gpa << endl;
}

/*********************************************************************
** Student::returnType
** Function that returns the type of the student
*********************************************************************/
Person Student::returnType()
{
	return STUDENT;
}