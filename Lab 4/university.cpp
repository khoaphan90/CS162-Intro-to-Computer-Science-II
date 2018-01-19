/*********************************************************************
** Program name: university.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Function program that is used to hold the functions
** of the university class. Functions range from displaying and 
** setting buildings and people within university.
*********************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "university.hpp"
#include "validation.hpp"

using namespace std;

/*********************************************************************
** University::University
** Default constructor for University object.
*********************************************************************/
University::University()
{
	name = "Oregon State University";
	srand(time(NULL));
}

/*********************************************************************
** University::~University
** Destructor that deallocates the memory created by new object.
*********************************************************************/
University::~University()
{
	for (int i = 0, s = n.size(); i < s; i++)
		delete n[i];
	n.clear();

	for (int i = 0, s = m.size(); i < s; i++)
		delete m[i];
	m.clear();
}

/*********************************************************************
** University::getUniName
** Function that returns University name
*********************************************************************/
string University::getUniName() const
{
	return name;
}

/*********************************************************************
** University::setBuilding
** Function that sets building into n vector
*********************************************************************/
void University::setBuilding(Building *b)
{
	n.push_back(b);
}

/*********************************************************************
** University::setStudent
** Function that sets student into m vector.
*********************************************************************/
void University::setStudent(Student *s)
{
	m.push_back(s);
}

/*********************************************************************
** University::setInstructor
** Function that sets student into m vector.
*********************************************************************/
void University::setInstructor(Instructor *i)
{
	m.push_back(i);
}

/*********************************************************************
** University::printBldgList
** Function prints the buildings names in a list.
*********************************************************************/
bool University::printBldgList()
{
	if (n.size() < 1)
	{
		cout << "\n*This list is empty.\n" << endl;
		return false;
	}
	else
	{
		for (int i = 0, s = n.size(); i < s; i++)
			cout << i + 1 << ". " << n.at(i)->getName() << endl;
		return true;
	}
}

/*********************************************************************
** University::printBldg
** Function that prints building info
*********************************************************************/
void University::printBldg(int i)
{
	for (int k = 0, s = n.size(); k < s; k++)
		if (k == (i - 1))
		{
			cout << "-----------------------------------------------\n";
			cout << "Building:	" << n.at(i - 1)->getName() << endl;
			cout << "Size:		" << n.at(i - 1)->getSize() << " SF" << endl;
			cout << "Address:	" << n.at(i - 1)->getAddress() << endl;
			cout << "-----------------------------------------------\n";
			break;
		}
}

/*********************************************************************
** University::printStudent
** Function that prints student info.
*********************************************************************/
int University::printStudent()
{
	int i = 0;
	bool list = false;

	if (m.size() < 1)
		cout << "\n*This list is empty.\n" << endl;

	else
	{
		for (int i = 0, s = m.size(); i < s; i++)
			if (m.at(i)->returnType() == STUDENT)
				cout << i + 1 << ". " << m.at(i)->getName() << endl;
		cout << endl;
		list = true;
	}

	if (list == true)
	{
		cout << "\n---Please select a student.---\n";
		i = checkInt();
		cout << endl;
		for (int k = 0, s = m.size(); k < s; k++)
			if (k == (i - 1))
			{
				m.at(k)->printInfo(k);
				break;
			}
	}
	return i;
}

/*********************************************************************
** University::printInstructor
** Function that prints instructor menu
*********************************************************************/
int University::printInstructor()
{
	int i = 0;
	bool list = false;

	if (m.size() < 1)
		cout << "\n*This list is empty.\n" << endl;

	else
	{
		for (int i = 0, s = m.size(); i < s; i++)
			if (m.at(i)->returnType() == INSTRUCTOR)
				cout << i + 1 << ". " << m.at(i)->getName() << endl;
		cout << endl;
		list = true;
	}

	if (list == true)
	{
		cout << "\n---Please select an instructor.---\n";
		i = checkInt();
		cout << endl;

		for (int k = 0, s = m.size(); k < s; k++)
			if (k == (i - 1))
			{
				m.at(k)->printInfo(k);
				break;
			}
	}
	return i;
}

/*********************************************************************
** University::do_workStudent
** Function allows user to select student from list and do an action
*********************************************************************/
void University::do_workStudent()
{
	int x, p;
	p = printStudent() - 1;
	for (int k = 0, s = m.size(); k < s; k++)
		if (k == p)
		{
			x = rand() % (100 + 1 - 0);
			m.at(k)->do_work(x);
			break;
		}
}

/*********************************************************************
** University::do_workInstructor
** Function allows user to select instructor from list and do an 
** action
*********************************************************************/
void University::do_workInstructor()
{
	int x, p;
	p = printInstructor() - 1;
	for (int k = 0, s = m.size(); k < s; k++)
		if (k == p)
		{
			x = rand() % (100 + 1 - 0);
			m.at(k)->do_work(x);
			break;
		}
}