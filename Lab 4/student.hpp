/*********************************************************************
** Program name: student.hpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Header file for the Student class.
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "people.hpp"

using namespace std;

class Student : public People
{
private:
	double gpa;
public:
	Student();
	Student(string, int, double);
	~Student();
	void do_work(int);
	void setGPA();
	double getAttribute();
	void printInfo(int);
	Person returnType();
protected:
};

#endif // !STUDENT_HPP