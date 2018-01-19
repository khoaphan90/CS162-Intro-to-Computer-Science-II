/*********************************************************************
** Program name: instructor.hpp for Lab4
** Author: Khoa Phan
** Date: April 28, 2017
** Description: Header file for the Instructor class.
*********************************************************************/


#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <string>
#include "people.hpp"

using namespace std;

class Instructor : public People
{
private:
	double rating;
public:
	Instructor();
	~Instructor();
	void do_work(int);
	void setRating();
	double getAttribute();
	void printInfo(int);
	Person returnType();
protected:
};

#endif // !INSTRUCTOR_HPP