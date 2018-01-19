/*********************************************************************
** Program name: university.hpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Header file for the University class.
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>
#include "people.hpp"
#include "instructor.hpp"
#include "student.hpp"
#include "building.hpp"

using namespace std;

class University
{
private:
	const int CAP = 10000;
	string name;
	vector<Building*> n;
	vector<People*> m;
	vector<string> fileInfo;
public:
	University();
	~University();
	string getUniName() const;
	void setBuilding(Building*);
	void setStudent(Student*);
	void setInstructor(Instructor*);
	bool printBldgList();
	void printBldg(int);
	int printStudent();
	int printInstructor();
	void do_workStudent();
	void do_workInstructor();
protected:
};

#endif // 
