/*********************************************************************
** Program name: menu.cpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Function program that is used to create a menu that
** will receive input from the user to choose options.
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "university.hpp"
#include "building.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "validation.hpp"

using namespace std;

University OSU;

/*********************************************************************
** Menu::mainMenu
** Menu that displays initial screen of options for user
*********************************************************************/
bool Menu::mainMenu()
{
	int input;
	cout << "+-------------------------------------+" << endl;
	cout << " Welcome to the Information System for" << endl;
	cout << " " << OSU.getUniName() << endl;
	cout << "+-------------------------------------+" << endl;
	cout << "\nPlease choose a following option:\n"
		<< "\n1. Building"
		<< "\n2. People"
		<< "\n3. Work"
		<< "\n4. Exit Program"
		<< endl;
	cout << "\nChoice: ";
	input = checkInt();

	switch (input)
	{
	case 1:
		bldgMenu();
		return true;
		break;
	case 2: 
		personMenu();
		return true;
		break;
	case 3:
		workMenu();
		return true;
		break;
	case 4:
		cout << "Thank you for using this program." << endl;
		return false;
		break;
	default:
		cout << "Please choose a valid option" << endl;
		return true;
	}
}

/*********************************************************************
** Menu::bldgMenu
** Menu that displays building options for user
*********************************************************************/
void Menu::bldgMenu()
{
	Building* bAdd = new Building;
	bool list = false;
	int input;

	cout << "\n----Please choose an option.----\n"
		<< "1. Add Building\n"
		<< "2. Print Building\n"
		<< "3. Go Back\n"
		<< "\nChoice: ";
	input = checkInt();
	cin.clear();

	switch (input)
	{
	case 1:
		bAdd->setName();
		bAdd->setSize();
		bAdd->setAddress();
		OSU.setBuilding(bAdd);
		cout << endl;
		break;
	case 2:
		int i;
		list = OSU.printBldgList();
		if (list == true)
		{
			cout << "\n---Please select a building.---\n";
			i = checkInt();
			cout << endl;
			OSU.printBldg(i);
			cout << endl;
		}
		break;
	case 3:
		break;
	default:
		cout << "Invalid choice." << endl;
		break;
	}
}

/*********************************************************************
** Menu::personMenu
** Menu that displays people options for user
*********************************************************************/
void Menu::personMenu()
{
	int input;

	cout << "\n----Please choose an option.----\n"
		<< "1. Student\n"
		<< "2. Instructor\n"
		<< "3. Go Back\n"
		<< "\nChoice: ";
	input = checkInt();
	cin.clear();

	switch (input)
	{
	case 1:
		studentMenu();
		break;
	case 2:
		instMenu();
		break;
	case 3:
		break;
	default:
		cout << "Invalid choice." << endl;
		break;
	}
}

/*********************************************************************
** Menu::studentMenu
** Menu that displays student options for user
*********************************************************************/
void Menu::studentMenu()
{
	Student* sAdd = new Student;

	int input;

	cout << "\n----Please choose an option.----\n"
		<< "1. Add Student\n"
		<< "2. Print Student\n"
		<< "3. Go Back\n"
		<< "\nChoice: ";
	input = checkInt();
	cin.clear();

	switch (input)
	{
	case 1:
		sAdd->setName();
		sAdd->setAge();
		sAdd->setGPA();
		OSU.setStudent(sAdd);
		cout << endl;
		break;
	case 2:
		OSU.printStudent();
		break;
	case 3:
		break;
	default:
		cout << "Invalid choice." << endl;
		break;
	}
}

/*********************************************************************
** Menu::instMenu
** Menu that displays instructor options for user
*********************************************************************/
void Menu::instMenu()
{
	Instructor* iAdd = new Instructor;
	int input;

	cout << "\n----Please choose an option.----\n"
		<< "1. Add Instructor\n"
		<< "2. Print Instructor\n"
		<< "3. Go Back\n"
		<< "\nChoice: ";
	input = checkInt();
	cin.clear();

	switch (input)
	{
	case 1:
		iAdd->setName();
		iAdd->setAge();
		iAdd->setRating();
		OSU.setInstructor(iAdd);
		cout << endl;
		break;
	case 2:
		OSU.printInstructor();
		break;
	case 3:
		break;
	default:
		cout << "Invalid choice." << endl;
		break;
	}
}

/*********************************************************************
** Menu::workMenu
** Menu that calls for instructor or student to do_work
*********************************************************************/
void Menu::workMenu()
{
	int input;

	cout << "\n----Please choose an option to do work.----\n"
		<< "1. Student\n"
		<< "2. Instructor\n"
		<< "3. Go Back\n"
		<< "\nChoice: ";
	input = checkInt();
	cin.clear();

	switch (input)
	{
	case 1:
		OSU.do_workStudent();
		break;
	case 2:
		OSU.do_workInstructor();
		break;
	case 3:
		break;
	default:
		cout << "Invalid choice." << endl;
		break;
	}
}